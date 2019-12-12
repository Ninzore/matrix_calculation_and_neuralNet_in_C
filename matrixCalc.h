#ifndef MatrixCalc
#define MatrixCalc

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>

#define SIZE 28
#define DEFARG(name, defval) ((#name[0]) ? (name + 0 ) : defval)

typedef struct initMat{
//initialise a matrix type struct  
    int col;
    int row;
    double val[SIZE][SIZE];
}matrix;

void printMartix(matrix matrix);

matrix createMatrix(int row, int col, double init_val[]);

double _gaussianDistribution(int centre, float std_deviation);

#define gaussianDistribution(centre, std_deviation) \
_gaussianDistribution(DEFARG(centre, 0), DEFARG(std_deviation, 1))

matrix _createNormalMatrix(int row, int col, int centre, float std_deviation);
#define createNormalMatrix(row, col, centre, std_deviation) \
_createNormalMatrix(DEFARG(row, 1), DEFARG(col, 1), DEFARG(centre, 0), DEFARG(std_deviation, 1))

matrix _createRandMatrix(int row, int col, int start, int end);
#define createRandMatrix(row, col, start, end) \
_createRandMatrix(DEFARG(row, 1), DEFARG(col, 1), DEFARG(start, 0), DEFARG(end, 1))

double *toArray(matrix matrix);

matrix transform(matrix mat_a);

matrix plus(matrix mat_a, matrix mat_b);

matrix minus(matrix mat_a, matrix mat_b);

matrix scalar(matrix mat_a, double num);

matrix dot(matrix mat_a, matrix mat_b);

#endif
