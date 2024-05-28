#include "enseignant.h"
#include "mainwindow/mainwindow.h"
#include "ui_enseignant.h"
#include <QtSql>
#include <iostream>
#include<QMessageBox>


enseignant::enseignant(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::enseignant)
    ,model(new QSqlQueryModel(this))
{
    ui->setupUi(this);
    setWindowIcon(QIcon("C:/Users/user/Desktop/IRM1-3/iconprojet.jpg"));
    setWindowTitle("grade managment");
    initializeModel();
    customizeTableView();
    ui->table_del->setModel(model);
    ui->table_update->setModel(model);
    connect(ui->table_del, &QTableView::clicked, this, &enseignant::displaySelectedProfessors);
    ui->Name_B->setVisible(false);
    ui->LName_B->setVisible(false);
    ui->Mail_B->setVisible(false);
    ui->Name_P->setVisible(false);
    ui->LName_P->setVisible(false);
    ui->Mail_P->setVisible(false);
    ui->newName->setVisible(false);
    ui->newLName->setVisible(false);
    ui->NewMail->setVisible(false);
    ui->updateN->setVisible(false);
    ui->updateL->setVisible(false);
    ui->updateM->setVisible(false);
}

enseignant::~enseignant()
{
    delete ui;
}



enseignant::enseignant(int cnrps, string nom, string prenom, string mail) : personne(), CNRPS(cnrps)
{
    Nom = nom;
    Prenom = prenom;
    Mail = mail;
}

std::ostream& operator<<(std::ostream& os, const enseignant& teacher) {

    os << "Nom: " << teacher.Nom << endl;
    os << "Prenom: " << teacher.Prenom << endl;
    os << "Mail: " << teacher.Mail << endl;
    os << "CNSS: " << teacher.CNRPS << endl;
    return os;
}
void enseignant::on_Adder_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void enseignant::on_show_clicked()
{
     ui->stackedWidget->setCurrentIndex(2);
}


void enseignant::on_deleteS_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}


void enseignant::on_update_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

//add_professor
void enseignant::on_pushButton_clicked()
{
    int cnrps = ui->CNRPS->text().toInt();
    QString nom = ui->Name->text();
    QString prenom = ui->LastName->text();
    QString mail = ui->Mail->text();


    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("example.db");
    if (!db.open()) {
        qDebug() << "Error: Failed to open database";
        return;
    }

    // Create the table if it doesn't exist
    QSqlQuery createTableQuery;
    if (!createTableQuery.exec("CREATE TABLE IF NOT EXISTS Enseignant ("
                               "cnrps INTEGER PRIMARY KEY,"
                               "nom TEXT NOT NULL COLLATE NOCASE,"
                               "prenom TEXT NOT NULL COLLATE NOCASE,"
                               "mail TEXT NOT NULL COLLATE NOCASE)")) {
        qDebug() << "Error creating table:" << createTableQuery.lastError().text();
        db.close();
        return;
    } else {
        qDebug() << "Table created successfully";
    }

    // Insert data into the database
    QSqlQuery insertQuery;
    insertQuery.prepare("INSERT INTO Enseignant (cnrps, nom, prenom, mail) VALUES (:cnrps, :nom, :prenom, :mail)");
    insertQuery.bindValue(":cnrps", cnrps);
    insertQuery.bindValue(":nom", nom);
    insertQuery.bindValue(":prenom", prenom);
    insertQuery.bindValue(":mail", mail);

    if (!insertQuery.exec()) {
        qDebug() << "Error inserting data:" << insertQuery.lastError().text();
    } else {
        QMessageBox::information(this,"scess","data inserted sucessfully");
        qDebug() << "Data inserted successfully";
    }
    db.close();
    ui->stackedWidget->setCurrentIndex(0);
}




//display professors and search
void enseignant::initializeModel()
{
    populateModel();
    ui->ens_table->setModel(model);
}

void enseignant::populateModel()
{

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("example.db");

    if (!db.open()) {
        qDebug() << "Error: Failed to open database";
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT * FROM Enseignant");
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
void enseignant::customizeTableView() {
    ui->ens_table->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Fixed);
    ui->ens_table->horizontalHeader()->resizeSection(0, 150);

    ui->ens_table->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Fixed);
    ui->ens_table->horizontalHeader()->resizeSection(1, 150);

    ui->ens_table->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Fixed);
    ui->ens_table->horizontalHeader()->resizeSection(2, 150);

    ui->ens_table->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Fixed);
    ui->ens_table->horizontalHeader()->resizeSection(3, 425);
}

void enseignant::on_search_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("example.db");
    if (!db.open()) {
        qDebug() << "Error: Failed to open database";
        return;
    }

    QString searchText = ui->searchField->text().trimmed(); // Get the text from the search field and remove leading/trailing whitespace

    // Construct the SQL query to search for the text in any of the fields
    QString queryString = "SELECT * FROM Enseignant WHERE cnrps LIKE :searchText OR nom LIKE :searchText OR prenom LIKE :searchText OR mail LIKE :searchText";

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


void enseignant::on_Goback_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}






//delete professor
void enseignant::displaySelectedProfessors(const QModelIndex &index) {
    // Get the row and column of the clicked item
    int row = index.row();

    // Retrieve the data of the selected student
    QSqlQueryModel *model = qobject_cast<QSqlQueryModel*>(ui->table_del->model());
    QString cnrps = model->data(model->index(row, 0)).toString();
    QString nom = model->data(model->index(row, 1)).toString();
    QString prenom = model->data(model->index(row, 2)).toString();
    QString mail = model->data(model->index(row, 3)).toString();

    // Populate line edits with the selected student's information
    ui->CNRPS_del->setText(cnrps);
    ui->nom->setText(nom);
    ui->prenom->setText(prenom);
    ui->mail->setText(mail);



}

