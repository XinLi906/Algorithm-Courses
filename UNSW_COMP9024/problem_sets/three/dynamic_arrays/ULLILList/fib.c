#include <stdio.h>
#include <stdlib.h>
#include "ULLILList.h"

ull fibs(int);

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]);
    fprintf(stdout, "%lld", fibs(n));

    return 0;
}

ull fibs(int n) {
    ULLILList L = NewULLILList();
    ULLILListPush(L, 1);
    ULLILListPush(L, 1);

    int i;
    for (i = 0; i < n - 2; i++) {
        ull d = L->first->val + L->first->next->val;
        // ull d = 0;
        // fprintf(stdout, "%lld", L->first->val);
        ULLILListPush(L, d);
    }

    return ULLILListPop(L);
}