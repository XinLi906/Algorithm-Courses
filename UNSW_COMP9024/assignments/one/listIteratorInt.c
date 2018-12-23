/*
  listIteratorInt.c : list Iterator ADT implementation
  Written by Xin Li
  Date: ....
*/

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "listIteratorInt.h"

#define PREV -1
#define NORM 0
#define NEXT 1

typedef struct Node {
    int val;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct IteratorIntRep {
    Node *head;
    Node *curr;
    // Node *last;
    Node *tail;
    int state;
} IteratorIntRep;

Node *NodeNew(int v) {
    Node *new = malloc(sizeof(Node));
    new->val = v;
    new->next = NULL;
    new->prev = NULL;

    return new;
}

IteratorInt IteratorIntNew(){
    IteratorIntRep *iterator = malloc(sizeof(IteratorIntRep));

    iterator->head = NULL;
    iterator->curr = NULL;
    // iterator->last = NULL;
    iterator->tail = NULL;
    iterator->state = NORM;

    return iterator;
}

void reset(IteratorInt it){
    it->curr = NULL;
    it->state = NORM;
}

int add(IteratorInt it, int v){
    Node *new = NodeNew(v);
    if (!it->head) {
        it->head = it->tail = it->curr = new;
    } else if (!it->curr) {
        it->head->prev = new;
        new->next = it->head;
        it->curr = it->head = new;
    } else if (it->curr == it->tail){
        it->curr->next = new;
        new->prev = it->tail;
        it->curr = it->tail = new;
    } else {
        it->curr->next = new;
        new->prev = it->curr;
        it->curr = new;
    }
    it->state = NORM;
    return 1;
}

int hasNext(IteratorInt it){
    if (!it->curr) {
        return it->head != NULL;
    }
    return it->curr->next != NULL;
}

int hasPrevious(IteratorInt it){
    return it->curr != NULL;
}


int *next(IteratorInt it){
    if (!hasNext(it)) {
        return NULL;
    }

    it->state = NEXT;
    it->curr = it->curr->next;

    return &(it->curr->val);
}

int *previous(IteratorInt it){
    if (!hasPrevious(it)) {
        return NULL;
    }

    it->state = PREV;
    it->curr = it->curr->prev;
    if (!it->curr) {
        return &(it->head->val);
    }
    return &(it->curr->next->val);
}

int deleteElm(IteratorInt it){
    if (it == NULL || it->state == NORM) {
        return 0;
    }

    Node *temp;
    int v;

    if (it->state == NEXT) {
        if (hasNext(it)) {
            it->curr->next->prev = it->curr->prev;
        } else {
            it->tail = it->curr->prev;
        }
        temp = it->curr;
        v = it->curr->val;
        it->curr->prev->next = it->curr->next;
        it->curr = it->curr->prev;
    } else if (!it->curr) {
        temp = it->head;
        v = it->head->val;
        it->head = it->head->next;
        it->head->prev = NULL;
    } else if (it->curr->next == it->tail) {
        temp = it->tail;
        v = it->tail->val;
        it->tail = it->tail->prev;
        it->tail->next = NULL;
    } else {
        temp = it->curr->next;
        v = it->curr->next->val;
        it->curr->next->next->prev = it->curr;
        it->curr->next = it->curr->next->next;
    }

    free(temp);
    it->state = NORM;

    return 1;
}


int set(IteratorInt it, int v){
    if (it == NULL || it->state == NORM) {
        return 0;
    }

    if (it->state == NEXT) {
        it->curr->val = v;
    } else {
        it->curr->next->val = v;
    }
    it->state = NORM;
    return 1;
}

int *findNext(IteratorInt it, int v){
    if (!it->curr) {
        it->curr = it->head;
    }
    Node *curr = it->curr->next;
    while (curr) {
        if (curr->val == v) {
            it->state = NEXT;
            it->curr = curr;
            return &it->curr->val;
        }
        curr = curr->next;
    }
    return NULL;
}

int *findPrevious(IteratorInt it, int v){
    // return NULL;
    if (!it->curr) {
        return NULL;
    }
    Node *curr = it->curr;
    while (curr) {
        if (curr->val == v) {
            it->state = PREV;
            it->curr = curr->prev;
            return &it->curr->val;
        }
        curr = curr->prev;
    }
    return NULL;
}

void freeIt(IteratorInt it){

    if (!it->head) {
        return;
    }

    Node *curr = it->head;
    Node *temp;
    while(curr) {
        temp = curr;
        curr = curr->next;
        free(temp);
    }
    free(it);
}





