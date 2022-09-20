#include<stdio.h>
#include<stdlib.h>
 
int foo(int age) {
    return 2022 - age;
} 
 
int main() {
    const int x = 10;
    const int* q = &x;
    const int* const p = (const int*) malloc(sizeof(const int) * 5);
    int* inserter; // here i have created pointer to integer because exercise asks
                               // to insert value of x into cells of memory which are read only
                               // therefore we made such a trick with pointer to integer
    for (int i = 0; i < 5; i++) {
        inserter = p + i;
        *inserter = x;
        printf("%p\n", q + i);
    }
    for (int i = 0; i < 5; i++) {
        inserter = p + i;
        scanf("%d", inserter);
    }
    for (int i = 0; i < 5; i++) {
        inserter = p + i;
        int year_of_birth = foo(*inserter);
        *inserter = year_of_birth;
        printf("%d\n", p[i]);
    }
    free(p);
    return 0;
}
