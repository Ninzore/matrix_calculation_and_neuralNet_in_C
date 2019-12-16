#ifndef activation
#define activation

#include "matrixCalc.h"

#include <stdio.h>
#include <float.h>
#include <math.h>

matrix sigmoid(matrix mat_in);
matrix relu(matrix mat_in);
matrix softmax(matrix mat_in);

#endif