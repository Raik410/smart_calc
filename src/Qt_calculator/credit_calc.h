#ifndef CREDIT_CALC_H
#define CREDIT_CALC_H

#include <QButtonGroup>
#include <QDialog>

namespace Ui {
class credit_calc;
}

class credit_calc : public QDialog {
  Q_OBJECT

 public:
  explicit credit_calc(QWidget *parent = nullptr);
  ~credit_calc();

 private:
  Ui::credit_calc *ui;
  QButtonGroup *buttonGroup;

 private slots:
  void calculate_credit();
};

#endif  // CREDIT_CALC_H
