#ifndef ENSEIGNANT_H
#define ENSEIGNANT_H
#include "personne/personne.h"
#include "qsqlquerymodel.h"
#include <QWidget>

namespace Ui {
class enseignant;
}

class enseignant : public QWidget,public personne
{
    Q_OBJECT

public:
    explicit enseignant(QWidget *parent = nullptr);
      enseignant(int, string, string, string);
    friend std::ostream& operator<<(std::ostream& os, const enseignant& teacher);
    ~enseignant();

private slots:
    void on_Adder_clicked();

    void on_show_clicked();

    void on_deleteS_clicked();

    void on_update_clicked();

    void on_pushButton_clicked();

    void on_search_clicked();

    void on_Goback_clicked();

    void on_pushButton_2_clicked();

    void on_go_b_del_clicked();

    void on_search_U_clicked();

    void on_LName_B_clicked();

    void on_Mail_B_clicked();

    void on_updateN_clicked();

    void on_updateL_clicked();

    void on_updateM_clicked();

    void on_GoB_clicked();



    void on_Name_B_clicked();

    void on_menu_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::enseignant *ui;
    QSqlQueryModel *model;
    int CNRPS;
    void initializeModel();
    void populateModel();
    void customizeTableView();
    void displaySelectedProfessors(const QModelIndex &index);
    void resetLineEditFields();
};

#endif // ENSEIGNANT_H
