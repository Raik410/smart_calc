#include "calc_functions.h"

Node *sharting_yard(Node *head, Node *tail) {
  Node *head_support = NULL;
  Node *tail_support = NULL;
  UNUSED(head);
  Node *head_output = NULL;
  Node *tail_output = NULL;
  double data = 0;
  Type type = 0;
  Priority priority = 0;

  while (tail != NULL) {
    if (tail->type == NUMBER) {
      push_right(&head_output, &tail_output, tail->data, tail->type, tail->priority);
      tail = tail->prev;
    } else if ((tail->type == LEFT_BRACKET) || (all_trigonometry_operation(tail))) {
      push_right(&head_support, &tail_support, tail->data, tail->type, tail->priority);
      tail = tail->prev;
    } else if (all_arithmetic_operation(tail)) {
      while ((tail_support != NULL && tail->priority <= tail_support->priority) && tail->type != POW) {
        push_right(&head_output, &tail_output, tail_support->data, tail_support->type, tail_support->priority);
        pop_tail(&head_support, &tail_support, &data, &type, &priority);
      }
      push_right(&head_support, &tail_support, tail->data, tail->type, tail->priority);
      tail = tail->prev;
    } else if (tail->type == RIGHT_BRACKET) {
      while (tail_support->type != LEFT_BRACKET) {
        if (all_arithmetic_operation(tail_support)) {
          push_right(&head_output, &tail_output, tail_support->data, tail_support->type, tail_support->priority);
          pop_tail(&head_support, &tail_support, &data, &type, &priority);
        }
      }
      pop_tail(&head_support, &tail_support, &data, &type, &priority);  // delete open bracket
      if (tail_support != NULL && all_trigonometry_operation(tail)) {
        push_right(&head_output, &tail_output, tail_support->data, tail_support->type, tail_support->priority);
        pop_tail(&head_support, &tail_support, &data, &type, &priority);
      }
      tail = tail->prev;
    }
  }

  while (tail_support != NULL) {
    push_right(&head_output, &tail_output, tail_support->data, tail_support->type, tail_support->priority);
    pop_tail(&head_support, &tail_support, &data, &type, &priority);
  }
  printStack(head_output, tail_output);
  stack_kaboom(head);
  stack_kaboom(head_support);

  return head_output;
}

bool all_arithmetic_operation(Node *tail) {
  return ((tail->type >= PLUS && tail->type <= MOD) || (tail->type == UNARY_MINUS));
}

bool all_trigonometry_operation(Node *tail) { return (tail->type >= COS && tail->type <= LOG); }