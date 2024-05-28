#include "etudiant.h"
#include "mainwindow/mainwindow.h"
#include "ui_etudiant.h"
#include"ui_mainwindow.h"
#include <QtSql>
#include<QMessageBox>

etudiant::etudiant(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::student_managment)
    ,model(new QSqlQueryModel(this))
{
    ui->setupUi(this);
    setWindowIcon(QIcon("C:/Users/user/Desktop/IRM1-3/iconprojet.jpg"));
    setWindowTitle("grade managment");
    initializeModel();
    customizeTableView();
    ui->table_del->setModel(model);
    ui->table_update->setModel(model);
    ui->button_back->setIcon(QIcon("C:/Users/user/Desktop/IRM1-3/carbon--return.svg"));
    connect(ui->table_del, &QTableView::clicked, this, &etudiant::displaySelectedStudent);
    ui->NameB->setVisible(false);
    ui->LName_B->setVisible(false);
    ui->Mail_B->setVisible(false);
    ui->Name_B_field->setVisible(false);
    ui->LName_B_field->setVisible(false);
    ui->Mail_B_field->setVisible(false);
    ui->newName->setVisible(false);
    ui->newLName->setVisible(false);
    ui->NewMail->setVisible(false);
    ui->updateN->setVisible(false);
    ui->updateL->setVisible(false);
    ui->updateM->setVisible(false);
}

etudiant::~etudiant()
{
    delete ui;
}


etudiant::etudiant(string nom, string prenom, string mail, int num_insc) : personne(), num_insc(num_insc)
{
    Nom = nom;
    Prenom = prenom;
    Mail = mail;
}
std::ostream& operator<<(std::ostream& os, const etudiant& student) {

    os << "Nom: " << student.Nom << endl;
    os << "Prenom: " << student.Prenom << endl;
    os << "Mail: " << student.Mail << endl;
    os << "numinsc: " << student.num_insc << endl;
    return os;
}



void etudiant::on_pushButton_clicked()
{
    int num_insc = ui->num_insc->text().toInt();
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
    if (!createTableQuery.exec("CREATE TABLE IF NOT EXISTS Etudiant ("
                               "num_insc INTEGER PRIMARY KEY,"
                               "nom TEXT NOT NULL COLLATE NOCASE,"
                               "prenom TEXT NOT NULL COLLATE NOCASE,"
                               "mail TEXT NOT NULL COLLATE NOCASE);")) {
        qDebug() << "Error creating table:" << createTableQuery.lastError().text();
        db.close();
        return;
    } else {
        qDebug() << "Table created successfully";
    }

    // Insert data into the database
    QSqlQuery insertQuery;
    insertQuery.prepare("INSERT INTO Etudiant (num_insc, nom, prenom, mail) VALUES (:num_insc, :nom, :prenom, :mail)");
    insertQuery.bindValue(":num_insc", num_insc);
    insertQuery.bindValue(":nom", nom);
    insertQuery.bindValue(":prenom", prenom);
    insertQuery.bindValue(":mail", mail);

    if (!insertQuery.exec()) {
        qDebug() << "Error inserting data:" << insertQuery.lastError().text();
    } else {
        QMessageBox::information(this,"scess","data inserted sucessfully");
        qDebug() << "Data inserted successfully";
    }

    // Close the database connection
    db.close();
    ui->stackedWidget->setCurrentIndex(0);

}




void etudiant::on_show_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}



void etudiant::on_Adder_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void etudiant::initializeModel()
{
    populateModel();
    ui->liste_table->setModel(model);
}

void etudiant::populateModel()
{

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("example.db");

    if (!db.open()) {
        qDebug() << "Error: Failed to open database";
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT * FROM Etudiant");
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





void etudiant::customizeTableView() {
    ui->liste_table->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Fixed);
    ui->liste_table->horizontalHeader()->resizeSection(0, 150);

    ui->liste_table->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Fixed);
    ui->liste_table->horizontalHeader()->resizeSection(1, 150);

    ui->liste_table->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Fixed);
    ui->liste_table->horizontalHeader()->resizeSection(2, 150);

    ui->liste_table->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Fixed);
    ui->liste_table->horizontalHeader()->resizeSection(3, 425);
}



void etudiant::on_search_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("example.db");
    if (!db.open()) {
        qDebug() << "Error: Failed to open database";
        return;
    }

    QString searchText = ui->searchField->text().trimmed(); // Get the text from the search field and remove leading/trailing whitespace

    // Construct the SQL query to search for the text in any of the fields
    QString queryString = "SELECT * FROM Etudiant WHERE num_insc LIKE :searchText OR nom LIKE :searchText OR prenom LIKE :searchText OR mail LIKE :searchText";

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





void etudiant::on_update_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}


void etudiant::on_Goback_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void etudiant::on_deleteS_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}
void etudiant::displaySelectedStudent(const QModelIndex &index) {
    // Get the row and column of the clicked item
    int row = index.row();

    // Retrieve the data of the selected student
    QSqlQueryModel *model = qobject_cast<QSqlQueryModel*>(ui->table_del->model());
    QString numinsc = model->data(model->index(row, 0)).toString();
    QString nom = model->data(model->index(row, 1)).toString();
    QString prenom = model->data(model->index(row, 2)).toString();
    QString mail = model->data(model->index(row, 3)).toString();

    // Populate line edits with the selected student's information
    ui->numinsc->setText(numinsc);
    ui->nom->setText(nom);
    ui->prenom->setText(prenom);
    ui->mail->setText(mail);



}



