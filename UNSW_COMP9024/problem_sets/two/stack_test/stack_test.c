#include <stdio.h>
#include "stack.h"

int main(int argc, char *argv)
{
    int n, num;
    printf("Enter a positive number: ");
    scanf("%d", &n);

    StackInit();
    while (n--) {
        printf("Enter a number: ");
        scanf("%d", &num);
        StackPush(num);
    }

    while (!StackIsEmpty()) {
        printf("%d\n", StackPop());
    }

    return 0;
}

