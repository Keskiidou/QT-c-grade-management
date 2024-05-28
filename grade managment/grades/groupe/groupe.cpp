#include "groupe.h"
#include "mainwindow/mainwindow.h"
#include "ui_groupe.h"
#include <QtSql>
#include <QMessageBox>
#include <QStandardItemModel>
#include <QStandardItem>
// -------------------------------------------
#include "pdfExport.h"
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


Groupe::Groupe(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Groupe)
    , groupeModel(new QSqlQueryModel(this))
    , specificGroupeModel(new QSqlQueryModel(this))
    ,moreInfoModel(new QSqlQueryModel(this))
{
    ui->setupUi(this);
    setWindowIcon(QIcon("C:/Users/user/Desktop/IRM1-3/iconprojet.jpg"));
    setWindowTitle("grade managment");
    ui->pushB->setIcon(QIcon("C:/Users/user/Desktop/IRM1-3/carbon--return.svg"));
    ui->go_b_del->setIcon(QIcon("C:/Users/user/Desktop/IRM1-3/carbon--return.svg"));
    connect(ui->tableGM_del, &QTableView::clicked, this, &Groupe::displaySelectedG);
    ui->groupe_table->setModel(groupeModel);
    ui->tableGM_del->setModel(groupeModel);
    ui->table_G_update->setModel(groupeModel);
    connect(ui->groupe_table, &QTableView::clicked, this, &Groupe::display_groupe_GM_ETU);
    populateComboBox_GM();
    populateComboBox_ETU();
    populateComboBox_Niveau();
    populateComboBox_Diplome();
    populateComboBox_specialite();
    populateComboBox_Num_G();
    populateGroupeModel();
    customizeTableView();
    //--------buttons update----------
    ui->NivG->setVisible(false);
    ui->DIPG->setVisible(false);
    ui->newNiv->setVisible(false);
    ui->Niv_G->setVisible(false);
    ui->Dip_G->setVisible(false);
    ui->newDIP->setVisible(false);
    ui->newNiv->setVisible(false);
    ui->SpecG->setVisible(false);
    ui->Spec_G->setVisible(false);
    ui->NewSpec->setVisible(false);
    ui->NumG->setVisible(false);
    ui->NewNum->setVisible(false);
    ui->Num_G->setVisible(false);
    ui->updateNum->setVisible(false);
    ui->updateD->setVisible(false);
    ui->updateS->setVisible(false);
    ui->updateN->setVisible(false);


}
Groupe::Groupe(string id, string niveau, string diplome, string specialite, int num, vector<groupemodule*>* listemodules, vector<etudiant*>* listeetudiants)
    : IdGRP(id), Niveau(niveau), Diplome(diplome), Specialite(specialite), Num_G(num) {
    ListeModules = *listemodules;
    ListeEtudiants = *listeetudiants;};

std::ostream& operator<<(std::ostream& os, const Groupe& grp) {
    os << "IdGRP: " << grp.IdGRP << "\n";
    os << "Niveau: " << grp.Niveau << "\n";
    os << "Diplome: " << grp.Diplome << "\n";
    os << "Specialite: " << grp.Specialite << "\n";
    os << "Num_G: " << grp.Num_G << "\n";
    os << "ListeModules: \n";
    for (const auto& module : grp.ListeModules) {
        os << *module << "\n";
    }
    os << "ListeEtudiants: \n";
    for (const auto& etudiant : grp.ListeEtudiants) {
        os << *etudiant << "\n";
    }
    return os;
}



Groupe::~Groupe()
{
    delete ui;
}
void Groupe::on_go_b_del_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void Groupe::on_Goback_clicked()
{
   ui->stackedWidget->setCurrentIndex(0);
}

void Groupe::populateComboBox_GM()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("example.db");

    // Open the database
    if (!db.open()) {
        qDebug() << "Error: Failed to open database";
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT IdGM FROM GroupeModule");
    if (!query.exec()) {
        qDebug() << "Error executing query:" << query.lastError().text();
        return;
    }

    QStringList comboItems;
    while (query.next()) {
        QString id_GM = query.value(0).toString();
        comboItems.append(id_GM);
    }


    db.close();


    QStringListModel *comboModel = new QStringListModel(this);
    comboModel->setStringList(comboItems);
    ui->Modules->setModel(comboModel);

}

