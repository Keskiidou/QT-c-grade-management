#include "groupemodule.h"
#include "mainwindow/mainwindow.h"
#include "ui_groupemodule.h"
#include <QtSql>
#include <QMessageBox>
groupemodule::groupemodule(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::groupemodule)
    , groupeModuleModel(new QSqlQueryModel(this))
    , groupeModuleMatiereModel(new QSqlQueryModel(this))
    ,model_del(new QSqlQueryModel(this))
{
    ui->setupUi(this);
    setWindowIcon(QIcon("C:/Users/user/Desktop/IRM1-3/iconprojet.jpg"));
    setWindowTitle("grade managment");
    ui->pushB->setIcon(QIcon("C:/Users/user/Desktop/IRM1-3/carbon--return.svg"));
    ui->go_b_del->setIcon(QIcon("C:/Users/user/Desktop/IRM1-3/carbon--return.svg"));
    connect(ui->tableGM_del, &QTableView::clicked, this, &groupemodule::displaySelectedGM);
    ui->groupemodule_table->setModel(groupeModuleModel);
    ui->groupemodule_matiere->setModel(groupeModuleMatiereModel);
    ui->tableGM_del->setModel(model_del);
    ui->table_GM_update->setModel(groupeModuleModel);
    ui->table_GMM_update->setModel(groupeModuleMatiereModel);
    populateGroupeModuleModel();
    populateGroupeModuleMatiereModel();
    initializeModel();
    initializeModel_del();
    customizeTableView();
    populateComboBox_mat();

    //buttons visibilty
    ui->Name_GM->setVisible(false);
    ui->coef_GM->setVisible(false);
    ui->mat_GM->setVisible(false);
    ui->Name_GM_P->setVisible(false);
    ui->coef_P_GM->setVisible(false);
    ui->mat_GM_P->setVisible(false);
    ui->newName->setVisible(false);
    ui->newCoef->setVisible(false);
    ui->NewMat->setVisible(false);
    ui->updateN->setVisible(false);
    ui->updateC->setVisible(false);
    ui->updateM->setVisible(false);
    ui->oldIdmat->setVisible(false);
    ui->old_idmat->setVisible(false);
}

groupemodule::groupemodule(string id, string nom, float coef, vector<matiere*>*matiere): IdGM(id), NomGM(nom), CoefGM(coef){ListeMat = *matiere;}


ostream& operator<<(ostream& os, const groupemodule& gm) {
    os << "IdGM: " << gm.IdGM << "\n";
    os << "NomGM: " << gm.NomGM << "\n";
    os << "CoefGM: " << gm.CoefGM << "\n";
    os << "ListeMat: \n";
    for (const auto& mat : gm.ListeMat) {
        os << *mat << "\n";
    }
    return os;
}
groupemodule::~groupemodule()
{
    delete ui;
}
void groupemodule::on_go_b_del_clicked()
{
   ui->stackedWidget->setCurrentIndex(0);
}

void groupemodule::on_deleteS_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void groupemodule::on_update_clicked()
{
     ui->stackedWidget->setCurrentIndex(3);
}

void groupemodule::on_GoB_clicked()
{
      ui->stackedWidget->setCurrentIndex(0);
}
void groupemodule::on_Adder_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}
void groupemodule::on_show_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}
void groupemodule::on_Goback_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void groupemodule::on_save_clicked()
{
    QString idmat = ui->idmmat->text();

    // Check if the idmat exists in the Matiere table
    bool idmatExists = false;

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
    // Prepare the SQL query
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM matiere WHERE idmat = :idmat");
    query.bindValue(":idmat", idmat);

    // Execute the query
    if (query.exec() && query.next()) {
        int count = query.value(0).toInt();
        if (count > 0) {
            idmatExists = true;
        }
    } else {
        qDebug() << "Error executing query:" << query.lastError().text();
        return;
    }

    if (!idmatExists) {
        qDebug() << "Invalid idmat! Please enter a valid idmat.";
        return;
    }

    // Add the idmat to the table widget for display
    int row = ui->table_idmat->rowCount();
    ui->table_idmat->insertRow(row);
    ui->table_idmat->setItem(row, 0, new QTableWidgetItem(idmat));
    ui->idmmat->clear();
    db.close();

}



