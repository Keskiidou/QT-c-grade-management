/********************************************************************************
** Form generated from reading UI file 'note.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOTE_H
#define UI_NOTE_H

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

class Ui_Note
{
public:
    QStackedWidget *stackedWidget;
    QWidget *grades_menu;
    QPushButton *menu;
    QPushButton *update;
    QLabel *label_2;
    QPushButton *show;
    QPushButton *Adder;
    QPushButton *average;
    QWidget *add_grades;
    QFrame *frame;
    QComboBox *Liste_grp;
    QComboBox *liste_grpm;
    QPushButton *show_S;
    QPushButton *continue_2;
    QPushButton *Continue;
    QComboBox *Liste_mat;
    QComboBox *type;
    QPushButton *proceed;
    QComboBox *Liste_etu;
    QComboBox *cnss;
    QPushButton *validate;
    QFrame *frame_2;
    QLineEdit *enter_note;
    QLabel *selected_ETU;
    QLabel *selected_mat;
    QLabel *selected_type;
    QPushButton *bak;
    QWidget *show_grades;
    QLineEdit *searchField;
    QLabel *label_4;
    QTableView *liste_note;
    QPushButton *search;
    QPushButton *Goback;
    QWidget *update_grades;
    QTableView *mainly_PV;
    QComboBox *PV_GRP;
    QPushButton *pushButton;
    QWidget *delete_grades;
    QLineEdit *type_2;
    QLineEdit *numinsc;
    QPushButton *pushButton_2;
    QLineEdit *note;
    QTableView *table_Notedel;
    QLineEdit *idmat;
    QPushButton *go_b_del;

    void setupUi(QWidget *Note)
    {
        if (Note->objectName().isEmpty())
            Note->setObjectName("Note");
        Note->resize(891, 581);
        stackedWidget = new QStackedWidget(Note);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(0, 0, 891, 581));
        grades_menu = new QWidget();
        grades_menu->setObjectName("grades_menu");
        menu = new QPushButton(grades_menu);
        menu->setObjectName("menu");
        menu->setGeometry(QRect(380, 490, 121, 29));
        update = new QPushButton(grades_menu);
        update->setObjectName("update");
        update->setGeometry(QRect(320, 270, 251, 51));
        label_2 = new QLabel(grades_menu);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(70, 80, 671, 101));
        label_2->setStyleSheet(QString::fromUtf8("font: 700 22pt \"Segoe UI\";\n"
"color: rgb(170, 0, 0);"));
        show = new QPushButton(grades_menu);
        show->setObjectName("show");
        show->setGeometry(QRect(320, 340, 251, 51));
        Adder = new QPushButton(grades_menu);
        Adder->setObjectName("Adder");
        Adder->setGeometry(QRect(320, 200, 251, 51));
        average = new QPushButton(grades_menu);
        average->setObjectName("average");
        average->setGeometry(QRect(320, 420, 251, 51));
        stackedWidget->addWidget(grades_menu);
        add_grades = new QWidget();
        add_grades->setObjectName("add_grades");
        frame = new QFrame(add_grades);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(60, 40, 781, 111));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        Liste_grp = new QComboBox(frame);
        Liste_grp->setObjectName("Liste_grp");
        Liste_grp->setGeometry(QRect(250, 30, 181, 31));
        liste_grpm = new QComboBox(frame);
        liste_grpm->setObjectName("liste_grpm");
        liste_grpm->setGeometry(QRect(560, 30, 121, 31));
        show_S = new QPushButton(frame);
        show_S->setObjectName("show_S");
        show_S->setGeometry(QRect(670, 70, 101, 29));
        continue_2 = new QPushButton(frame);
        continue_2->setObjectName("continue_2");
        continue_2->setGeometry(QRect(170, 30, 71, 29));
        Continue = new QPushButton(frame);
        Continue->setObjectName("Continue");
        Continue->setGeometry(QRect(460, 30, 81, 29));
        Liste_mat = new QComboBox(frame);
        Liste_mat->setObjectName("Liste_mat");
        Liste_mat->setGeometry(QRect(20, 70, 181, 31));
        type = new QComboBox(frame);
        type->addItem(QString());
        type->addItem(QString());
        type->addItem(QString());
        type->setObjectName("type");
        type->setGeometry(QRect(470, 70, 181, 31));
        proceed = new QPushButton(frame);
        proceed->setObjectName("proceed");
        proceed->setGeometry(QRect(700, 30, 71, 29));
        Liste_etu = new QComboBox(frame);
        Liste_etu->setObjectName("Liste_etu");
        Liste_etu->setGeometry(QRect(250, 70, 181, 31));
        cnss = new QComboBox(frame);
        cnss->setObjectName("cnss");
        cnss->setGeometry(QRect(20, 30, 141, 31));
        validate = new QPushButton(add_grades);
        validate->setObjectName("validate");
        validate->setGeometry(QRect(330, 518, 191, 31));
        frame_2 = new QFrame(add_grades);
        frame_2->setObjectName("frame_2");
        frame_2->setGeometry(QRect(60, 190, 781, 261));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        enter_note = new QLineEdit(frame_2);
        enter_note->setObjectName("enter_note");
        enter_note->setGeometry(QRect(570, 100, 141, 31));
        selected_ETU = new QLabel(frame_2);
        selected_ETU->setObjectName("selected_ETU");
        selected_ETU->setGeometry(QRect(20, 100, 131, 41));
        selected_mat = new QLabel(frame_2);
        selected_mat->setObjectName("selected_mat");
        selected_mat->setGeometry(QRect(170, 100, 131, 41));
        selected_type = new QLabel(frame_2);
        selected_type->setObjectName("selected_type");
        selected_type->setGeometry(QRect(360, 100, 131, 41));
        bak = new QPushButton(add_grades);
        bak->setObjectName("bak");
        bak->setGeometry(QRect(0, 0, 71, 31));
        stackedWidget->addWidget(add_grades);
        show_grades = new QWidget();
        show_grades->setObjectName("show_grades");
        searchField = new QLineEdit(show_grades);
        searchField->setObjectName("searchField");
        searchField->setGeometry(QRect(10, 80, 191, 28));
        label_4 = new QLabel(show_grades);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(30, 50, 141, 21));
        liste_note = new QTableView(show_grades);
        liste_note->setObjectName("liste_note");
        liste_note->setGeometry(QRect(0, 120, 891, 381));
        liste_note->horizontalHeader()->setVisible(true);
        liste_note->verticalHeader()->setVisible(false);
        search = new QPushButton(show_grades);
        search->setObjectName("search");
        search->setGeometry(QRect(220, 80, 83, 29));
        Goback = new QPushButton(show_grades);
        Goback->setObjectName("Goback");
        Goback->setGeometry(QRect(332, 510, 161, 29));
        stackedWidget->addWidget(show_grades);
        update_grades = new QWidget();
        update_grades->setObjectName("update_grades");
        mainly_PV = new QTableView(update_grades);
        mainly_PV->setObjectName("mainly_PV");
        mainly_PV->setGeometry(QRect(0, 140, 891, 331));
        mainly_PV->horizontalHeader()->setVisible(false);
        mainly_PV->verticalHeader()->setVisible(false);
        PV_GRP = new QComboBox(update_grades);
        PV_GRP->addItem(QString());
        PV_GRP->setObjectName("PV_GRP");
        PV_GRP->setGeometry(QRect(30, 30, 151, 28));
        pushButton = new QPushButton(update_grades);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(400, 530, 83, 29));
        stackedWidget->addWidget(update_grades);
        delete_grades = new QWidget();
        delete_grades->setObjectName("delete_grades");
        type_2 = new QLineEdit(delete_grades);
        type_2->setObjectName("type_2");
        type_2->setEnabled(false);
        type_2->setGeometry(QRect(590, 280, 181, 28));
        numinsc = new QLineEdit(delete_grades);
        numinsc->setObjectName("numinsc");
        numinsc->setEnabled(false);
        numinsc->setGeometry(QRect(590, 220, 181, 28));
        pushButton_2 = new QPushButton(delete_grades);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(600, 400, 151, 31));
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushbotton{ }\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(170, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));"));
        note = new QLineEdit(delete_grades);
        note->setObjectName("note");
        note->setGeometry(QRect(590, 340, 181, 28));
        table_Notedel = new QTableView(delete_grades);
        table_Notedel->setObjectName("table_Notedel");
        table_Notedel->setGeometry(QRect(0, 0, 431, 561));
        table_Notedel->verticalHeader()->setVisible(false);
        idmat = new QLineEdit(delete_grades);
        idmat->setObjectName("idmat");
        idmat->setEnabled(false);
        idmat->setGeometry(QRect(590, 160, 181, 28));
        go_b_del = new QPushButton(delete_grades);
        go_b_del->setObjectName("go_b_del");
        go_b_del->setGeometry(QRect(430, 0, 83, 29));
        stackedWidget->addWidget(delete_grades);

        retranslateUi(Note);

        stackedWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(Note);
    } // setupUi

    void retranslateUi(QWidget *Note)
    {
        Note->setWindowTitle(QCoreApplication::translate("Note", "Form", nullptr));
        menu->setText(QCoreApplication::translate("Note", "Main Menu", nullptr));
        update->setText(QCoreApplication::translate("Note", "Update grades", nullptr));
        label_2->setText(QCoreApplication::translate("Note", "                               Grades", nullptr));
        show->setText(QCoreApplication::translate("Note", "Show grades", nullptr));
        Adder->setText(QCoreApplication::translate("Note", "Add grades", nullptr));
        average->setText(QCoreApplication::translate("Note", "PV", nullptr));
        show_S->setText(QCoreApplication::translate("Note", "confirm", nullptr));
        continue_2->setText(QCoreApplication::translate("Note", "continue", nullptr));
        Continue->setText(QCoreApplication::translate("Note", "continue", nullptr));
        type->setItemText(0, QCoreApplication::translate("Note", "DS", nullptr));
        type->setItemText(1, QCoreApplication::translate("Note", "TP", nullptr));
        type->setItemText(2, QCoreApplication::translate("Note", "EXAMEN", nullptr));

        proceed->setText(QCoreApplication::translate("Note", "continue", nullptr));
        validate->setText(QCoreApplication::translate("Note", "validate", nullptr));
        selected_ETU->setText(QString());
        selected_mat->setText(QString());
        selected_type->setText(QString());
        bak->setText(QString());
        label_4->setText(QCoreApplication::translate("Note", "Search ", nullptr));
        search->setText(QCoreApplication::translate("Note", "Search", nullptr));
        Goback->setText(QCoreApplication::translate("Note", "Go Back", nullptr));
        PV_GRP->setItemText(0, QCoreApplication::translate("Note", "groupe", nullptr));

        pushButton->setText(QCoreApplication::translate("Note", "Goback", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Note", "Update", nullptr));
        go_b_del->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Note: public Ui_Note {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOTE_H
