//
// Created by Timi on 6. 07. 2017.
//

#include "../headers/VectorOperations.h"

float *addTwoVectors(float *vector_a, float *vector_b, int d) {
    float *temp = new float[d];
    for (int i = 0; i < d; i++) {
        temp[i] = vector_a[i] + vector_b[i];
    }
    return temp;
}

float *subtractTwoVectors(float *vector_a, float *vector_b, int d) {
    float *temp = new float[d];
    for (int i = 0; i < d; i++) {
        temp[i] = vector_a[i] - vector_b[i];
    }
    return temp;
}

float *multiplyVectorByScalar(float scalar, float *vector, int d) {
    float *temp = new float[d];
    for (int i = 0; i < d; i++) {
        temp[i] *= vector[i] * scalar;
    }
    return temp;
}

float *mutationVectorOperation(float *a1, float *a2, float *a3, float F, int dimen) {
    float *temp = new float[dimen];
    for (int i = 0; i < dimen; i++) {
        temp[i] = a1[i] + (F * (a2[i] - a3[i]));
    }
    return temp;
}