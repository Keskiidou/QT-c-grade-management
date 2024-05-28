/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainwindow
{
public:
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;

    void setupUi(QWidget *mainwindow)
    {
        if (mainwindow->objectName().isEmpty())
            mainwindow->setObjectName("mainwindow");
        mainwindow->resize(891, 551);
        label = new QLabel(mainwindow);
        label->setObjectName("label");
        label->setGeometry(QRect(100, -10, 691, 151));
        label->setStyleSheet(QString::fromUtf8("color: red; font-size: 20px; font-weight: bold;\n"
"font: 16pt \"Titillium Web\";"));
        label_2 = new QLabel(mainwindow);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(0, 0, 121, 111));
        label_2->setPixmap(QPixmap(QString::fromUtf8("../../../../../iconprojet.jpg")));
        label_2->setScaledContents(true);
        pushButton = new QPushButton(mainwindow);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(160, 260, 141, 51));
        pushButton_2 = new QPushButton(mainwindow);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(410, 260, 141, 51));
        pushButton_3 = new QPushButton(mainwindow);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(650, 260, 141, 51));
        pushButton_4 = new QPushButton(mainwindow);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(160, 350, 141, 51));
        pushButton_5 = new QPushButton(mainwindow);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(410, 350, 141, 51));
        pushButton_6 = new QPushButton(mainwindow);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(650, 350, 141, 51));

        retranslateUi(mainwindow);

        QMetaObject::connectSlotsByName(mainwindow);
    } // setupUi

    void retranslateUi(QWidget *mainwindow)
    {
        mainwindow->setWindowTitle(QCoreApplication::translate("mainwindow", "Form", nullptr));
        label->setText(QCoreApplication::translate("mainwindow", "                           WELCOME TO  GRADE MANAGMENT", nullptr));
        label_2->setText(QString());
        pushButton->setText(QCoreApplication::translate("mainwindow", "students", nullptr));
        pushButton_2->setText(QCoreApplication::translate("mainwindow", "teachers", nullptr));
        pushButton_3->setText(QCoreApplication::translate("mainwindow", "subjects", nullptr));
        pushButton_4->setText(QCoreApplication::translate("mainwindow", "groupe module", nullptr));
        pushButton_5->setText(QCoreApplication::translate("mainwindow", "groupe", nullptr));
        pushButton_6->setText(QCoreApplication::translate("mainwindow", "grades", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mainwindow: public Ui_mainwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
