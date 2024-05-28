/********************************************************************************
** Form generated from reading UI file 'groupe.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GROUPE_H
#define UI_GROUPE_H

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

class Ui_Groupe
{
public:
    QStackedWidget *stackedWidget;
    QWidget *groupe_menu;
    QPushButton *menu;
    QPushButton *update_Groupe;
    QLabel *label_2;
    QPushButton *show_Groupe;
    QPushButton *delete_Groupe;
    QPushButton *Add_groupe;
    QWidget *add_groupe;
    QFrame *frame;
    QLineEdit *ID_G;
    QLabel *label_id;
    QTableWidget *table_GM;
    QPushButton *save_GM;
    QLabel *label_3_coef_2;
    QLabel *label_3;
    QPushButton *pushB;
    QComboBox *specialite;
    QComboBox *Dipolome;
    QComboBox *NUM_G;
    QComboBox *NIveau;
    QComboBox *Modules;
    QComboBox *Students;
    QTableWidget *table_ETU;
    QPushButton *save_etu;
    QPushButton *add_grp;
    QLabel *label_3_coef_3;
    QLabel *label_3_coef_4;
    QLabel *label_3_coef_5;
    QLabel *label_3_coef_6;
    QLabel *label_3_coef_7;
    QWidget *show_groupe;
    QLineEdit *searchField;
    QLabel *label_4;
    QLabel *label;
    QTableView *groupe_table;
    QPushButton *search;
    QPushButton *Goback;
    QWidget *update_groupe;
    QPushButton *updateD;
    QLineEdit *idG_up;
    QPushButton *updateN;
    QLabel *label_5;
    QPushButton *NivG;
    QPushButton *updateS;
    QPushButton *search_GM;
    QPushButton *DIPG;
    QLabel *newDIP;
    QLabel *newNiv;
    QPushButton *SpecG;
    QTableView *table_G_update;
    QPushButton *GoB;
    QComboBox *Spec_G;
    QLabel *NewSpec;
    QComboBox *Niv_G;
    QComboBox *Dip_G;
    QPushButton *NumG;
    QComboBox *Num_G;
    QPushButton *updateNum;
    QLabel *NewNum;
    QWidget *delete_groupe;
    QLineEdit *diplome;
    QLineEdit *Niveau;
    QPushButton *delete_G;
    QTableView *tableGM_del;
    QLineEdit *ID_Groupe;
    QPushButton *go_b_del;
    QLineEdit *spec;
    QLineEdit *num_g;

    void setupUi(QWidget *Groupe)
    {
        if (Groupe->objectName().isEmpty())
            Groupe->setObjectName("Groupe");
        Groupe->resize(891, 581);
        stackedWidget = new QStackedWidget(Groupe);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(0, 0, 891, 581));
        groupe_menu = new QWidget();
        groupe_menu->setObjectName("groupe_menu");
        menu = new QPushButton(groupe_menu);
        menu->setObjectName("menu");
        menu->setGeometry(QRect(380, 490, 121, 29));
        update_Groupe = new QPushButton(groupe_menu);
        update_Groupe->setObjectName("update_Groupe");
        update_Groupe->setGeometry(QRect(320, 240, 251, 51));
        label_2 = new QLabel(groupe_menu);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(110, 40, 671, 101));
        label_2->setStyleSheet(QString::fromUtf8("font: 700 22pt \"Segoe UI\";\n"
"color: rgb(170, 0, 0);"));
        show_Groupe = new QPushButton(groupe_menu);
        show_Groupe->setObjectName("show_Groupe");
        show_Groupe->setGeometry(QRect(320, 400, 251, 51));
        delete_Groupe = new QPushButton(groupe_menu);
        delete_Groupe->setObjectName("delete_Groupe");
        delete_Groupe->setGeometry(QRect(320, 320, 251, 51));
        Add_groupe = new QPushButton(groupe_menu);
        Add_groupe->setObjectName("Add_groupe");
        Add_groupe->setGeometry(QRect(320, 160, 251, 51));
        stackedWidget->addWidget(groupe_menu);
        add_groupe = new QWidget();
        add_groupe->setObjectName("add_groupe");
        frame = new QFrame(add_groupe);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(0, 0, 891, 581));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        ID_G = new QLineEdit(frame);
        ID_G->setObjectName("ID_G");
        ID_G->setGeometry(QRect(40, 190, 181, 31));
        label_id = new QLabel(frame);
        label_id->setObjectName("label_id");
        label_id->setGeometry(QRect(40, 160, 191, 20));
        table_GM = new QTableWidget(frame);
        if (table_GM->columnCount() < 1)
            table_GM->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        table_GM->setHorizontalHeaderItem(0, __qtablewidgetitem);
        table_GM->setObjectName("table_GM");
        table_GM->setGeometry(QRect(760, 0, 131, 261));
        save_GM = new QPushButton(frame);
        save_GM->setObjectName("save_GM");
        save_GM->setGeometry(QRect(490, 260, 81, 29));
        label_3_coef_2 = new QLabel(frame);
        label_3_coef_2->setObjectName("label_3_coef_2");
        label_3_coef_2->setGeometry(QRect(280, 230, 211, 20));
        label_3 = new QLabel(frame);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(70, 40, 671, 101));
        label_3->setStyleSheet(QString::fromUtf8("font: 700 22pt \"Segoe UI\";\n"
"color: rgb(170, 0, 0);"));
        pushB = new QPushButton(frame);
        pushB->setObjectName("pushB");
        pushB->setGeometry(QRect(0, 0, 61, 31));
        specialite = new QComboBox(frame);
        specialite->setObjectName("specialite");
        specialite->setGeometry(QRect(40, 390, 181, 31));
        Dipolome = new QComboBox(frame);
        Dipolome->setObjectName("Dipolome");
        Dipolome->setGeometry(QRect(40, 330, 181, 31));
        NUM_G = new QComboBox(frame);
        NUM_G->setObjectName("NUM_G");
        NUM_G->setGeometry(QRect(40, 460, 180, 31));
        NIveau = new QComboBox(frame);
        NIveau->setObjectName("NIveau");
        NIveau->setGeometry(QRect(40, 260, 181, 30));
        Modules = new QComboBox(frame);
        Modules->setObjectName("Modules");
        Modules->setGeometry(QRect(280, 260, 180, 31));
        Students = new QComboBox(frame);
        Students->setObjectName("Students");
        Students->setGeometry(QRect(280, 390, 180, 31));
        table_ETU = new QTableWidget(frame);
        if (table_ETU->columnCount() < 1)
            table_ETU->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        table_ETU->setHorizontalHeaderItem(0, __qtablewidgetitem1);
        table_ETU->setObjectName("table_ETU");
        table_ETU->setGeometry(QRect(760, 310, 131, 261));
        save_etu = new QPushButton(frame);
        save_etu->setObjectName("save_etu");
        save_etu->setGeometry(QRect(490, 390, 81, 29));
        add_grp = new QPushButton(frame);
        add_grp->setObjectName("add_grp");
        add_grp->setGeometry(QRect(420, 490, 111, 29));
        label_3_coef_3 = new QLabel(frame);
        label_3_coef_3->setObjectName("label_3_coef_3");
        label_3_coef_3->setGeometry(QRect(280, 360, 211, 20));
        label_3_coef_4 = new QLabel(frame);
        label_3_coef_4->setObjectName("label_3_coef_4");
        label_3_coef_4->setGeometry(QRect(40, 230, 211, 20));
        label_3_coef_5 = new QLabel(frame);
        label_3_coef_5->setObjectName("label_3_coef_5");
        label_3_coef_5->setGeometry(QRect(40, 300, 211, 20));
        label_3_coef_6 = new QLabel(frame);
        label_3_coef_6->setObjectName("label_3_coef_6");
        label_3_coef_6->setGeometry(QRect(40, 370, 211, 20));
        label_3_coef_7 = new QLabel(frame);
        label_3_coef_7->setObjectName("label_3_coef_7");
        label_3_coef_7->setGeometry(QRect(40, 440, 211, 20));
        stackedWidget->addWidget(add_groupe);
        show_groupe = new QWidget();
        show_groupe->setObjectName("show_groupe");
        searchField = new QLineEdit(show_groupe);
        searchField->setObjectName("searchField");
        searchField->setGeometry(QRect(10, 80, 191, 28));
        label_4 = new QLabel(show_groupe);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(30, 50, 141, 21));
        label = new QLabel(show_groupe);
        label->setObjectName("label");
        label->setGeometry(QRect(130, -20, 681, 101));
        label->setStyleSheet(QString::fromUtf8("font: 700 22pt \"Segoe UI\";"));
        groupe_table = new QTableView(show_groupe);
        groupe_table->setObjectName("groupe_table");
        groupe_table->setGeometry(QRect(0, 120, 891, 381));
        search = new QPushButton(show_groupe);
        search->setObjectName("search");
        search->setGeometry(QRect(220, 80, 83, 29));
        Goback = new QPushButton(show_groupe);
        Goback->setObjectName("Goback");
        Goback->setGeometry(QRect(332, 510, 161, 29));
        stackedWidget->addWidget(show_groupe);
        update_groupe = new QWidget();
        update_groupe->setObjectName("update_groupe");
        updateD = new QPushButton(update_groupe);
        updateD->setObjectName("updateD");
        updateD->setGeometry(QRect(790, 310, 83, 29));
        idG_up = new QLineEdit(update_groupe);
        idG_up->setObjectName("idG_up");
        idG_up->setGeometry(QRect(400, 80, 221, 28));
        updateN = new QPushButton(update_groupe);
        updateN->setObjectName("updateN");
        updateN->setGeometry(QRect(790, 240, 83, 29));
        label_5 = new QLabel(update_groupe);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(400, 50, 231, 20));
        NivG = new QPushButton(update_groupe);
        NivG->setObjectName("NivG");
        NivG->setGeometry(QRect(270, 240, 161, 29));
        updateS = new QPushButton(update_groupe);
        updateS->setObjectName("updateS");
        updateS->setGeometry(QRect(790, 380, 83, 29));
        search_GM = new QPushButton(update_groupe);
        search_GM->setObjectName("search_GM");
        search_GM->setGeometry(QRect(460, 120, 101, 31));
        DIPG = new QPushButton(update_groupe);
        DIPG->setObjectName("DIPG");
        DIPG->setGeometry(QRect(270, 310, 161, 29));
        newDIP = new QLabel(update_groupe);
        newDIP->setObjectName("newDIP");
        newDIP->setGeometry(QRect(510, 280, 251, 20));
        newNiv = new QLabel(update_groupe);
        newNiv->setObjectName("newNiv");
        newNiv->setGeometry(QRect(520, 210, 251, 20));
        SpecG = new QPushButton(update_groupe);
        SpecG->setObjectName("SpecG");
        SpecG->setGeometry(QRect(270, 380, 161, 29));
        table_G_update = new QTableView(update_groupe);
        table_G_update->setObjectName("table_G_update");
        table_G_update->setGeometry(QRect(-10, 0, 261, 581));
        GoB = new QPushButton(update_groupe);
        GoB->setObjectName("GoB");
        GoB->setGeometry(QRect(250, 0, 101, 31));
        Spec_G = new QComboBox(update_groupe);
        Spec_G->addItem(QString());
        Spec_G->addItem(QString());
        Spec_G->addItem(QString());
        Spec_G->setObjectName("Spec_G");
        Spec_G->setGeometry(QRect(510, 380, 221, 28));
        NewSpec = new QLabel(update_groupe);
        NewSpec->setObjectName("NewSpec");
        NewSpec->setGeometry(QRect(510, 350, 221, 20));
        Niv_G = new QComboBox(update_groupe);
        Niv_G->addItem(QString());
        Niv_G->addItem(QString());
        Niv_G->addItem(QString());
        Niv_G->setObjectName("Niv_G");
        Niv_G->setGeometry(QRect(510, 240, 221, 28));
        Dip_G = new QComboBox(update_groupe);
        Dip_G->addItem(QString());
        Dip_G->addItem(QString());
        Dip_G->addItem(QString());
        Dip_G->setObjectName("Dip_G");
        Dip_G->setGeometry(QRect(510, 310, 221, 28));
        NumG = new QPushButton(update_groupe);
        NumG->setObjectName("NumG");
        NumG->setGeometry(QRect(270, 450, 161, 29));
        Num_G = new QComboBox(update_groupe);
        Num_G->addItem(QString());
        Num_G->addItem(QString());
        Num_G->addItem(QString());
        Num_G->setObjectName("Num_G");
        Num_G->setGeometry(QRect(510, 450, 221, 28));
        updateNum = new QPushButton(update_groupe);
        updateNum->setObjectName("updateNum");
        updateNum->setGeometry(QRect(790, 450, 83, 29));
        NewNum = new QLabel(update_groupe);
        NewNum->setObjectName("NewNum");
        NewNum->setGeometry(QRect(510, 430, 221, 20));
        stackedWidget->addWidget(update_groupe);
        updateD->raise();
        idG_up->raise();
        updateN->raise();
        label_5->raise();
        updateS->raise();
        search_GM->raise();
        DIPG->raise();
        newDIP->raise();
        newNiv->raise();
        SpecG->raise();
        table_G_update->raise();
        GoB->raise();
        Spec_G->raise();
        NewSpec->raise();
        Niv_G->raise();
        Dip_G->raise();
        NumG->raise();
        Num_G->raise();
        updateNum->raise();
        NewNum->raise();
        NivG->raise();
        delete_groupe = new QWidget();
        delete_groupe->setObjectName("delete_groupe");
        diplome = new QLineEdit(delete_groupe);
        diplome->setObjectName("diplome");
        diplome->setGeometry(QRect(570, 230, 181, 28));
        Niveau = new QLineEdit(delete_groupe);
        Niveau->setObjectName("Niveau");
        Niveau->setGeometry(QRect(570, 180, 181, 28));
        delete_G = new QPushButton(delete_groupe);
        delete_G->setObjectName("delete_G");
        delete_G->setGeometry(QRect(590, 390, 151, 31));
        delete_G->setStyleSheet(QString::fromUtf8("QPushbotton{ }\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(170, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));"));
        tableGM_del = new QTableView(delete_groupe);
        tableGM_del->setObjectName("tableGM_del");
        tableGM_del->setGeometry(QRect(0, 0, 431, 581));
        tableGM_del->verticalHeader()->setVisible(false);
        ID_Groupe = new QLineEdit(delete_groupe);
        ID_Groupe->setObjectName("ID_Groupe");
        ID_Groupe->setGeometry(QRect(570, 120, 181, 28));
        go_b_del = new QPushButton(delete_groupe);
        go_b_del->setObjectName("go_b_del");
        go_b_del->setGeometry(QRect(430, 0, 83, 29));
        spec = new QLineEdit(delete_groupe);
        spec->setObjectName("spec");
        spec->setGeometry(QRect(570, 280, 181, 28));
        num_g = new QLineEdit(delete_groupe);
        num_g->setObjectName("num_g");
        num_g->setGeometry(QRect(570, 340, 181, 28));
        stackedWidget->addWidget(delete_groupe);

        retranslateUi(Groupe);

        stackedWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(Groupe);
    } // setupUi

    void retranslateUi(QWidget *Groupe)
    {
        Groupe->setWindowTitle(QCoreApplication::translate("Groupe", "Form", nullptr));
        menu->setText(QCoreApplication::translate("Groupe", "Main Menu", nullptr));
        update_Groupe->setText(QCoreApplication::translate("Groupe", "Update groupe", nullptr));
        label_2->setText(QCoreApplication::translate("Groupe", "                  groupe  Managment ", nullptr));
        show_Groupe->setText(QCoreApplication::translate("Groupe", "Show groupe", nullptr));
        delete_Groupe->setText(QCoreApplication::translate("Groupe", "Delete groupe", nullptr));
        Add_groupe->setText(QCoreApplication::translate("Groupe", "Add groupe", nullptr));
        label_id->setText(QCoreApplication::translate("Groupe", "     Enter ID groupe", nullptr));
        QTableWidgetItem *___qtablewidgetitem = table_GM->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("Groupe", "Groupe Module", nullptr));
        save_GM->setText(QCoreApplication::translate("Groupe", "save", nullptr));
        label_3_coef_2->setText(QCoreApplication::translate("Groupe", "Enter ID of The groupemodule", nullptr));
        label_3->setText(QCoreApplication::translate("Groupe", "                          Add Groupe", nullptr));
        pushB->setText(QString());
        QTableWidgetItem *___qtablewidgetitem1 = table_ETU->horizontalHeaderItem(0);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("Groupe", "Students", nullptr));
        save_etu->setText(QCoreApplication::translate("Groupe", "save", nullptr));
        add_grp->setText(QCoreApplication::translate("Groupe", "Add", nullptr));
        label_3_coef_3->setText(QCoreApplication::translate("Groupe", "Enter num_insc ", nullptr));
        label_3_coef_4->setText(QCoreApplication::translate("Groupe", "Niveau", nullptr));
        label_3_coef_5->setText(QCoreApplication::translate("Groupe", "Enter Diplome", nullptr));
        label_3_coef_6->setText(QCoreApplication::translate("Groupe", "Enter specialite", nullptr));
        label_3_coef_7->setText(QCoreApplication::translate("Groupe", "Enter num_g", nullptr));
        label_4->setText(QCoreApplication::translate("Groupe", "Search For groupe", nullptr));
        label->setText(QCoreApplication::translate("Groupe", "                Liste of Groupe", nullptr));
        search->setText(QCoreApplication::translate("Groupe", "Search", nullptr));
        Goback->setText(QCoreApplication::translate("Groupe", "Go Back", nullptr));
        updateD->setText(QCoreApplication::translate("Groupe", "update", nullptr));
        updateN->setText(QCoreApplication::translate("Groupe", "update", nullptr));
        label_5->setText(QCoreApplication::translate("Groupe", "Enter the ID of the groupe ", nullptr));
        NivG->setText(QCoreApplication::translate("Groupe", "Niveau", nullptr));
        updateS->setText(QCoreApplication::translate("Groupe", "update", nullptr));
        search_GM->setText(QCoreApplication::translate("Groupe", "search", nullptr));
        DIPG->setText(QCoreApplication::translate("Groupe", "diplome", nullptr));
        newDIP->setText(QCoreApplication::translate("Groupe", "Enter new Diplome:", nullptr));
        newNiv->setText(QCoreApplication::translate("Groupe", "enter new Niveau:", nullptr));
        SpecG->setText(QCoreApplication::translate("Groupe", "specialite", nullptr));
        GoB->setText(QCoreApplication::translate("Groupe", "Go back", nullptr));
        Spec_G->setItemText(0, QCoreApplication::translate("Groupe", "INF", nullptr));
        Spec_G->setItemText(1, QCoreApplication::translate("Groupe", "INDUS", nullptr));
        Spec_G->setItemText(2, QCoreApplication::translate("Groupe", "MATH", nullptr));

        NewSpec->setText(QCoreApplication::translate("Groupe", "Enter new specialite :", nullptr));
        Niv_G->setItemText(0, QCoreApplication::translate("Groupe", "Premiere", nullptr));
        Niv_G->setItemText(1, QCoreApplication::translate("Groupe", "Deuxieme", nullptr));
        Niv_G->setItemText(2, QCoreApplication::translate("Groupe", "Troisieme", nullptr));

        Dip_G->setItemText(0, QCoreApplication::translate("Groupe", "ING", nullptr));
        Dip_G->setItemText(1, QCoreApplication::translate("Groupe", "Master", nullptr));
        Dip_G->setItemText(2, QCoreApplication::translate("Groupe", "LMD", nullptr));

        NumG->setText(QCoreApplication::translate("Groupe", "num_g", nullptr));
        Num_G->setItemText(0, QCoreApplication::translate("Groupe", "1", nullptr));
        Num_G->setItemText(1, QCoreApplication::translate("Groupe", "2", nullptr));
        Num_G->setItemText(2, QCoreApplication::translate("Groupe", "3", nullptr));

        updateNum->setText(QCoreApplication::translate("Groupe", "update", nullptr));
        NewNum->setText(QCoreApplication::translate("Groupe", "Enter new num_g :", nullptr));
        delete_G->setText(QCoreApplication::translate("Groupe", "DELETE", nullptr));
        go_b_del->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Groupe: public Ui_Groupe {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GROUPE_H
