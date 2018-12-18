#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "linkedlist.h"

struct LinkedListNode {
    int value;
    struct LinkedListNode *next;
};

NodeT *makeNode(int value) {
    NodeT *new = malloc(sizeof(NodeT));
    assert(new != NULL);
    new->value = value;
    new->next = NULL;
    return new;
}

void freeLL(NodeT *head) {
    NodeT *curr = head;
    NodeT *temp;
    while (curr != NULL) {
        temp = curr->next;
        free(curr);
        curr = temp;
    }
}

void showLL(NodeT *head) {
    NodeT *curr = head;
    while(curr) {
        fprintf(stdout, "%d ", curr->value);
        curr = curr->next;
    }
    putchar('\n');
}

NodeT *joinLL(NodeT *head1, NodeT *head2) {
    NodeT *curr = head1;
    if (!head1) {
        return head2;
    }
    if (head2) {
        while (curr->next) {
            curr = curr->next;
        }
        curr->next = head2;
    }
    return head1;
}

NodeT *splitLL(NodeT *head) {
    assert(head != NULL);

    NodeT *slow = head;
    NodeT *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    NodeT *head2 = slow->next;
    slow->next = NULL:
    return head2;
}