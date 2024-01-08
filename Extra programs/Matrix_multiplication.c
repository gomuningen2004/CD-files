#include <stdio.h>

void multiplyMatrices(int firstMatrix[10][10], int secondMatrix[10][10], int result[10][10], int rows, int cols, int cols2) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols2; ++j) {
            result[i][j] = 0;
        }
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols2; ++j) {
            for (int k = 0; k < cols; ++k) {
                result[i][j] += firstMatrix[i][k] * secondMatrix[k][j];
            }
        }
    }
}

void inputMatrix(int matrix[10][10], int rows, int cols) {
    printf("Enter matrix elements:\n");
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void displayMatrix(int matrix[10][10], int rows, int cols) {
    printf("Matrix:\n");
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int firstMatrix[10][10], secondMatrix[10][10], result[10][10];
    int rows1, cols1, rows2, cols2;

    printf("Enter the number of rows and columns for the first matrix: ");
    scanf("%d %d", &rows1, &cols1);

    printf("Enter the number of rows and columns for the second matrix: ");
    scanf("%d %d", &rows2, &cols2);

    if (cols1 != rows2) {
        printf("Matrix multiplication is not possible.\n");
        return 0;
    }

    printf("Enter elements for the first matrix:\n");
    inputMatrix(firstMatrix, rows1, cols1);

    printf("Enter elements for the second matrix:\n");
    inputMatrix(secondMatrix, rows2, cols2);

    multiplyMatrices(firstMatrix, secondMatrix, result, rows1, cols1, cols2);

    printf("Result of matrix multiplication:\n");
    displayMatrix(result, rows1, cols2);

    return 0;
}
