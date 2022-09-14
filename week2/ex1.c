#include<stdio.h>
#include<limits.h>
#include<float.h>

int main() {
    int first_var;
    unsigned short int second_var;
    signed long int third_var;
    float forth_var;
    double fifth_var;
    first_var = INT_MAX;
    second_var = USHRT_MAX;
    third_var = LONG_MAX;
    forth_var = FLT_MAX;
    fifth_var = DBL_MAX;
    printf("Integer:\n Size - %ld,\n Value - %d\n", sizeof(first_var), first_var);
    printf("Unsigned short integer:\n Size - %ld,\n Value - %hu\n", 
        sizeof(second_var), second_var);
    printf("Signed short integer:\n Size - %ld,\n Value - %ld\n", sizeof(third_var), third_var);
    printf("Float:\n Size - %ld,\n Value - %f\n", sizeof(forth_var), forth_var);
    printf("Double:\n Size - %ld,\n Value - %f", sizeof(fifth_var), fifth_var);
    return 0;
}
