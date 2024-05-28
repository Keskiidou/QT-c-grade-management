/********************************************************************************
** Form generated from reading UI file 'matiere.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MATIERE_H
#define UI_MATIERE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_matiere
{
public:
    QStackedWidget *stackedWidget;
    QWidget *matiere_menu;
    QPushButton *menu;
    QPushButton *update;
    QLabel *label_2;
    QPushButton *show;
    QPushButton *deleteS;
    QPushButton *Adder;
    QWidget *add_matiere;
    QPushButton *pushButton;
    QFrame *frame;
    QLineEdit *ID;
    QLabel *label_id;
    QLineEdit *Name;
    QLabel *label_2_Name;
    QLineEdit *coefficient;
    QLabel *label_3_coef;
    QLabel *label_4_professor;
    QComboBox *cnrps;
    QPushButton *pushButton_3;
    QWidget *show_matiere;
    QLineEdit *searchField;
    QLabel *label_4;
    QLabel *label;
    QTableView *mat_table;
    QPushButton *search;
    QPushButton *Goback;
    QWidget *update_professor;
    QPushButton *updateC;
    QLineEdit *id_up;
    QLabel *NewProf;
    QPushButton *updateN;
    QLabel *label_5;
    QPushButton *Name_B;
    QPushButton *updateP;
    QPushButton *search_U;
    QLineEdit *coef_P;
    QPushButton *coef_B;
    QLabel *newCoef;
    QLabel *newName;
    QLineEdit *Name_P;
    QPushButton *prof_B;
    QLineEdit *prof_P;
    QTableView *table_M_update;
    QLabel *notificationLabel;
    QPushButton *GoB;
    QWidget *delete_matiere;
    QLineEdit *coef;
    QLineEdit *nom;
    QPushButton *pushButton_2;
    QLineEdit *cnrps_mat;
    QTableView *table_del;
    QLineEdit *ID_mat;
    QPushButton *go_b_del;

    void setupUi(QWidget *matiere)
    {
        if (matiere->objectName().isEmpty())
            matiere->setObjectName("matiere");
        matiere->resize(898, 591);
        stackedWidget = new QStackedWidget(matiere);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(0, 0, 891, 581));
        matiere_menu = new QWidget();
        matiere_menu->setObjectName("matiere_menu");
        menu = new QPushButton(matiere_menu);
        menu->setObjectName("menu");
        menu->setGeometry(QRect(380, 490, 121, 29));
        update = new QPushButton(matiere_menu);
        update->setObjectName("update");
        update->setGeometry(QRect(320, 240, 251, 51));
        label_2 = new QLabel(matiere_menu);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(90, 40, 671, 101));
        label_2->setStyleSheet(QString::fromUtf8("font: 700 22pt \"Segoe UI\";\n"
"color: rgb(170, 0, 0);"));
        show = new QPushButton(matiere_menu);
        show->setObjectName("show");
        show->setGeometry(QRect(320, 400, 251, 51));
        deleteS = new QPushButton(matiere_menu);
        deleteS->setObjectName("deleteS");
        deleteS->setGeometry(QRect(320, 320, 251, 51));
        Adder = new QPushButton(matiere_menu);
        Adder->setObjectName("Adder");
        Adder->setGeometry(QRect(320, 160, 251, 51));
        stackedWidget->addWidget(matiere_menu);
        add_matiere = new QWidget();
        add_matiere->setObjectName("add_matiere");
        pushButton = new QPushButton(add_matiere);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(340, 490, 191, 29));
        frame = new QFrame(add_matiere);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(140, 80, 601, 391));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        ID = new QLineEdit(frame);
        ID->setObjectName("ID");
        ID->setGeometry(QRect(190, 60, 231, 31));
        label_id = new QLabel(frame);
        label_id->setObjectName("label_id");
        label_id->setGeometry(QRect(230, 30, 131, 20));
        Name = new QLineEdit(frame);
        Name->setObjectName("Name");
        Name->setGeometry(QRect(190, 140, 231, 31));
        label_2_Name = new QLabel(frame);
        label_2_Name->setObjectName("label_2_Name");
        label_2_Name->setGeometry(QRect(200, 110, 211, 20));
        coefficient = new QLineEdit(frame);
        coefficient->setObjectName("coefficient");
        coefficient->setGeometry(QRect(190, 220, 231, 31));
        label_3_coef = new QLabel(frame);
        label_3_coef->setObjectName("label_3_coef");
        label_3_coef->setGeometry(QRect(190, 190, 231, 20));
        label_4_professor = new QLabel(frame);
        label_4_professor->setObjectName("label_4_professor");
        label_4_professor->setGeometry(QRect(210, 270, 191, 20));
        cnrps = new QComboBox(frame);
        cnrps->addItem(QString());
        cnrps->setObjectName("cnrps");
        cnrps->setGeometry(QRect(190, 300, 231, 28));
        pushButton_3 = new QPushButton(add_matiere);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(0, 0, 83, 29));
        stackedWidget->addWidget(add_matiere);
        show_matiere = new QWidget();
        show_matiere->setObjectName("show_matiere");
        searchField = new QLineEdit(show_matiere);
        searchField->setObjectName("searchField");
        searchField->setGeometry(QRect(10, 80, 191, 28));
        label_4 = new QLabel(show_matiere);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(30, 50, 141, 21));
        label = new QLabel(show_matiere);
        label->setObjectName("label");
        label->setGeometry(QRect(130, -20, 511, 101));
        label->setStyleSheet(QString::fromUtf8("font: 700 22pt \"Segoe UI\";"));
        mat_table = new QTableView(show_matiere);
        mat_table->setObjectName("mat_table");
        mat_table->setGeometry(QRect(0, 120, 891, 381));
        mat_table->horizontalHeader()->setVisible(true);
        mat_table->verticalHeader()->setVisible(false);
        search = new QPushButton(show_matiere);
        search->setObjectName("search");
        search->setGeometry(QRect(220, 80, 83, 29));
        Goback = new QPushButton(show_matiere);
        Goback->setObjectName("Goback");
        Goback->setGeometry(QRect(332, 510, 161, 29));
        stackedWidget->addWidget(show_matiere);
        update_professor = new QWidget();
        update_professor->setObjectName("update_professor");
        updateC = new QPushButton(update_professor);
        updateC->setObjectName("updateC");
        updateC->setGeometry(QRect(790, 310, 83, 29));
        id_up = new QLineEdit(update_professor);
        id_up->setObjectName("id_up");
        id_up->setGeometry(QRect(400, 80, 221, 28));
        NewProf = new QLabel(update_professor);
        NewProf->setObjectName("NewProf");
        NewProf->setGeometry(QRect(520, 350, 251, 20));
        updateN = new QPushButton(update_professor);
        updateN->setObjectName("updateN");
        updateN->setGeometry(QRect(790, 240, 83, 29));
        label_5 = new QLabel(update_professor);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(400, 50, 231, 20));
        Name_B = new QPushButton(update_professor);
        Name_B->setObjectName("Name_B");
        Name_B->setGeometry(QRect(270, 240, 161, 29));
        updateP = new QPushButton(update_professor);
        updateP->setObjectName("updateP");
        updateP->setGeometry(QRect(790, 380, 83, 29));
        search_U = new QPushButton(update_professor);
        search_U->setObjectName("search_U");
        search_U->setGeometry(QRect(460, 120, 101, 31));
        coef_P = new QLineEdit(update_professor);
        coef_P->setObjectName("coef_P");
        coef_P->setGeometry(QRect(510, 310, 221, 28));
        coef_B = new QPushButton(update_professor);
        coef_B->setObjectName("coef_B");
        coef_B->setGeometry(QRect(270, 310, 161, 29));
        newCoef = new QLabel(update_professor);
        newCoef->setObjectName("newCoef");
        newCoef->setGeometry(QRect(510, 280, 251, 20));
        newName = new QLabel(update_professor);
        newName->setObjectName("newName");
        newName->setGeometry(QRect(520, 210, 251, 20));
        Name_P = new QLineEdit(update_professor);
        Name_P->setObjectName("Name_P");
        Name_P->setGeometry(QRect(510, 240, 221, 28));
        prof_B = new QPushButton(update_professor);
        prof_B->setObjectName("prof_B");
        prof_B->setGeometry(QRect(270, 380, 161, 29));
        prof_P = new QLineEdit(update_professor);
        prof_P->setObjectName("prof_P");
        prof_P->setGeometry(QRect(510, 380, 221, 28));
        table_M_update = new QTableView(update_professor);
        table_M_update->setObjectName("table_M_update");
        table_M_update->setGeometry(QRect(-10, 0, 261, 571));
        notificationLabel = new QLabel(update_professor);
        notificationLabel->setObjectName("notificationLabel");
        notificationLabel->setGeometry(QRect(380, 170, 261, 20));
        GoB = new QPushButton(update_professor);
        GoB->setObjectName("GoB");
        GoB->setGeometry(QRect(470, 430, 101, 31));
        stackedWidget->addWidget(update_professor);
        delete_matiere = new QWidget();
        delete_matiere->setObjectName("delete_matiere");
        coef = new QLineEdit(delete_matiere);
        coef->setObjectName("coef");
        coef->setGeometry(QRect(590, 280, 181, 28));
        nom = new QLineEdit(delete_matiere);
        nom->setObjectName("nom");
        nom->setGeometry(QRect(590, 220, 181, 28));
        pushButton_2 = new QPushButton(delete_matiere);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(600, 400, 151, 31));
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushbotton{ }\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(170, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));"));
        cnrps_mat = new QLineEdit(delete_matiere);
        cnrps_mat->setObjectName("cnrps_mat");
        cnrps_mat->setGeometry(QRect(590, 340, 181, 28));
        table_del = new QTableView(delete_matiere);
        table_del->setObjectName("table_del");
        table_del->setGeometry(QRect(0, 0, 471, 591));
        table_del->verticalHeader()->setVisible(false);
        ID_mat = new QLineEdit(delete_matiere);
        ID_mat->setObjectName("ID_mat");
        ID_mat->setGeometry(QRect(590, 160, 181, 28));
        go_b_del = new QPushButton(delete_matiere);
        go_b_del->setObjectName("go_b_del");
        go_b_del->setGeometry(QRect(470, 0, 83, 29));
        stackedWidget->addWidget(delete_matiere);

        retranslateUi(matiere);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(matiere);
    } // setupUi

    void retranslateUi(QWidget *matiere)
    {
        matiere->setWindowTitle(QCoreApplication::translate("matiere", "Form", nullptr));
        menu->setText(QCoreApplication::translate("matiere", "Main Menu", nullptr));
        update->setText(QCoreApplication::translate("matiere", "Update subject", nullptr));
        label_2->setText(QCoreApplication::translate("matiere", "                  subject Managment ", nullptr));
        show->setText(QCoreApplication::translate("matiere", "Show subject", nullptr));
        deleteS->setText(QCoreApplication::translate("matiere", "Delete subject", nullptr));
        Adder->setText(QCoreApplication::translate("matiere", "Add subject", nullptr));
        pushButton->setText(QCoreApplication::translate("matiere", "Add", nullptr));
        label_id->setText(QCoreApplication::translate("matiere", "     Enter ID Subject", nullptr));
        label_2_Name->setText(QCoreApplication::translate("matiere", "      Enter Name of The Subject", nullptr));
        coefficient->setText(QString());
        label_3_coef->setText(QCoreApplication::translate("matiere", "   Enter  Coefficent of The Subject", nullptr));
        label_4_professor->setText(QCoreApplication::translate("matiere", "Select  the professor", nullptr));
        cnrps->setItemText(0, QCoreApplication::translate("matiere", "                     CNRPS", nullptr));

        pushButton_3->setText(QString());
        label_4->setText(QCoreApplication::translate("matiere", "Search For Student", nullptr));
        label->setText(QCoreApplication::translate("matiere", "                Liste of Students ", nullptr));
        search->setText(QCoreApplication::translate("matiere", "Search", nullptr));
        Goback->setText(QCoreApplication::translate("matiere", "Go Back", nullptr));
        updateC->setText(QCoreApplication::translate("matiere", "update", nullptr));
        NewProf->setText(QCoreApplication::translate("matiere", "Enter new professor :", nullptr));
        updateN->setText(QCoreApplication::translate("matiere", "update", nullptr));
        label_5->setText(QCoreApplication::translate("matiere", "Enter the ID of the Sbject", nullptr));
        Name_B->setText(QCoreApplication::translate("matiere", "Name", nullptr));
        updateP->setText(QCoreApplication::translate("matiere", "update", nullptr));
        search_U->setText(QCoreApplication::translate("matiere", "search", nullptr));
        coef_B->setText(QCoreApplication::translate("matiere", "coef", nullptr));
        newCoef->setText(QCoreApplication::translate("matiere", "Enter new coefficent:", nullptr));
        newName->setText(QCoreApplication::translate("matiere", "enter new Name:", nullptr));
        prof_B->setText(QCoreApplication::translate("matiere", "professor", nullptr));
        notificationLabel->setText(QString());
        GoB->setText(QCoreApplication::translate("matiere", "Go back", nullptr));
        pushButton_2->setText(QCoreApplication::translate("matiere", "DELETE", nullptr));
        go_b_del->setText(QCoreApplication::translate("matiere", "Go back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class matiere: public Ui_matiere {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MATIERE_H
