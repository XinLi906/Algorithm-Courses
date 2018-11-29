#include <stdio.h>

float innerProduct(float a[], float b[], int n);

int main(int argc, char *argv[]) {
    int n;
    scanf("%d", &n);
    float v1[n], v2[n];


    for (int i = 0; i < n; ++i){
        scanf("%f", &v1[i]);
    }
    for (int i = 0; i < n; ++i){
        scanf("%f", &v2[i]);
    }

    printf("The inner product of v1 and v2 is %f.\n",
            innerProduct(v1, v2, n));
    return 0;
}

float innerProduct(float a[], float b[], int n)
{
    float res = 0;
    for (int i = 0; i < n; ++i) {
        res += a[i] * b[i];
    }

    return res;
}
