#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

int main(int argc, char *argv[])
{
    StackInit();

    for (int i = 1; i < argc; i++) {
        int num = atoi(argv[i]);
        StackPush(num);
    }

    while (!StackIsEmpty()) {
        printf("%d\n", StackPop());
    }

    return 0;
}

