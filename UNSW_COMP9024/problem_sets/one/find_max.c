#include <stdio.h>
#include <stdlib.h>

int find_max(int a, int b, int c);

int main(int argc, char *argv[])
{
    if (argc != 4) {
        printf("Not enough arguments!");
        exit(1);
    }

    int a = atoi(argv[1]), b = atoi(argv[2])
        , c = atoi(argv[3]);

    printf("The maximum element among %d, %d and %d is %d.\n",
            a, b, c, find_max(a, b, c));

    return 0;
}

int find_max(int a, int b, int c)
{
    int t = a;
    (t < b) && (t = b);
    (t < c) && (t = c);
    return t;
}

