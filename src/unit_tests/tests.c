#include <check.h>
#include <math.h>

#include "../calc_functions/calc_functions.h"
#include "../smart_calc.h"

START_TEST(test_plus) {
  char str[] = "2+2";
  double x = 12;
  double result = parser(str, x);
  ck_assert_double_eq_tol(result, 4, 1e-6);
}
END_TEST

START_TEST(test_plus2) {
  char str[] = "25+30+45+(25+30)";
  double x = 12;
  double result = parser(str, x);
  ck_assert_double_eq_tol(result, 155, 1e-6);
}
END_TEST

START_TEST(test_minus) {
  char str[] = "30-24-123-235-22";
  double x = 12;
  double result = parser(str, x);
  ck_assert_double_eq_tol(result, -374, 1e-6);
}
END_TEST

START_TEST(test_minus2) {
  char str[] = "32313-23132-22-111";
  double x = 12;
  double result = parser(str, x);
  ck_assert_double_eq_tol(result, 9048, 1e-6);
}
END_TEST

START_TEST(test_minus3) {
  char str[] = "32313-23132-22-111-(-320)";
  double x = 12;
  double result = parser(str, x);
  ck_assert_double_eq_tol(result, 9368, 1e-6);
}
END_TEST

START_TEST(test_multy1) {
  char str[] = "2*35*23*1";
  double x = 12;
  double result = parser(str, x);
  ck_assert_double_eq_tol(result, 1610, 1e-6);
}
END_TEST

START_TEST(test_multy2) {
  char str[] = "2*13*(-32)*1";
  double x = 12;
  double result = parser(str, x);
  ck_assert_double_eq_tol(result, -832, 1e-6);
}
END_TEST

START_TEST(test_multy3) {
  char str[] = "2*13*(-32)*1+20^2";
  double x = 12;
  double result = parser(str, x);
  ck_assert_double_eq_tol(result, -432, 1e-6);
}
END_TEST

START_TEST(test_div) {
  char str[] = "1000/32/51/23";
  double x = 12;
  double result = parser(str, x);
  ck_assert_double_eq_tol(result, 0.02664109121, 1e-6);
}
END_TEST

START_TEST(test_div2) {
  char str[] = "435/23/13*25";
  double x = 12;
  double result = parser(str, x);
  ck_assert_double_eq_tol(result, 36.3712374582, 1e-6);
}
END_TEST

START_TEST(test_div3) {
  char str[] = "545/545";
  double x = 12;
  double result = parser(str, x);
  ck_assert_double_eq_tol(result, 1, 1e-6);
}
END_TEST

START_TEST(test_pow) {
  char str[] = "30^3";
  double x = 12;
  double result = parser(str, x);
  ck_assert_double_eq_tol(result, 27000, 1e-6);
}
END_TEST

START_TEST(test_pow2) {
  char str[] = "30^1.2";
  double x = 12;
  double result = parser(str, x);
  ck_assert_double_eq_tol(result, 59.230514575, 1e-6);
}
END_TEST

START_TEST(test_pow3) {
  char str[] = "30^1.2-25";
  double x = 12;
  double result = parser(str, x);
  ck_assert_double_eq_tol(result, 34.230514575, 1e-6);
}
END_TEST

START_TEST(test_pow4) {
  char str[] = "30^1.2-25^0.5";
  double x = 12;
  double result = parser(str, x);
  ck_assert_double_eq_tol(result, 54.230514575, 1e-6);
}
END_TEST

START_TEST(test_pow5) {
  char str[] = "30^1.2-25^0.5+x";
  double x = 12;
  double result = parser(str, x);
  ck_assert_double_eq_tol(result, 66.230514575, 1e-6);
}
END_TEST

START_TEST(test_mod) {
  char str[] = "30%15";
  double x = 12;
  double result = parser(str, x);
  ck_assert_double_eq_tol(result, 0, 1e-6);
}
END_TEST

START_TEST(test_mod1) {
  char str[] = "30%29+30+40";
  double x = 12;
  double result = parser(str, x);
  ck_assert_double_eq_tol(result, 71, 1e-6);
}
END_TEST

