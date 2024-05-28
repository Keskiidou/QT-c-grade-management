#ifndef NOTE_H
#define NOTE_H

#include "etudiant/etudiant.h"
#include "matiere/matiere.h"
#include "qsqlquerymodel.h"
#include <QWidget>

namespace Ui {
class Note;
}

class Note : public QWidget
{
    Q_OBJECT

public:
    explicit Note(QWidget *parent = nullptr);
    Note(matiere*, etudiant*, float, string);
    friend std::ostream& operator<<(std::ostream& os, const Note& grade);
    ~Note();

private slots:


   void on_Continue_clicked();

   void on_continue_2_clicked();


   void on_show_S_clicked();


   void on_proceed_clicked();

   void on_validate_clicked();

   void on_Adder_clicked();

   void on_show_clicked();

   void on_bak_clicked();

   void on_search_clicked();

   void on_pushButton_2_clicked();

   void on_update_clicked();

   void on_go_b_del_clicked();

   void on_Goback_clicked();

   void on_menu_clicked();

   void on_average_clicked();



   // void on_pushButton_clicked();

   void on_PRINT_PV_clicked();

   void on_pushButton_clicked();

   private:
    Ui::Note *ui;
    QSqlQueryModel *NoteModel;
    // QSqlQueryModel *PvModel;
    QSqlQueryModel *MainlyPvModel;
    void populate_grp();
    void populate_grpm();
    void populate_mat();
    void populate_students();
    void populateComboBox();
    void display_frame_2();
    void populateNoteModel();
    void customizeTableView();
    void displaySelectedNote(const QModelIndex &index);
    void resetLineEditFields();
    double calculer_moyenne(int id,QString mat);
    double calculer_moyenne_GM(int id,QString IDGRPM);
    double calculer_moyenne_G(int id,QString IDG);
    QString  Resultat(int id,QString IDG);
    QString mention(int id,QString IDG);
    void populate_PV_grp();

    void populateS();
    void PV();
    // void displayNoteTable();


    // ------------------------
    matiere* Mat;
    etudiant* Etu;
    float note;
    string Type;


};

#endif // NOTE_H
