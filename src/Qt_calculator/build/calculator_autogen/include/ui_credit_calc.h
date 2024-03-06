/********************************************************************************
** Form generated from reading UI file 'credit_calc.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREDIT_CALC_H
#define UI_CREDIT_CALC_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_credit_calc
{
public:
    QGridLayout *gridLayout_2;
    QDialogButtonBox *buttonBox;
    QGridLayout *gridLayout;
    QRadioButton *radioButton_annuity;
    QLabel *label_overpayment;
    QLabel *label_6;
    QLabel *label;
    QLabel *label_total_payout;
    QLabel *label_4;
    QLineEdit *lineEdit;
    QLabel *label_monthly_payment;
    QLineEdit *lineEdit_3;
    QLabel *label_5;
    QLabel *label_2;
    QRadioButton *radioButton_differentiated;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton_calculate;

    void setupUi(QDialog *credit_calc)
    {
        if (credit_calc->objectName().isEmpty())
            credit_calc->setObjectName("credit_calc");
        credit_calc->resize(400, 325);
        credit_calc->setStyleSheet(QString::fromUtf8("background-color: #1A1F33;"));
        gridLayout_2 = new QGridLayout(credit_calc);
        gridLayout_2->setObjectName("gridLayout_2");
        buttonBox = new QDialogButtonBox(credit_calc);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout_2->addWidget(buttonBox, 1, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        radioButton_annuity = new QRadioButton(credit_calc);
        radioButton_annuity->setObjectName("radioButton_annuity");
        radioButton_annuity->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"	background-color: #353A4E;\n"
"	color: white;\n"
"	font-family: 'JetBrains Mono';\n"
"	padding: 8px 0 8px;\n"
"	border-radius: 7px;\n"
"	width: 157px;\n"
"	max-width: 157px;\n"
"}"));
        radioButton_annuity->setChecked(true);
        radioButton_annuity->setAutoExclusive(false);

        gridLayout->addWidget(radioButton_annuity, 4, 1, 1, 1, Qt::AlignRight);

        label_overpayment = new QLabel(credit_calc);
        label_overpayment->setObjectName("label_overpayment");
        label_overpayment->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	border: 1.5px solid #353A4E;\n"
"	border-radius: 7px;\n"
"	padding: 4px 0 4px;\n"
"	margin: 0 1px 0;\n"
"	font-family: 'JetBrains Mono';\n"
"	color: white;\n"
"}"));

        gridLayout->addWidget(label_overpayment, 7, 1, 1, 1);

        label_6 = new QLabel(credit_calc);
        label_6->setObjectName("label_6");
        label_6->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	background-color: #353A4E;\n"
"	color: white;\n"
"	font-family: 'JetBrains Mono';\n"
"	padding: 8px 0 8px;\n"
"	border-radius: 7px;\n"
"	min-width: 157px;\n"
"}"));
        label_6->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_6, 8, 0, 1, 1, Qt::AlignHCenter);

        label = new QLabel(credit_calc);
        label->setObjectName("label");
        label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	background-color: #353A4E;\n"
"	color: white;\n"
"	font-family: 'JetBrains Mono';\n"
"	padding: 8px 0 8px;\n"
"	border-radius: 7px;\n"
"	min-width: 157px;\n"
"	max-width: 157px;\n"
"}"));

        gridLayout->addWidget(label, 0, 0, 1, 1, Qt::AlignHCenter|Qt::AlignVCenter);

        label_total_payout = new QLabel(credit_calc);
        label_total_payout->setObjectName("label_total_payout");
        label_total_payout->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	border: 1.5px solid #353A4E;\n"
"	border-radius: 7px;\n"
"	padding: 4px 0 4px;\n"
"	margin: 0 1px 0;\n"
"	font-family: 'JetBrains Mono';\n"
"	color: white;\n"
"}"));

        gridLayout->addWidget(label_total_payout, 8, 1, 1, 1);

        label_4 = new QLabel(credit_calc);
        label_4->setObjectName("label_4");
        label_4->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	background-color: #353A4E;\n"
"	color: white;\n"
"	font-family: 'JetBrains Mono';\n"
"	padding: 8px 0 8px;\n"
"	border-radius: 7px;\n"
"	min-width: 157px;\n"
"}"));
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_4, 6, 0, 1, 1, Qt::AlignHCenter);

        lineEdit = new QLineEdit(credit_calc);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	border: 1.5px solid #353A4E;\n"
"	border-radius: 7px;\n"
"	padding: 4px 0 4px;\n"
"	margin: 0 1px 0;\n"
"	font-family: 'JetBrains Mono';\n"
"	color: white;\n"
"}"));

        gridLayout->addWidget(lineEdit, 0, 1, 1, 1);

        label_monthly_payment = new QLabel(credit_calc);
        label_monthly_payment->setObjectName("label_monthly_payment");
        label_monthly_payment->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	border: 1.5px solid #353A4E;\n"
"	border-radius: 7px;\n"
"	padding: 4px 0 4px;\n"
"	margin: 0 1px 0;\n"
"	font-family: 'JetBrains Mono';\n"
"	color: white;\n"
"}"));

        gridLayout->addWidget(label_monthly_payment, 6, 1, 1, 1);

        lineEdit_3 = new QLineEdit(credit_calc);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	border: 1.5px solid #353A4E;\n"
"	border-radius: 7px;\n"
"	padding: 4px 0 4px;\n"
"	margin: 0 1px 0;\n"
"	font-family: 'JetBrains Mono';\n"
"	color: white;\n"
"}"));

        gridLayout->addWidget(lineEdit_3, 2, 1, 1, 1);

        label_5 = new QLabel(credit_calc);
        label_5->setObjectName("label_5");
        label_5->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	background-color: #353A4E;\n"
"	color: white;\n"
"	font-family: 'JetBrains Mono';\n"
"	padding: 8px 0 8px;\n"
"	border-radius: 7px;\n"
"	min-width: 157px;\n"
"}"));
        label_5->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_5, 7, 0, 1, 1, Qt::AlignHCenter);

        label_2 = new QLabel(credit_calc);
        label_2->setObjectName("label_2");
        label_2->setMinimumSize(QSize(157, 34));
        label_2->setMaximumSize(QSize(157, 16777215));
        label_2->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	background-color: #353A4E;\n"
"	color: white;\n"
"	font-family: 'JetBrains Mono';\n"
"	padding: 8px 0 8px;\n"
"	border-radius: 7px;\n"
"	min-width: 157px;\n"
"	heigh: 26px;\n"
"}"));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 1, 0, 1, 1, Qt::AlignHCenter);

        radioButton_differentiated = new QRadioButton(credit_calc);
        radioButton_differentiated->setObjectName("radioButton_differentiated");
        radioButton_differentiated->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"	background-color: #353A4E;\n"
"	color: white;\n"
"	font-family: 'JetBrains Mono';\n"
"	padding: 8px 0 8px;\n"
"	border-radius: 7px;\n"
"	width: 157px;\n"
"	max-width: 157px;\n"
"}"));
        radioButton_differentiated->setCheckable(true);

        gridLayout->addWidget(radioButton_differentiated, 4, 0, 1, 1);

        label_3 = new QLabel(credit_calc);
        label_3->setObjectName("label_3");
        label_3->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	background-color: #353A4E;\n"
"	color: white;\n"
"	font-family: 'JetBrains Mono';\n"
"	padding: 8px 0 8px;\n"
"	border-radius: 7px;\n"
"	min-width: 157px;\n"
"}"));
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_3, 2, 0, 1, 1, Qt::AlignHCenter);

        lineEdit_2 = new QLineEdit(credit_calc);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	border: 1.5px solid #353A4E;\n"
"	border-radius: 7px;\n"
"	padding: 4px 0 4px;\n"
"	margin: 0 1px 0;\n"
"	font-family: 'JetBrains Mono';\n"
"	color: white;\n"
"}"));

        gridLayout->addWidget(lineEdit_2, 1, 1, 1, 1);

        pushButton_calculate = new QPushButton(credit_calc);
        pushButton_calculate->setObjectName("pushButton_calculate");
        pushButton_calculate->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: #353A4E;\n"
"	color: white;\n"
"	font-family: 'JetBrains Mono';\n"
"	padding: 8px 0 8px;\n"
"	border-radius: 7px;\n"
"	min-width: 157px;\n"
"}"));

        gridLayout->addWidget(pushButton_calculate, 9, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        retranslateUi(credit_calc);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, credit_calc, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, credit_calc, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(credit_calc);
    } // setupUi

    void retranslateUi(QDialog *credit_calc)
    {
        credit_calc->setWindowTitle(QCoreApplication::translate("credit_calc", "Dialog", nullptr));
        radioButton_annuity->setText(QCoreApplication::translate("credit_calc", "Annuity", nullptr));
        label_overpayment->setText(QCoreApplication::translate("credit_calc", "0", nullptr));
#if QT_CONFIG(tooltip)
        label_6->setToolTip(QCoreApplication::translate("credit_calc", "<html><head/><body><p align=\"center\"><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        label_6->setText(QCoreApplication::translate("credit_calc", "Total payout", nullptr));
        label->setText(QCoreApplication::translate("credit_calc", "Total credit amount", nullptr));
        label_total_payout->setText(QCoreApplication::translate("credit_calc", "0", nullptr));
        label_4->setText(QCoreApplication::translate("credit_calc", "Monthly payment", nullptr));
        lineEdit->setText(QCoreApplication::translate("credit_calc", "0", nullptr));
        label_monthly_payment->setText(QCoreApplication::translate("credit_calc", "0", nullptr));
        lineEdit_3->setText(QCoreApplication::translate("credit_calc", "0", nullptr));
        label_5->setText(QCoreApplication::translate("credit_calc", "Overpayment", nullptr));
        label_2->setText(QCoreApplication::translate("credit_calc", "Credit term", nullptr));
        radioButton_differentiated->setText(QCoreApplication::translate("credit_calc", "Differentiated", nullptr));
        label_3->setText(QCoreApplication::translate("credit_calc", "Interest rate", nullptr));
        lineEdit_2->setText(QCoreApplication::translate("credit_calc", "0", nullptr));
        pushButton_calculate->setText(QCoreApplication::translate("credit_calc", "\320\241alculate", nullptr));
    } // retranslateUi

};

namespace Ui {
    class credit_calc: public Ui_credit_calc {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREDIT_CALC_H