void etudiant::on_pushButton_2_clicked()
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
    int numinsc = ui->numinsc->text().toInt();
    QSqlQuery queryDelete;
    queryDelete.prepare(" DELETE FROM Etudiant WHERE  num_insc=:num_insc");
    queryDelete.bindValue(":num_insc", numinsc);
    if (!queryDelete.exec()) {
        qDebug() << "Error executing query:" << queryDelete.lastError().text();
        return;
    }
    QMessageBox::information(this,"Success","student deleted  successfully");
    qDebug() << "student deleted successfully";
    populateModel();
    resetLineEditFields();
}
void etudiant::resetLineEditFields() {
    ui->numinsc->clear();
    ui->nom->clear();
    ui->prenom->clear();
    ui->mail->clear();
}





void etudiant::on_search_U_clicked()
{
    int num_insc = ui->num_insc_UP->text().toInt();
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("example.db");
    if (!db.open()) {
        qDebug() << "Error: Failed to open database";
        return;
    }
    QSqlQuery searchQuery;
    searchQuery.prepare("SELECT COUNT(*) FROM  Etudiant WHERE num_insc= :num_insc");
    searchQuery.bindValue(":num_insc", num_insc);
    if (!searchQuery.exec()) {
        qDebug() << "Error executing query:" << searchQuery.lastError().text();
        return;
    }

    searchQuery.next();
    int count = searchQuery.value(0).toInt();
    if (count > 0) {
        QMessageBox::information(this, "Student Found", "The student exists.");
        ui->NameB->setVisible(true);
        ui->LName_B->setVisible(true);
        ui->Mail_B->setVisible(true);
    } else {
        QMessageBox::information(this, "Student Not Found", "The student does not exist.");
    }

}


void etudiant::on_NameB_clicked()
{
    ui->Name_B_field->setVisible(true);
    ui->newName->setVisible(true);
    ui->updateN->setVisible(true);
}



void etudiant::on_LName_B_clicked()
{
    ui->LName_B_field->setVisible(true);
    ui->newLName->setVisible(true);
    ui->updateL->setVisible(true);
}



void etudiant::on_Mail_B_clicked()
{
    ui->Mail_B_field->setVisible(true);
    ui->NewMail->setVisible(true);
    ui->updateM->setVisible(true);
}



void etudiant::on_updateN_clicked()
{
    int num_insc = ui->num_insc_UP->text().toInt();
    QString name = ui->Name_B_field->text();
    if (name.isEmpty()) {
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
    updateNQuery.prepare("UPDATE  Etudiant SET nom=:nom WHERE num_insc=:num_insc");
    updateNQuery.bindValue(":nom", name);
    updateNQuery.bindValue(":num_insc", num_insc);
    if (!updateNQuery.exec()) {
        qDebug() << "Error executing query:" << updateNQuery.lastError().text();
        return;
    }
    else{
    QMessageBox::information(this,"Success","Name updated successfully");
    qDebug() << "Name updated successfully";
    populateModel();
    }
}






void etudiant::on_GoB_clicked()
{
     ui->stackedWidget->setCurrentIndex(0);
}


void etudiant::on_updateM_clicked()
{
    int num_insc = ui->num_insc_UP->text().toInt();
    QString mail = ui->Mail_B_field->text();
    if (mail.isEmpty()) {
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
    updateMQuery.prepare("UPDATE  Etudiant SET mail=:mail WHERE num_insc=:num_insc");
    updateMQuery.bindValue(":mail", mail);
    updateMQuery.bindValue(":num_insc", num_insc);
    if (!updateMQuery.exec()) {
        qDebug() << "Error executing query:" << updateMQuery.lastError().text();
        return;
    } else {
        QMessageBox::information(this,"scess"," mail updated sucessfully");
        qDebug() << " mail updated sucessfully";
        populateModel();
    }

}


void etudiant::on_updateL_clicked()
{
    int num_insc = ui->num_insc_UP->text().toInt();
    QString Lname = ui->LName_B_field->text();
    if (Lname.isEmpty()) {
        QMessageBox::warning(this, "Warning", "Please enter a Lname.");
        return;
    }
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("example.db");
    if (!db.open()) {
        qDebug() << "Error: Failed to open database";
        return;
    }
    QSqlQuery updateLQuery;
    updateLQuery.prepare("UPDATE  Etudiant SET prenom=:prenom WHERE num_insc=:num_insc");
    updateLQuery.bindValue(":prenom", Lname);
    updateLQuery.bindValue(":num_insc", num_insc);
    if (!updateLQuery.exec()) {
        qDebug() << "Error executing query:" << updateLQuery.lastError().text();
        return;
    } else {
        QMessageBox::information(this,"scess"," last name updated sucessfully");
        qDebug() << " last name updated sucessfully";
        populateModel();
    }
}


void etudiant::on_go_b_del_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void etudiant::on_button_back_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void etudiant::on_menu_clicked()
{
    this->hide();
    mainwindow *mainWindow = new mainwindow();
    mainWindow->show();
}