void Groupe::populateComboBox_ETU()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("example.db");

    // Open the database
    if (!db.open()) {
        qDebug() << "Error: Failed to open database";
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT num_insc FROM Etudiant");
    if (!query.exec()) {
        qDebug() << "Error executing query:" << query.lastError().text();
        return;
    }

    QStringList comboETUItems;
    while (query.next()) {
        QString numinsc = query.value(0).toString();
        comboETUItems.append(numinsc);
    }


    db.close();


    QStringListModel *comboETUModel = new QStringListModel(this);
    comboETUModel->setStringList(comboETUItems);
    ui->Students->setModel(comboETUModel);

}

void Groupe::on_save_GM_clicked()
{
    QString selectedModule = ui->Modules->currentText();

    for (int row = 0; row < ui->table_GM->rowCount(); ++row) {
        QTableWidgetItem *item = ui->table_GM->item(row, 0);
        if (item && item->text() == selectedModule) {
            QMessageBox::warning(this, "Duplicate Module", "The selected module already exists in the table.");
            return; // Prevent adding duplicate module
        }
    }

    int row = ui->table_GM->rowCount();
    ui->table_GM->insertRow(row);
    ui->table_GM->setItem(row, 0, new QTableWidgetItem(selectedModule));
}


void Groupe::on_save_etu_clicked()
{
    QString selectedModule_ETU = ui->Students->currentText();

    for (int row = 0; row < ui->table_ETU->rowCount(); ++row) {
        QTableWidgetItem *item = ui->table_ETU->item(row, 0);
        if (item && item->text() == selectedModule_ETU) {
            QMessageBox::warning(this, "Duplicate student", "The selected student already exists in the table.");
            return; // Prevent adding duplicate module
        }
    }

    int row = ui->table_ETU->rowCount();
    ui->table_ETU->insertRow(row);
    ui->table_ETU->setItem(row, 0, new QTableWidgetItem(selectedModule_ETU));
}

void Groupe::populateComboBox_Niveau()
{

    ui->NIveau->clear();

    ui->NIveau->addItem("Premiere");
    ui->NIveau->addItem("Deuxieme");
    ui->NIveau->addItem("Troisieme");
}

void Groupe::populateComboBox_Diplome()
{

    ui->Dipolome->clear();

    ui->Dipolome->addItem("ING");
    ui->Dipolome->addItem("Master");
    ui->Dipolome->addItem("LMD");
}

void Groupe::populateComboBox_specialite()
{

    ui->specialite->clear();

    ui->specialite->addItem("INF");
    ui->specialite->addItem("INDUS");
    ui->specialite->addItem("MATH");
}
void Groupe::populateComboBox_Num_G()
{

    ui->NUM_G->clear();

    ui->NUM_G->addItem("1");
    ui->NUM_G->addItem("2");
    ui->NUM_G->addItem("3");
}

