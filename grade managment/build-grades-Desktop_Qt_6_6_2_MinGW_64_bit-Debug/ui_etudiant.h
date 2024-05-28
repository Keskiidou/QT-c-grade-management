/********************************************************************************
** Form generated from reading UI file 'etudiant.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ETUDIANT_H
#define UI_ETUDIANT_H

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

class Ui_student_managment
{
public:
    QStackedWidget *stackedWidget;
    QWidget *student_menu;
    QPushButton *menu;
    QPushButton *update;
    QLabel *label_2;
    QPushButton *show;
    QPushButton *deleteS;
    QPushButton *Adder;
    QWidget *add_student;
    QPushButton *pushButton;
    QFrame *frame;
    QLineEdit *num_insc;
    QLabel *label_numinsc;
    QLineEdit *Name;
    QLabel *label_2_Name;
    QLineEdit *LastName;
    QLabel *label_3;
    QLineEdit *Mail;
    QLabel *label_4_Mail;
    QPushButton *button_back;
    QWidget *show_student;
    QLineEdit *searchField;
    QLabel *label_4;
    QLabel *label;
    QTableView *liste_table;
    QPushButton *search;
    QPushButton *Goback;
    QWidget *update_student;
    QPushButton *updateL;
    QLineEdit *num_insc_UP;
    QLabel *NewMail;
    QPushButton *updateN;
    QLabel *label_5;
    QPushButton *NameB;
    QPushButton *updateM;
    QPushButton *search_U;
    QLineEdit *LName_B_field;
    QPushButton *LName_B;
    QLabel *newLName;
    QLabel *newName;
    QLineEdit *Name_B_field;
    QPushButton *Mail_B;
    QLineEdit *Mail_B_field;
    QTableView *table_update;
    QLabel *notificationLabel;
    QPushButton *GoB;
    QWidget *delete_student;
    QLineEdit *prenom;
    QLineEdit *nom;
    QPushButton *pushButton_2;
    QLineEdit *mail;
    QTableView *table_del;
    QLineEdit *numinsc;
    QPushButton *go_b_del;

    void setupUi(QWidget *student_managment)
    {
        if (student_managment->objectName().isEmpty())
            student_managment->setObjectName("student_managment");
        student_managment->resize(891, 550);
        stackedWidget = new QStackedWidget(student_managment);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(0, 0, 891, 551));
        student_menu = new QWidget();
        student_menu->setObjectName("student_menu");
        menu = new QPushButton(student_menu);
        menu->setObjectName("menu");
        menu->setGeometry(QRect(380, 490, 121, 29));
        update = new QPushButton(student_menu);
        update->setObjectName("update");
        update->setGeometry(QRect(320, 240, 251, 51));
        label_2 = new QLabel(student_menu);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(90, 40, 671, 101));
        label_2->setStyleSheet(QString::fromUtf8("font: 700 22pt \"Segoe UI\";\n"
"color: rgb(170, 0, 0);"));
        show = new QPushButton(student_menu);
        show->setObjectName("show");
        show->setGeometry(QRect(320, 400, 251, 51));
        deleteS = new QPushButton(student_menu);
        deleteS->setObjectName("deleteS");
        deleteS->setGeometry(QRect(320, 320, 251, 51));
        Adder = new QPushButton(student_menu);
        Adder->setObjectName("Adder");
        Adder->setGeometry(QRect(320, 160, 251, 51));
        stackedWidget->addWidget(student_menu);
        add_student = new QWidget();
        add_student->setObjectName("add_student");
        pushButton = new QPushButton(add_student);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(302, 480, 191, 29));
        frame = new QFrame(add_student);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(130, 60, 591, 381));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        num_insc = new QLineEdit(frame);
        num_insc->setObjectName("num_insc");
        num_insc->setGeometry(QRect(160, 60, 231, 31));
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
        button_back = new QPushButton(add_student);
        button_back->setObjectName("button_back");
        button_back->setGeometry(QRect(0, 0, 83, 29));
        stackedWidget->addWidget(add_student);
        show_student = new QWidget();
        show_student->setObjectName("show_student");
        searchField = new QLineEdit(show_student);
        searchField->setObjectName("searchField");
        searchField->setGeometry(QRect(10, 80, 191, 28));
        label_4 = new QLabel(show_student);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(30, 50, 141, 21));
        label = new QLabel(show_student);
        label->setObjectName("label");
        label->setGeometry(QRect(130, -20, 511, 101));
        label->setStyleSheet(QString::fromUtf8("font: 700 22pt \"Segoe UI\";"));
        liste_table = new QTableView(show_student);
        liste_table->setObjectName("liste_table");
        liste_table->setGeometry(QRect(0, 120, 891, 381));
        liste_table->horizontalHeader()->setVisible(true);
        liste_table->verticalHeader()->setVisible(false);
        search = new QPushButton(show_student);
        search->setObjectName("search");
        search->setGeometry(QRect(220, 80, 83, 29));
        Goback = new QPushButton(show_student);
        Goback->setObjectName("Goback");
        Goback->setGeometry(QRect(332, 510, 161, 29));
        stackedWidget->addWidget(show_student);
        update_student = new QWidget();
        update_student->setObjectName("update_student");
        updateL = new QPushButton(update_student);
        updateL->setObjectName("updateL");
        updateL->setGeometry(QRect(790, 310, 83, 29));
        num_insc_UP = new QLineEdit(update_student);
        num_insc_UP->setObjectName("num_insc_UP");
        num_insc_UP->setGeometry(QRect(400, 80, 221, 28));
        NewMail = new QLabel(update_student);
        NewMail->setObjectName("NewMail");
        NewMail->setGeometry(QRect(510, 350, 251, 20));
        updateN = new QPushButton(update_student);
        updateN->setObjectName("updateN");
        updateN->setGeometry(QRect(790, 240, 83, 29));
        label_5 = new QLabel(update_student);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(400, 50, 231, 20));
        NameB = new QPushButton(update_student);
        NameB->setObjectName("NameB");
        NameB->setGeometry(QRect(270, 240, 161, 29));
        updateM = new QPushButton(update_student);
        updateM->setObjectName("updateM");
        updateM->setGeometry(QRect(790, 380, 83, 29));
        search_U = new QPushButton(update_student);
        search_U->setObjectName("search_U");
        search_U->setGeometry(QRect(460, 120, 101, 31));
        LName_B_field = new QLineEdit(update_student);
        LName_B_field->setObjectName("LName_B_field");
        LName_B_field->setGeometry(QRect(510, 310, 221, 28));
        LName_B = new QPushButton(update_student);
        LName_B->setObjectName("LName_B");
        LName_B->setGeometry(QRect(270, 310, 161, 29));
        newLName = new QLabel(update_student);
        newLName->setObjectName("newLName");
        newLName->setGeometry(QRect(510, 280, 251, 20));
        newName = new QLabel(update_student);
        newName->setObjectName("newName");
        newName->setGeometry(QRect(520, 210, 251, 20));
        Name_B_field = new QLineEdit(update_student);
        Name_B_field->setObjectName("Name_B_field");
        Name_B_field->setGeometry(QRect(510, 240, 221, 28));
        Mail_B = new QPushButton(update_student);
        Mail_B->setObjectName("Mail_B");
        Mail_B->setGeometry(QRect(270, 380, 161, 29));
        Mail_B_field = new QLineEdit(update_student);
        Mail_B_field->setObjectName("Mail_B_field");
        Mail_B_field->setGeometry(QRect(510, 380, 221, 28));
        table_update = new QTableView(update_student);
        table_update->setObjectName("table_update");
        table_update->setGeometry(QRect(0, 0, 251, 551));
        notificationLabel = new QLabel(update_student);
        notificationLabel->setObjectName("notificationLabel");
        notificationLabel->setGeometry(QRect(380, 170, 261, 20));
        GoB = new QPushButton(update_student);
        GoB->setObjectName("GoB");
        GoB->setGeometry(QRect(470, 430, 101, 31));
        stackedWidget->addWidget(update_student);
        delete_student = new QWidget();
        delete_student->setObjectName("delete_student");
        prenom = new QLineEdit(delete_student);
        prenom->setObjectName("prenom");
        prenom->setGeometry(QRect(590, 280, 181, 28));
        nom = new QLineEdit(delete_student);
        nom->setObjectName("nom");
        nom->setGeometry(QRect(590, 220, 181, 28));
        pushButton_2 = new QPushButton(delete_student);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(600, 400, 151, 31));
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushbotton{ }\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(170, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));"));
        mail = new QLineEdit(delete_student);
        mail->setObjectName("mail");
        mail->setGeometry(QRect(590, 340, 181, 28));
        table_del = new QTableView(delete_student);
        table_del->setObjectName("table_del");
        table_del->setGeometry(QRect(0, 0, 471, 551));
        table_del->verticalHeader()->setVisible(false);
        numinsc = new QLineEdit(delete_student);
        numinsc->setObjectName("numinsc");
        numinsc->setGeometry(QRect(590, 160, 181, 28));
        go_b_del = new QPushButton(delete_student);
        go_b_del->setObjectName("go_b_del");
        go_b_del->setGeometry(QRect(470, 0, 83, 29));
        stackedWidget->addWidget(delete_student);

        retranslateUi(student_managment);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(student_managment);
    } // setupUi

    void retranslateUi(QWidget *student_managment)
    {
        student_managment->setWindowTitle(QCoreApplication::translate("student_managment", "Form", nullptr));
        menu->setText(QCoreApplication::translate("student_managment", "Main Menu", nullptr));
        update->setText(QCoreApplication::translate("student_managment", "Update Student", nullptr));
        label_2->setText(QCoreApplication::translate("student_managment", "                  Student Managment ", nullptr));
        show->setText(QCoreApplication::translate("student_managment", "Show Students", nullptr));
        deleteS->setText(QCoreApplication::translate("student_managment", "Delete Student", nullptr));
        Adder->setText(QCoreApplication::translate("student_managment", "Add Student", nullptr));
        pushButton->setText(QCoreApplication::translate("student_managment", "Add", nullptr));
        label_numinsc->setText(QCoreApplication::translate("student_managment", "     Enter num_insc", nullptr));
        label_2_Name->setText(QCoreApplication::translate("student_managment", "      Enter Name", nullptr));
        LastName->setText(QString());
        label_3->setText(QCoreApplication::translate("student_managment", "   Enter  Last Name", nullptr));
        label_4_Mail->setText(QCoreApplication::translate("student_managment", "         Enter Mail", nullptr));
        button_back->setText(QString());
        label_4->setText(QCoreApplication::translate("student_managment", "Search For Student", nullptr));
        label->setText(QCoreApplication::translate("student_managment", "                Liste of Students ", nullptr));
        search->setText(QCoreApplication::translate("student_managment", "Search", nullptr));
        Goback->setText(QCoreApplication::translate("student_managment", "Go Back", nullptr));
        updateL->setText(QCoreApplication::translate("student_managment", "update", nullptr));
        NewMail->setText(QCoreApplication::translate("student_managment", "Enter new Mail :", nullptr));
        updateN->setText(QCoreApplication::translate("student_managment", "update", nullptr));
        label_5->setText(QCoreApplication::translate("student_managment", "Enter the num_insc of the student ", nullptr));
        NameB->setText(QCoreApplication::translate("student_managment", "Name", nullptr));
        updateM->setText(QCoreApplication::translate("student_managment", "update", nullptr));
        search_U->setText(QCoreApplication::translate("student_managment", "search", nullptr));
        LName_B->setText(QCoreApplication::translate("student_managment", "Last Name", nullptr));
        newLName->setText(QCoreApplication::translate("student_managment", "Enter new Last Name :", nullptr));
        newName->setText(QCoreApplication::translate("student_managment", "enter new Name:", nullptr));
        Mail_B->setText(QCoreApplication::translate("student_managment", "Mail", nullptr));
        notificationLabel->setText(QString());
        GoB->setText(QCoreApplication::translate("student_managment", "Go back", nullptr));
        pushButton_2->setText(QCoreApplication::translate("student_managment", "DELETE", nullptr));
        go_b_del->setText(QCoreApplication::translate("student_managment", "Go back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class student_managment: public Ui_student_managment {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ETUDIANT_H
