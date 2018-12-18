#include <stdlib.h>
#include <assert.h>
#include "ULLILList.h"

ULLILList NewULLILList() {
    ULLILList L = malloc(sizeof(ULLILListRep));
    L->first = NULL;
    L->length = 0;
    return L;
}

void DropULLILList(ULLILList L) {
    NodeT *curr = L->first;
    NodeT *temp;
    while (curr) {
        temp = curr->next;
        free(curr);
        curr = temp;
    }
    free(L);
}

int ULLILListIsEmpty(ULLILList L) {
    return L->length == 0;
}

void ULLILListPush(ULLILList L, ull d) {
    NodeT *new = malloc(sizeof(NodeT));
    assert(new != NULL);
    new->val = d;
    new->next = L->first;
    L->first = new;
    L->length++;
}

ull ULLILListPop(ULLILList L) {
    assert(L->length > 0);
    ull d = L->first->val;
    L->length--;
    NodeT *temp = L->first;
    L->first = L->first->next;
    free(temp);
    return d;
}