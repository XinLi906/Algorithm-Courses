#include <stdio.h>
#include <stdlib.h>

int *makeArrayOfInts(void);

int main() {
    int *arr = makeArrayOfInts();
    int i;
    for (i = 0; i < 10; i++) {
        fprintf(stdout, "%d ", arr[i]);
    }
    free(arr);
    return 0;
}

int *makeArrayOfInts(void) {
    int *arr = malloc(10 * sizeof(int));
    int i;
    for (i = 0; i < 10; i++) {
        arr[i] = i;
    }
    return arr;
}