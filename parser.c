#include "calc_functions.h"

double parser(char *expression_str, double x_value) {
    setlocale(LC_NUMERIC, "C");
    if (check_valid_brackets(expression_str)) {
        printf("Use valid brackets.\n");
        return FAILED;
    }
    int expression_str_length = strlen(expression_str);
    int i = 0;
    Node *head = NULL;
    Node *tail = NULL;
    double result = 0;

    for (i = 0; i <= expression_str_length; i++) {
        parse_arithmetic(&head, &tail, expression_str, &i, &x_value);
        parse_trigonometry(&head, &tail, expression_str, &i);
    }

    printStack(head, tail);
    head = sharting_yard(head, tail);
    result = calc_sharting_yard(head);

    stack_kaboom(head);

    return result;
}

void parse_arithmetic(Node **head, Node **tail, char *expression_str, int *i, double *x_value) {
    double value = 0;
    int token = 0;

    switch (expression_str[*i]) {
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
        append_number(expression_str, i, &value, &token);
        push_left(head, tail, value, NUMBER, NUM);
        if (expression_str[*i + 1] == '(') push_left(head, tail, value, MUL, HIGH);
        break;
    case '+':
        if (*i == 0 || expression_str[*i - 1] == '(' || strchr("+-*/^%", expression_str[*i - 1])) {
            return;
        }
        push_left(head, tail, 0, PLUS, LOW);
        break;
    case '-':
        if (*i == 0 || expression_str[*i - 1] == '(' || strchr("+-*/^% ", expression_str[*i - 1])) {
            push_left(head, tail, 0, UNARY_MINUS, UNARY);
        } else {
            push_left(head, tail, 0, MINUS, LOW);
        }
        break;
    case '*':
        push_left(head, tail, 0, MUL, MID);
        break;
    case '/':
        push_left(head, tail, 0, DIV, MID);
        break;
    case '(':
        push_left(head, tail, 0, LEFT_BRACKET, BRACKET);
        break;
    case ')':
        push_left(head, tail, 0, RIGHT_BRACKET, BRACKET);
        break;
    case '%':
        push_left(head, tail, 0, MOD, HIGH);
        break;
    case '^':
        push_left(head, tail, 0, POW, HIGH);
        break;
    case 'x':
        push_left(head, tail, *x_value, NUMBER, NUM);
        break;
    default:
        break;
    }
}

void parse_trigonometry(Node **head, Node **tail, char *expression_str, int *i) {
    switch (expression_str[*i]) {
    case 's':
        if (expression_str[*i + 1] == 'i' && expression_str[*i + 2] == 'n') {
            push_left(head, tail, 0, SIN, HIGH);
            *i += 2;
        } else if (expression_str[*i + 1] == 'q' && expression_str[*i + 2] == 'r' && expression_str[*i + 3] == 't') {
            push_left(head, tail, 0, SQRT, HIGH);
            *i += 3;
        }
        break;
    case 'c':
        if (expression_str[*i + 1] == 'o' && expression_str[*i + 2] == 's') {
            push_left(head, tail, 0, COS, HIGH);
            *i += 2;
        }
        break;
    case 't':
        if (expression_str[*i + 1] == 'a' && expression_str[*i + 2] == 'n') {
            push_left(head, tail, 0, TAN, HIGH);
            *i += 2;
        }
        break;
    case 'a':
        if (expression_str[*i + 1] == 'c' && expression_str[*i + 2] == 'o' && expression_str[*i + 3] == 's') {
            push_left(head, tail, 0, ACOS, HIGH);
            *i += 3;
        } else if (expression_str[*i + 1] == 't' && expression_str[*i + 2] == 'a' && expression_str[*i + 3] == 'n') {
            push_left(head, tail, 0, ATAN, HIGH);
            *i += 3;
        } else if (expression_str[*i + 1] == 's' && expression_str[*i + 2] == 'i' && expression_str[*i + 3] == 'n') {
            push_left(head, tail, 0, ASIN, HIGH);
            *i += 3;
        }
        break;
    case 'l':
        if (expression_str[*i + 1] == 'n') {
            push_left(head, tail, 0, LN, HIGH);
            *i += 1;
        } else if (expression_str[*i + 1] == 'o' && expression_str[*i + 2] == 'g') {
            push_left(head, tail, 0, LOG, HIGH);
            *i += 2;
        }
    default:
        break;
    }
}

void append_number(char *expression_str, int *i, double *value, int *token) {
    setlocale(LC_NUMERIC, "C");
    char c = 'z';
    int scanf = 0;
    scanf = sscanf(expression_str + *i, "%lf%c", value, &c);
    *token = (strchr("+-^*%/() ", c) || scanf == 1) ? 1 : 0;
    if (!(*token)) return;
    *i += length_of_double(*value);
    *token = 0;
}

int length_of_double(double number) {
    setlocale(LC_NUMERIC, "C");
    char buffer[50];
    sprintf(buffer, "%lf", number);

    int length = strlen(buffer);
    while (length > 0 && (buffer[length - 1] == '0' || buffer[length - 1] == '.' || buffer[length - 1] == ',')) {
        if (buffer[length - 1] == ',' || buffer[length - 1] == '.') {
            buffer[length - 1] = '\0';
            break;
        }
        buffer[--length] = '\0';
    }

    return strlen(buffer) - 1;
}
