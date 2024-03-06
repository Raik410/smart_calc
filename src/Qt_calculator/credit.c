#include "calc_functions.h"

Credit_output credit_calculator(Credit_params credit_params) {
  setlocale(LC_NUMERIC, "C");
  Credit_output credit_result = {0};
  double average_days_per_month = 365.2425 / 12;
  double monthly_rate = (credit_params.interest_rate / 100.0) / 12.0 * (30.445 / average_days_per_month);

  if (credit_params.annuity) {
    credit_params.differentiated = false;
    credit_result.monthly_payment =
        credit_params.sum_credit * monthly_rate / (1 - pow(1 + monthly_rate, -credit_params.term_credit));
    credit_result.total_payout = credit_result.monthly_payment * credit_params.term_credit;
    credit_result.overpayment = credit_result.total_payout - credit_params.sum_credit;
  }

  if (credit_params.differentiated) {
    credit_params.annuity = false;
    double principal_payment = credit_params.sum_credit / credit_params.term_credit;
    credit_result.max_payment = principal_payment + (credit_params.sum_credit * monthly_rate);
    credit_result.min_payment = principal_payment + (principal_payment * monthly_rate);

    // Расчет общей выплаты и переплаты
    double total_interest = 0;
    for (int month = 1; month <= credit_params.term_credit; month++) {
      total_interest += (credit_params.sum_credit - principal_payment * (month - 1)) * monthly_rate;
    }
    credit_result.total_payout = credit_params.sum_credit + total_interest;
    credit_result.overpayment = total_interest;
  }

  return credit_result;
}

// int main() {
//   Credit_params credit_param = {100, 12, 6, 0, 1};
//   Credit_output credit_result = {0};
//   credit_result = credit_calculator(credit_param);
//   printf("monthly_payment -> %lf | overpayment -> %lf | total_payout -> %lf\n", credit_result.monthly_payment,
//   credit_result.overpayment, credit_result.total_payout); printf("minpayment -> %lf | maxpayment -> %lf\n",
//   credit_result.min_payment, credit_result.max_payment); return 0;
// }