START_TEST(test_sin) {
  char str[] = "sin(30)";
  double x = 12;
  double result = parser(str, x);
  ck_assert_double_eq_tol(result, -0.98803162409, 1e-6);
}
END_TEST

START_TEST(test_sin2) {
  char str[] = "sin(30+25)+sin(20)";
  double x = 12;
  double result = parser(str, x);
  ck_assert_double_eq_tol(result, -0.08680992263, 1e-6);
}
END_TEST

START_TEST(test_sin3) {
  char str[] = "sin(30+25)+sin(20)-2^3";
  double x = 12;
  double result = parser(str, x);
  ck_assert_double_eq_tol(result, -8.08680992263, 1e-6);
}
END_TEST

START_TEST(test_cos) {
  char str[] = "sin(30)";
  double x = 12;
  double result = parser(str, x);
  ck_assert_double_eq_tol(result, -0.98803162409, 1e-6);
}
END_TEST

START_TEST(test_cos1) {
  char str[] = "cos(30+25)+cos(20)";
  double x = 12;
  double result = parser(str, x);
  ck_assert_double_eq_tol(result, 0.43020881807, 1e-6);
}
END_TEST

START_TEST(test_cos2) {
  char str[] = "cos(30+25)+cos(20)-2^3";
  double x = 12;
  double result = parser(str, x);
  ck_assert_double_eq_tol(result, -7.56979118192, 1e-6);
}
END_TEST

START_TEST(test_cos3) {
  char str[] = "cos(30+25)+cos(20)-2^3+20*2";
  double x = 12;
  double result = parser(str, x);
  ck_assert_double_eq_tol(result, 32.4302088181, 1e-6);
}
END_TEST

START_TEST(test_tan) {
  char str[] = "tan(45)";
  double x = 0;
  double result = parser(str, x);
  ck_assert_double_eq_tol(result, 1.61977519054, 1e-6);
}
END_TEST

START_TEST(test_atan) {
  char str[] = "atan(1)";
  double x = 0;
  double result = parser(str, x);
  ck_assert_double_eq_tol(result, 0.78539816339, 1e-6);
}
END_TEST

START_TEST(test_acos) {
  char str[] = "acos(0.5)";
  double x = 0;
  double result = parser(str, x);
  ck_assert_double_eq_tol(result, 1.0471975512, 1e-6);
}
END_TEST

START_TEST(test_asin) {
  char str[] = "asin(0.5)";
  double x = 0;
  double result = parser(str, x);
  ck_assert_double_eq_tol(result, 0.52359877559, 1e-6);
}
END_TEST

START_TEST(test_tan2) {
  char str[] = "tan(60)";
  double x = 0;
  double result = parser(str, x);
  ck_assert_double_eq_tol(result, 0.32004038938, 1e-6);
}
END_TEST

START_TEST(test_atan2) {
  char str[] = "atan(0.573)";
  double x = 0;
  double result = parser(str, x);
  ck_assert_double_eq_tol(result, 0.520329928, 1e-6);
}
END_TEST

START_TEST(test_acos2) {
  char str[] = "acos(-0.5)";
  double x = 0;
  double result = parser(str, x);
  ck_assert_double_eq_tol(result, 2.09439510239, 1e-6);
}
END_TEST

START_TEST(test_asin2) {
  char str[] = "asin(-0.86602)";
  double x = 0;
  double result = parser(str, x);
  ck_assert_double_eq_tol(result, -1.04718674, 1e-6);
}
END_TEST

START_TEST(test_not_valid_brackets) {
  char str[] = "(5+5)))";
  double x = 0;
  double result = parser(str, x);
  ck_assert_double_eq_tol(result, 1, 1e-6);
}
END_TEST

START_TEST(test_pow6) {
  char input[255] = "(-1)^2-(-1^2)";
  double result = parser(input, 0);
  ck_assert_double_eq(result, 2);
}
END_TEST

