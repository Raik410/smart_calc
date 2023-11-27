#include "calc_functions.h"

int check_valid_brackets(char* expression_str) {
    Node* head = NULL;
    Node* tail = NULL;
    double num = 0;
    Type type = 0;
    Priority priority = 0;

    for (; *expression_str; expression_str++) {
        if (*expression_str == '(') {
            push_left(&head, &tail, 0, type, priority);
        } else if (*expression_str == ')') {
            if (isEmpty(head)) {
                free(head);
                return FAILED;
            }
            pop_head(&head, &tail, &num, &type, &priority);
        }
    }

    int result = isEmpty(head) ? OK : FAILED;

    stack_kaboom(head);

    return result;
}