void Groupe::on_add_grp_clicked()
{
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("example.db");

        // Open the database
        if (!db.open()) {
            qDebug() << "Error: Failed to open database";
            return;
        }
        QString idG = ui->ID_G->text();
        QString niveau = ui->NIveau->currentText();
        QString diplome = ui->Dipolome->currentText();
        QString specialite = ui->specialite->currentText();
        QString NumG = ui->NUM_G->currentText();
        // Create Groupe table
        QString createGroupeTableQuery = "CREATE TABLE IF NOT EXISTS Groupe ("
                                         "IdGRP TEXT PRIMARY KEY,"
                                         "Niveau TEXT NOT NULL,"
                                         "Diplome TEXT NOT NULL,"
                                         "Specialite TEXT NOT NULL,"
                                         "NumG INTEGER NOT NULL"
                                         ");";
        QSqlQuery createGroupeTable;
        if (!createGroupeTable.exec(createGroupeTableQuery)) {
            qDebug() << "Error creating Groupe table:" << createGroupeTable.lastError().text();
            return;
        } else {
            qDebug() << "Groupe table created successfully";
        }
        QSqlQuery insertQuery;
        insertQuery.prepare("INSERT INTO Groupe (IdGRP, Niveau, Diplome, Specialite, NumG) "
                            "VALUES (:idG, :niveau, :diplome, :specialite, :numG)");
        insertQuery.bindValue(":idG", idG);
        insertQuery.bindValue(":niveau", niveau);
        insertQuery.bindValue(":diplome", diplome);
        insertQuery.bindValue(":specialite", specialite);
        insertQuery.bindValue(":numG", NumG);

        if (!insertQuery.exec()) {
            qDebug() << "Error inserting values into Groupe table:" << insertQuery.lastError().text();
        } else {
            qDebug() << "Values inserted into Groupe table successfully";
        }
    // Create Groupe_GM_Etudiant table
        QString createGroupeGMEtudiantTableQuery ="CREATE TABLE IF NOT EXISTS Groupe_GM_Etudiant ("
                                                   "IdG TEXT,"
                                                   "IdGm TEXT,"
                                                   "numinsc TEXT,"
                                                   "FOREIGN KEY (IdG) REFERENCES Groupe(IdGRP),"
                                                   "FOREIGN KEY (IdGm) REFERENCES GroupeModule(IdGM),"
                                                   "FOREIGN KEY (numinsc) REFERENCES Etudiant(num_insc)"
                                                   ");";

    QSqlQuery createGroupeGMEtudiantTable;
    if (!createGroupeGMEtudiantTable.exec(createGroupeGMEtudiantTableQuery)) {
        qDebug() << "Error creating Groupe_GM_Etudiant table:" << createGroupeGMEtudiantTable.lastError().text();
        return;
    } else {
        qDebug() << "Groupe_GM_Etudiant table created successfully";
    }

    // Insert data from table_GM
    int rowCountETU = ui->table_ETU->rowCount();
    int rowCountGM = ui->table_GM->rowCount();
    QStringList idGList;
    QSqlQuery idGQuery("SELECT IdGRP FROM Groupe");
    while (idGQuery.next()) {
        idGList << idGQuery.value(0).toString();
    }

    // Iterate over each IdG value
        for (int rowGM = 0; rowGM < rowCountGM; ++rowGM) {
            QString idGm = ui->table_GM->item(rowGM, 0)->text(); // Assuming the first column contains IdGm

            for (int rowETU = 0; rowETU < rowCountETU; ++rowETU) {
                QString numinsc = ui->table_ETU->item(rowETU, 0)->text(); // Assuming the first column contains numinsc

                QSqlQuery insertGMEtudiantQuery;
                insertGMEtudiantQuery.prepare("INSERT INTO Groupe_GM_Etudiant (IdG, IdGm, numinsc) VALUES (:idG, :idGm, :numinsc)");
                insertGMEtudiantQuery.bindValue(":idG", idG);
                insertGMEtudiantQuery.bindValue(":idGm", idGm);
                insertGMEtudiantQuery.bindValue(":numinsc", numinsc);

                if (!insertGMEtudiantQuery.exec()) {
                    qDebug() << "Error inserting values into Groupe_GM_Etudiant table:" << insertGMEtudiantQuery.lastError().text();
                    db.close();
                    return;
                }
            }
    }
    // Display a QMessageBox to inform the user
    QMessageBox::information(this, "Success", "Data inserted successfully into Groupe_GM_Etudiant table");
    db.close();
    ui->stackedWidget->setCurrentIndex(0);
}




void Groupe::on_Add_groupe_clicked()
{
     ui->stackedWidget->setCurrentIndex(1);
}


void Groupe::on_pushB_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void Groupe::on_show_Groupe_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void Groupe::populateGroupeModel()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("example.db");

    if (!db.open()) {
        qDebug() << "Error: Failed to open database";
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT * FROM Groupe");
    if (!query.exec()) {
        qDebug() << "Error executing query:" << query.lastError().text();
        return;
    }

    groupeModel->setQuery(query);

    if (groupeModel->lastError().isValid()) {
        qDebug() << "Error setting query:" << groupeModel->lastError().text();
    }

    db.close();
}
void Groupe::customizeTableView()
{

    int columnCount1 = ui->groupe_table->model()->columnCount();
    int columnWidth1 = 891 / columnCount1;
    for (int i = 0; i < columnCount1; ++i) {
        ui->groupe_table->horizontalHeader()->setSectionResizeMode(i, QHeaderView::Fixed);
        ui->groupe_table->horizontalHeader()->resizeSection(i, columnWidth1);
    }
    QTableView *tableView = ui->tableGM_del;
    int columnCount = tableView->model()->columnCount();
    int tableWidth = 431;


    int columnWidth = tableWidth / columnCount;

    for (int i = 0; i < columnCount; ++i) {
        tableView->horizontalHeader()->setSectionResizeMode(i, QHeaderView::Fixed);
        tableView->setColumnWidth(i, columnWidth);
    }
    QTableView *tableView1 = ui->table_G_update;
    int columnCount2 = tableView1->model()->columnCount();
    int tableWidth2 = 261;
    int columnWidth2 = tableWidth2 / columnCount2;
    for (int i = 0; i < columnCount2; ++i) {
        tableView1->horizontalHeader()->setSectionResizeMode(i, QHeaderView::Fixed);
        tableView1->setColumnWidth(i, columnWidth2);
    }
}


