#include "matrixCalc.h"

#define SIZE 28

//print the whole matrix
void printMartix(matrix matrix){
    for (int i=0; i<matrix.row; i++){
        for (int j=0; j<matrix.col; j++){
            printf("%-8.2f", matrix.val[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

//use the row, col and an array to create a matrix type
matrix createMatrix(int row, int col, double init_val[]){
    matrix mat;
    mat.row = row;
    mat.col = col;
    for (int i=0; i<row; i++){
        for (int j=0; j<col; j++){
            mat.val[i][j] = init_val[i * col + j];
        }
    }
    return mat;
}

//copy the matrix to a memery location buffer, 
//with size = matrix.row * matrix.col
//remember to free after using
double *toArray(matrix matrix){
    double *rt_array = malloc(matrix.row * matrix.col);
    double array[matrix.row * matrix.col];
    // int size = matrix.row * matrix.col;
    for (int i=0; i<matrix.row; i++){
        for (int j=0; j<matrix.col; j++){
            array[i * matrix.col + j] = matrix.val[i][j];
        }
    }
    memcpy(rt_array, array, matrix.row * matrix.col);
    return rt_array;
}

//matrix transformation
matrix transform(matrix mat_a){
    double arr[] = {0};
    matrix mat_b = createMatrix(mat_a.row, mat_b.col, arr);
    for (int i=0; i<mat_a.row; i++){
        for (int j=0; j<mat_b.col; j++){
            mat_b.val[i][j] = mat_a.val[j][i];
        }
    }   
    return mat_b;
}

matrix plus(matrix mat_a, matrix mat_b){
    double arr_c[] = {0};
    matrix mat_c = createMatrix(mat_a.row, mat_b.col, arr_c);
    if ((mat_a.row != mat_b.row) || (mat_a.col != mat_b.col)){
        printf("\nerror, matrix A and matrix B have different sizes");
        return mat_c;
    }
    else{
        for (int i=0; i<mat_a.row; i++){
            for (int j=0; j<mat_a.col; j++){
                mat_c.val[i][j] = mat_a.val[i][j] + mat_b.val[i][j];
            }
        }   
    }
    return mat_c;
}

matrix minus(matrix mat_a, matrix mat_b){
    double arr_c[] = {0};
    matrix mat_c = createMatrix(mat_a.row, mat_b.col, arr_c);
    if ((mat_a.row != mat_b.row) || (mat_a.col != mat_b.col)){
        printf("\nerror, matrix A and matrix B have different sizes");
        return mat_c;
    }
    else{
        for (int i=0; i<mat_a.row; i++){
            for (int j=0; j<mat_a.col; j++){
                mat_c.val[i][j] = mat_a.val[i][j] - mat_b.val[i][j];
            }
        }   
    }
    return mat_c;
}

matrix scalar(matrix mat_a, double num){
//multiply with a scalar
    double arr[] = {0};
    matrix mat_b = createMatrix(mat_a.row, mat_b.col, arr);
    for (int i=0; i<mat_a.row; i++){
        for (int j=0; j<mat_b.col; j++){
            mat_b.val[i][j] = mat_a.val[i][j] * num;
        }
    }   
    return mat_b;
}

matrix dot(matrix mat_a, matrix mat_b){
    double arr_c[] = {0};
    matrix mat_c = createMatrix(mat_a.row, mat_b.col, arr_c);
    if (mat_a.col != mat_b.row){
        printf("\nerror, matrix A's row isn't equal to matrix B's col");
        return mat_c;
    }
    else{
        for (int i=0; i<mat_a.row; i++){
            for (int j=0; j<mat_b.col; j++){
                for (int k=0; k<mat_a.col; k++){
                    mat_c.val[i][j] = mat_c.val[i][j] + mat_a.val[i][k] * mat_b.val[k][j];
                }
            }
        }   
    }
    return mat_c;
}
