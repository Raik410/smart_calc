#include "credit_calc.h"

#include <QButtonGroup>

#include "calc_functions.h"
#include "ui_credit_calc.h"

credit_calc::credit_calc(QWidget *parent) : QDialog(parent), ui(new Ui::credit_calc) {
  ui->setupUi(this);
  buttonGroup = new QButtonGroup(this);             // Создаем группу кнопок
  buttonGroup->addButton(ui->radioButton_annuity);  // Добавляем первую радио-кнопку
  buttonGroup->addButton(ui->radioButton_differentiated);
  connect(ui->pushButton_calculate, &QPushButton::clicked, this, &credit_calc::calculate_credit);
}

credit_calc::~credit_calc() {
  delete ui;
  delete buttonGroup;
}

void credit_calc::calculate_credit() {
  double sum_credit = ui->lineEdit->text().toDouble();
  int term_credit = ui->lineEdit_2->text().toInt();
  int interest_rate = ui->lineEdit_3->text().toInt();
  bool annuity = ui->radioButton_annuity->isChecked();
  bool differentiated = ui->radioButton_differentiated->isChecked();

  Credit_params credit_params = {sum_credit, term_credit, interest_rate, annuity, differentiated};
  Credit_output credit_result = {0, 0, 0, 0, 0};
  credit_result = credit_calculator(credit_params);

  if (annuity) {
    ui->label_monthly_payment->setText(QString::number(credit_result.monthly_payment, 'f', 2));
  }
  if (differentiated) {
    QString resultText = QString::number(credit_result.min_payment, 'f', 2) + " ... " +
                         QString::number(credit_result.max_payment, 'f', 2);
    ui->label_monthly_payment->setText(resultText);
  }
  ui->label_overpayment->setText(QString::number(credit_result.overpayment, 'f', 2));
  ui->label_total_payout->setText(QString::number(credit_result.total_payout, 'f', 2));
}
