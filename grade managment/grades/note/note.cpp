#include "note.h"
#include "mainwindow/mainwindow.h"
#include "ui_note.h"
#include <QtSql>
#include<QMessageBox>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QFileDialog>
#include <QFile>
// -------------------------------------------
#include "./groupe/pdfExport.h"
#include <QPdfWriter>
#include <QTextDocument>
#include <QTextCursor>
#include <QTextTable>
#include <QTextTableCell>
#include <QTextTableFormat>
#include <QFileDialog>
#include <QFile>
#include <QPrinter>
#include <QPdfWriter>
#include <QPainter>
#include <QPageSize>
// -----------------------------

Note::Note(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Note)
    , NoteModel(new QSqlQueryModel(this))
    , MainlyPvModel(new QSqlQueryModel(this))
    // , PvModel(new QSqlQueryModel(this))

{
    ui->setupUi(this);
    setWindowIcon(QIcon("C:/Users/user/Desktop/IRM1-3/iconprojet.jpg"));
    setWindowTitle("grade managment");
    ui->bak->setIcon(QIcon("C:/Users/user/Desktop/IRM1-3/carbon--return.svg"));
    ui->go_b_del->setIcon(QIcon("C:/Users/user/Desktop/IRM1-3/carbon--return.svg"));
    connect(ui->table_Notedel, &QTableView::clicked, this, &Note::displaySelectedNote);
    ui->Liste_grp->setVisible(false);
    ui->liste_grpm->setVisible(false);
    ui->show_S->setVisible(false);
    ui->Continue->setVisible(false);
    ui->Liste_mat->setVisible(false);
    ui->Liste_etu->setVisible(false);
    ui->type->setVisible(false);
    ui->proceed->setVisible(false);
    ui->frame_2->setVisible(false);
    populateComboBox();
    populate_PV_grp();
    populate_grp();
    populate_grpm();
    populate_mat();
    display_frame_2();
    ui->liste_note->setModel(NoteModel);
    ui->table_Notedel->setModel(NoteModel);

    populateNoteModel();
    customizeTableView();
    // populate_mainly_PV();
    // Resultat(21199,"IRM1-3");
    // calculer_moyenne_G(21199,"IRM1-3");
    // calculer_moyenne_GM(23031,"GRP009");
    // calculer_moyenne_GM(21199,"GRP002");
    // calculer_moyenne(21371,"MAT016");
    // calculer_moyenne(21371,"MAT015");
    // populateS();
    // connect(ui->PV_GRP, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &Note::populateS);

    // ui->mainly_PV->setModel(PvModel);
    PV();
    connect(ui->PV_GRP, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &Note::PV);


}
Note::Note(matiere* mat, etudiant* etu, float note, string type) :Mat(mat), Etu(etu), note(note), Type(type) {}