START_TEST(interactive_test) {
  char input[255] = "(15/(7-(1+1))*3-(2+(1+1-1+1*2/2))+15/(7-(1+1))*3-(2+(1+1+1-1*2/2)))";
  double result = parser(input, 0);
  ck_assert_double_eq(result, 10);
}
END_TEST

START_TEST(interactive_test1) {
  char input[255] =
      "cos(15/(7-(1+1))*3-(2+(1+1-1+1*2/2))+15/(7-(1+1))*3-(2+(1+1+1-1*2/"
      "2)))-1";
  double result = parser(input, 0);
  ck_assert_double_eq_tol(result, -1.83907152908, 1e-07);
}
END_TEST

START_TEST(interactive_test2) {
  char input[256] = "(+5.23+1.25)*(0.25+0.001)";
  double result = parser(input, 0);
  ck_assert_float_eq((5.23 + 1.25) * (0.25 + 0.001), result);
}
END_TEST

START_TEST(interactive_test3) {
  char input[256] = "sin((5.23+1.25)*(0.25+0.001))";
  double result = parser(input, 0);
  ck_assert_float_eq(sin((5.23 + 1.25) * (0.25 + 0.001)), result);
}
END_TEST

START_TEST(interactive_test4) {
  char input[256] = "cos((5.23+1.25)*(0.25+0.001))";
  double result = parser(input, 0);
  ck_assert_float_eq(cos((5.23 + 1.25) * (0.25 + 0.001)), result);
}
END_TEST

START_TEST(interactive_test5) {
  char input[256] = "tan((5.23+1.25)*(0.25+0.001))";
  double result = parser(input, 0);
  ck_assert_float_eq(tan((5.23 + 1.25) * (0.25 + 0.001)), result);
}
END_TEST

START_TEST(special_for_dima) {
  char input[256] = "dima5+cos(30)eblan+sin(35)";
  double result = parser(input, 0);
  ck_assert_float_eq(4.72606878039, result);
}
END_TEST

START_TEST(sqrt_test) {
  char input[256] = "sqrt(20)";
  double result = parser(input, 0);
  ck_assert_float_eq(4.472135955, result);
}
END_TEST

START_TEST(log_test) {
  char input[256] = "ln(20)";
  double result = parser(input, 0);
  ck_assert_float_eq(log(20), result);
}
END_TEST

START_TEST(log10_test) {
  char input[256] = "log(20)";
  double result = parser(input, 0);
  ck_assert_float_eq(log10(20), result);
}
END_TEST

START_TEST(spam) {
  char input[256] = "fdjkfjfbajbffwrittrgfy5+5+1+2+3+4+5+6+7+8+9+10";
  double result = parser(input, 0);
  ck_assert_float_eq((5 + 5 + 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 + 10), result);
}
END_TEST

START_TEST(spam2) {
  char input[256] = "fdjkfjfbajbffwrittrgfy5+5+1+2+3+4+5+6+7+8+9+10-11-23";
  double result = parser(input, 0);
  ck_assert_float_eq((5 + 5 + 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 + 10 - 11 - 23), result);
}
END_TEST

START_TEST(test_axyz) {
  char str[] = "axyz(-0.86602)";
  double x = 0;
  double result = parser(str, x);
  ck_assert_double_eq_tol(result, 0, 1e-6);
}
END_TEST

START_TEST(test_hidden_mulpi) {
  char str[] = "5(5+5)";
  double x = 0;
  double result = parser(str, x);
  ck_assert_double_eq_tol(result, 5 * (5 + 5), 1e-6);
}
END_TEST

START_TEST(test_unar) {
  char str[] = "-5(5+5)";
  double x = 0;
  double result = parser(str, x);
  ck_assert_double_eq_tol(result, -5 * (5 + 5), 1e-6);
}
END_TEST

START_TEST(test_unar2) {
  char str[] = "+5(5+5)";
  double x = 0;
  double result = parser(str, x);
  ck_assert_double_eq_tol(result, 5 * (5 + 5), 1e-6);
}
END_TEST

