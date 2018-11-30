#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

#define BASE 2

int main(int argc, char *argv[])
{
    StackInit();

    int num = atoi(argv[1]);

    while (num) {
        StackPush(num % BASE);
        num /= BASE;
    }

    printf("Result: ");
    while (!StackIsEmpty()) {
        printf("%d", StackPop());
    }

    putchar('\n');

    return 0;
}
