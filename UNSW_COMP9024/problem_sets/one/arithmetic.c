#include <stdio.h>

int reveres(int);

int main(int argc, char *argv[])
{
    for(int i = 1000; i < 2500; ++i) {
        if(4 * i == reveres(i)) {
            printf("4 * %d = %d\n", i, 4 * i);
        }
    }

    return 0;
}

int reveres(int anum)
{
    int rev = 0;
    int last_digit;
    while(anum) {
        last_digit = anum % 10;
        rev = rev * 10 + last_digit;
        anum /= 10;
    }

    return rev;
}
