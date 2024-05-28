#include "matiere.h"
#include "mainwindow/mainwindow.h"
#include "ui_matiere.h"
#include <QtSql>
#include<QMessageBox>
matiere::matiere(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::matiere)
    ,model(new QSqlQueryModel(this))
{
    ui->setupUi(this);
    setWindowIcon(QIcon("C:/Users/user/Desktop/IRM1-3/iconprojet.jpg"));
     ui->pushButton_3->setIcon(QIcon("C:/Users/user/Desktop/IRM1-3/carbon--return.svg"));
    setWindowTitle("grade managment");
    ui->table_del->setModel(model);
    ui->table_M_update->setModel(model);
    connect(ui->table_del, &QTableView::clicked, this, &matiere::displaySelectedmatiere);
    initializeModel();
    initializecomboModel();
    customizeTableView();
    ui->Name_B->setVisible(false);
    ui->coef_B->setVisible(false);
    ui->prof_B->setVisible(false);
    ui->Name_P->setVisible(false);
    ui->coef_P->setVisible(false);
    ui->prof_P->setVisible(false);
    ui->NewProf->setVisible(false);
    ui->newName->setVisible(false);
    ui->newCoef->setVisible(false);
    ui->updateN->setVisible(false);
    ui->updateC->setVisible(false);
    ui->updateP->setVisible(false);

}
matiere::matiere(string id, string nomMat, float coef, enseignant* ens): IdMat(id), NomMat(nomMat), Coef(coef), Ens(ens) {}
ostream& operator<<(ostream& os, const matiere& mat) {
    os << "IdMat: " << mat.IdMat << "\n";
    os << "NomMat: " << mat.NomMat << "\n";
    os << "Coef: " << mat.Coef << "\n";
    os << "Enseignant: " << *(mat.Ens) << "\n";
    return os;
}
matiere::~matiere()
{
    delete ui;
}


void matiere::on_Adder_clicked()
{
      ui->stackedWidget->setCurrentIndex(1);
}


void matiere::on_show_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void matiere::on_update_clicked()
{
     ui->stackedWidget->setCurrentIndex(3);
}


void matiere::on_deleteS_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}



void matiere::populateComboBox()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("example.db");

    // Open the database
    if (!db.open()) {
        qDebug() << "Error: Failed to open database";
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT cnrps,nom FROM Enseignant");
    if (!query.exec()) {
        qDebug() << "Error executing query:" << query.lastError().text();
        return;
    }

    QStringList comboItems;
    while (query.next()) {
        QString cnrps = query.value(0).toString();
        QString nom =query.value(1).toString();
        QString combinedString = cnrps + " - " + nom;
        comboItems.append(combinedString);
    }


    db.close();


    QStringListModel *comboModel = new QStringListModel(this);
    comboModel->setStringList(comboItems);
    ui->cnrps->setModel(comboModel);
}

void matiere::initializecomboModel()
{
    populateComboBox();
}

void matiere::on_pushButton_clicked()
{
    QString id = ui->ID->text();
    QString nomS = ui->Name->text();
    float coef = ui->coefficient->text().toFloat();
    QString selectedText = ui->cnrps->currentText();


    QStringList parts = selectedText.split(" - ");
    if (parts.size() != 2) {
        qDebug() << "Error: Invalid selected text format";
        return;
    }

    bool ok;
    int cnrp = parts.at(0).toInt(&ok);
    if (!ok) {
        qDebug() << "Error: Failed to convert cnrp to integer";
        return;
    }
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("example.db");
    if (!db.open()) {
        qDebug() << "Error: Failed to open database";
        return;
    }
    QSqlQuery createTableQuery;
    if (!createTableQuery.exec("CREATE TABLE IF NOT EXISTS Matiere ("
                               "idmat TEXT PRIMARY KEY,"
                               "nommat TEXT NOT NULL COLLATE NOCASE,"
                               "coef REAL NOT NULL COLLATE NOCASE,"
                               "cnrp INTEGER NOT NULL COLLATE NOCASE,"
                               "FOREIGN KEY (cnrp) REFERENCES Enseignant(cnrps)"
                               ");")) {
        qDebug() << "Error creating table:" << createTableQuery.lastError().text();
        db.close();
        return;
    } else {
        qDebug() << "Table created successfully";
    }
    QSqlQuery insertQuery;
    insertQuery.prepare("INSERT INTO Matiere (idmat, nommat, coef, cnrp) VALUES (:id, :nom, :coef, :cnrp)");

    // Bind values to the placeholders in the prepared statement
    insertQuery.bindValue(":id", id);
    insertQuery.bindValue(":nom", nomS);
    insertQuery.bindValue(":coef", coef);
    insertQuery.bindValue(":cnrp", cnrp);

    if (!insertQuery.exec()) {
        qDebug() << "Error executing insert query:" << insertQuery.lastError().text();
    } else {
        qDebug() << "Insert successful";
    }

    db.close();
    ui->stackedWidget->setCurrentIndex(0);

}
//display professors and search
void matiere::initializeModel()
{
    populateModel();
    ui->mat_table->setModel(model);
}

