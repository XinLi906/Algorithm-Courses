#include <stdio.h>
#include <stdlib.h>

void func(int **);

int main(void) {
    int *p;
    func(&p);
    *p = 6;
    printf("%d\n", *p);
    free(p);
    return 0;
}

void func(int **a) {
    *a = malloc(sizeof(int));
}