#include "matrixCalc.h"

#include <stdio.h>
#include <float.h>
#include <math.h>

inline double sigmoid(double x){
    return 1/(1+exp(-x));
}

matrix relu(matrix mat_in){
    matrix result_mat = createMatrix(mat_in.row, mat_in.col, 0);
    for (int i=0; i<mat_in.row; i++){
        for (int j=0; j<mat_in.col; j++){
            result_mat.val[i][j] = mat_in.val[i][j] > 0 ? mat_in.val[i][j] : 0;
        }
    }
    return result_mat;
}

matrix softmax(matrix mat_in){
    matrix result_mat = createMatrix(mat_in.row, mat_in.col, 0);
    double exp_sum = expSum(mat_in);
    for (int i=0; i<mat_in.row; i++){
        for (int j=0; j<mat_in.col; j++){
            result_mat.val[i][j] = exp(mat_in.val[i][j]) / exp_sum;
        }
    }
    return result_mat;
}
