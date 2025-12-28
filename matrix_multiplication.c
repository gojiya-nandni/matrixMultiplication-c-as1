#include <stdio.h>

/* Function to input matrix elements */
void inputMatrix(int matrix[10][10], int rows, int cols, char name) {
    int i, j;
    printf("\nEnter elements of Matrix %c:\n", name);
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("Matrix %c [%d][%d] = ", name, i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

/* Function to display matrix */
void displayMatrix(int matrix[10][10], int rows, int cols, char name) {
    int i, j;
    printf("\nMatrix %c:\n", name);
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%5d", matrix[i][j]);
        }
        printf("\n");
    }
}

/* Function to multiply two matrices */
void multiplyMatrix(
    int a[10][10], int b[10][10], int result[10][10],
    int r1, int c1, int c2
) {
    int i, j, k;

    // Initializing result matrix to 0
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
            result[i][j] = 0;
        }
    }

    // Matrix multiplication logic
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
            for (k = 0; k < c1; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main() {
    int matrixA[10][10], matrixB[10][10], result[10][10];
    int r1, c1, r2, c2;

    printf("===== MATRIX MULTIPLICATION PROGRAM =====\n");

    /* Taking matrix sizes */
    printf("\nEnter rows and columns of Matrix A: ");
    scanf("%d %d", &r1, &c1);

    printf("Enter rows and columns of Matrix B: ");
    scanf("%d %d", &r2, &c2);

    /* Validation for matrix multiplication */
    if (c1 != r2) {
        printf("\nMatrix multiplication not possible!");
        printf("\nColumns of Matrix A must equal rows of Matrix B.\n");
        return 0;
    }

    /* Input matrices */
    inputMatrix(matrixA, r1, c1, 'A');
    inputMatrix(matrixB, r2, c2, 'B');

    /* Display input matrices */
    displayMatrix(matrixA, r1, c1, 'A');
    displayMatrix(matrixB, r2, c2, 'B');

    /* Multiply matrices */
    multiplyMatrix(matrixA, matrixB, result, r1, c1, c2);

    /* Display result */
    displayMatrix(result, r1, c2, 'R');

    printf("\n Matrix multiplication completed successfully!\n");
    return 0;
}
