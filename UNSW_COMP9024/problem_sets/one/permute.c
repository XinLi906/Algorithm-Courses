#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compar(const void *a, const void *b);
void swap(char *str, int i, int j);
void permute(char *str, int start, int end);

int main(int argc, char *argv[])
{
    char target[100] = {'\0'};

    if (argc <= 1) {
        printf("No arguments!");
        exit(1);
    }

    for (int i = 1; i < argc; i++) {
        printf("Now concat %s and %s.\n",
                strlen(target) ? target :"\"\"", argv[i]);
        strcat(target, argv[i]);
    }

    qsort(target, strlen(target), sizeof(char), compar);
    printf("After sorting, target now is %s.\n", target);

    printf("-------------------------------------\n");
    printf("|All possible permutation of %s is:|\n", target);
    printf("-------------------------------------\n");
    permute(target, 0, strlen(target));

    return 0;
}

int compar(const void *a, const void *b)
{
    return *(char *)a - *(char *)b;
}

void swap(char *str, int i, int j)
{
    char temp = str[i];
    str[i] = str[j];
    str[j] = temp;
}

void permute(char *str, int start, int end)
{
    if (start == end) {
        printf("%s\n", str);
        return;
    }

    permute(str, start + 1, end);
    for (int i = start + 1; i < end; i++) {
        if(str[start] == str[i]) {
            continue;
        }
        swap(str, start, i);
        permute(str, start + 1, end);
        swap(str, start, i);
    }
}
