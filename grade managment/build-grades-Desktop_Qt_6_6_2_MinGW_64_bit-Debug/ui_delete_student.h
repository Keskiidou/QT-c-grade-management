/********************************************************************************
** Form generated from reading UI file 'delete_student.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELETE_STUDENT_H
#define UI_DELETE_STUDENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QLineEdit *mail;
    QTableView *table_del;
    QLineEdit *numinsc;
    QLineEdit *nom;
    QDialogButtonBox *buttonBox;
    QPushButton *pushButton;
    QLineEdit *prenom;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName("Form");
        Form->resize(1061, 617);
        mail = new QLineEdit(Form);
        mail->setObjectName("mail");
        mail->setGeometry(QRect(800, 330, 181, 28));
        table_del = new QTableView(Form);
        table_del->setObjectName("table_del");
        table_del->setGeometry(QRect(0, 0, 541, 531));
        numinsc = new QLineEdit(Form);
        numinsc->setObjectName("numinsc");
        numinsc->setGeometry(QRect(800, 150, 181, 28));
        nom = new QLineEdit(Form);
        nom->setObjectName("nom");
        nom->setGeometry(QRect(800, 210, 181, 28));
        buttonBox = new QDialogButtonBox(Form);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(330, 540, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        pushButton = new QPushButton(Form);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(810, 390, 151, 31));
        pushButton->setStyleSheet(QString::fromUtf8("QPushbotton{ }\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(170, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));"));
        prenom = new QLineEdit(Form);
        prenom->setObjectName("prenom");
        prenom->setGeometry(QRect(800, 270, 181, 28));

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("Form", "DELETE", nullptr));
    } // retranslateUi

};

namespace Ui {
class Form: public Ui_Form {private slots:
    void on_pushButton_clicked();
};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELETE_STUDENT_H