void Groupe::display_groupe_GM_ETU(const QModelIndex &index) {
    if (index.isValid()) {
        int row = index.row();

        // Get the model associated with the table view
        QAbstractItemModel *model = ui->groupe_table->model();
        if (model) {
            // Retrieve the data for IdGRP from the selected row
            QVariant data = model->data(model->index(row, 0));

            // Convert the data to string
            QString idGrp = data.toString();

            qDebug() << "Selected idGrp:" << idGrp;
            // Open the database
            QSqlDatabase db = QSqlDatabase::database();
            if (!db.isValid() || !db.isOpen()) {
                qDebug() << "Error: Database connection is not valid or not open";
                return;
            }

            QSqlQuery queryG(db);
            queryG.prepare("SELECT  IdGRP, Niveau, Diplome, Specialite, NumG FROM Groupe WHERE IdGRP = :idGrp");
            queryG.bindValue(":idGrp", idGrp);
            if (!queryG.exec()) {
                qDebug() << "Error executing query:" << queryG.lastError().text();
                return;
            }
            // specificGroupeModel->clear();

            specificGroupeModel->setQuery(queryG);

            //-----------------------------------------
            QSqlQuery moreInfoQuery(db);

            moreInfoQuery.prepare("SELECT DISTINCT Etudiant.num_insc, Etudiant.nom, Etudiant.prenom, Groupe_GM_Etudiant.IdGm, "
                                  "GroupeModule.NomGM, GROUP_CONCAT(Matiere.nommat, ', ') AS Subjects "
                                  "FROM Etudiant "
                                  "INNER JOIN Groupe_GM_Etudiant ON Etudiant.num_insc = Groupe_GM_Etudiant.numinsc "
                                  "INNER JOIN GroupeModule ON Groupe_GM_Etudiant.IdGm = GroupeModule.IdGM "
                                  "INNER JOIN GroupeModule_Matiere ON GroupeModule.IdGM = GroupeModule_Matiere.IdGM "
                                  "INNER JOIN Matiere ON GroupeModule_Matiere.idmat = Matiere.idmat "
                                  "WHERE Groupe_GM_Etudiant.IdG = :idGrp "
                                  "GROUP BY Etudiant.num_insc, Groupe_GM_Etudiant.IdGm");
            moreInfoQuery.bindValue(":idGrp", idGrp);

            // Execute the query
            if (!moreInfoQuery.exec()) {
                qDebug() << "Error executing more info query:" << moreInfoQuery.lastError().text();
                return;
            }

            // Create the model and set headers
            QStandardItemModel *moreInfoModel = new QStandardItemModel;
            moreInfoModel->setHorizontalHeaderLabels(QStringList() << "Num_insc" << "Nom" << "Prenom" << "IdGm" << "NomGM" << "Subjects");

            // Fetch and add data to the model
            while (moreInfoQuery.next()) {
                // Retrieve student information
                QString num_insc = moreInfoQuery.value(0).toString();
                QString nom = moreInfoQuery.value(1).toString();
                QString prenom = moreInfoQuery.value(2).toString();
                QString idGmColumnValue = moreInfoQuery.value(3).toString();
                QString nomGM = moreInfoQuery.value(4).toString();
                QString subjects = moreInfoQuery.value(5).toString();

                // Create a list of row items
                QList<QStandardItem*> rowItems;
                rowItems.append(new QStandardItem(num_insc));
                rowItems.append(new QStandardItem(nom));
                rowItems.append(new QStandardItem(prenom));
                rowItems.append(new QStandardItem(idGmColumnValue));
                rowItems.append(new QStandardItem(nomGM));
                rowItems.append(new QStandardItem(subjects));

                // Append the row to the model
                moreInfoModel->appendRow(rowItems);
            }


             // moreInfoModel->setQuery(moreInfoQuery);
            QDialog dialog2;
            groupe_gm_etu.setupUi(&dialog2);
            groupe_gm_etu.specific_table_groupe->setModel(specificGroupeModel);
            groupe_gm_etu.more_info_groupe->setModel(moreInfoModel);
            dialog2.exec();
        }
    }
}
void Groupe::on_search_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("example.db");
    if (!db.open()) {
        qDebug() << "Error: Failed to open database";
        return;
    }

    QString searchText = ui->searchField->text().trimmed();

    // Search in the Groupe table
    QString queryString = "SELECT IdGRP, Niveau, Diplome, Specialite, NumG FROM Groupe "
                          "WHERE IdGRP LIKE :searchText OR Niveau LIKE :searchText OR Diplome LIKE :searchText "
                          "OR Specialite LIKE :searchText OR NumG LIKE :searchText";

    QSqlQuery query;
    query.prepare(queryString);
    query.bindValue(":searchText", "%" + searchText + "%");

    if (!query.exec()) {
        qDebug() << "Error executing query:" << query.lastError().text();
        return;
    }

    // Set the query result to the model
    groupeModel->setQuery(query);
    if (groupeModel->lastError().isValid()) {
        qDebug() << "Error setting query:" << groupeModel->lastError().text();
        return;
    }
}
void Groupe::displaySelectedG(const QModelIndex &index) {
    // Get the row and column of the clicked item
    int row = index.row();

    // Retrieve the data of the selected student
    QSqlQueryModel *model = qobject_cast<QSqlQueryModel*>(ui->tableGM_del->model());
    QString idG = model->data(model->index(row, 0)).toString();
    QString niveau = model->data(model->index(row, 1)).toString();
    QString diplome = model->data(model->index(row, 2)).toString();
    QString specialite = model->data(model->index(row, 3)).toString();
    int num_g = model->data(model->index(row, 4)).toInt();


    // Populate line edits with the selected student's information
    ui->ID_Groupe->setText(idG);
    ui->Niveau->setText(niveau);
    ui->diplome->setText(diplome);
    ui->spec->setText(specialite);
    ui->num_g->setText(QString::number(num_g));
}




