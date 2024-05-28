/********************************************************************************
** Form generated from reading UI file 'groupemodule.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GROUPEMODULE_H
#define UI_GROUPEMODULE_H

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
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_groupemodule
{
public:
    QStackedWidget *stackedWidget;
    QWidget *groupemodule_menu;
    QPushButton *menu;
    QPushButton *update;
    QLabel *label_2;
    QPushButton *show;
    QPushButton *deleteS;
    QPushButton *Adder;
    QWidget *add_groupemodule;
    QPushButton *pushButton;
    QFrame *frame;
    QLineEdit *IDGM;
    QLabel *label_id;
    QLineEdit *NameGM;
    QLabel *label_2_Name;
    QLineEdit *coefficientGM;
    QLabel *label_3_coef;
    QTableWidget *table_idmat;
    QLineEdit *idmmat;
    QPushButton *save;
    QLabel *label_3_coef_2;
    QLabel *label_3;
    QPushButton *pushB;
    QWidget *show_groupemodule;
    QLineEdit *searchField;
    QLabel *label_4;
    QLabel *label;
    QTableView *groupemodule_table;
    QPushButton *search;
    QPushButton *Goback;
    QTableView *groupemodule_matiere;
    QWidget *update_groupemodule;
    QPushButton *updateC;
    QLineEdit *idGM_up;
    QLabel *NewMat;
    QPushButton *updateN;
    QLabel *label_5;
    QPushButton *Name_GM;
    QPushButton *updateM;
    QPushButton *search_GM;
    QLineEdit *coef_P_GM;
    QPushButton *coef_GM;
    QLabel *newCoef;
    QLabel *newName;
    QLineEdit *Name_GM_P;
    QPushButton *mat_GM;
    QTableView *table_GM_update;
    QPushButton *GoB;
    QTableView *table_GMM_update;
    QComboBox *mat_GM_P;
    QLineEdit *oldIdmat;
    QLabel *old_idmat;
    QWidget *delete_groupemodule;
    QLineEdit *coef;
    QLineEdit *nomGM;
    QPushButton *delete_GM;
    QTableView *tableGM_del;
    QLineEdit *ID_GM;
    QPushButton *go_b_del;

    void setupUi(QWidget *groupemodule)
    {
        if (groupemodule->objectName().isEmpty())
            groupemodule->setObjectName("groupemodule");
        groupemodule->resize(891, 581);
        stackedWidget = new QStackedWidget(groupemodule);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(0, 0, 891, 581));
        groupemodule_menu = new QWidget();
        groupemodule_menu->setObjectName("groupemodule_menu");
        menu = new QPushButton(groupemodule_menu);
        menu->setObjectName("menu");
        menu->setGeometry(QRect(380, 490, 121, 29));
        update = new QPushButton(groupemodule_menu);
        update->setObjectName("update");
        update->setGeometry(QRect(320, 240, 251, 51));
        label_2 = new QLabel(groupemodule_menu);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(30, 40, 671, 101));
        label_2->setStyleSheet(QString::fromUtf8("font: 700 22pt \"Segoe UI\";\n"
"color: rgb(170, 0, 0);"));
        show = new QPushButton(groupemodule_menu);
        show->setObjectName("show");
        show->setGeometry(QRect(320, 400, 251, 51));
        deleteS = new QPushButton(groupemodule_menu);
        deleteS->setObjectName("deleteS");
        deleteS->setGeometry(QRect(320, 320, 251, 51));
        Adder = new QPushButton(groupemodule_menu);
        Adder->setObjectName("Adder");
        Adder->setGeometry(QRect(320, 160, 251, 51));
        stackedWidget->addWidget(groupemodule_menu);
        add_groupemodule = new QWidget();
        add_groupemodule->setObjectName("add_groupemodule");
        pushButton = new QPushButton(add_groupemodule);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(350, 540, 191, 29));
        frame = new QFrame(add_groupemodule);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(10, 10, 861, 521));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        IDGM = new QLineEdit(frame);
        IDGM->setObjectName("IDGM");
        IDGM->setGeometry(QRect(30, 180, 181, 31));
        label_id = new QLabel(frame);
        label_id->setObjectName("label_id");
        label_id->setGeometry(QRect(20, 140, 191, 20));
        NameGM = new QLineEdit(frame);
        NameGM->setObjectName("NameGM");
        NameGM->setGeometry(QRect(310, 180, 181, 31));
        label_2_Name = new QLabel(frame);
        label_2_Name->setObjectName("label_2_Name");
        label_2_Name->setGeometry(QRect(270, 140, 271, 20));
        coefficientGM = new QLineEdit(frame);
        coefficientGM->setObjectName("coefficientGM");
        coefficientGM->setGeometry(QRect(40, 330, 181, 31));
        label_3_coef = new QLabel(frame);
        label_3_coef->setObjectName("label_3_coef");
        label_3_coef->setGeometry(QRect(0, 300, 261, 20));
        table_idmat = new QTableWidget(frame);
        if (table_idmat->columnCount() < 1)
            table_idmat->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        table_idmat->setHorizontalHeaderItem(0, __qtablewidgetitem);
        table_idmat->setObjectName("table_idmat");
        table_idmat->setGeometry(QRect(730, 130, 131, 391));
        idmmat = new QLineEdit(frame);
        idmmat->setObjectName("idmmat");
        idmmat->setGeometry(QRect(300, 330, 181, 31));
        save = new QPushButton(frame);
        save->setObjectName("save");
        save->setGeometry(QRect(490, 330, 81, 29));
        label_3_coef_2 = new QLabel(frame);
        label_3_coef_2->setObjectName("label_3_coef_2");
        label_3_coef_2->setGeometry(QRect(300, 300, 171, 20));
        label_3 = new QLabel(frame);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(80, 0, 671, 101));
        label_3->setStyleSheet(QString::fromUtf8("font: 700 22pt \"Segoe UI\";\n"
"color: rgb(170, 0, 0);"));
        pushB = new QPushButton(frame);
        pushB->setObjectName("pushB");
        pushB->setGeometry(QRect(0, 0, 61, 31));
        stackedWidget->addWidget(add_groupemodule);
        show_groupemodule = new QWidget();
        show_groupemodule->setObjectName("show_groupemodule");
        searchField = new QLineEdit(show_groupemodule);
        searchField->setObjectName("searchField");
        searchField->setGeometry(QRect(10, 80, 191, 28));
        label_4 = new QLabel(show_groupemodule);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(30, 50, 141, 21));
        label = new QLabel(show_groupemodule);
        label->setObjectName("label");
        label->setGeometry(QRect(130, -20, 681, 101));
        label->setStyleSheet(QString::fromUtf8("font: 700 22pt \"Segoe UI\";"));
        groupemodule_table = new QTableView(show_groupemodule);
        groupemodule_table->setObjectName("groupemodule_table");
        groupemodule_table->setGeometry(QRect(0, 120, 421, 381));
        groupemodule_table->horizontalHeader()->setVisible(true);
        groupemodule_table->verticalHeader()->setVisible(false);
        search = new QPushButton(show_groupemodule);
        search->setObjectName("search");
        search->setGeometry(QRect(220, 80, 83, 29));
        Goback = new QPushButton(show_groupemodule);
        Goback->setObjectName("Goback");
        Goback->setGeometry(QRect(332, 510, 161, 29));
        groupemodule_matiere = new QTableView(show_groupemodule);
        groupemodule_matiere->setObjectName("groupemodule_matiere");
        groupemodule_matiere->setGeometry(QRect(440, 120, 441, 381));
        groupemodule_matiere->horizontalHeader()->setVisible(true);
        groupemodule_matiere->verticalHeader()->setVisible(false);
        stackedWidget->addWidget(show_groupemodule);
        update_groupemodule = new QWidget();
        update_groupemodule->setObjectName("update_groupemodule");
        updateC = new QPushButton(update_groupemodule);
        updateC->setObjectName("updateC");
        updateC->setGeometry(QRect(790, 310, 83, 29));
        idGM_up = new QLineEdit(update_groupemodule);
        idGM_up->setObjectName("idGM_up");
        idGM_up->setGeometry(QRect(400, 80, 221, 28));
        NewMat = new QLabel(update_groupemodule);
        NewMat->setObjectName("NewMat");
        NewMat->setGeometry(QRect(280, 450, 221, 20));
        updateN = new QPushButton(update_groupemodule);
        updateN->setObjectName("updateN");
        updateN->setGeometry(QRect(790, 240, 83, 29));
        label_5 = new QLabel(update_groupemodule);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(400, 50, 231, 20));
        Name_GM = new QPushButton(update_groupemodule);
        Name_GM->setObjectName("Name_GM");
        Name_GM->setGeometry(QRect(270, 240, 161, 29));
        updateM = new QPushButton(update_groupemodule);
        updateM->setObjectName("updateM");
        updateM->setGeometry(QRect(780, 440, 83, 29));
        search_GM = new QPushButton(update_groupemodule);
        search_GM->setObjectName("search_GM");
        search_GM->setGeometry(QRect(460, 120, 101, 31));
        coef_P_GM = new QLineEdit(update_groupemodule);
        coef_P_GM->setObjectName("coef_P_GM");
        coef_P_GM->setGeometry(QRect(510, 310, 221, 28));
        coef_GM = new QPushButton(update_groupemodule);
        coef_GM->setObjectName("coef_GM");
        coef_GM->setGeometry(QRect(270, 310, 161, 29));
        newCoef = new QLabel(update_groupemodule);
        newCoef->setObjectName("newCoef");
        newCoef->setGeometry(QRect(510, 280, 251, 20));
        newName = new QLabel(update_groupemodule);
        newName->setObjectName("newName");
        newName->setGeometry(QRect(520, 210, 251, 20));
        Name_GM_P = new QLineEdit(update_groupemodule);
        Name_GM_P->setObjectName("Name_GM_P");
        Name_GM_P->setGeometry(QRect(510, 240, 221, 28));
        mat_GM = new QPushButton(update_groupemodule);
        mat_GM->setObjectName("mat_GM");
        mat_GM->setGeometry(QRect(270, 380, 161, 29));
        table_GM_update = new QTableView(update_groupemodule);
        table_GM_update->setObjectName("table_GM_update");
        table_GM_update->setGeometry(QRect(-10, 0, 261, 301));
        GoB = new QPushButton(update_groupemodule);
        GoB->setObjectName("GoB");
        GoB->setGeometry(QRect(460, 490, 101, 31));
        table_GMM_update = new QTableView(update_groupemodule);
        table_GMM_update->setObjectName("table_GMM_update");
        table_GMM_update->setGeometry(QRect(0, 310, 251, 271));
        table_GMM_update->verticalHeader()->setVisible(true);
        mat_GM_P = new QComboBox(update_groupemodule);
        mat_GM_P->setObjectName("mat_GM_P");
        mat_GM_P->setGeometry(QRect(510, 440, 221, 28));
        oldIdmat = new QLineEdit(update_groupemodule);
        oldIdmat->setObjectName("oldIdmat");
        oldIdmat->setGeometry(QRect(510, 380, 221, 28));
        old_idmat = new QLabel(update_groupemodule);
        old_idmat->setObjectName("old_idmat");
        old_idmat->setGeometry(QRect(510, 350, 221, 20));
        stackedWidget->addWidget(update_groupemodule);
        delete_groupemodule = new QWidget();
        delete_groupemodule->setObjectName("delete_groupemodule");
        coef = new QLineEdit(delete_groupemodule);
        coef->setObjectName("coef");
        coef->setGeometry(QRect(580, 320, 181, 28));
        nomGM = new QLineEdit(delete_groupemodule);
        nomGM->setObjectName("nomGM");
        nomGM->setGeometry(QRect(580, 250, 181, 28));
        delete_GM = new QPushButton(delete_groupemodule);
        delete_GM->setObjectName("delete_GM");
        delete_GM->setGeometry(QRect(590, 390, 151, 31));
        delete_GM->setStyleSheet(QString::fromUtf8("QPushbotton{ }\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(170, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));"));
        tableGM_del = new QTableView(delete_groupemodule);
        tableGM_del->setObjectName("tableGM_del");
        tableGM_del->setGeometry(QRect(0, 0, 431, 581));
        tableGM_del->verticalHeader()->setVisible(false);
        ID_GM = new QLineEdit(delete_groupemodule);
        ID_GM->setObjectName("ID_GM");
        ID_GM->setGeometry(QRect(580, 180, 181, 28));
        go_b_del = new QPushButton(delete_groupemodule);
        go_b_del->setObjectName("go_b_del");
        go_b_del->setGeometry(QRect(430, 0, 83, 29));
        stackedWidget->addWidget(delete_groupemodule);

        retranslateUi(groupemodule);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(groupemodule);
    } // setupUi

    void retranslateUi(QWidget *groupemodule)
    {
        groupemodule->setWindowTitle(QCoreApplication::translate("groupemodule", "Form", nullptr));
        menu->setText(QCoreApplication::translate("groupemodule", "Main Menu", nullptr));
        update->setText(QCoreApplication::translate("groupemodule", "Update groupemodule", nullptr));
        label_2->setText(QCoreApplication::translate("groupemodule", "                  groupe module Managment ", nullptr));
        show->setText(QCoreApplication::translate("groupemodule", "Show groupemodule", nullptr));
        deleteS->setText(QCoreApplication::translate("groupemodule", "Delete groupemodule", nullptr));
        Adder->setText(QCoreApplication::translate("groupemodule", "Add groupemodule", nullptr));
        pushButton->setText(QCoreApplication::translate("groupemodule", "Add", nullptr));
        label_id->setText(QCoreApplication::translate("groupemodule", "     Enter ID groupe module", nullptr));
        label_2_Name->setText(QCoreApplication::translate("groupemodule", "      Enter Name of The groupe module", nullptr));
        coefficientGM->setText(QString());
        label_3_coef->setText(QCoreApplication::translate("groupemodule", "   Enter  Coefficent of groupe module", nullptr));
        QTableWidgetItem *___qtablewidgetitem = table_idmat->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("groupemodule", "ID mat", nullptr));
        save->setText(QCoreApplication::translate("groupemodule", "save", nullptr));
        label_3_coef_2->setText(QCoreApplication::translate("groupemodule", "Enter ID of The Subject", nullptr));
        label_3->setText(QCoreApplication::translate("groupemodule", "                Add  groupe module ", nullptr));
        pushB->setText(QString());
        label_4->setText(QCoreApplication::translate("groupemodule", "Search For Student", nullptr));
        label->setText(QCoreApplication::translate("groupemodule", "                Liste of Groupe Modulde ", nullptr));
        search->setText(QCoreApplication::translate("groupemodule", "Search", nullptr));
        Goback->setText(QCoreApplication::translate("groupemodule", "Go Back", nullptr));
        updateC->setText(QCoreApplication::translate("groupemodule", "update", nullptr));
        NewMat->setText(QCoreApplication::translate("groupemodule", "Enter new matiere :", nullptr));
        updateN->setText(QCoreApplication::translate("groupemodule", "update", nullptr));
        label_5->setText(QCoreApplication::translate("groupemodule", "Enter the ID of the groupe module ", nullptr));
        Name_GM->setText(QCoreApplication::translate("groupemodule", "Name", nullptr));
        updateM->setText(QCoreApplication::translate("groupemodule", "update", nullptr));
        search_GM->setText(QCoreApplication::translate("groupemodule", "search", nullptr));
        coef_GM->setText(QCoreApplication::translate("groupemodule", "coef", nullptr));
        newCoef->setText(QCoreApplication::translate("groupemodule", "Enter new coefficent:", nullptr));
        newName->setText(QCoreApplication::translate("groupemodule", "enter new Name:", nullptr));
        mat_GM->setText(QCoreApplication::translate("groupemodule", "subject", nullptr));
        GoB->setText(QCoreApplication::translate("groupemodule", "Go back", nullptr));
        old_idmat->setText(QCoreApplication::translate("groupemodule", "Enter the ID mat to update :", nullptr));
        delete_GM->setText(QCoreApplication::translate("groupemodule", "DELETE", nullptr));
        go_b_del->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class groupemodule: public Ui_groupemodule {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GROUPEMODULE_H
