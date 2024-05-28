/********************************************************************************
** Form generated from reading UI file 'add_student.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADD_STUDENT_H
#define UI_ADD_STUDENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_etudiant
{
public:
    QFrame *frame;
    QLineEdit *num_insc_2;
    QLabel *label_numinsc_2;
    QLineEdit *Name_2;
    QLabel *label_2_Name_2;
    QLineEdit *LastName_2;
    QLabel *label_4;
    QLineEdit *Mail_2;
    QLabel *label_4_Mail_2;
    QDialogButtonBox *buttonBox;

    void setupUi(QWidget *etudiant)
    {
        if (etudiant->objectName().isEmpty())
            etudiant->setObjectName("etudiant");
        etudiant->resize(979, 603);
        frame = new QFrame(etudiant);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(180, 80, 591, 381));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        num_insc_2 = new QLineEdit(frame);
        num_insc_2->setObjectName("num_insc_2");
        num_insc_2->setGeometry(QRect(160, 60, 231, 31));
        label_numinsc_2 = new QLabel(frame);
        label_numinsc_2->setObjectName("label_numinsc_2");
        label_numinsc_2->setGeometry(QRect(200, 30, 131, 20));
        Name_2 = new QLineEdit(frame);
        Name_2->setObjectName("Name_2");
        Name_2->setGeometry(QRect(160, 140, 231, 31));
        label_2_Name_2 = new QLabel(frame);
        label_2_Name_2->setObjectName("label_2_Name_2");
        label_2_Name_2->setGeometry(QRect(200, 110, 131, 20));
        LastName_2 = new QLineEdit(frame);
        LastName_2->setObjectName("LastName_2");
        LastName_2->setGeometry(QRect(160, 220, 231, 31));
        label_4 = new QLabel(frame);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(200, 190, 131, 20));
        Mail_2 = new QLineEdit(frame);
        Mail_2->setObjectName("Mail_2");
        Mail_2->setGeometry(QRect(160, 310, 231, 31));
        label_4_Mail_2 = new QLabel(frame);
        label_4_Mail_2->setObjectName("label_4_Mail_2");
        label_4_Mail_2->setGeometry(QRect(200, 280, 131, 20));
        buttonBox = new QDialogButtonBox(etudiant);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(390, 490, 171, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(etudiant);

        QMetaObject::connectSlotsByName(etudiant);
    } // setupUi

    void retranslateUi(QWidget *etudiant)
    {
        etudiant->setWindowTitle(QCoreApplication::translate("etudiant", "Form", nullptr));
        label_numinsc_2->setText(QCoreApplication::translate("etudiant", "     Enter num_insc", nullptr));
        label_2_Name_2->setText(QCoreApplication::translate("etudiant", "      Enter Name", nullptr));
        LastName_2->setText(QString());
        label_4->setText(QCoreApplication::translate("etudiant", "   Enter  Last Name", nullptr));
        label_4_Mail_2->setText(QCoreApplication::translate("etudiant", "         Enter Mail", nullptr));
    } // retranslateUi

};

namespace Ui {
    class etudiant: public Ui_etudiant {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADD_STUDENT_H