void matiere::populateModel()
{

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("example.db");

    if (!db.open()) {
        qDebug() << "Error: Failed to open database";
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT * FROM Matiere");
    if (!query.exec()) {
        qDebug() << "Error executing query:" << query.lastError().text();
        return;
    }

    model->setQuery(query);
    if (model->lastError().isValid()) {
        qDebug() << "Error setting query:" << model->lastError().text();
    }


    db.close();
}
void matiere::customizeTableView() {
    ui->mat_table->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Fixed);
    ui->mat_table->horizontalHeader()->resizeSection(0, 150);

    ui->mat_table->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Fixed);
    ui->mat_table->horizontalHeader()->resizeSection(1, 150);

    ui->mat_table->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Fixed);
    ui->mat_table->horizontalHeader()->resizeSection(2, 150);

    ui->mat_table->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Fixed);
    ui->mat_table->horizontalHeader()->resizeSection(3, 425);
}



void matiere::on_search_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("example.db");
    if (!db.open()) {
        qDebug() << "Error: Failed to open database";
        return;
    }

    QString searchText = ui->searchField->text().trimmed(); // Get the text from the search field and remove leading/trailing whitespace

    // Construct the SQL query to search for the text in any of the fields
    QString queryString = "SELECT * FROM Matiere WHERE idmat LIKE :searchText OR nommat LIKE :searchText OR coef LIKE :searchText OR cnrp LIKE :searchText";

    // Prepare the query
    QSqlQuery query;
    query.prepare(queryString);
    query.bindValue(":searchText", "%" + searchText + "%"); // Use bindValue to avoid SQL injection and allow partial matching

    // Execute the query
    if (!query.exec()) {
        qDebug() << "Error executing query:" << query.lastError().text();
        return;
    }

    // Set the new query result to the model
    model->setQuery(query);
    if (model->lastError().isValid()) {
        qDebug() << "Error setting query:" << model->lastError().text();
        return;
    }
}



void matiere::on_Goback_clicked()
{
     ui->stackedWidget->setCurrentIndex(0);
}

// delete matiere
void matiere::displaySelectedmatiere(const QModelIndex &index) {
    // Get the row and column of the clicked item
    int row = index.row();

    // Retrieve the data of the selected student
    QSqlQueryModel *model = qobject_cast<QSqlQueryModel*>(ui->table_del->model());
    QString idmat = model->data(model->index(row, 0)).toString();
    QString nom = model->data(model->index(row, 1)).toString();
    float coef = model->data(model->index(row, 2)).toFloat();
    int cnrps = model->data(model->index(row, 3)).toInt();

    // Populate line edits with the selected student's information
    ui->ID_mat->setText(idmat);
    ui->nom->setText(nom);
    ui->coef->setText(QString::number(coef)); // Convert float to QString for setText
    ui->cnrps_mat->setText(QString::number(cnrps)); // Convert int to QString for setText
}

void matiere::resetLineEditFields() {
    ui->ID_mat->clear();
    ui->nom->clear();
    ui->coef->clear();
    ui->cnrps_mat->clear();
}


void matiere::on_pushButton_2_clicked()
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
    QString ID_del = ui->ID_mat->text();
    QSqlQuery queryDelete;
    queryDelete.prepare(" DELETE FROM matiere WHERE  idmat=:ID_del");
    queryDelete.bindValue(":ID_del", ID_del);
    if (!queryDelete.exec()) {
        qDebug() << "Error executing query:" << queryDelete.lastError().text();
        return;
    }
    QMessageBox::information(this,"Success","student deleted  successfully");
    qDebug() << "student deleted successfully";
    populateModel();
    resetLineEditFields();
}


