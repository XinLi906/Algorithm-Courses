#include <stdio.h>

#define ZERO 48

int main(int argc, char *argv[])
{
    int a = *argv[1], b = *argv[2], c = *argv[3];
    printf("a is %d, b is %d, c is %d.\n", a, b, c);
    int e = (a * (a / b) + b * (b / a)) - ZERO;
    int f = (b * (b / c) + c * (c / b)) - ZERO;
    printf("e is %d, f  is %d\n", e, f);
    int max = (e * (e / f) + f * (f / e));
    printf("max is %d.\n", max);

    return 0;
}
