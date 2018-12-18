#include <stdlib.h>
#include <assert.h>
#include "queue.h"

typedef struct QueueNode {
    int val;
    struct QueueNode *next;
} NodeT;

typedef struct QueueRep {
    NodeT *head;
    NodeT *tail;
    int length;
} QueueRep;

queue newQueue(void) {
    queue q = malloc(sizeof(QueueRep));
    assert(q != NULL);
    q->head = NULL;
    q->tail = NULL;
    q->length = 0;
    return q;
}

void dropQueue(queue q) {
    NodeT *curr = q->head;
    NodeT *temp;
    while (curr) {
        temp = curr->next;
        free(curr);
        curr = temp;
    }
    free(q);
}

int QueueIsEmpty(queue q) {
    return q->length == 0;
}

void QueueEnqueue(queue q, int d) {
    NodeT *new = malloc(sizeof(NodeT));
    assert(new != NULL);
    new->val = d;
    new->next = NULL;
    if (!q->head) {
        q->head = q->tail = new;
    } else {
        q->tail->next = new;
        q->tail = q->tail->next;
    }
    q->length++;
}

int QueueDequeue(queue q) {
    assert(q->length > 0);
    NodeT *head = q->head;
    int d = head->val;
    q->head = head->next;
    head->next = NULL;
    free(head);
    return d;
}