void groupemodule::on_pushButton_clicked()
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

    QString idgm = ui->IDGM->text();
    QString nomgm = ui->NameGM->text();
    float coefgm = ui->coefficientGM->text().toFloat();
    QString createTableQuery = "CREATE TABLE IF NOT EXISTS GroupeModule ("
                               "IdGM TEXT PRIMARY KEY,"
                               "NomGM TEXT NOT NULL COLLATE NOCASE,"
                               "CoefGM REAL NOT NULL COLLATE NOCASE);";
    QSqlQuery insertQuery;
    if (!insertQuery.exec(createTableQuery)) {
        qDebug() << "Error creating GroupeModule table:" << insertQuery.lastError().text();
        return;
    } else {
        qDebug() << "GroupeModule table created successfully";
    }
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT * FROM GroupeModule_Matiere WHERE idmat = :idmat");
    for (int row = 0; row < ui->table_idmat->rowCount(); ++row) {
        QString idmat = ui->table_idmat->item(row, 0)->text();
        checkQuery.bindValue(":idmat", idmat);
        if (checkQuery.exec() && checkQuery.next()) {

            QString assignedIdGM = checkQuery.value(0).toString();
            qDebug() << "Subject" << idmat << "is already assigned to groupemodule" << assignedIdGM;
            QMessageBox::warning(this, "Error", "Subject " + idmat + " is already assigned to groupemodule " + assignedIdGM);
            return;
        }
    }
    insertQuery.prepare("INSERT INTO GroupeModule (IdGM, NomGM, CoefGM) VALUES (:idgm, :nomgm, :coefgm)");

    insertQuery.bindValue(":idgm", idgm);
    insertQuery.bindValue(":nomgm", nomgm);
    insertQuery.bindValue(":coefgm", coefgm);
    if (!insertQuery.exec()) {
        qDebug() << "Error inserting values into GroupeModule_Matiere table:" << insertQuery.lastError().text();
        return;
    } else {
        QMessageBox::information(this,"Success","GroupeModule inserted  successfully");
        qDebug() << "Values inserted into GroupeModule table successfully";
    }

    QSqlQuery matiereInsertQuery;
    QString createGroupeModuleMatiereTableQuery = "CREATE TABLE IF NOT EXISTS GroupeModule_Matiere ("
                                                  "IdGM TEXT,"
                                                  "idmat TEXT,"
                                                  "PRIMARY KEY (IdGM, idmat),"
                                                  "FOREIGN KEY (IdGM) REFERENCES GroupeModule(IdGM),"
                                                  "FOREIGN KEY (idmat) REFERENCES Matiere(idmat)"
                                                  ");";

    if (!matiereInsertQuery.exec(createGroupeModuleMatiereTableQuery)) {
        qDebug() << "Error creating GroupeModule_Matiere table:" << matiereInsertQuery.lastError().text();
        return;
    } else {
        qDebug() << "GroupeModule_Matiere table created successfully";
    }
    for (int row = 0; row < ui->table_idmat->rowCount(); ++row) {
        QString idmat = ui->table_idmat->item(row, 0)->text();



        matiereInsertQuery.prepare("INSERT INTO GroupeModule_Matiere (IdGM, idmat) VALUES (:idgm, :idmat)");
        matiereInsertQuery.bindValue(":idgm", idgm);
        matiereInsertQuery.bindValue(":idmat", idmat);

        if (!matiereInsertQuery.exec()) {
            qDebug() << "Error inserting values into GroupeModule_Matiere table:" << matiereInsertQuery.lastError().text();
            return;
        } else {

            qDebug() << "Values inserted into GroupeModule_Matiere table successfully";
        }
    }
    db.close();
    ui->stackedWidget->setCurrentIndex(0);
}

void groupemodule::initializeModel()
{
    populateGroupeModuleModel();
    populateGroupeModuleMatiereModel();
}

