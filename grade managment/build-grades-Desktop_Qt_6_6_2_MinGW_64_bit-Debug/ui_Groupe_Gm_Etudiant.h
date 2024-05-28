/********************************************************************************
** Form generated from reading UI file 'Groupe_Gm_Etudiant.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GROUPE_GM_ETUDIANT_H
#define UI_GROUPE_GM_ETUDIANT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_groupe_GM_ETU
{
public:
    QTableView *more_info_groupe;
    QTableView *specific_table_groupe;

    void setupUi(QWidget *groupe_GM_ETU)
    {
        if (groupe_GM_ETU->objectName().isEmpty())
            groupe_GM_ETU->setObjectName("groupe_GM_ETU");
        groupe_GM_ETU->resize(861, 766);
        more_info_groupe = new QTableView(groupe_GM_ETU);
        more_info_groupe->setObjectName("more_info_groupe");
        more_info_groupe->setGeometry(QRect(0, 110, 861, 661));
        specific_table_groupe = new QTableView(groupe_GM_ETU);
        specific_table_groupe->setObjectName("specific_table_groupe");
        specific_table_groupe->setGeometry(QRect(140, 60, 571, 51));
        QWidget::setTabOrder(more_info_groupe, specific_table_groupe);

        retranslateUi(groupe_GM_ETU);

        QMetaObject::connectSlotsByName(groupe_GM_ETU);
    } // setupUi

    void retranslateUi(QWidget *groupe_GM_ETU)
    {
        groupe_GM_ETU->setWindowTitle(QCoreApplication::translate("groupe_GM_ETU", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class groupe_GM_ETU: public Ui_groupe_GM_ETU {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GROUPE_GM_ETUDIANT_H
