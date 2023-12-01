#ifndef PARSER
#define PARSER

#ifdef __cplusplus
extern "C"{
#endif
#include <locale.h>
#include <stdbool.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define UNUSED(x) (void)(x)

typedef enum {
  BRACKET = 0,
  NUM = 1,
  LOW = 10,
  MID = 100,
  UNARY = 99,
  HIGH = 1000,
} Priority;

typedef enum {
  NUMBER = 1,
  X = 2,
  PLUS = 3,
  MINUS = 4,
  MUL = 5,
  DIV = 6,
  POW = 7,
  MOD = 8,
  COS = 9,
  SIN = 10,
  TAN = 11,
  ACOS = 12,
  ASIN = 13,
  ATAN = 14,
  SQRT = 15,
  LN = 16,
  LOG = 17,
  UNARY_MINUS = 18,
  LEFT_BRACKET = 19,
  RIGHT_BRACKET = 20,
} Type;

typedef struct {
    double sum_credit;
    int term_credit;
    int interest_rate;
    bool annuity;
    bool differentiated;
} Credit_params;

typedef struct {
    double monthly_payment;
    double overpayment;
    double total_payout;
    double min_payment;
    double max_payment;
} Credit_output;

typedef enum {
  OK = 0,
  FAILED = 1,
  MEMORY_FAILED_ALLOCATED = 2,
} Output;

typedef struct Node {
  double data;
  Type type;
  Priority priority;

  struct Node* next;
  struct Node* prev;
} Node;

Node* push_left(Node** head, Node** tail, double data, Type type, Priority priority);
Node* push_right(Node** head, Node** tail, double data, Type type, Priority priority);
Node* pop_head(Node** head, Node** tail, double* data, Type* type, Priority* priority);
Node* pop_tail(Node** head, Node** tail, double* data, Type* type, Priority* priority);
Node* peek_left(Node* head, double* data, Type* type, Priority* priority);
Node* peek_right(Node* tail, double* data, Type* type, Priority* priority);
void BimBimBamBamStack(Node* head);
void printStack(Node* head, Node* tail);
int isEmpty(Node* head);
void stack_kaboom_backward(Node* last);
void stack_kaboom_forward(Node* first);
void stack_kaboom(Node* any);
double parser(char* expression_str, double x_value);
double convert_string_num_to_num(char* string_num, bool* num_found, int* index);
int length_of_double(double number);
void append_number(char* expression_str, int* i, double* value, int* token);
Node* sharting_yard(Node* head, Node* tail);
double calc_sharting_yard(Node* head);
void arithmetic_calculation(Node** head_calculation, Node** tail_calculation, Node* head, double* result, double* a,
    double* b);
void trigonometry_calculation(Node** head_calculation, Node** tail_calculation, Node* head, double* result, double* c);
void parse_trigonometry(Node** head, Node** tail, char* expression_str, int* i);
void parse_arithmetic(Node** head, Node** tail, char* expression_str, int* i, double* x_value);
bool all_arithmetic_operation(Node* tail);
bool all_trigonometry_operation(Node* tail);
int check_valid_brackets(char* expression_str);
Credit_output credit_calculator(Credit_params credit_params);
#ifdef __cplusplus
}
#endif
#endif
