#ifndef GROUPE_H
#define GROUPE_H

#include "etudiant/etudiant.h"
#include "groupemodule/groupemodule.h"
#include "qsqlquerymodel.h"
#include "ui_Groupe_Gm_Etudiant.h"
#include <QWidget>

namespace Ui {
class Groupe;
}

class Groupe : public QWidget
{
    Q_OBJECT

public:
    explicit Groupe(QWidget *parent = nullptr);
    Groupe(string, string, string, string, int, vector<groupemodule*>*, vector<etudiant*>*);
    friend ostream& operator<<(std::ostream& os, const Groupe& grp);
    ~Groupe();


private slots:
    void on_save_GM_clicked();

    void on_save_etu_clicked();

    void on_add_grp_clicked();

    void on_Add_groupe_clicked();

    void on_pushB_clicked();

    void on_show_Groupe_clicked();

    void on_Goback_clicked();

    void on_search_clicked();

    void on_go_b_del_clicked();

    void on_delete_G_clicked();

    void on_search_GM_clicked();

    void on_NivG_clicked();

    void on_DIPG_clicked();

    void on_SpecG_clicked();

    void on_NumG_clicked();

    void on_updateN_clicked();

    void on_updateD_clicked();

    void on_updateS_clicked();

    void on_updateNum_clicked();

    void on_update_Groupe_clicked();

    void on_delete_Groupe_clicked();

    void on_menu_clicked();

    void on_GoB_clicked();

private:
    Ui::Groupe *ui;
    QSqlQueryModel *groupeModel;
    QSqlQueryModel *specificGroupeModel;
    QSqlQueryModel *moreInfoModel;
    Ui::groupe_GM_ETU groupe_gm_etu;
    void populateComboBox_GM();
    void populateComboBox_ETU();
    void populateComboBox_Niveau();
    void populateComboBox_Diplome();
    void populateComboBox_specialite();
    void populateComboBox_Num_G();
    void populateGroupeModel();
    void customizeTableView();
    void display_groupe_GM_ETU(const QModelIndex &index);
    void displaySelectedG(const QModelIndex &index);
    void resetLineEditFields();

    // -------------------------------
    string IdGRP;
    string Niveau;
    string Diplome;
    string Specialite;
    int Num_G;
    vector<groupemodule*> ListeModules;
    vector<etudiant*> ListeEtudiants;
};
#endif // GROUPE_H
