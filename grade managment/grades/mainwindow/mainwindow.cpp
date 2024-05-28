#include "mainwindow.h"
#include "enseignant/enseignant.h"
#include "groupe/groupe.h"
#include "groupemodule/groupemodule.h"
#include "matiere/matiere.h"
#include "note/note.h"
#include "ui_mainwindow.h"
#include "etudiant/etudiant.h"
mainwindow::mainwindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::mainwindow)
{
    ui->setupUi(this);
    setWindowIcon(QIcon("C:/Users/user/Desktop/IRM1-3/iconprojet.jpg"));
    setWindowTitle("grade managment");
}

mainwindow::~mainwindow()
{
    delete ui;
}

void mainwindow::on_pushButton_clicked()
{
    this->hide();
    etudiant *studentsWindow = new etudiant();
    studentsWindow->show();
}


void mainwindow::on_pushButton_2_clicked()
{
    this->hide();
    enseignant *enseignantsWindow = new enseignant();
    enseignantsWindow->show();
}


void mainwindow::on_pushButton_3_clicked()
{
    this->hide();
    matiere *matiereWindow = new matiere();
    matiereWindow->show();
}


void mainwindow::on_pushButton_4_clicked()
{
    this->hide();
    groupemodule *groupemoduleWindow = new groupemodule();
    groupemoduleWindow->show();
}


void mainwindow::on_pushButton_5_clicked()
{
    this->hide();
    Groupe *groupeeWindow = new Groupe();
    groupeeWindow->show();
}


void mainwindow::on_pushButton_6_clicked()
{
    this->hide();
    Note *noteWindow = new Note();
    noteWindow->show();
}

