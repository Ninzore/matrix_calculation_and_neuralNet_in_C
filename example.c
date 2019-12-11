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
  
  //initialize a random matrix k with given row, col, and range
  //REMEMBER to use srand BEFORE using!!!
  srand((unsigned) time(0));
  matrix k = createRandMatrix(3,3,0,1);
  printMartix(k);
  
  //do dot product, handling the result with a matrix structure
  matrix c = dot(m, n);
  printMartix(c);
  
  //do addition
  matrix d = plus(m, n);
  printMartix(d);
  
  //do minus
  matrix e = minus(m,n);
  printMartix(e);
  
  //matrix transform
  d = transform(d);
  printMartix(d);
  
  //multiply with an int
  d = scalar(d, 2);
  printMartix(d);
  
  //transform the 2d matrix to 1d array, handling the result with a double pointer
  double *buffer = toArray(m);
  printf("%f", buffer[0]);
  //ALWAYS REMEMBER to free
  free(buffer);
}