std::ostream& operator<<(std::ostream& os, const Note& grade) {
    os << "Matiere: " << *(grade.Mat) << "\n";
    os << "Etudiant: " << *(grade.Etu) << "\n";
    os << "Note: "<< grade.note << endl;
    os << "Type: " << grade.Type << endl;
    return os;
}
Note::~Note()
{
    delete ui;
}
void Note::populateComboBox()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("example.db");

    // Open the database
    if (!db.open()) {
        qDebug() << "Error: Failed to open database";
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT cnrps FROM Enseignant");
    if (!query.exec()) {
        qDebug() << "Error executing query:" << query.lastError().text();
        return;
    }

    QStringList comboItems;
    while (query.next()) {
        QString cnrps = query.value(0).toString();
        comboItems.append(cnrps);
    }


    db.close();


    QStringListModel *comboModel = new QStringListModel(this);
    comboModel->setStringList(comboItems);
    ui->cnss->setModel(comboModel);
}
void Note::populate_grp()
{
    // Assuming ui->cnss is the QLineEdit
    QString cnssText = ui->cnss->currentText();
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("example.db");

    // Open the database
    if (!db.open()) {
        qDebug() << "Error: Failed to open database";
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT DISTINCT Groupe_GM_Etudiant.IdG "
                  "FROM Enseignant "
                  "JOIN Matiere ON Enseignant.cnrps = Matiere.cnrp "
                  "JOIN GroupeModule_Matiere ON Matiere.idmat = GroupeModule_Matiere.idmat "
                  "JOIN GroupeModule ON GroupeModule_Matiere.IdGM = GroupeModule.IdGM "
                  "JOIN Groupe_GM_Etudiant ON GroupeModule.IdGM = Groupe_GM_Etudiant.IdGm "
                  "WHERE Enseignant.cnrps = :cnss");
    query.bindValue(":cnss", cnssText);
    if (!query.exec()) {
        qDebug() << "Error executing query:" << query.lastError().text();
        return;
    }
    QStringList comboItems;
    while (query.next()) {
        QString id_grp = query.value(0).toString();
        comboItems.append(id_grp);
    }

    db.close();

    QStringListModel *comboModel = new QStringListModel(this);
    comboModel->setStringList(comboItems);
    ui->Liste_grp->setModel(comboModel);
}
void Note::populate_mat()
{
    QString selectedIdGrpm = ui->liste_grpm->currentText();
    QString cnss = ui->cnss->currentText();

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("example.db");

    // Open the database
    if (!db.open()) {
        qDebug() << "Error: Failed to open database";
        return;
    }
    QSqlQuery query;
    query.prepare("SELECT Matiere.nommat FROM Matiere "
                  "INNER JOIN GroupeModule_Matiere ON Matiere.idmat = GroupeModule_Matiere.idmat "
                  "INNER JOIN GroupeModule ON GroupeModule_Matiere.IdGM = GroupeModule.IdGM "
                  "WHERE GroupeModule.IdGM = :selectedIdGrpm "
                  "AND Matiere.cnrp = :selectedIdcnrp");
    query.bindValue(":selectedIdGrpm", selectedIdGrpm);
    query.bindValue(":selectedIdcnrp", cnss);
    if (!query.exec()) {
        qDebug() << "Error executing query:" << query.lastError().text();
        return;
    }

    QStringList comboItems;
    while (query.next()) {
        QString nommat = query.value(0).toString();
        comboItems.append(nommat);
    }

    db.close();

    QStringListModel *comboModel = new QStringListModel(this);
    comboModel->setStringList(comboItems);
    ui->Liste_mat->setModel(comboModel);
}



void Note::on_continue_2_clicked()
{
    QString  cnss = ui->cnss->currentText();
    QSqlDatabase db = QSqlDatabase::database();

    if (!db.isOpen()) {
        qDebug() << "Error: Database not open";
        return;
    }

        QSqlQuery query;
        query.prepare("SELECT COUNT(*) FROM Matiere WHERE cnrp = :cnrp");
        query.bindValue(":cnrp", cnss);
        if (!query.exec()) {
            qDebug() << "Error executing query:" << query.lastError().text();
            return;
        }

        int count = 0;
        if (query.next()) {
            count = query.value(0).toInt();
        }

        db.close();

        if (count == 0) {
                    QMessageBox::warning(this, "Warning", "No valid CNRP entered. Please enter a valid CNRP.");
        } else {
            ui->Liste_grp->setVisible(true);
            ui->Continue->setVisible(true);
            populate_grp();
        }
}



