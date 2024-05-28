/********************************************************************************
** Form generated from reading UI file 'enseignant.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENSEIGNANT_H
#define UI_ENSEIGNANT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_enseignant
{
public:
    QStackedWidget *stackedWidget;
    QWidget *professor_menu;
    QPushButton *menu;
    QPushButton *update;
    QLabel *label_2;
    QPushButton *show;
    QPushButton *deleteS;
    QPushButton *Adder;
    QWidget *add_Professor;
    QPushButton *pushButton;
    QFrame *frame;
    QLineEdit *CNRPS;
    QLabel *label_numinsc;
    QLineEdit *Name;
    QLabel *label_2_Name;
    QLineEdit *LastName;
    QLabel *label_3;
    QLineEdit *Mail;
    QLabel *label_4_Mail;
    QPushButton *pushButton_3;
    QWidget *show_professor;
    QLineEdit *searchField;
    QLabel *label_4;
    QLabel *label;
    QTableView *ens_table;
    QPushButton *search;
    QPushButton *Goback;
    QWidget *update_professor;
    QPushButton *updateL;
    QLineEdit *CNRPS_up;
    QLabel *NewMail;
    QPushButton *updateN;
    QLabel *label_5;
    QPushButton *Name_B;
    QPushButton *updateM;
    QPushButton *search_U;
    QLineEdit *LName_P;
    QPushButton *LName_B;
    QLabel *newLName;
    QLabel *newName;
    QLineEdit *Name_P;
    QPushButton *Mail_B;
    QLineEdit *Mail_P;
    QTableView *table_update;
    QLabel *notificationLabel;
    QPushButton *GoB;
    QWidget *delete_professor;
    QLineEdit *prenom;
    QLineEdit *nom;
    QPushButton *pushButton_2;
    QLineEdit *mail;
    QTableView *table_del;
    QLineEdit *CNRPS_del;
    QPushButton *go_b_del;

    void setupUi(QWidget *enseignant)
    {
        if (enseignant->objectName().isEmpty())
            enseignant->setObjectName("enseignant");
        enseignant->resize(903, 551);
        stackedWidget = new QStackedWidget(enseignant);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(10, 0, 881, 581));
        professor_menu = new QWidget();
        professor_menu->setObjectName("professor_menu");
        menu = new QPushButton(professor_menu);
        menu->setObjectName("menu");
        menu->setGeometry(QRect(380, 490, 121, 29));
        update = new QPushButton(professor_menu);
        update->setObjectName("update");
        update->setGeometry(QRect(320, 240, 251, 51));
        label_2 = new QLabel(professor_menu);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(90, 40, 671, 101));
        label_2->setStyleSheet(QString::fromUtf8("font: 700 22pt \"Segoe UI\";\n"
"color: rgb(170, 0, 0);"));
        show = new QPushButton(professor_menu);
        show->setObjectName("show");
        show->setGeometry(QRect(320, 400, 251, 51));
        deleteS = new QPushButton(professor_menu);
        deleteS->setObjectName("deleteS");
        deleteS->setGeometry(QRect(320, 320, 251, 51));
        Adder = new QPushButton(professor_menu);
        Adder->setObjectName("Adder");
        Adder->setGeometry(QRect(320, 160, 251, 51));
        stackedWidget->addWidget(professor_menu);
        add_Professor = new QWidget();
        add_Professor->setObjectName("add_Professor");
        pushButton = new QPushButton(add_Professor);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(330, 490, 191, 29));
        frame = new QFrame(add_Professor);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(130, 60, 601, 391));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        CNRPS = new QLineEdit(frame);
        CNRPS->setObjectName("CNRPS");
        CNRPS->setGeometry(QRect(160, 60, 231, 31));
        label_numinsc = new QLabel(frame);
        label_numinsc->setObjectName("label_numinsc");
        label_numinsc->setGeometry(QRect(200, 30, 131, 20));
        Name = new QLineEdit(frame);
        Name->setObjectName("Name");
        Name->setGeometry(QRect(160, 140, 231, 31));
        label_2_Name = new QLabel(frame);
        label_2_Name->setObjectName("label_2_Name");
        label_2_Name->setGeometry(QRect(200, 110, 131, 20));
        LastName = new QLineEdit(frame);
        LastName->setObjectName("LastName");
        LastName->setGeometry(QRect(160, 220, 231, 31));
        label_3 = new QLabel(frame);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(200, 190, 131, 20));
        Mail = new QLineEdit(frame);
        Mail->setObjectName("Mail");
        Mail->setGeometry(QRect(160, 310, 231, 31));
        label_4_Mail = new QLabel(frame);
        label_4_Mail->setObjectName("label_4_Mail");
        label_4_Mail->setGeometry(QRect(200, 280, 131, 20));
        pushButton_3 = new QPushButton(add_Professor);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(20, 30, 83, 29));
        stackedWidget->addWidget(add_Professor);
        show_professor = new QWidget();
        show_professor->setObjectName("show_professor");
        searchField = new QLineEdit(show_professor);
        searchField->setObjectName("searchField");
        searchField->setGeometry(QRect(10, 80, 191, 28));
        label_4 = new QLabel(show_professor);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(30, 50, 141, 21));
        label = new QLabel(show_professor);
        label->setObjectName("label");
        label->setGeometry(QRect(130, -20, 511, 101));
        label->setStyleSheet(QString::fromUtf8("font: 700 22pt \"Segoe UI\";"));
        ens_table = new QTableView(show_professor);
        ens_table->setObjectName("ens_table");
        ens_table->setGeometry(QRect(0, 120, 891, 381));
        ens_table->horizontalHeader()->setVisible(true);
        ens_table->verticalHeader()->setVisible(false);
        search = new QPushButton(show_professor);
        search->setObjectName("search");
        search->setGeometry(QRect(220, 80, 83, 29));
        Goback = new QPushButton(show_professor);
        Goback->setObjectName("Goback");
        Goback->setGeometry(QRect(332, 510, 161, 29));
        stackedWidget->addWidget(show_professor);
        update_professor = new QWidget();
        update_professor->setObjectName("update_professor");
        updateL = new QPushButton(update_professor);
        updateL->setObjectName("updateL");
        updateL->setGeometry(QRect(790, 310, 83, 29));
        CNRPS_up = new QLineEdit(update_professor);
        CNRPS_up->setObjectName("CNRPS_up");
        CNRPS_up->setGeometry(QRect(400, 80, 221, 28));
        NewMail = new QLabel(update_professor);
        NewMail->setObjectName("NewMail");
        NewMail->setGeometry(QRect(510, 350, 251, 20));
        updateN = new QPushButton(update_professor);
        updateN->setObjectName("updateN");
        updateN->setGeometry(QRect(790, 240, 83, 29));
        label_5 = new QLabel(update_professor);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(400, 50, 231, 20));
        Name_B = new QPushButton(update_professor);
        Name_B->setObjectName("Name_B");
        Name_B->setGeometry(QRect(270, 240, 161, 29));
        updateM = new QPushButton(update_professor);
        updateM->setObjectName("updateM");
        updateM->setGeometry(QRect(790, 380, 83, 29));
        search_U = new QPushButton(update_professor);
        search_U->setObjectName("search_U");
        search_U->setGeometry(QRect(460, 120, 101, 31));
        LName_P = new QLineEdit(update_professor);
        LName_P->setObjectName("LName_P");
        LName_P->setGeometry(QRect(510, 310, 221, 28));
        LName_B = new QPushButton(update_professor);
        LName_B->setObjectName("LName_B");
        LName_B->setGeometry(QRect(270, 310, 161, 29));
        newLName = new QLabel(update_professor);
        newLName->setObjectName("newLName");
        newLName->setGeometry(QRect(510, 280, 251, 20));
        newName = new QLabel(update_professor);
        newName->setObjectName("newName");
        newName->setGeometry(QRect(520, 210, 251, 20));
        Name_P = new QLineEdit(update_professor);
        Name_P->setObjectName("Name_P");
        Name_P->setGeometry(QRect(510, 240, 221, 28));
        Mail_B = new QPushButton(update_professor);
        Mail_B->setObjectName("Mail_B");
        Mail_B->setGeometry(QRect(270, 380, 161, 29));
        Mail_P = new QLineEdit(update_professor);
        Mail_P->setObjectName("Mail_P");
        Mail_P->setGeometry(QRect(510, 380, 221, 28));
        table_update = new QTableView(update_professor);
        table_update->setObjectName("table_update");
        table_update->setGeometry(QRect(-10, 0, 261, 551));
        notificationLabel = new QLabel(update_professor);
        notificationLabel->setObjectName("notificationLabel");
        notificationLabel->setGeometry(QRect(380, 170, 261, 20));
        GoB = new QPushButton(update_professor);
        GoB->setObjectName("GoB");
        GoB->setGeometry(QRect(470, 430, 101, 31));
        stackedWidget->addWidget(update_professor);
        delete_professor = new QWidget();
        delete_professor->setObjectName("delete_professor");
        prenom = new QLineEdit(delete_professor);
        prenom->setObjectName("prenom");
        prenom->setGeometry(QRect(590, 280, 181, 28));
        nom = new QLineEdit(delete_professor);
        nom->setObjectName("nom");
        nom->setGeometry(QRect(590, 220, 181, 28));
        pushButton_2 = new QPushButton(delete_professor);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(600, 400, 151, 31));
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushbotton{ }\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(170, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));"));
        mail = new QLineEdit(delete_professor);
        mail->setObjectName("mail");
        mail->setGeometry(QRect(590, 340, 181, 28));
        table_del = new QTableView(delete_professor);
        table_del->setObjectName("table_del");
        table_del->setGeometry(QRect(0, 0, 471, 551));
        table_del->verticalHeader()->setVisible(false);
        CNRPS_del = new QLineEdit(delete_professor);
        CNRPS_del->setObjectName("CNRPS_del");
        CNRPS_del->setGeometry(QRect(590, 160, 181, 28));
        go_b_del = new QPushButton(delete_professor);
        go_b_del->setObjectName("go_b_del");
        go_b_del->setGeometry(QRect(470, 0, 83, 29));
        stackedWidget->addWidget(delete_professor);

        retranslateUi(enseignant);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(enseignant);
    } // setupUi

    void retranslateUi(QWidget *enseignant)
    {
        enseignant->setWindowTitle(QCoreApplication::translate("enseignant", "Form", nullptr));
        menu->setText(QCoreApplication::translate("enseignant", "Main Menu", nullptr));
        update->setText(QCoreApplication::translate("enseignant", "Update Professor", nullptr));
        label_2->setText(QCoreApplication::translate("enseignant", "                  Professor Managment ", nullptr));
        show->setText(QCoreApplication::translate("enseignant", "Show Professors", nullptr));
        deleteS->setText(QCoreApplication::translate("enseignant", "Delete Professor", nullptr));
        Adder->setText(QCoreApplication::translate("enseignant", "Add Professor", nullptr));
        pushButton->setText(QCoreApplication::translate("enseignant", "Add", nullptr));
        label_numinsc->setText(QCoreApplication::translate("enseignant", "     Enter CNRPS", nullptr));
        label_2_Name->setText(QCoreApplication::translate("enseignant", "      Enter Name", nullptr));
        LastName->setText(QString());
        label_3->setText(QCoreApplication::translate("enseignant", "   Enter  Last Name", nullptr));
        label_4_Mail->setText(QCoreApplication::translate("enseignant", "         Enter Mail", nullptr));
        pushButton_3->setText(QCoreApplication::translate("enseignant", "go back", nullptr));
        label_4->setText(QCoreApplication::translate("enseignant", "Search For Student", nullptr));
        label->setText(QCoreApplication::translate("enseignant", "                Liste of Students ", nullptr));
        search->setText(QCoreApplication::translate("enseignant", "Search", nullptr));
        Goback->setText(QCoreApplication::translate("enseignant", "Go Back", nullptr));
        updateL->setText(QCoreApplication::translate("enseignant", "update", nullptr));
        NewMail->setText(QCoreApplication::translate("enseignant", "Enter new Mail :", nullptr));
        updateN->setText(QCoreApplication::translate("enseignant", "update", nullptr));
        label_5->setText(QCoreApplication::translate("enseignant", "Enter the CNRPS of the professor ", nullptr));
        Name_B->setText(QCoreApplication::translate("enseignant", "Name", nullptr));
        updateM->setText(QCoreApplication::translate("enseignant", "update", nullptr));
        search_U->setText(QCoreApplication::translate("enseignant", "search", nullptr));
        LName_B->setText(QCoreApplication::translate("enseignant", "Last Name", nullptr));
        newLName->setText(QCoreApplication::translate("enseignant", "Enter new Last Name :", nullptr));
        newName->setText(QCoreApplication::translate("enseignant", "enter new Name:", nullptr));
        Mail_B->setText(QCoreApplication::translate("enseignant", "Mail", nullptr));
        notificationLabel->setText(QString());
        GoB->setText(QCoreApplication::translate("enseignant", "Go back", nullptr));
        pushButton_2->setText(QCoreApplication::translate("enseignant", "DELETE", nullptr));
        go_b_del->setText(QCoreApplication::translate("enseignant", "Go back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class enseignant: public Ui_enseignant {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENSEIGNANT_H
