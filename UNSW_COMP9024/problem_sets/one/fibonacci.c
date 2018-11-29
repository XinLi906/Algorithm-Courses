#include <stdio.h>

#define MAX_LENGTH 11

void rec_print(int n){
    printf("%d\n", n);
    if (n == 1) {
        return;
    } else if (!(n % 2)) {
        rec_print(n / 2);
    } else {
        rec_print(3 * n + 1);
    }
}

int main(int argc, char *argv)
{
    int fibs[MAX_LENGTH] = {1, 1};
    for (int i = 2; i < MAX_LENGTH; i++) {
        fibs[i] = fibs[i - 1] + fibs[i - 2];
    }

    for (int i = 0; i < MAX_LENGTH; i++) {
        printf("Fib[%d] = %d\n", i, fibs[i]);
        rec_print(fibs[i]);
    }

    return 1;
}