void Groupe::resetLineEditFields() {

    ui->ID_Groupe->clear();
    ui->Niveau->clear();
    ui->diplome->clear();
    ui->spec->clear();
    ui->num_g->clear();
}
void Groupe::on_delete_G_clicked()
{

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("example.db");

    // Open the database
    if (!db.open()) {
        qDebug() << "Error: Failed to open database";
        return;
    }
    else{
        qDebug() << "databse opened ";
    }
    QString ID_del = ui->ID_Groupe->text();
    QSqlQuery queryDelete;
    queryDelete.prepare(" DELETE FROM Groupe WHERE  IdGRP=:ID_del");
    queryDelete.bindValue(":ID_del", ID_del);
    if (!queryDelete.exec()) {
        qDebug() << "Error executing query:" << queryDelete.lastError().text();
        return;
    }

    queryDelete.prepare(" DELETE FROM Groupe_GM_Etudiant WHERE  IdG=:ID_del");
    queryDelete.bindValue(":ID_del", ID_del);
    if (!queryDelete.exec()) {
        qDebug() << "Error executing query:" << queryDelete.lastError().text();
        return;
    }
    QMessageBox::information(this,"Success","groupe deleted  successfully");
    qDebug() << "Groupe deleted successfully";
    populateGroupeModel();
    resetLineEditFields();
}



void Groupe::on_search_GM_clicked()
{
    QString ID = ui->idG_up->text();
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("example.db");
    if (!db.open()) {
        qDebug() << "Error: Failed to open database";
        return;
    }
    QSqlQuery searchQuery;
    searchQuery.prepare("SELECT COUNT(*) FROM  Groupe WHERE IdGRP= :ID");
    searchQuery.bindValue(":ID", ID);
    if (!searchQuery.exec()) {
        qDebug() << "Error executing query:" << searchQuery.lastError().text();
        return;
    }

    searchQuery.next();
    int count = searchQuery.value(0).toInt();
    if (count > 0) {
        QMessageBox::information(this, "groupe Found", "The groupe exists.");
        ui->NivG->setVisible(true);
        ui->DIPG->setVisible(true);
        ui->SpecG->setVisible(true);
        ui->NumG->setVisible(true);
    } else {
        QMessageBox::critical(this, "groupe Not Found", "The groupe does not exist.");
    }
}


