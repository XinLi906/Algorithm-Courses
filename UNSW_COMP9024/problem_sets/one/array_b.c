#include <stdio.h>

void matrixProduct(float a[][], float b[][], float c[][]);

int main()
{
    return 0;
}

void matrixProduct(float a[M][N], float b[N][P], float c[M][P])
{
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < P; ++j) {
            c[i][j] = 0;
            for (int k = 0; k < N; ++k) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}