void enseignant::resetLineEditFields() {
    ui->CNRPS_del->clear();
    ui->nom->clear();
    ui->prenom->clear();
    ui->mail->clear();
}

void enseignant::on_pushButton_2_clicked()
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
    int cnrps_del = ui->CNRPS_del->text().toInt();
    QSqlQuery queryDelete;
    queryDelete.prepare(" DELETE FROM Enseignant WHERE  cnrps=:cnrps");
    queryDelete.bindValue(":cnrps", cnrps_del);
    if (!queryDelete.exec()) {
        qDebug() << "Error executing query:" << queryDelete.lastError().text();
        return;
    }
    QMessageBox::information(this,"Success","student deleted  successfully");
    qDebug() << "student deleted successfully";
    populateModel();
    resetLineEditFields();
}


void enseignant::on_go_b_del_clicked()
{
     ui->stackedWidget->setCurrentIndex(0);
}

//update professors


void enseignant::on_search_U_clicked()
{
    int cnrps = ui->CNRPS_up->text().toInt();
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("example.db");
    if (!db.open()) {
        qDebug() << "Error: Failed to open database";
        return;
    }
    QSqlQuery searchQuery;
    searchQuery.prepare("SELECT COUNT(*) FROM  Enseignant WHERE cnrps= :cnrps");
    searchQuery.bindValue(":cnrps", cnrps);
    if (!searchQuery.exec()) {
        qDebug() << "Error executing query:" << searchQuery.lastError().text();
        return;
    }

    searchQuery.next();
    int count = searchQuery.value(0).toInt();
    if (count > 0) {
        QMessageBox::information(this, "Professor Found", "The Professor exists.");
        ui->Name_B->setVisible(true);
        ui->LName_B->setVisible(true);
        ui->Mail_B->setVisible(true);
    } else {
        QMessageBox::information(this, "Professor Not Found", "The Professor does not exist.");
    }
}



void enseignant::on_Name_B_clicked()
{
    ui->Name_P->setVisible(true);
    ui->newName->setVisible(true);
    ui->updateN->setVisible(true);
}


void enseignant::on_LName_B_clicked()
{
    ui->LName_P->setVisible(true);
    ui->newLName->setVisible(true);
    ui->updateL->setVisible(true);
}


void enseignant::on_Mail_B_clicked()
{
    ui->Mail_P->setVisible(true);
    ui->NewMail->setVisible(true);
    ui->updateM->setVisible(true);
}

void enseignant::on_updateN_clicked()
{
    int cnrp = ui->CNRPS_up->text().toInt();
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
    updateNQuery.prepare("UPDATE Enseignant SET prenom=:prenom WHERE cnrps=:cnrp");
    updateNQuery.bindValue(":prenom", newFirstName);
    updateNQuery.bindValue(":cnrp", cnrp);
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


void enseignant::on_updateL_clicked()
{
    int cnrp = ui->CNRPS_up->text().toInt();
    QString newLastName = ui->LName_P->text();
    if (newLastName.isEmpty()) {
        QMessageBox::warning(this, "Warning", "Please enter a last name.");
        return;
    }
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("example.db");
    if (!db.open()) {
        qDebug() << "Error: Failed to open database";
        return;
    }
    QSqlQuery updateLQuery;
    updateLQuery.prepare("UPDATE Enseignant SET nom=:nom WHERE cnrps=:cnrp");
    updateLQuery.bindValue(":nom", newLastName);
    updateLQuery.bindValue(":cnrp", cnrp);
    if (!updateLQuery.exec()) {
        qDebug() << "Error executing query:" << updateLQuery.lastError().text();
        return;
    } else {
        QMessageBox::information(this,"Success","Last name updated successfully");
        qDebug() << "Last name updated successfully";
        populateModel();
    }
}





void enseignant::on_updateM_clicked()
{
    int cnrp = ui->CNRPS_up->text().toInt();
    QString mailP = ui->Mail_P->text();
    if (mailP.isEmpty()) {
        QMessageBox::warning(this, "Warning", "Please enter a mail.");
        return;
    }
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("example.db");
    if (!db.open()) {
        qDebug() << "Error: Failed to open database";
        return;
    }
    QSqlQuery updateMQuery;
    updateMQuery.prepare("UPDATE Enseignant SET mail=:mail WHERE cnrps=:cnrp");
    updateMQuery.bindValue(":mail", mailP);
    updateMQuery.bindValue(":cnrps", cnrp);
    if (!updateMQuery.exec()) {
        qDebug() << "Error executing query:" << updateMQuery.lastError().text();
        return;
    } else {
        QMessageBox::information(this,"scess"," mail updated sucessfully");
        qDebug() << " mail updated sucessfully";
        populateModel();
    }
}


void enseignant::on_GoB_clicked()
{
     ui->stackedWidget->setCurrentIndex(0);
}





void enseignant::on_menu_clicked()
{
    this->hide();
    mainwindow *mainWindow = new mainwindow();
    mainWindow->show();
}


void enseignant::on_pushButton_3_clicked()
{
      ui->stackedWidget->setCurrentIndex(0);
}