void Groupe::on_NivG_clicked()
{
    ui->Niv_G->setVisible(true);
    ui->newNiv->setVisible(true);
    ui->updateN->setVisible(true);
}


void Groupe::on_DIPG_clicked()
{
    ui->Dip_G->setVisible(true);
    ui->newDIP->setVisible(true);
    ui->updateD->setVisible(true);
}


void Groupe::on_SpecG_clicked()
{
    ui->Spec_G->setVisible(true);
    ui->NewSpec->setVisible(true);
    ui->updateS->setVisible(true);
}


void Groupe::on_NumG_clicked()
{
    ui->Num_G->setVisible(true);
    ui->NewNum->setVisible(true);
    ui->updateNum->setVisible(true);
}


void Groupe::on_updateN_clicked()
{
    QString selectedText = ui->Niv_G->currentText();
    QString idG = ui->idG_up->text();
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("example.db");
    if (!db.open()) {
        qDebug() << "Error: Failed to open database";
        return;
    }
    QSqlQuery updateQuery;
    updateQuery.prepare("UPDATE Groupe SET Niveau = :newniveau WHERE IdGRP = :idGrp ");

    // Bind the values
    updateQuery.bindValue(":newniveau", selectedText);
    updateQuery.bindValue(":idGrp", idG);

    // Execute the query
    if (!updateQuery.exec()) {
        qDebug() << "Error executing update query:" << updateQuery.lastError().text();
        return;
    }
    else {
        QMessageBox::information(this, "Success", "niveau updated successfully");
        qDebug() << "niveau updated successfully";
        populateGroupeModel();
    }
}


void Groupe::on_updateD_clicked()
{
    QString selectedText = ui->Dip_G->currentText();
    QString idG = ui->idG_up->text();
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("example.db");
    if (!db.open()) {
        qDebug() << "Error: Failed to open database";
        return;
    }
    QSqlQuery updateQuery;
    updateQuery.prepare("UPDATE Groupe SET Diplome = :newdiplome WHERE IdGRP = :idGrp ");

    // Bind the values
    updateQuery.bindValue(":newdiplome", selectedText);
    updateQuery.bindValue(":idGrp", idG);

    // Execute the query
    if (!updateQuery.exec()) {
        qDebug() << "Error executing update query:" << updateQuery.lastError().text();
        return;
    }
    else {
        QMessageBox::information(this, "Success", "diplome updated successfully");
        qDebug() << "diplome updated successfully";
        populateGroupeModel();
    }
}


void Groupe::on_updateS_clicked()
{
    QString selectedText = ui->Spec_G->currentText();
    QString idG = ui->idG_up->text();
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("example.db");
    if (!db.open()) {
        qDebug() << "Error: Failed to open database";
        return;
    }
    QSqlQuery updateQuery;
    updateQuery.prepare("UPDATE Groupe SET Specialite = :newdspec WHERE IdGRP = :idGrp ");

    // Bind the values
    updateQuery.bindValue(":newdspec", selectedText);
    updateQuery.bindValue(":idGrp", idG);

    // Execute the query
    if (!updateQuery.exec()) {
        qDebug() << "Error executing update query:" << updateQuery.lastError().text();
        return;
    }
    else {
        QMessageBox::information(this, "Success", "specialite updated successfully");
        qDebug() << "specialite updated successfully";
        populateGroupeModel();
    }
}


void Groupe::on_updateNum_clicked()
{

        QString selectedText = ui->Num_G->currentText();
        QString idG = ui->idG_up->text();
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("example.db");
        if (!db.open()) {
            qDebug() << "Error: Failed to open database";
            return;
        }
        QSqlQuery updateQuery;
        updateQuery.prepare("UPDATE Groupe SET NumG = :newnumg WHERE IdGRP = :idGrp ");

        // Bind the values
        updateQuery.bindValue(":newnumg", selectedText);
        updateQuery.bindValue(":idGrp", idG);

        // Execute the query
        if (!updateQuery.exec()) {
            qDebug() << "Error executing update query:" << updateQuery.lastError().text();
            return;
        }
        else {
            QMessageBox::information(this, "Success", "numG updated successfully");
            qDebug() << "Num updated successfully";
            populateGroupeModel();
        }
}


