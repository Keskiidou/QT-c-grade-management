#ifndef ETUDIANT_H
#define ETUDIANT_H
#include "../personne/personne.h"
#include "qlabel.h"
#include <QWidget>
#include <QtSql>
namespace Ui {
class student_managment;
}

class etudiant : public QWidget,public personne

{
    Q_OBJECT

public:

    explicit etudiant(QWidget *parent = nullptr);
    etudiant(string,string,string,int);
     friend std::ostream& operator<<(std::ostream& os, const etudiant& student);
    ~etudiant();

private slots:


    void on_pushButton_clicked();

    void on_Adder_clicked();

    void on_search_clicked();

    void on_show_clicked();

    void on_update_clicked();

    void on_Goback_clicked();

    void on_deleteS_clicked();

    void on_pushButton_2_clicked();

    void on_search_U_clicked();

    void on_NameB_clicked();

    void on_LName_B_clicked();

    void on_Mail_B_clicked();

    void on_updateN_clicked();

    void on_updateL_clicked();

    void on_GoB_clicked();

    void on_updateM_clicked();

    void on_go_b_del_clicked();

    void on_button_back_clicked();

    void on_menu_clicked();

private:
    int num_insc;
    Ui::student_managment *ui;
    QSqlQueryModel *model;
    QLabel *notificationLabel;
    void initializeModel();
    void populateModel();
    void customizeTableView();
    void displaySelectedStudent(const QModelIndex &index);
    void resetLineEditFields();

};

#endif // ETUDIANT_H
