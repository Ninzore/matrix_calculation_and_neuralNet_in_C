#include "matrixCalc.h"
#include "activation.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include <time.h>
#include <math.h>

typedef struct initNeuralNet
{
    int input_size;
    int hidden_size;
    int output_size;
    float learning_rate;
    matrix weight_i2h;
    matrix weight_h2o;
}neuralNet;


neuralNet init(int input_size, int hidden_size, int output_size, float learning_rate){
    neuralNet neuralNet;
    neuralNet.input_size = input_size;
    neuralNet.hidden_size = hidden_size;
    neuralNet.output_size = output_size;
    neuralNet.learning_rate = learning_rate;

    neuralNet.weight_i2h = createNormalMatrix(hidden_size, input_size, 0, pow(hidden_size, -0.5));
    neuralNet.weight_i2h = createNormalMatrix(hidden_size, input_size, 0, pow(output_size, -0.5));

    return neuralNet;
}

neuralNet forward(neuralNet nn, double input_arr[], int input_arr_len, double target_arr[], int target_arr_len){
    matrix input = createMatrix(input_arr_len, 1, input_arr);
    matrix target = createMatrix(target_arr_len, 1, target_arr);

    matrix in_hid = dot(nn.weight_i2h, input);
    matrix i2h_active = sigmoid(in_hid);

    matrix hid_out = dot(nn.weight_h2o, i2h_active);
    matrix h2o_active = sigmoid(hid_out);

    matrix out_err = minusMat(target, h2o_active);
    matrix hid_err = dot(transpose(out_err), out_err);

    matrix temp1 = multiply(hid_err, in_hid);
    matrix temp2 = numMinus(1, i2h_active);
    matrix temp3 = multiply(temp1, temp2);
    nn.weight_i2h = dot(temp3, transpose(input));

    temp1 = multiply(out_err, hid_out);
    temp2 = numMinus(1, h2o_active);
    temp3 = multiply(temp1, temp2);
    nn.weight_h2o = dot(temp3, transpose(i2h_active));
    return nn;
}

matrix eval(neuralNet nn, double input_arr[], int input_arr_len){
    matrix input = createMatrix(input_arr_len, 1, input_arr);

    matrix in_hid = dot(nn.weight_i2h, input);
    matrix i2h_active = sigmoid(in_hid);

    matrix hid_out = dot(nn.weight_h2o, i2h_active);
    matrix h2o_active = sigmoid(hid_out);

    return h2o_active;
}

int main(){
    srand((unsigned) time(0));
    char train_file[] = "";
    char line[1000];
    char *vals = NULL;
    char *buffer = NULL;
    FILE *train;
    errno_t err;
    err = fopen_s(&train, train_file, "r");

    for (int i=0; i<100; i++){
      fgets(line, 1000, train);
    ...
    }

    fclose(train);
}