void Groupe::on_update_Groupe_clicked()
{
       ui->stackedWidget->setCurrentIndex(3);
}



void Groupe::on_delete_Groupe_clicked()
{
     ui->stackedWidget->setCurrentIndex(4);
}


void Groupe::on_menu_clicked()
{
    this->hide();
    mainwindow *mainWindow = new mainwindow();
    mainWindow->show();
}


void Groupe::on_GoB_clicked()
{
     ui->stackedWidget->setCurrentIndex(0);
}


pdfExport::pdfExport(){}

void pdfExport::exportTableToPDF(const QTableView* tableView)
{

    // Create a QTextDocument to hold the content
    QTextDocument document;

    // Create a QTextCursor to manipulate the document
    QTextCursor cursor(&document);

    // Determine the number of non-empty columns
    int nonEmptyColumns = 0;
    for (int col = 0; col < tableView->model()->columnCount(); ++col) {
        bool isEmpty = true;
        for (int row = 0; row < tableView->model()->rowCount(); ++row) {
            QModelIndex index = tableView->model()->index(row, col);
            if (index.isValid() && !index.data().toString().isEmpty()) {
                isEmpty = false;
                break;
            }
        }
        if (!isEmpty) {
            nonEmptyColumns++;
        }
    }

    // Create a QTextTable with the same number of rows and non-empty columns as the QTableView
    QTextTable* textTable = cursor.insertTable(tableView->model()->rowCount() + 1, nonEmptyColumns);

    // Set the header data in the first row of the QTextTable
    int exportCol = 0;
    for (int col = 0; col < tableView->model()->columnCount(); ++col) {
        bool isEmpty = true;
        for (int row = 0; row < tableView->model()->rowCount(); ++row) {
            QModelIndex index = tableView->model()->index(row, col);
            if (index.isValid() && !index.data().toString().isEmpty()) {
                isEmpty = false;
                break;
            }
        }

        // Check if the column is not empty
        if (!isEmpty) {
            QString header = tableView->model()->headerData(col, Qt::Horizontal).toString();
            if (header != "Delete" && header != "Edit") {
                textTable->cellAt(0, exportCol).firstCursorPosition().insertText(header);
                exportCol++;
            }
        }
    }

    // Set the alignment and column width for the QTextTableFormat
    QTextTableFormat tableFormat = textTable->format();
    tableFormat.setAlignment(Qt::AlignHCenter);
    tableFormat.setColumnWidthConstraints(QVector<QTextLength>(nonEmptyColumns, QTextLength(QTextLength::PercentageLength, 100.0 / nonEmptyColumns)));

    textTable->setFormat(tableFormat);

    // Populate the rest of the QTextTable with data from the QTableView
    for (int row = 0; row < tableView->model()->rowCount(); ++row) {
        exportCol = 0;  // Reset the column count for each row
        for (int col = 0; col < tableView->model()->columnCount(); ++col) {
            QModelIndex index = tableView->model()->index(row, col);
            if (index.isValid() && !index.data().toString().isEmpty()) {
                QString data = index.data().toString();
                textTable->cellAt(row + 1, exportCol).firstCursorPosition().insertText(data);
                exportCol++;
            }
        }
    }

    // Save the PDF file
    QString filePath = QFileDialog::getSaveFileName(nullptr, "Save PDF", "", "PDF Files (*.pdf)");

    if (!filePath.isEmpty()) {
        // Ensure the file has a .pdf extension
        if (!filePath.endsWith(".pdf", Qt::CaseInsensitive))
            filePath += ".pdf";

        // Create a QPrinter and set it up for PDF output
        QPrinter printer(QPrinter::PrinterResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setOutputFileName(filePath);

        // Print the QTextDocument to the PDF
        document.print(&printer);

        QMessageBox::information(nullptr, "Export Successful", "Table successfully exported to PDF.");
    }
}



