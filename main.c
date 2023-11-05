#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ITERATIONS 1000

int main() {
    int n;
    double eps;
    printf("Enter order of matrix: ");
    scanf("%d", &n);
    double A[n][n], B[n], X[n], X_old[n], error;
    printf("Enter matrix A:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &A[i][j]);
        }
    }
    printf("Enter matrix B:\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf", &B[i]);
    }
    printf("Enter error tolerance: ");
    scanf("%lf", &eps);
    int iterations = 0;
    do {
        error = 0;
        for (int i = 0; i < n; i++) {
            X_old[i] = X[i];
            double sum = B[i];
            for (int j = 0; j < n; j++) {
                if (j != i) {
                    sum -= A[i][j] * X[j];
                }
            }
            X[i] = sum / A[i][i];
            error += fabs(X[i] - X_old[i]);
        }
        iterations++;
    } while (error > eps && iterations < MAX_ITERATIONS);
    if (iterations == MAX_ITERATIONS) {
        printf("Maximum number of iterations reached.\n");
    } else {
        printf("Solution:\n");
        for (int i = 0; i < n; i++) {
            printf("X[%d] = %lf\n", i + 1, X[i]);
        }
        printf("Number of iterations: %d\n", iterations);
    }
    return 0;
}