void groupemodule::populateGroupeModuleModel()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("example.db");

    if (!db.open()) {
        qDebug() << "Error: Failed to open database";
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT * FROM GroupeModule");
    if (!query.exec()) {
        qDebug() << "Error executing query:" << query.lastError().text();
        return;
    }

    groupeModuleModel->setQuery(query);

    if (groupeModuleModel->lastError().isValid()) {
        qDebug() << "Error setting query:" << groupeModuleModel->lastError().text();
    }
    model_del->setQuery(query);
    if (model_del->lastError().isValid()) {
        qDebug() << "Error setting query:" << model_del->lastError().text();
    }

    db.close();
}

void groupemodule::populateGroupeModuleMatiereModel()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("example.db");

    if (!db.open()) {
        qDebug() << "Error: Failed to open database";
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT * FROM GroupeModule_Matiere");
    if (!query.exec()) {
        qDebug() << "Error executing query:" << query.lastError().text();
        return;
    }

    groupeModuleMatiereModel->setQuery(query);
    if (groupeModuleMatiereModel->lastError().isValid()) {
        qDebug() << "Error setting query:" << groupeModuleMatiereModel->lastError().text();
    }

    db.close();
}
void groupemodule::customizeTableView()
{
    // Customize groupemodule_table
    int columnCount1 = ui->groupemodule_table->model()->columnCount();
    int totalWidth = 421; // Total width of your table
    int secondColumnWidth = 300; // Adjust this value as needed
    int remainingWidth = totalWidth - secondColumnWidth;
    int columnWidth1 = remainingWidth / (columnCount1 - 1); // Remaining width for other columns

    // Set the width for the second column
    ui->groupemodule_table->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Fixed);
    ui->groupemodule_table->horizontalHeader()->resizeSection(1, secondColumnWidth);

    // Set the width for other columns
    for (int i = 0; i < columnCount1; ++i) {
        if (i != 1) {
            ui->groupemodule_table->horizontalHeader()->setSectionResizeMode(i, QHeaderView::Fixed);
            ui->groupemodule_table->horizontalHeader()->resizeSection(i, columnWidth1);
        }
    }

    // Customize groupemodule_matiere
    int columnCount2 = ui->groupemodule_matiere->model()->columnCount();
    int columnWidth2 = 421 / columnCount2;
    for (int i = 0; i < columnCount2; ++i) {
        ui->groupemodule_matiere->horizontalHeader()->setSectionResizeMode(i, QHeaderView::Fixed);
        ui->groupemodule_matiere->horizontalHeader()->resizeSection(i, columnWidth2);
    }

    // Customize tableGM_del
    int columnCount3 = ui->tableGM_del->model()->columnCount();
    int columnWidth3 = 471 / columnCount3;
    for (int i = 0; i < columnCount3; ++i) {
        ui->tableGM_del->horizontalHeader()->setSectionResizeMode(i, QHeaderView::Fixed);
        ui->tableGM_del->horizontalHeader()->resizeSection(i, columnWidth3);
    }
    // Customize table_GM_update
    int columnCount4 = ui->table_GM_update->model()->columnCount();
    int columnWidth4 = 245 / columnCount4; // Adjusted width to make it smaller
    for (int i = 0; i < columnCount4; ++i) {
        ui->table_GM_update->horizontalHeader()->setSectionResizeMode(i, QHeaderView::Fixed);
        ui->table_GM_update->horizontalHeader()->resizeSection(i, columnWidth4);
    }

    // Customize table_GMM_update
    int columnCount5 = ui->table_GMM_update->model()->columnCount();
    int columnWidth5 = 235 / columnCount5; // Adjusted width to make it smaller
    for (int i = 0; i < columnCount5; ++i) {
        ui->table_GMM_update->horizontalHeader()->setSectionResizeMode(i, QHeaderView::Fixed);
        ui->table_GMM_update->horizontalHeader()->resizeSection(i, columnWidth5);
    }

}

