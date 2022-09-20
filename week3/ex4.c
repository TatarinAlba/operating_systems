//
// Created by alber on 9/20/2022.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void* aggregate(void* base, size_t size, int n, void* initial_value, void* (*opr)(const void*, const void*));

void* addInt(const void* a, const void* b){
    int* first = (int*) a;
    int* second = (int*) b;
    int* result = malloc(sizeof(int));
    *result = *first + *second;
    return result;
}

void* addDouble(const void* a, const void* b){
    double* first = (double*) a;
    double* second = (double*) b;
    double* result = malloc(sizeof(double));
    *result = *first + *second;
    return result;
}

void* mulInt(const void* a, const void* b){
    int* first = (int*) a;
    int* second = (int*) b;
    int* result = malloc(sizeof(int));
    *result = *first * *second;
    return result;
}

void* mulDouble(const void* a, const void* b){
    double* first = (double*) a;
    double* second = (double*) b;
    double* result = malloc(sizeof(double));
    *result = *first + *second;
    return result;
}

void* meanInt(const void* a, const void* b){
    int* first = (int*) a;
    int* second = (int*) b;
    int* result = malloc(sizeof(int));
    *result = *first + *second;
    return result;
}

void* meanDouble(const void* a, const void* b){
    double* first = (double*) a;
    double* second = (double*) b;
    double* result = malloc(sizeof(double));
    *result = *first + *second;
    return result;
}

void* aggregate(void* base, size_t size, int n, void* initial_value, void* (*opr)(const void*, const void*)){

    void* output;

    if (size==sizeof(int)){ // base is a pointer to an integer
        int* array = (int*) base;
        int counter = *(int*) initial_value;
        for (int i = 0; i < n; i++) {
            int *res = opr(&counter, array + i);
            counter = *res;
            free(res);
        }
        if (opr == meanInt) { //If there will be a situation where we have meanInt we should divide all by n
            counter /= n;
        }
        int* res = malloc(sizeof(int));
        *res = counter;
        output = res;
    } else{ // base is a pointer to a double
        double* array = (double*) base;
        double counter = *(double*) initial_value;
        for (int i = 0; i < n; i++) {
            double *res = opr(&counter, array + i);
            counter = *res;
            free(res);
        }
        if (opr == meanDouble) { //If there will be a situation where we have meanInt we should divide all by n
            counter /= n;
        }
        double* res = malloc(sizeof(double));
        *res = counter;
        output = res;
    }

    return output;
}




int main(){

    int* ints = malloc(sizeof(int)*5);
    double* doubles = malloc(sizeof(double)*5);

    //<WRITE YOUR CODE HERE>;
    for (int i = 0; i < 5; i++) {
        ints[i] = i * 10;
        doubles[i] = (double) (i * 10 / 7);
    }
    int basic_int;
    double basic_double;
    // Addition

    int* result1a;
    basic_int = 0;
    result1a = aggregate(ints, sizeof(int), 5, &basic_int, addInt);

    //<WRITE YOUR CODE HERE>;

    printf("%d\n", *result1a);

    double* result2a;
    basic_double = 0.0;
    //<WRITE YOUR CODE HERE>;
    result2a = aggregate(doubles, sizeof(double), 5, &basic_double, addDouble);


    printf("%f\n", *result2a);


    // Multiplication

    int* result1m;

    basic_int = 1;
    result1m = aggregate(ints, sizeof(int), 5, &basic_int, mulInt);
    //<WRITE YOUR CODE HERE>;

    printf("%d\n", *result1m);

    double* result2m;
    basic_double = 1;
    result1m = aggregate(doubles, sizeof(double), 5, &basic_double, mulDouble);
    //<WRITE YOUR CODE HERE>;

    printf("%f\n", *result2m);



    // Mean

    int* result1mean;
    basic_int = 0;
    result1mean = aggregate(ints, sizeof(int), 5, &basic_int, meanInt);
    //<WRITE YOUR CODE HERE>;

    printf("%d\n", *result1mean);

    double* result2mean;
    basic_double = 0;
    result2mean = aggregate(doubles, sizeof(double), 5, &basic_double, meanDouble);
    //<WRITE YOUR CODE HERE>;

    printf("%f\n", *result2mean);


    // free the pointers
    //<WRITE YOUR CODE HERE>;

    free(ints);
    free(doubles);
    free(result1a);
    free(result1m);
    free(result1mean);
    free(result2a);
    free(result2m);
    free(result2mean);
    return 0;
}