START_TEST(test_coz) {
  char str[] = "coz(1)";
  double x = 0;
  double result = parser(str, x);
  ck_assert_double_eq_tol(result, 1, 1e-6);
}
END_TEST

START_TEST(credit_test1) {
  Credit_params credit_param = {100, 12, 6, 0, 1};
  Credit_output credit_result = {0};
  credit_result = credit_calculator(credit_param);
  ck_assert_double_eq_tol(credit_result.min_payment, 8.375511, 1e-6);
  ck_assert_double_eq_tol(credit_result.max_payment, 8.839463, 1e-6);
}
END_TEST

START_TEST(credit_test2) {
  Credit_params credit_param = {100, 12, 6, 1, 0};
  Credit_output credit_result = {0};
  credit_result = credit_calculator(credit_param);
  ck_assert_double_eq_tol(credit_result.monthly_payment, 8.610024, 1e-6);
}
END_TEST

int main() {
  Suite *suite = suite_create("GOOD LUCK");
  TCase *tcase = tcase_create("calculator");
  SRunner *sr = srunner_create(suite);
  int result = 0;
  suite_add_tcase(suite, tcase);

  tcase_add_test(tcase, test_plus);
  tcase_add_test(tcase, test_plus2);
  tcase_add_test(tcase, test_minus);
  tcase_add_test(tcase, test_minus2);
  tcase_add_test(tcase, test_minus3);
  tcase_add_test(tcase, test_multy1);
  tcase_add_test(tcase, test_multy2);
  tcase_add_test(tcase, test_multy3);
  tcase_add_test(tcase, test_div);
  tcase_add_test(tcase, test_div2);
  tcase_add_test(tcase, test_div3);
  tcase_add_test(tcase, test_pow);
  tcase_add_test(tcase, test_pow2);
  tcase_add_test(tcase, test_pow3);
  tcase_add_test(tcase, test_pow4);
  tcase_add_test(tcase, test_pow5);
  tcase_add_test(tcase, test_mod);
  tcase_add_test(tcase, test_mod1);
  tcase_add_test(tcase, test_sin);
  tcase_add_test(tcase, test_sin2);
  tcase_add_test(tcase, test_sin3);
  tcase_add_test(tcase, test_cos);
  tcase_add_test(tcase, test_cos1);
  tcase_add_test(tcase, test_cos2);
  tcase_add_test(tcase, test_cos3);
  tcase_add_test(tcase, test_tan);
  tcase_add_test(tcase, test_atan);
  tcase_add_test(tcase, test_acos);
  tcase_add_test(tcase, test_asin);
  tcase_add_test(tcase, test_tan2);
  tcase_add_test(tcase, test_atan2);
  tcase_add_test(tcase, test_acos2);
  tcase_add_test(tcase, test_asin2);
  tcase_add_test(tcase, test_not_valid_brackets);
  tcase_add_test(tcase, test_pow6);
  tcase_add_test(tcase, interactive_test);
  tcase_add_test(tcase, interactive_test1);
  tcase_add_test(tcase, interactive_test2);
  tcase_add_test(tcase, interactive_test3);
  tcase_add_test(tcase, interactive_test4);
  tcase_add_test(tcase, interactive_test5);
  tcase_add_test(tcase, special_for_dima);
  tcase_add_test(tcase, sqrt_test);
  tcase_add_test(tcase, log_test);
  tcase_add_test(tcase, log10_test);
  tcase_add_test(tcase, spam);
  tcase_add_test(tcase, spam2);
  tcase_add_test(tcase, test_axyz);
  tcase_add_test(tcase, test_hidden_mulpi);
  tcase_add_test(tcase, test_unar);
  tcase_add_test(tcase, test_unar2);
  tcase_add_test(tcase, test_coz);
  tcase_add_test(tcase, credit_test1);
  tcase_add_test(tcase, credit_test2);
  srunner_run_all(sr, CK_VERBOSE);
  result = srunner_ntests_failed(sr);
  srunner_free(sr);

  return result == 0 ? 0 : 1;
}