void Note::populate_grpm()
{
    QString selectedIdgrp = ui->Liste_grp->currentText();
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("example.db");

    // Open the database
    if (!db.open()) {
        qDebug() << "Error: Failed to open database";
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT DISTINCT IdGM FROM  Groupe_GM_Etudiant WHERE IdG=:idg ");
    query.bindValue(":idg", selectedIdgrp);
    if (!query.exec()) {
        qDebug() << "Error executing query:" << query.lastError().text();
        return;
    }

    QStringList idGRPItems;
    while (query.next()) {
        QString idGRP = query.value(0).toString();
        idGRPItems.append(idGRP);
    }

    db.close();

    QStringListModel *idGRPModel = new QStringListModel(this);
    idGRPModel->setStringList(idGRPItems);
    ui->liste_grpm->setModel(idGRPModel);


}
void Note::on_Continue_clicked()
{
    ui->liste_grpm->setVisible(true);
    ui->proceed->setVisible(true);
    populate_grpm();

}

void Note::populate_students() {
    QString selectedIdGrp = ui->Liste_grp->currentText();
    QSqlDatabase db = QSqlDatabase::database();

    if (!db.isOpen()) {
        qDebug() << "Error: Database not open";
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT DISTINCT e.nom FROM Etudiant e "
                  "INNER JOIN Groupe_GM_Etudiant g ON e.num_insc = g.numinsc "
                  "WHERE g.IdG = :selectedIdGrp");
    query.bindValue(":selectedIdGrp", selectedIdGrp);
    if (!query.exec()) {
        qDebug() << "Error executing query:" << query.lastError().text();
        return;
    }

    QStringList comboItems;
    while (query.next()) {
        QString nom_etu = query.value(0).toString();
        comboItems.append(nom_etu);
    }

    db.close();

    QStringListModel *comboModel = new QStringListModel(this);
    comboModel->setStringList(comboItems);
    ui->Liste_etu->setModel(comboModel);
}




void Note::on_proceed_clicked()
{
    ui->Liste_mat->setVisible(true);
    ui->show_S->setVisible(true);
    ui->Liste_etu->setVisible(true);
    ui->type->setVisible(true);
    populate_mat();
    populate_students();
}
void Note::display_frame_2()
{

    QString selectedStudent = ui->Liste_etu->currentText();
    QString selectedMatiere = ui->Liste_mat->currentText();
    QString selectedType = ui->type->currentText();

    ui->selected_ETU->setText(selectedStudent);
    ui->selected_mat->setText(selectedMatiere);
    ui->selected_type->setText(selectedType);

}
void Note::on_show_S_clicked()
{

    ui->frame_2->setVisible(true);
     display_frame_2();

}

void Note::on_validate_clicked()
{
    // Open the database connection
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        qDebug() << "Error: Database not open";
        return;
    }

    // Create the Note table if it doesn't exist
    QSqlQuery createTableQuery;
    if (!createTableQuery.exec("CREATE TABLE IF NOT EXISTS Note ("
                               "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                               "mat TEXT,"
                               "etu INTEGER,"
                               "note REAL,"
                               "type TEXT,"
                               "FOREIGN KEY(mat) REFERENCES Matiere(idmat),"
                               "FOREIGN KEY(etu) REFERENCES Etudiant(num_insc)"
                               ")")) {
        qDebug() << "Error creating Note table:" << createTableQuery.lastError().text();
        return;
    }

    QSqlQuery query;
    QString matiereName = ui->Liste_mat->currentText();
    query.prepare("SELECT idmat FROM Matiere WHERE nommat = :nommat");
    query.bindValue(":nommat", matiereName);
    if (!query.exec() || !query.next()) {
        qDebug() << "Error executing query or matiere not found:" << query.lastError().text();
        return;
    }
    QString idmat = query.value(0).toString();
    QString selectedStudent = ui->Liste_etu->currentText();
    query.prepare("SELECT num_insc FROM Etudiant WHERE nom = :nom");
    query.bindValue(":nom", selectedStudent);
    if (!query.exec() || !query.next()) {
        qDebug() << "Error executing query or student not found:" << query.lastError().text();
        return;
    }
    QString num_insc = query.value(0).toString();

    QString type = ui->type->currentText();
    double note = ui->enter_note->text().toDouble();

    // Insert data into the Note table
    query.prepare("INSERT INTO Note (mat, etu, note, type) VALUES (:mat, :etu, :note, :type)");
    query.bindValue(":mat", idmat);
    query.bindValue(":etu", num_insc);
    query.bindValue(":note", note);
    query.bindValue(":type", type);
    if (!query.exec()) {
        qDebug() << "Error executing query:" << query.lastError().text();
        return;
    }
    // Clear the comboboxes and line edit
    ui->Liste_etu->setCurrentIndex(0);
    ui->Liste_mat->setCurrentIndex(0);
    ui->type->setCurrentIndex(0);
    ui->enter_note->clear();

    // Clear the labels
    ui->selected_ETU->setText("");
    ui->selected_mat->setText("");
    ui->selected_type->setText("");

    qDebug() << "Data inserted into the Note table successfully";
}