void groupemodule::on_search_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("example.db");
    if (!db.open()) {
        qDebug() << "Error: Failed to open database";
        return;
    }

    QString searchText = ui->searchField->text().trimmed();
    //search in groupemodule table
    QString queryString = "SELECT * FROM GroupeModule WHERE IdGM LIKE :searchText OR NomGM LIKE :searchText OR CoefGM LIKE :searchText";

    QSqlQuery query;
    query.prepare(queryString);
    query.bindValue(":searchText", "%" + searchText + "%");


    if (!query.exec()) {
        qDebug() << "Error executing query:" << query.lastError().text();
        return;
    }

    groupeModuleModel->setQuery(query);
    if (groupeModuleModel->lastError().isValid()) {
        qDebug() << "Error setting query:" << groupeModuleModel->lastError().text();
        return;
    }

    //search in groupe module matiere
    QString queryStringGMM = "SELECT * FROM GroupeModule_Matiere WHERE IdGM LIKE :searchText OR idmat LIKE :searchText ";

    QSqlQuery queryGM;
    queryGM.prepare(queryStringGMM);
    queryGM.bindValue(":searchText", "%" + searchText + "%");


    if (!queryGM.exec()) {
        qDebug() << "Error executing query:" << queryGM.lastError().text();
        return;
    }

    groupeModuleMatiereModel->setQuery(queryGM);
    if (groupeModuleMatiereModel->lastError().isValid()) {
        qDebug() << "Error setting query for GroupeModule_Matiere:" << groupeModuleMatiereModel->lastError().text();
        return;
    }


}
void groupemodule::initializeModel_del()
{
    populateGroupeModuleModel();
}
void groupemodule::populateComboBox_mat()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("example.db");

    // Open the database
    if (!db.open()) {
        qDebug() << "Error: Failed to open database";
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT idmat,nommat FROM Matiere");
    if (!query.exec()) {
        qDebug() << "Error executing query:" << query.lastError().text();
        return;
    }

    QStringList comboItems;
    while (query.next()) {
        QString id_mat = query.value(0).toString();
        QString nom_mat =query.value(1).toString();
        QString combinedString = id_mat + " - " + nom_mat;
        comboItems.append(combinedString);
    }


    db.close();


    QStringListModel *comboModel = new QStringListModel(this);
    comboModel->setStringList(comboItems);
    ui->mat_GM_P->setModel(comboModel);
}




void groupemodule::on_search_GM_clicked()
{

    QString ID = ui->idGM_up->text();
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("example.db");
    if (!db.open()) {
        qDebug() << "Error: Failed to open database";
        return;
    }
    QSqlQuery searchQuery;
    searchQuery.prepare("SELECT COUNT(*) FROM  GroupeModule WHERE IdGM= :ID");
    searchQuery.bindValue(":ID", ID);
    if (!searchQuery.exec()) {
        qDebug() << "Error executing query:" << searchQuery.lastError().text();
        return;
    }

    searchQuery.next();
    int count = searchQuery.value(0).toInt();
    if (count > 0) {
        QMessageBox::information(this, "subject Found", "The subject exists.");
        ui->Name_GM->setVisible(true);
        ui->coef_GM->setVisible(true);
        ui->mat_GM->setVisible(true);
    } else {
        QMessageBox::information(this, "subject Not Found", "The subject does not exist.");
    }
}


void groupemodule::on_Name_GM_clicked()
{
    ui->Name_GM_P->setVisible(true);
    ui->newName->setVisible(true);
    ui->updateN->setVisible(true);
}

void groupemodule::on_coef_GM_clicked()
{
    ui->coef_P_GM->setVisible(true);
    ui->newCoef->setVisible(true);
    ui->updateC->setVisible(true);

}

void groupemodule::on_mat_GM_clicked()
{

    ui->oldIdmat->setVisible(true);
    ui->old_idmat->setVisible(true);
    ui->mat_GM_P->setVisible(true);
    ui->NewMat->setVisible(true);
    ui->updateM->setVisible(true);
}



