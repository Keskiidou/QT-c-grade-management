#ifndef MATIERE_H
#define MATIERE_H

#include <QWidget>
#include "qsqlquerymodel.h"
#include "enseignant/enseignant.h"
namespace Ui {
class matiere;
}

class matiere : public QWidget
{
    Q_OBJECT

public:
    explicit matiere(QWidget *parent = nullptr);
     matiere(string, string, float, enseignant*);
     friend ostream& operator<<(ostream& os, const matiere& mat);
    ~matiere();
private:
    string IdMat;
    string NomMat;
    float Coef;
    enseignant* Ens;

private slots:
    void on_Adder_clicked();

    void on_show_clicked();

    void on_update_clicked();

    void on_deleteS_clicked();

    void on_pushButton_clicked();

    void on_search_clicked();

    void on_Goback_clicked();

    void on_pushButton_2_clicked();

    void on_go_b_del_clicked();

    void on_search_U_clicked();

    void on_Name_B_clicked();

    void on_coef_B_clicked();

    void on_prof_B_clicked();

    void on_GoB_clicked();

    void on_updateN_clicked();

    void on_updateC_clicked();

    void on_updateP_clicked();

    void on_menu_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::matiere *ui;
    QSqlQueryModel *model;
    void populateComboBox();
    void initializecomboModel();
    void customizeTableView();
    void initializeModel();
    void populateModel();
    void displaySelectedmatiere(const QModelIndex &index);
    void resetLineEditFields();
};

#endif // MATIERE_H
