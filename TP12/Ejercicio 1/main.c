#include <stdlib.h>
#include <stdio.h>

double *eye(unsigned int n);
void free_eye(double *matrix);
void print_matrix(double *matrix, unsigned int n);

int main()
{
    unsigned int n = 5;
    double *matrix = eye(n);
    print_matrix(matrix, n);
    free_eye(matrix);

    return 0;
}

double *eye(unsigned int n)
{
    double *matrix = (double *)malloc(n * n * sizeof(double));
    if (matrix == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    for (unsigned int i = 0; i < n; i++) {
        for (unsigned int j = 0; j < n; j++) {
            matrix[i * n + j] = (i == j) ? 1.0 : 0.0;
        }
    }

    return matrix;
}

void free_eye(double *matrix)
{
    free(matrix);
}

void print_matrix(double *matrix, unsigned int n)
{
    for (unsigned int i = 0; i < n; i++) {
        for (unsigned int j = 0; j < n; j++) {
            printf("%lf ", matrix[i * n + j]);
        }
        printf("\n");
    }
}