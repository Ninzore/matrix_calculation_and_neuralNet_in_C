#include "matrixCalc.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>

int main(){
  //create an array for initialization matrix
  double arr[] = {4,7,12,2};
  
  //initialize matrix m and n with given row, col and array
  matrix m = createMatrix(2,2, arr);
  matrix n = createMatrix(2,2, arr);
  
  //print out the matrixs
  printMartix(m);
  printMartix(n);
  
  //create an identity matrix
  matrix i = createIdentityMatrix(5);
  printMartix(i);
  
  //initialize a random matrix k with given row, col, and range
  //REMEMBER to use srand BEFORE using!!!
  srand((unsigned) time(0));
  matrix k = createRandMatrix(3,3,0,1);
  printMartix(k);
  
  //transform the 2d matrix to 1d array, handling the result with a double pointer
  double *buffer = toArray(m);
  printf("%f", buffer[0]);
  //ALWAYS REMEMBER to free
  free(buffer);
  
  //get 1 random number obey the gaussian distribution
  printf("%f\n", gaussianDistribution(0,1));
  //default output is centre at 0, standard deviation 1
  printf("%f\n", gaussianDistribution(,));
  
  //get a matrix of random number obey the gaussian distribution, 
  matrix normal_mat = createNormalMatrix(5, 5, 0, 1);
  printMartix(normal_mat);
  //default output is 1*1 matrix with value centre at 0, standard deviation 1
  matrix normal_mat_ = createNormalMatrix(,,,);
  printMartix(normal_mat_);
  
  //print the inner product of two 1-d matrix(array)
  printf("%f", inner(m, n));
  
  //do dot product, handling the result with a matrix structure
  matrix c = dot(m, n);
  printMartix(c);
  
  //do dot product for two 1-d matrix(array), give the inner product of them in a 0-d matrix(scalar)
  matrix s = createNormalMatrix(1,5, arr);
  matrix d = createNormalMatrix(1,5, arr);
  matrix f = dot(s, d);
  printMartix(f);
  
  //do addition
  matrix d = plus(m, n);
  printMartix(d);
  
  //do minus
  matrix e = minus(m,n);
  printMartix(e);
  
  //matrix transform
  d = transform(d);
  printMartix(d);
  
  //transfer all the members in the matrix to exponential form
  matrix expMatrix = expMat(i);
  printMatrix(expMatrix);
  
  //multiply with a float
  d = scalar(d, 2);
  printMartix(d);
  
  //calculate the sum of members in a matrix
  double sum = sum(m);
  
  //calculate the sum exponential of members in a matrix
  double expSum = expSum(m);
}
