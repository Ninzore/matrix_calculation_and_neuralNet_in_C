#ifndef MatrixCalc
#define MatrixCalc

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>

#define DEFARG(name, defval) ((#name[0]) ? (name + 0 ) : defval)

typedef struct initMat{
//initialise a matrix type struct  
    int col;
    int row;
    double **val;
}matrix;

void printMartix(matrix matrix);

matrix createMatrix(int row, int col, double init_val[]);

matrix createConstMatrix(int row, int col, int num);

matrix createIdentityMatrix(int n);

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

matrix expMat(matrix mat_in);

double sum(matrix mat_in);

double expSum(matrix mat_in);

matrix plus(matrix mat_a, double num);

matrix minus(matrix mat_a, double num);

matrix numMinus(double num, matrix mat_a);

matrix plusMat(matrix mat_a, matrix mat_b);

matrix minusMat(matrix mat_a, matrix mat_b);

matrix scalar(matrix mat_a, double num);

matrix multiply(matrix matrix_a, matrix matrix_b);

double inner(matrix mat_a, matrix mat_b);

matrix dot(matrix mat_a, matrix mat_b);

#endif