void matiere::on_go_b_del_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void matiere::on_search_U_clicked()
{

    QString ID = ui->id_up->text();
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("example.db");
    if (!db.open()) {
        qDebug() << "Error: Failed to open database";
        return;
    }
    QSqlQuery searchQuery;
    searchQuery.prepare("SELECT COUNT(*) FROM  matiere WHERE idmat= :ID");
    searchQuery.bindValue(":ID", ID);
    if (!searchQuery.exec()) {
        qDebug() << "Error executing query:" << searchQuery.lastError().text();
        return;
    }

    searchQuery.next();
    int count = searchQuery.value(0).toInt();
    if (count > 0) {
        QMessageBox::information(this, "subject Found", "The subject exists.");
        ui->Name_B->setVisible(true);
        ui->coef_B->setVisible(true);
        ui->prof_B->setVisible(true);
    } else {
        QMessageBox::information(this, "subject Not Found", "The subject does not exist.");
    }
}



void matiere::on_Name_B_clicked()
{
    ui->Name_P->setVisible(true);
    ui->newName->setVisible(true);
    ui->updateN->setVisible(true);
}


void matiere::on_coef_B_clicked()
{
    ui->coef_P->setVisible(true);
    ui->newCoef->setVisible(true);
    ui->updateC->setVisible(true);
}



void matiere::on_prof_B_clicked()
{
    ui->prof_P->setVisible(true);
    ui->NewProf->setVisible(true);
    ui->updateP->setVisible(true);
}


void matiere::on_GoB_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}



void matiere::on_updateN_clicked()
{
    QString id = ui->id_up->text();
    QString newFirstName = ui->Name_P->text();
    if (newFirstName.isEmpty()) {
        QMessageBox::warning(this, "Warning", "Please enter a name.");
        return;
    }
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("example.db");
    if (!db.open()) {
        qDebug() << "Error: Failed to open database";
        return;
    }
    QSqlQuery updateNQuery;
    updateNQuery.prepare("UPDATE matiere SET nommat=:nomat WHERE idmat=:id");
    updateNQuery.bindValue(":nomat", newFirstName);
    updateNQuery.bindValue(":id", id);
    if (!updateNQuery.exec()) {
        qDebug() << "Error executing query:" << updateNQuery.lastError().text();
        return;
    }
    else {
        QMessageBox::information(this, "Success", "First name updated successfully");
        qDebug() << "First name updated successfully";
        populateModel();
    }
}


void matiere::on_updateC_clicked()
{
    QString id = ui->id_up->text();
    float newcoef = ui->coef_P->text().toFloat();
    if (newcoef == 0.0f) {
        QMessageBox::warning(this, "Warning", "The coefficient cannot be zero.");
        return;
    }
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("example.db");
    if (!db.open()) {
        qDebug() << "Error: Failed to open database";
        return;
    }
    QSqlQuery updateNQuery;
    updateNQuery.prepare("UPDATE matiere SET coef=:coeff WHERE idmat=:id");
    updateNQuery.bindValue(":coeff", newcoef);
    updateNQuery.bindValue(":id", id);
    if (!updateNQuery.exec()) {
        qDebug() << "Error executing query:" << updateNQuery.lastError().text();
        return;
    }
    else {
        QMessageBox::information(this, "Success", "coefficient updated successfully");
        qDebug() << "coefficent updated successfully";
        populateModel();
    }
}


void matiere::on_updateP_clicked()
{
    QString id = ui->id_up->text();
    QString newcnrps= ui->prof_P->text();
    if (newcnrps.isEmpty()) {
        QMessageBox::warning(this, "Warning", "Please enter a valid cnrps.");
        return;
    }
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("example.db");
    if (!db.open()) {
        qDebug() << "Error: Failed to open database";
        return;
    }

    // Check if the new cnrp exists in the Enseignant table
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT cnrps FROM Enseignant WHERE cnrps = :newcnrp");
    checkQuery.bindValue(":newcnrp", newcnrps);
    if (!checkQuery.exec()) {
        qDebug() << "Error executing query:" << checkQuery.lastError().text();
        return;
    }
    if (checkQuery.next()) {
        // If a row is returned, the cnrp exists
         QMessageBox::information(this, "Success", "professor exists in  table enseignant");
        QSqlQuery updateNQuery;
        updateNQuery.prepare("UPDATE matiere SET cnrp=:newcnrp WHERE idmat=:id");
        updateNQuery.bindValue(":newcnrp", newcnrps);
        updateNQuery.bindValue(":id", id);
        if (!updateNQuery.exec()) {
            qDebug() << "Error executing query:" << updateNQuery.lastError().text();
            return;
        }
        else {
            QMessageBox::information(this, "Success", "professor updated successfully");
            qDebug() << "professor updated successfully";
            populateModel();
        }
        return;
    }


}


void matiere::on_menu_clicked()
{
    this->hide();
    mainwindow *mainWindow = new mainwindow();
    mainWindow->show();
}


void matiere::on_pushButton_3_clicked()
{
     ui->stackedWidget->setCurrentIndex(0);
}

