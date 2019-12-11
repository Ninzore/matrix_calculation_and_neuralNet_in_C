#ifndef MatrixCalc
#define MatrixCalc

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>

#define SIZE 28

typedef struct initMat{
//initialise a matrix type struct  
    int col;
    int row;
    double val[SIZE][SIZE];
}matrix;

void printMartix(matrix matrix);
matrix createMatrix(int row, int col, double init_val[]);
double *toArray(matrix matrix);
matrix transform(matrix mat_a);
matrix plus(matrix mat_a, matrix mat_b);
matrix minus(matrix mat_a, matrix mat_b);
matrix scalar(matrix mat_a, double num);
matrix dot(matrix mat_a, matrix mat_b);

#endif