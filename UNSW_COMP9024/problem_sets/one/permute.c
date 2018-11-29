#include <stdio.h>

void permute();

int main(void)
{
    permute();

    return 1;
}

void permute(char *arr, n)
{
    if n <= 1 {
        return arr;
    }

    n--;
    for (int i = 0; i < n; i++) {
        return permute(arr, n);
        if length % 2 {
            temp = arr[i];
            arr[i] = arr[n];
            arr[n] = temp;
        } else {
            temp = arr[0];
            arr[0] = arr[n];
            arr[n] = temp;
        }
    }
    return permute(arr, n);
}