void Note::populateNoteModel()
{

    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isValid()) {
        qDebug() << "Error: Database connection invalid";
        return;
    }

    QSqlQuery query(db);
    if (!query.exec("SELECT * FROM Note")) {
        qDebug() << "Error executing query:" << query.lastError().text();
        return;
    }


    NoteModel->setQuery(query);


    if (NoteModel->lastError().isValid()) {
        qDebug() << "Error setting query:" << NoteModel->lastError().text();
        return;
    }
}

void Note::customizeTableView()
{
    int columnCount = ui->liste_note->model()->columnCount();
    int columnWidth = 891 / columnCount;

    for (int i = 0; i < columnCount; ++i) {
        ui->liste_note->horizontalHeader()->setSectionResizeMode(i, QHeaderView::Fixed);
        ui->liste_note->horizontalHeader()->resizeSection(i, columnWidth);
    }



}




void Note::on_Adder_clicked()
{
     ui->stackedWidget->setCurrentIndex(1);
}


void Note::on_show_clicked()
{
     ui->stackedWidget->setCurrentIndex(2);
}


void Note::on_bak_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}



void Note::on_search_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("example.db");
    if (!db.open()) {
        qDebug() << "Error: Failed to open database";
        return;
    }

    QString searchText = ui->searchField->text().trimmed();

    QString queryString = "SELECT  mat, etu, note, type FROM Note "
                          "WHERE mat LIKE :searchText OR etu LIKE :searchText OR note LIKE :searchText "
                          "OR type LIKE :searchText";

    QSqlQuery query;
    query.prepare(queryString);
    query.bindValue(":searchText", "%" + searchText + "%");

    if (!query.exec()) {
        qDebug() << "Error executing query:" << query.lastError().text();
        return;
    }

    // Set the query result to the model
    NoteModel->setQuery(query);
    if (NoteModel->lastError().isValid()) {
        qDebug() << "Error setting query:" << NoteModel->lastError().text();
        return;
    }
}
void Note::displaySelectedNote(const QModelIndex &index) {

    int row = index.row();



    QSqlQueryModel *model = qobject_cast<QSqlQueryModel*>(ui->table_Notedel->model());
    QString idmat = model->data(model->index(row, 0)).toString();
    QString numinsc = model->data(model->index(row, 1)).toString();
    QString type = model->data(model->index(row, 3)).toString();
    QString note = model->data(model->index(row, 2)).toString();


    ui->idmat->setText(idmat);
    ui->numinsc->setText(numinsc);
    ui->type_2->setText(type);
    ui->note->setText(note);
}


void Note::on_pushButton_2_clicked()
{
    // Get the new note value and other necessary information
    QString newNote = ui->note->text();
    QString idmat = ui->idmat->text();
    QString numinsc = ui->numinsc->text();
    QString type = ui->type_2->text();

    // Update the note in the Note table
    QSqlQuery query;
    query.prepare("UPDATE Note SET note = :newNote WHERE mat = :idmat AND etu = :numinsc AND type = :type ");
    query.bindValue(":newNote", newNote);
    query.bindValue(":idmat", idmat);
    query.bindValue(":numinsc", numinsc);
    query.bindValue(":type", type);

    if (!query.exec()) {
        qDebug() << "Error updating note:" << query.lastError().text();
        return;
    }


    populateNoteModel();
    resetLineEditFields();

    qDebug() << "Note updated successfully.";
}
void Note::resetLineEditFields() {

    ui->idmat->clear();
    ui->numinsc->clear();
    ui->type->clear();
    ui->note->clear();
}

void Note::on_update_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}


void Note::on_go_b_del_clicked()
{
     ui->stackedWidget->setCurrentIndex(0);
}


void Note::on_Goback_clicked()
{
   ui->stackedWidget->setCurrentIndex(0);
}


