#include "calc_functions.h"

Node *push_left(Node **head, Node **tail, double data, Type type, Priority priority) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  if (newNode == NULL) {
    return NULL;
  }
  newNode->data = data;
  newNode->priority = priority;
  newNode->type = type;
  newNode->next = *head;
  newNode->prev = NULL;

  if (*head != NULL) {
    (*head)->prev = newNode;
  } else {
    *tail = newNode;  // Обновление tail, если список был пуст
  }

  *head = newNode;  // Обновление head
  return newNode;
}

Node *push_right(Node **head, Node **tail, double data, Type type, Priority priority) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  if (newNode == NULL) {
    return NULL;
  }
  newNode->data = data;
  newNode->priority = priority;
  newNode->type = type;
  newNode->next = NULL;
  newNode->prev = *tail;

  if (*tail != NULL) {
    (*tail)->next = newNode;
  } else {
    *head = newNode;  // Обновление head, если список был пуст
  }

  *tail = newNode;  // Обновление tail
  return newNode;
}

Node *pop_head(Node **head, Node **tail, double *data, Type *type, Priority *priority) {
  if (*head == NULL) {
    return NULL;
  }

  Node *temp = *head;
  *data = temp->data;
  *type = temp->type;
  *priority = temp->priority;
  *head = temp->next;

  if (*head != NULL) {
    (*head)->prev = NULL;
  } else {
    *tail = NULL;  // Обновление tail, если это был последний узел
  }

  free(temp);
  return *head;
}

Node *pop_tail(Node **head, Node **tail, double *data, Type *type, Priority *priority) {
  if (*tail == NULL) {
    return NULL;
  }

  Node *temp = *tail;
  *data = temp->data;
  *type = temp->type;
  *priority = temp->priority;
  *tail = temp->prev;

  if (*tail != NULL) {
    (*tail)->next = NULL;
  } else {
    *head = NULL;  // Обновление head, если это был последний узел
  }

  free(temp);
  return *head;
}

Node *peek_left(Node *head, double *data, Type *type, Priority *priority) {
  if (head == NULL) {
    printf("Peek left: empty node head");
    return NULL;
  }

  *type = head->type;
  *priority = head->priority;
  *data = head->data;
  return head;
}

Node *peek_right(Node *tail, double *data, Type *type, Priority *priority) {
  if (tail == NULL) {
    printf("Peek right: empty node head");
    return NULL;
  }

  *data = tail->data;
  *priority = tail->priority;
  *type = tail->type;
  return tail;
}

void BimBimBamBamStack(Node *head) {
  if (head == NULL) return;
  if (head->next) BimBimBamBamStack(head->next);
  free(head);
}

const char *TypeStrings[] = {"", "NUMBER", "X", "PLUS", "MINUS", "MUL", "DIV", "POW", "MOD", "COS", "SIN", "TAN",
    "ACOS", "ASIN", "ATAN", "SQRT", "LN", "LOG", "UNARY_MINUS", "LEFT_BRACKET", "RIGHT_BRACKET"};

void printStack(Node *head, Node *tail) {
  Node *current_head = head;
  Node *current_tail = tail;
  printf("---------------\n");
  printf("Node head is %p\n", (void *)head);
  printf("Node tail is %p\n\n", (void *)tail);

  printf("Node data head is -> %lf Type is -> %s Priority is -> %d \n", head->data, TypeStrings[current_head->type],
      current_head->priority);
  printf("Node data tail is -> %lf Type is -> %s Priority is -> %d \n\n", tail->data, TypeStrings[current_tail->type],
      current_tail->priority);

  while (current_head != NULL) {
    printf("Data is -> %lf | Type is -> %s | Priority is -> %d\n", current_head->data, TypeStrings[current_head->type],
        current_head->priority);
    current_head = current_head->next;
  }

  printf("\n");
  printf("---------------\n");
}

int isEmpty(Node *head) { return head == NULL; }

void stack_kaboom_backward(Node *last) {
  if (!last) return;
  if (last->prev) stack_kaboom_backward(last->prev);
  free(last);
}

void stack_kaboom_forward(Node *first) {
  if (!first) return;
  if (first->next) stack_kaboom_forward(first->next);
  free(first);
}

void stack_kaboom(Node *any) {
  if (!any) return;
  if (any->prev) stack_kaboom_backward(any->prev);
  if (any->next) stack_kaboom_forward(any->next);
  free(any);
}
