#ifndef GROUPEMODULE_H
#define GROUPEMODULE_H

#include <QWidget>
#include "matiere/matiere.h"
#include<vector>

namespace Ui {
class groupemodule;
}

class groupemodule : public QWidget
{
    Q_OBJECT

public:
    explicit groupemodule(QWidget *parent = nullptr);
    groupemodule(string, string, float, vector<matiere*>*);
    friend ostream& operator<<(ostream& os, const groupemodule& gm);
    ~groupemodule();

private slots:
    void on_save_clicked();

    void on_pushButton_clicked();

    void on_show_clicked();

    void on_Adder_clicked();

    void on_Goback_clicked();

    void on_search_clicked();



    void on_search_GM_clicked();

    void on_Name_GM_clicked();

    void on_coef_GM_clicked();

    void on_mat_GM_clicked();

    void on_updateN_clicked();

    void on_GoB_clicked();

    void on_updateC_clicked();

    void on_updateM_clicked();

    void on_update_clicked();

    void on_deleteS_clicked();


    void on_pushB_clicked();


    void on_delete_GM_clicked();

    void on_go_b_del_clicked();

    void on_menu_clicked();

private:
    Ui::groupemodule *ui;
    QSqlQueryModel *groupeModuleModel;
    QSqlQueryModel *groupeModuleMatiereModel;
    QSqlQueryModel *model_del;
    void initializeModel();
    void initializeModel_del();
    void populateGroupeModuleMatiereModel();
    void populateGroupeModuleModel();
    void customizeTableView();
    void populateComboBox_mat();
    void displaySelectedGM(const QModelIndex &index);
    void resetLineEditFields();

    string IdGM;
    string NomGM;
    float CoefGM;
    vector<matiere*> ListeMat;

};

#endif // GROUPEMODULE_H