void Note::on_menu_clicked()
{
    this->hide();
    mainwindow *mainWindow = new mainwindow();
    mainWindow->show();
}
double Note::calculer_moyenne(int id, QString mat)
{
    float moyenne = 0;
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("example.db");
    if (!db.open()) {
        qDebug() << "Error: Failed to open database";
        return 0;
    }
    QSqlQuery query;
    query.prepare("SELECT COUNT(*), AVG(note) FROM Note WHERE etu = :id AND mat = :mat");
    query.bindValue(":id", id);
    query.bindValue(":mat", mat);
    if (!query.exec() || !query.next()) {
        qDebug() << "Error executing query or no rows found";
        return 0;
    }

    moyenne = query.value(1).toFloat();
    moyenne = qRound(moyenne * 100) / 100.0;
    qDebug() << "moyenne  " <<mat <<":  "<< moyenne;
    return moyenne;
}
double Note::calculer_moyenne_GM(int id, QString IDGRPM)
{
    float moymat_coef = 0;
    float moymat_coefSum = 0;

    float totalCoefficientSum = 0;
    float coefficient;
    QVector<QString> idmats;

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("example.db");
    if (!db.open()) {
        qDebug() << "Error: Failed to open database";
        return 0;
    }

    QSqlQuery query;
    query.prepare("SELECT idmat FROM GroupeModule_Matiere WHERE IdGM = :idgm ");
    query.bindValue(":idgm", IDGRPM);
    if (!query.exec()) {
        qDebug() << "Error executing query";
        return 0;
    }

    while (query.next()) {
        QString idmat = query.value(0).toString();
         idmats.append(idmat);

    }
     for (const QString& idmat : idmats)
    {
        float moyenne = calculer_moyenne(id, idmat);
        QSqlQuery coefquery;
        coefquery.prepare("SELECT coef FROM Matiere WHERE idmat = :idm ");
        coefquery.bindValue(":idm", idmat);
        if (!coefquery.exec()) {
            qDebug() << "Error executing query";
            return 0;
        }

        if (coefquery.next()) {
             coefficient = coefquery.value(0).toFloat();
        } else {
            qDebug() << "No coefficient found for idmat:" << idmat;
        }
        moymat_coef=moyenne*coefficient;
        moymat_coefSum +=moymat_coef;
        totalCoefficientSum+= coefficient;
    }
    float moyenneGM= moymat_coefSum/totalCoefficientSum;
    moyenneGM = qRound(moyenneGM * 100) / 100.0;
    qDebug() << "moyen GM " << moyenneGM;
    return moyenneGM;

}
double Note::calculer_moyenne_G(int id,QString IDG)
{
    float moyGM_coef = 0;
    float moyGM_coefSum = 0;

    float totalCoefficientSum = 0;
    float coefficient;
    QVector<QString> idGRPM;

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("example.db");
    if (!db.open()) {
        qDebug() << "Error: Failed to open database";
        return 0;
    }

    QSqlQuery query;
    query.prepare("SELECT IdGm FROM Groupe_GM_Etudiant WHERE IdG = :idg ");
    query.bindValue(":idg", IDG);
    if (!query.exec()) {
        qDebug() << "Error executing query";
        return 0;
    }

    while (query.next()) {
        QString Idgrpm = query.value(0).toString();
        idGRPM.append(Idgrpm);

    }
    for (const QString& Idgrpm : idGRPM)
    {
        float moyenneGM = calculer_moyenne_GM(id,Idgrpm);
        QSqlQuery coefquery;
        coefquery.prepare("SELECT CoefGM FROM GroupeModule WHERE IdGM = :idgm ");
        coefquery.bindValue(":idgm", Idgrpm);
        if (!coefquery.exec()) {
            qDebug() << "Error executing query";
            return 0;
        }

        if (coefquery.next()) {
            coefficient = coefquery.value(0).toFloat();
        } else {
            qDebug() << "No coefficient found for idmat:" << Idgrpm;
        }
        moyGM_coef=moyenneGM*coefficient;
        moyGM_coefSum +=moyGM_coef;
        totalCoefficientSum+= coefficient;




    }
    float moyenne_G= moyGM_coefSum/totalCoefficientSum;
    moyenne_G = qRound(moyenne_G * 100) / 100.0;
    qDebug() << "moyen G " << moyenne_G;
    return moyenne_G;
}
QString Note::Resultat(int id, QString IDG)
{
    float moyenne_G = calculer_moyenne_G(id, IDG);
    if (moyenne_G > 10)
    {
        return "Admis";
    }
    else
    {
        return "Ajourné";
    }
}
QString Note::mention(int id, QString IDG)
{
    float moyenne_G = calculer_moyenne_G(id, IDG);

    if (moyenne_G >= 18 && moyenne_G <= 20) {
        return "Excellent";
    } else if (moyenne_G >= 16 && moyenne_G < 18) {
        return "Très Bien";
    } else if (moyenne_G >= 14 && moyenne_G < 16) {
        return "Bien";
    } else if (moyenne_G >= 12 && moyenne_G < 14) {
        return "Assez Bien";
    } else if (moyenne_G >= 10 && moyenne_G < 12) {
        return "Passable";
    }
    else {
        return "NEXT YEAR!!!";
    }


    return "";
}
void Note::populate_PV_grp()
{
    ui->PV_GRP->addItem("Select Groupe");
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("example.db");

    // Open the database
    if (!db.open()) {
        qDebug() << "Error: Failed to open database";
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT IdGRP from Groupe");
    if (!query.exec()) {
        qDebug() << "Error executing query:" << query.lastError().text();
        return;
    }
    QStringList comboItems;
    while (query.next()) {
        QString id_grp = query.value(0).toString();
        comboItems.append(id_grp);
    }

    db.close();

    QStringListModel *comboModel = new QStringListModel(this);
    comboModel->setStringList(comboItems);
    ui->PV_GRP->setModel(comboModel);
}
void Note::on_average_clicked()
{
     ui->stackedWidget->setCurrentIndex(3);

}









void Note::PV() {
    QString selectedGroupID = ui->PV_GRP->currentText();

    QVector<QString> groupModuleIDs;
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("example.db");

    if (!db.open()) {
        qDebug() << "Error: Failed to open database";
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT DISTINCT IdGm FROM Groupe_GM_Etudiant WHERE IdG = :idg ");
    query.bindValue(":idg", selectedGroupID);

    if (!query.exec()) {
        qDebug() << "Error executing query";
        db.close();
        return;
    }

    while (query.next()) {
        groupModuleIDs.append(query.value(0).toString());
    }

    db.close();

    QStandardItemModel *model = new QStandardItemModel(0, 0);
    QList<QStandardItem *> rowItems;
    for (int i = 0; i < 3; ++i) {
        QStandardItem *item = new QStandardItem("");
        item->setEditable(false);
        rowItems << item;
    }
    ui->mainly_PV->setSpan(0, 0, 1, 3);

    for (const QString& groupModuleID : groupModuleIDs)
    {
        QVector<QString> matiereNames;

        db.open();
        query.prepare("SELECT Matiere.nommat FROM GroupeModule_Matiere "
                      "JOIN Matiere ON GroupeModule_Matiere.idmat = Matiere.idmat "
                      "WHERE GroupeModule_Matiere.IdGM = :idgm");
        query.bindValue(":idgm", groupModuleID);

        if (!query.exec()) {
            qDebug() << "Error executing query";
            db.close();

        }

        while (query.next()) {
            matiereNames.append(query.value(0).toString());
        }
        db.close();

        QString groupName;
        db.open();
        query.prepare("SELECT NomGM FROM GroupeModule WHERE IdGM = :idgm");
        query.bindValue(":idgm", groupModuleID);

        if (!query.exec()) {
            qDebug() << "Error executing query";
            db.close();

        }

        if (query.next()) {
            groupName = query.value(0).toString();
        }
        db.close();

        for (const QString& matiereName : matiereNames) {
            rowItems << new QStandardItem(matiereName);


            db.open();
            query.prepare("SELECT coef FROM Matiere WHERE nommat = :matiereName");
            query.bindValue(":matiereName", matiereName);
            if (!query.exec()) {
                qDebug() << "Error executing query for coefficient";
                db.close();

            }
            if (query.next()) {
                double coefficient = query.value(0).toDouble();
                rowItems << new QStandardItem(QString::number(coefficient));
            }
            db.close();
        }

        rowItems << new QStandardItem(groupName);


        db.open();
        query.prepare("SELECT CoefGM FROM GroupeModule WHERE NomGM = :groupName");
        query.bindValue(":groupName", groupName);
        if (!query.exec()) {
            qDebug() << "Error executing query for coefficient";
            db.close();
        }
        if (query.next()) {
            double coefficient = query.value(0).toDouble();
            rowItems << new QStandardItem(QString::number(coefficient));
        }
        db.close();
    }

    model->appendRow(rowItems);
    model->setHorizontalHeaderLabels({"Num Insc", "Nom", "Prenom"});

    db.open();
    query.prepare("SELECT DISTINCT e.num_insc, e.nom, e.prenom FROM Etudiant e, Groupe_GM_etudiant GMM WHERE GMM.numinsc = e.num_insc AND GMM.IdG = :idg");
    query.bindValue(":idg", selectedGroupID);

    if (!query.exec()) {
        qDebug() << "Error executing query";
        db.close();
        return;
    }

    int row = 0;
    while (query.next()) {
        QString numInsc = query.value(0).toString();
        QString nom = query.value(1).toString();
        QString prenom = query.value(2).toString();

        QList<QStandardItem *> studentItems;
        studentItems << new QStandardItem(numInsc);
        studentItems << new QStandardItem(nom);
        studentItems << new QStandardItem(prenom);

        model->insertRow(row + 1, studentItems);

        row++;
    }

    db.close();
    QStandardItem *moyenneItem = new QStandardItem("Moyenne");
    model->setItem(0, model->columnCount(), moyenneItem);

    QStandardItem *resultItem = new QStandardItem("resultat");
    model->setItem(0, model->columnCount(), resultItem);
    QStandardItem *mentionItem = new QStandardItem("mention");
    model->setItem(0, model->columnCount(), mentionItem);



    for (int row = 1; row < model->rowCount(); ++row) {
        QString numInsc = model->item(row, 0)->text();
        qDebug() << "Numinsc:" << numInsc;
        int studentID = numInsc.toInt();

        for (int col = 3; col < model->columnCount(); ++col) {
            QString itemName = model->item(0, col)->text();
            QString matiereID;
            db.open();
            QSqlQuery query;
            query.prepare("SELECT idmat FROM Matiere WHERE nommat = :itemName");
            query.bindValue(":itemName", itemName);
            if (!query.exec()) {
                qDebug() << "Error executing Matiere query:" << query.lastError().text();
                db.close();

            }
            if (query.next()) {
                matiereID = query.value(0).toString();
                qDebug() << "Matiere ID:" << matiereID << "Student ID:" << studentID;



                double moyenne = calculer_moyenne(studentID, matiereID);
                qDebug() << "Average for Subject" << itemName << ":" << moyenne;
                QModelIndex index = model->index(row, col);
                model->setData(index, moyenne);
            }
            db.close();

            if (matiereID.isEmpty()) {

                QString groupModuleID;
                db.open();
                query.prepare("SELECT IdGM FROM GroupeModule WHERE NomGM = :itemName");
                query.bindValue(":itemName", itemName);
                if (!query.exec()) {
                    qDebug() << "Error executing GroupeModule query:" << query.lastError().text();
                    db.close();

                }
                if (query.next()) {
                    groupModuleID = query.value(0).toString();
                    qDebug() << "GroupModule ID:" << groupModuleID << "Student ID:" << studentID;


                    double moyenneGM = calculer_moyenne_GM(studentID, groupModuleID);
                    qDebug() << "Average for Group Module:" << moyenneGM;
                    QModelIndex index = model->index(row, col);
                    model->setData(index, moyenneGM);
                }
                db.close();
            }
        }

        double moyenne_G = calculer_moyenne_G(studentID, selectedGroupID);


        QModelIndex moyenneIndex = model->index(row, model->columnCount() - 3);
        model->setData(moyenneIndex, moyenne_G);

        QString resultat = Resultat(studentID, selectedGroupID);
        QModelIndex resultIndex = model->index(row, model->columnCount() - 2);
        model->setData(resultIndex, resultat);

        QString mentionString = mention(studentID, selectedGroupID);
        QModelIndex mentionIndex = model->index(row, model->columnCount() - 1);
        model->setData(mentionIndex, mentionString);
    }



    ui->mainly_PV->setModel(model);
    ui->mainly_PV->resizeColumnsToContents();
    ui->mainly_PV->resizeRowsToContents();

}




void Note::on_PRINT_PV_clicked()
{
    pdfExport pdfExporter;
    pdfExporter.exportTableToPDF(ui->mainly_PV);
}


void Note::on_pushButton_clicked()
{
     ui->stackedWidget->setCurrentIndex(0);
}

