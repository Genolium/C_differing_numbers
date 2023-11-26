#include <stdio.h>
#include <windows.h>
#include "lib/matrixlib.h"
#include "lib/staticlib.h"

int findAverageInMatrix(void*, int, int);
int findDifferingNumbers(void*, int, int, int, int);

int main() {
    SetConsoleOutputCP(CP_UTF8); // Установить кодировку UTF-8 для консоли
    int rowsInMatrix = 2, colsInMatrix = 2, sizeOfM = 2;

    int** intMatrix = (int**)allocate_matrix(rowsInMatrix, colsInMatrix, sizeof(int));

    input_int_matrix(intMatrix, rowsInMatrix, colsInMatrix);

    int M[sizeOfM];
    inputIntArray(M, sizeOfM);

    int averageMatrix = findAverageInMatrix((void *)intMatrix, rowsInMatrix, colsInMatrix);
    int averageArr = findAverageInMatrix(M, 1, sizeOfM);

    printf("Количество элементов матрицы, отличающихся от среднего "
           "арифметического значения элементов массива более чем вдвое: %d\n",
           findDifferingNumbers((void *)intMatrix,rowsInMatrix, colsInMatrix,averageArr,2));

    printf("Количество элементов массива, отличающихся от среднего арифметического значения "
           "матрицы более, чем втрое: %d\n",
           findDifferingNumbers(M,1, sizeOfM,averageMatrix,3));


    deallocate_matrix(intMatrix, rowsInMatrix);
    return 0;
}

int findAverageInMatrix(void *matrix, int rows, int cols) {
    int sum = 0, count = 0;
    if (rows == 1) {
        // Одномерный массив
        int *array = (int *)matrix;
        for (int i = 0; i < cols; i++) {
            sum += array[i];
            count++;
        }
    } else {
        // Двумерная матрица
        int **matrixData = (int **)matrix;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                sum += matrixData[i][j];
                count++;
            }
        }
    }

    return sum / count;
}
int findDifferingNumbers(void *matrix, int rows, int cols, int number, int times) {
    int count = 0;

    if (rows == 1) {
        // Одномерный массив
        int *array = (int *)matrix;
        for (int i = 0; i < cols; i++) {
            int element = array[i];
            if ((double)element / number > times || (double)element / number < (double)1 / times) {
                count++;
            }
        }
    } else {
        // Двумерная матрица
        int **matrixData = (int **)matrix;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int element = matrixData[i][j];
                if ((double)element / number > times || (double)element / number < (double)1 / times) {
                    count++;
                }
            }
        }
    }
    return count;
}
