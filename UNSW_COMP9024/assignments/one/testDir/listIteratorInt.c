/*
  listIteratorInt.c : A naive list Iterator ADT implementation
  Written by Xin Li
  Date: ....
*/
#include <stdlib.h>
#include <assert.h>
#include "listIteratorInt.h"

typedef enum IterStates {
    NORM, NEXT, PREV
} IterStates;

typedef struct NodeRep {
    int val;
    struct NodeRep *next, *prev;
} NodeT;

typedef struct IteratorIntRep {
    NodeT *curr;
    NodeT *head;
    IterStates state;
} IterT;

NodeT *NodeNew(int v) {
    NodeT *new = malloc(sizeof(NodeT));
    assert(new != NULL);
    new->val = v;
    new->next = new->prev = NULL;
    return new;
}

IteratorInt IteratorIntNew() {
    IterT *it = malloc(sizeof(IterT));
    assert(it != NULL);
    it->curr = it->head = NULL;
    it->state = NORM;
    return it;
}

int add(IteratorInt it, int v) {
    NodeT *new = NodeNew(v);
    it->state = NORM;
    if (!it->head) {
        it->head = it->curr = new;
        return 1;
    }
    if (!it->curr) {
        it->curr = new;
        it->curr->next = it->head;
        it->head->prev = it->curr;
        return 1;
    }
    if (it->curr->next) {
        it->curr->next->prev = new;
        new->next = it->curr->next;
    }
    it->curr->next = new;
    new->prev = it->curr;
    it->curr = it->curr->next;
    return 1;
}

int hasNext(IteratorInt it) {
    return it->curr->next != NULL;
}

int hasPrevious(IteratorInt it) {
    return it->curr != NULL;
}

int *next(IteratorInt it) {
    if (!hasNext(it)) {
        it->state = NORM;
        return NULL;
    }
    if (!it->curr) {
        it->curr = it->head;
    } else {
        it->curr = it->curr->next;
    }
    it->state = NEXT;
    return &(it->curr->val);
}

int *previous(IteratorInt it) {
    if (!hasPrevious(it)) {
        it->state = NORM;
        return NULL;
    }
    int *temp = &(it->curr->val);
    it->curr = it->curr->prev;
    it->state = PREV;
    return temp;
}

int deleteElm(IteratorInt it) {
    if (it->state == NORM) {
        return 0;
    }
    NodeT *temp;
    if (it->state == NEXT) {
        if (!it->curr->next) {
            temp = it->curr;
            it->curr = it->curr->prev;
        } else {
            temp = it->curr;
            it->curr = it->curr->prev;
            temp->next->prev = temp->prev;
            temp->prev->next = temp->next;
        }
    } else {
        if (!it->curr) {
            temp = it->head;
            it->head = it->head->next;
        } else {
            temp = it->curr->next;
            it->curr->next = temp->next;
            temp->next->prev = it->curr;
        }
    }
    free(temp);
    it->state = NORM;
    return 1;
}

int set(IteratorInt it, int v) {
    if (it->state == NORM) {
        return 0;
    }
    if (it->state == NEXT) {
        it->curr->val = v;
    } else if (it->state == PREV && it->curr) {
        it->curr->next->val = v;
    } else {
        it->head->val = v;
    }
    it->state = NORM;
    return 1;
}

int *findNext(IteratorInt it, int v) {
    return &(it->curr->val);
}

int *findPrevious(IteratorInt it, int v) {
    return &(it->curr->val);

}

void reset(IteratorInt it) {
    it->curr = NULL;
    it->state = NORM;
}

void freeIt(IteratorInt it) {
    NodeT *curr = it->head;
    NodeT *temp;
    while(curr) {
        temp = curr;
        curr = curr->next;
        free(temp);
    }
    free(it);
}