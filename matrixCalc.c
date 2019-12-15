#include "matrixCalc.h"

#define SIZE 28
#define DEFARG(name, defval) ((#name[0]) ? (name + 0 ) : defval)

/*
matrix type, with max size = SIZE,
which has been defined above

    row: int, total number of rows of the matrix
    col: int, total number of col of the matrix
    val: the values within the matrix,
         use matrix.val[][] to access this matrix
*/
// typedef struct initMat{
// //initialise a matrix type struct  
//     int col;
//     int row;
//     double val[SIZE][SIZE];
// }matrix;


/*
use the row, col and an array to create a matrix type

Args:  
    row: int, total number of rows of the matrix
    col: int, total number of col of the matrix
    init_val: double list, the list transfer to matrix
                           can be 0;

Return: matrix, if the size of matrix is larger than the
                init_val, matrix size will not be changed
                rest of the matrix will be all 0;
*/
void printMartix(matrix matrix){
//print matrix
    for (int i=0; i<matrix.row; i++){
        for (int j=0; j<matrix.col; j++){
            printf("%-8.2f", matrix.val[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

/*
use the row, col and an array to create a matrix

Args:  
    row: int, total number of rows of the matrix
    col: int, total number of col of the matrix
    init_val: double list, the list transfer to matrix
                           can be 0;

Return: matrix, if the size of matrix is larger than the
                init_val, matrix size will not be changed
                rest of the matrix will be all 0;
*/
matrix createMatrix(int row, int col, double init_val[]){
    matrix mat;
    mat.row = row;
    mat.col = col;
    mat.val = (double**)malloc(sizeof(double*) * mat.row);
    for (int i=0; i<mat.row; i++){
        mat.val[i] = (double*)malloc(sizeof(double) * mat.col);
        for (int j=0; j<mat.row; j++){
            mat.val[i][j] = init_val[i * mat.row + j];
        }
    }
    return mat;
}


/*
use the row, col and an array to create a matrix

Args:  
    row: int, total number of rows of the matrix
    col: int, total number of col of the matrix

Return: matrix, with all members are 0
*/
matrix createConstMatrix(int row, int col, int num){
    matrix mat;
    mat.row = row;
    mat.col = col;
    mat.val = (double**)malloc(sizeof(double*) * mat.row);
    for (int i=0; i<mat.row; i++){
        mat.val[i] = (double*)malloc(sizeof(double) * mat.col);
        for (int j=0; j<mat.col; j++){
            mat.val[i][j] = num;
        }
    }

    return mat;
}

/*
create an identity matrix

Args:  
    row: int, total number of rows of the matrix

Return: matrix, the identity matrix
*/
matrix createIdentityMatrix(int n){
    matrix mat;
    mat.row = n;
    mat.col = n;
    for (int i=0; i<n; i++){
        mat.val[i][i] = 1;
    }
    return mat;
}

/*
generate a random matrix with shape row*col
REMEMBER to call srand((unsigned) time(0)) only ONCE before using
default output 1*1 matrix with vals within 0~1
change the macro below to change the default behavior

Args:
    row: int, total number of rows of the matrix
    col: int, total number of col of the matrix
    start: int, the minium of values
    end: int, the maxium of values

Return: matrix type
*/
matrix _createRandMatrix(int row, int col, int start, int end){
    double arr[row*col];
    if (start < end){
        for (int i; i<row*col; i++){
            arr[i] = ((start + end * rand()) / ((double) RAND_MAX ));
        }
        matrix mat = createMatrix(row, col, arr);
        return mat;
    }
    else{
        printf("error, start >= end");
        exit(-1);
    }
}
#define createRandMatrix(row, col, start, end) _createRandMatrix(DEFARG(row, 1), DEFARG(col, 1), DEFARG(start, 0), DEFARG(end, 1))

/*
use Box-Muller method to generate number in Gaussian (normal) distrubution

Args:
    centre: int, set the centre
    std_deviation: float, the standard deviation of the distrubution

Return: double the random number generated
*/
double _gaussianDistribution(int centre, float std_deviation){
    double PI = 3.1415926535897932;
    double z = 0;
    double a = (rand()/((double) RAND_MAX + 1));
    double b = rand()/((double) RAND_MAX + 1);
    double radius = sqrt(-2 * log(a));
    double theta = PI * 2 * b;
    // z = radius * cos(theta);
    z = (radius * sin(theta) + centre) * std_deviation;
    return z;
}
#define gaussianDistribution(centre, std_deviation) \
_gaussianDistribution(DEFARG(centre, 0), DEFARG(std_deviation, 1))

/*
use Box-Muller method to generate a matrix with values follow Gaussian (normal) distrubution

Args:
    row: int, total number of rows of the matrix
    col: int, total number of col of the matrix
    centre: int, set the centre of the distrubution
    std_deviation: float, the standard deviation of the distrubution
             
Return: mattrix type, with values follows normal distrubution
*/
matrix _createNormalMatrix(int row, int col, int centre, float std_deviation){
    double arr[row*col];
    for (int i=0; i<row*col; i++){
        arr[i] = gaussianDistribution(centre, std_deviation);
    }
    matrix mat = createMatrix(row, col, arr);
    return mat;
}
#define createNormalMatrix(row, col, centre, std_deviation) \
_createNormalMatrix(DEFARG(row, 1), DEFARG(col, 1), DEFARG(centre, 0), DEFARG(std_deviation, 1))

/*
copy the matrix to an array stored in buffer memery location, 
array size = matrix.row * matrix.col
REMEMBER to free the memery after using
Args:
    matrix: matrix type
Return:
    array: double pointer, use array[] to access individual val 
*/
double *toArray(matrix matrix){
    //allocate the memery for the array, x8 for double, change to x4 for int or float
    double *array = malloc(matrix.row * matrix.col * 8);
    for (int i=0; i<matrix.row; i++){
        for (int j=0; j<matrix.col; j++){
            array[i * matrix.col + j] = matrix.val[i][j];
        }
    }
    return array;
}

/*
matrix transformation
Args:
    matrix: matrix, a matrix
*/
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

/*
transfer all the members in the matrix to exponential form
Args:
    matrix_a: matrix type, a matrix

Return: matrix, the exp form of the input matrix
*/
matrix expMat(matrix mat_in){
    double arr[mat_in.row * mat_in.col];
    for (int i=0; i<mat_in.row; i++){
        for (int j=0; j<mat_in.col; j++){
            arr[i * mat_in.col + j] = exp(mat_in.val[i][j]);
        }
    }
    matrix mat_result = createMatrix(mat_in.row, mat_in.col, arr);
    return mat_result;
}

/*
add a number to all members in the matrix
Args:
    mat_a: matrix type, a matrix
*/
matrix plus(matrix mat_a, double num){
    matrix mat_c = createConstMatrix(mat_a.row, mat_a.col, 0);
    for (int i=0; i<mat_a.row; i++){
        for (int j=0; j<mat_a.col; j++){
            mat_c.val[i][j] = mat_a.val[i][j] + num;
        }
    }       
    return mat_c;
}


/*
minus a number from all members in the matrix
Args:
    mat_a: matrix type, a matrix
*/
matrix minus(matrix mat_a, double num){
    matrix mat_c = createConstMatrix(mat_a.row, mat_a.col, 0);
    for (int i=0; i<mat_a.row; i++){
        for (int j=0; j<mat_a.col; j++){
            mat_c.val[i][j] = mat_a.val[i][j] - num;
        }
    }       
    return mat_c;
}

/*
matrix addition
Args:
    matrix_a: matrix type, a matrix
    matrix_b: matrix type, a matrix
*/
matrix plusMat(matrix mat_a, matrix mat_b){
    double arr_c[] = {0};
    matrix mat_c = createMatrix(mat_a.row, mat_b.col, arr_c);
    if ((mat_a.row != mat_b.row) || (mat_a.col != mat_b.col)){
        printf("error, matrix A and matrix B have different sizes");
        exit(-1);
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

/*
matrix subtraction
Args:
    matrix_a: matrix type, a matrix
    matrix_b: matrix type, a matrix
*/
matrix minusMat(matrix mat_a, matrix mat_b){
    double arr_c[] = {0};
    matrix mat_c = createMatrix(mat_a.row, mat_b.col, arr_c);
    if ((mat_a.row != mat_b.row) || (mat_a.col != mat_b.col)){
        printf("error, matrix A and matrix B have different sizes");
        exit(-1);
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

/*
calculate the sum of members in a matrix
Args:
    matrix_a: matrix type, a matrix

Return: double, the sum of each member in the matrix
*/
double sum(matrix mat_in){
    double result = 0;
    for (int i=0; i<mat_in.row; i++){
        for (int j=0; j<mat_in.col; j++){
            result += mat_in.val[i][j];
        }
    }   
    return result;
}

/*
calculate the sum exponential of members in a matrix
Args:
    matrix_a: matrix type, a matrix

Return: double, the sum exp of each member in the matrix
*/
double expSum(matrix mat_in){
    double result = 0;
    for (int i=0; i<mat_in.row; i++){
        for (int j=0; j<mat_in.col; j++){
            result += exp(mat_in.val[i][j]);
        }
    }   
    return result;
}

/*
matrix multiply with a scalar value
Args:
    matrix_a: matrix type, a matrix
    num: double, the number used to multiply
Return: 
    matrix type, the result matrix
*/
matrix scalar(matrix matrix_a, double num){
//multiply with a scalar
    double arr[] = {0};
    matrix mat_b = createMatrix(matrix_a.row, mat_b.col, arr);
    for (int i=0; i<matrix_a.row; i++){
        for (int j=0; j<mat_b.col; j++){
            mat_b.val[i][j] = matrix_a.val[i][j] * num;
        }
    }   
    return mat_b;
}

/*
get the inner product of 2 1-d matrix(array)
Args:
    mat_a: matrix type, a 1-d matrix(array)
    mat_b: matrix type, a 1-d matrix(array)
Return: 
    double, the inner product result
*/
double inner(matrix mat_a, matrix mat_b){
    double product;
    if (mat_a.row == 1 && mat_b.row == 1){
        if (mat_a.col == mat_b.col){
            for(int i=0; i<mat_a.col; i++){
                product += mat_a.val[0][i] * mat_b.val[0][i];
            }
        }
        else{
            printf("error, matrix A and matrix B have different size");
            exit(-1);
        }
    }
    return product;
}

/*
if 2 matrixs are 1-d matrix(array), return the inner product as a 0-d matrix, 
inner() function is better for this as it returns a double

if they are 2-d matrix, then do matrix multiplication
Args:
    mat_a: matrix type, a matrix
    mat_b: matrix type, a matrix
Return: 
    matrix type, the result matrix
*/
matrix dot(matrix mat_a, matrix mat_b){
    double arr_c[] = {0};
    matrix mat_c;
    if (mat_a.row == 1 && mat_b.row == 1){
        if (mat_a.col == mat_b.col){
            mat_c = createMatrix(1, 1, arr_c);
            for(int i=0; i<mat_a.col; i++){
                mat_c.val[0][0] += mat_a.val[0][i] * mat_b.val[0][i];
            }
        }
        else{
            printf("error, matrix A's col isn't equal to matrix B's col\n");
            exit(-1);
        }
    }
    else if (mat_a.col == mat_b.row){
        mat_c = createMatrix(mat_a.row, mat_b.col, arr_c);
        for (int i=0; i<mat_a.row; i++){
            for (int j=0; j<mat_b.col; j++){
                for (int k=0; k<mat_a.col; k++){
                    mat_c.val[i][j] = mat_c.val[i][j] + mat_a.val[i][k] * mat_b.val[k][j];
                }
            }
        }
    }
    else{
        printf("\nerror, matrix A's row isn't equal to matrix B's col");
        exit(-1);
    }
    return mat_c;
}


matrix reshape(matrix mat_a, int row, int col){
    matrix mat_b;
    if (mat_a.row * mat_a.col != row * col){
        printf("\nerror, the target size is %dx%d but the input matrix size is %dx%d", row, col, mat_a.row, mat_a.col);
        exit(-1);
    }
    else{
        double arr[row*col];
        for (int i=0; i<mat_a.row; i++){
            for (int j=0; j<mat_a.col; j++){
                arr[i * mat_a.col + j] = mat_a.val[i][j];
                mat_b = createMatrix(row, col, arr);
            }
        }
    }
    return mat_b;
}
