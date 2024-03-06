#include "calc_functions/calc_functions.h"

int main() {
  char str[] = "2^2^3";
  double x = 12;
  double result = 0;

  result = parser(str, x);

  printf("Result in main is -> %lf\n", result);

  return 0;
}