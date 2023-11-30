#include "calc_functions.h"

double calc_sharting_yard(Node* head) {
    Node* tail = NULL;
    Node* head_calculation = NULL;
    Node* tail_calculation = NULL;
    UNUSED(tail);
    double a = 0;
    double b = 0;
    double result = 0;
    double c = 0;
    Type type = 0;
    Priority priority = 0;

    while (head != NULL) {
        if (head->type == NUMBER) {
            push_right(&head_calculation, &tail_calculation, head->data, head->type, head->priority);
            head = head->next;
        } else if ((head->type >= PLUS && head->type <= MOD)) {
            pop_tail(&head_calculation, &tail_calculation, &b, &type, &priority);
            pop_tail(&head_calculation, &tail_calculation, &a, &type, &priority);
            arithmetic_calculation(&head_calculation, &tail_calculation, head, &result, &a, &b);
            head = head->next;
        } else if ((head->type >= COS && head->type <= LOG) || head->type == UNARY_MINUS) {
            pop_tail(&head_calculation, &tail_calculation, &c, &type, &priority);
            trigonometry_calculation(&head_calculation, &tail_calculation, head, &result, &c);
            head = head->next;
        }
    }

    pop_head(&head_calculation, &tail_calculation, &result, &type, &priority);
    stack_kaboom(head);
    stack_kaboom(head_calculation);

    return result;
}

void arithmetic_calculation(Node** head_calculation, Node** tail_calculation, Node* head, double* result, double* a,
                            double* b) {
    switch (head->type) {
    case PLUS:
        *result = *a + *b;
        push_right(head_calculation, tail_calculation, *result, NUMBER, NUM);
        *result = 0;
        break;
    case MINUS:
        *result = *a - *b;
        push_right(head_calculation, tail_calculation, *result, NUMBER, NUM);
        *result = 0;
        break;
    case MUL:
        *result = *a * *b;
        push_right(head_calculation, tail_calculation, *result, NUMBER, NUM);
        *result = 0;
        break;
    case DIV:
        *result = *a / *b;
        push_right(head_calculation, tail_calculation, *result, NUMBER, NUM);
        *result = 0;
        break;
    case POW:
        *result = pow(*a, *b);
        push_right(head_calculation, tail_calculation, *result, NUMBER, NUM);
        *result = 0;
        break;
    case MOD:
        *result = fmod(*a, *b);
        push_right(head_calculation, tail_calculation, *result, NUMBER, NUM);
        *result = 0;
        break;
    default:
        break;
    }
}

void trigonometry_calculation(Node** head_calculation, Node** tail_calculation, Node* head, double* result, double* c) {
    switch (head->type) {
    case UNARY_MINUS:
        *result = *c * -1;
        push_right(head_calculation, tail_calculation, *result, NUMBER, NUM);
        *result = 0;
        break;
    case SIN:
        *result = sin(*c);
        push_right(head_calculation, tail_calculation, *result, NUMBER, NUM);
        *result = 0;
        break;
    case COS:
        *result = cos(*c);
        push_right(head_calculation, tail_calculation, *result, NUMBER, NUM);
        *result = 0;
        break;
    case TAN:
        *result = tan(*c);
        push_right(head_calculation, tail_calculation, *result, NUMBER, NUM);
        *result = 0;
        break;
    case ACOS:
        *result = acos(*c);
        push_right(head_calculation, tail_calculation, *result, NUMBER, NUM);
        *result = 0;
        break;
    case ASIN:
        *result = asin(*c);
        push_right(head_calculation, tail_calculation, *result, NUMBER, NUM);
        *result = 0;
        break;
    case ATAN:
        *result = atan(*c);
        push_right(head_calculation, tail_calculation, *result, NUMBER, NUM);
        *result = 0;
        break;
    case SQRT:
        *result = sqrt(*c);
        push_right(head_calculation, tail_calculation, *result, NUMBER, NUM);
        *result = 0;
        break;
    case LN:
        *result = log(*c);
        push_right(head_calculation, tail_calculation, *result, NUMBER, NUM);
        *result = 0;
        break;
    case LOG:
        *result = log10(*c);
        push_right(head_calculation, tail_calculation, *result, NUMBER, NUM);
        *result = 0;
        break;
    default:
        break;
    }
}