void groupemodule::on_updateN_clicked()
{
    QString id = ui->idGM_up->text();
    QString newNameGM = ui->Name_GM_P->text();
    if (newNameGM.isEmpty()) {
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
    updateNQuery.prepare("UPDATE GroupeModule SET NomGM=:nomGM WHERE IdGM=:id");
    updateNQuery.bindValue(":nomGM", newNameGM);
    updateNQuery.bindValue(":id", id);
    if (!updateNQuery.exec()) {
        qDebug() << "Error executing query:" << updateNQuery.lastError().text();
        return;
    }
    else {
        QMessageBox::information(this, "Success", "First name updated successfully");
        qDebug() << "First name updated successfully";

    }
     populateGroupeModuleModel();

}





void groupemodule::on_updateC_clicked()
{
    QString id = ui->idGM_up->text();
    float newcoef = ui->coef_P_GM->text().toFloat();
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
    updateNQuery.prepare("UPDATE GroupeModule SET CoefGM=:coeff WHERE IdGM=:id");
    updateNQuery.bindValue(":coeff", newcoef);
    updateNQuery.bindValue(":id", id);
    if (!updateNQuery.exec()) {
        qDebug() << "Error executing query:" << updateNQuery.lastError().text();
        return;
    }
    else {
        QMessageBox::information(this, "Success", "coefficient updated successfully");
        qDebug() << "coefficent updated successfully";
        populateGroupeModuleModel();
    }
}



void groupemodule::on_updateM_clicked()
{
    // Extract idmat from the selected text in mat_GM_P ComboBox
    QString selectedText = ui->mat_GM_P->currentText();
    QStringList parts = selectedText.split("-");
    QString newIdmat = parts.at(0).trimmed();

    // Retrieve the IdGM and old idmat from the line edits
    QString idGM = ui->idGM_up->text();
    QString oldIdmat = ui->oldIdmat->text(); // Assuming oldidmat is the name of your line edit

    // Open the database connection
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("example.db");
    if (!db.open()) {
        qDebug() << "Error: Failed to open database";
        return;
    }

    // Prepare the update query
    QSqlQuery updateQuery;
    updateQuery.prepare("UPDATE GroupeModule_Matiere SET idmat = :newIdmat WHERE IdGM = :idGM AND idmat = :oldIdmat");

    // Bind the values
    updateQuery.bindValue(":newIdmat", newIdmat);
    updateQuery.bindValue(":idGM", idGM);
    updateQuery.bindValue(":oldIdmat", oldIdmat);

    // Execute the query
    if (!updateQuery.exec()) {
        qDebug() << "Error executing update query:" << updateQuery.lastError().text();
        return;
    }
    else {
        QMessageBox::information(this, "Success", "matiere updated successfully");
        qDebug() << "matiere updated successfully";
        populateGroupeModuleMatiereModel();
    }



}

void groupemodule::on_pushB_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
// delete GM
void groupemodule::displaySelectedGM(const QModelIndex &index) {
    // Get the row and column of the clicked item
    int row = index.row();

    // Retrieve the data of the selected student
    QSqlQueryModel *model = qobject_cast<QSqlQueryModel*>(ui->tableGM_del->model());
    QString idGM = model->data(model->index(row, 0)).toString();
    QString nomGM = model->data(model->index(row, 1)).toString();
    float coefGM = model->data(model->index(row, 2)).toFloat();


    // Populate line edits with the selected student's information
    ui->ID_GM->setText(idGM);
    ui->nomGM->setText(nomGM);
    ui->coef->setText(QString::number(coefGM)); // Convert float to QString for setText
}

void groupemodule::resetLineEditFields() {
    ui->ID_GM->clear();
    ui->nomGM->clear();
    ui->coef->clear();
}

void groupemodule::on_delete_GM_clicked()
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
    QString ID_del = ui->ID_GM->text();
    QSqlQuery queryDelete;
    queryDelete.prepare(" DELETE FROM GroupeModule WHERE  IdGM=:ID_del");
    queryDelete.bindValue(":ID_del", ID_del);
    if (!queryDelete.exec()) {
        qDebug() << "Error executing query:" << queryDelete.lastError().text();
        return;
    }

    queryDelete.prepare(" DELETE FROM GroupeModule_Matiere WHERE  IdGM=:ID_del");
    queryDelete.bindValue(":ID_del", ID_del);
    if (!queryDelete.exec()) {
        qDebug() << "Error executing query:" << queryDelete.lastError().text();
        return;
    }
    QMessageBox::information(this,"Success","GM deleted  successfully");
    qDebug() << "GM deleted successfully";
    populateGroupeModuleModel();
    resetLineEditFields();
}




void groupemodule::on_menu_clicked()
{
    this->hide();
    mainwindow *mainWindow = new mainwindow();
    mainWindow->show();
}

