#include <stdio.h>

int main(int argc, char *argv[])
{
    int i = 0;
    char *target = argv[1];

    while (target[i++] != '\0');

    while(--i > 0) {
        target[i] = '\0';
        printf("%s\n", target);
    }

    return 0;
}
