//
// Created by alber on 9/14/2022.
//
#include <stdio.h>
int tribonacci(int n) {
    int first_t = 0;
    int second_t = 1;
    int third_t = 1;
    int forth_t = 0;
    for (int i = 3; i <= n; i++) {
        forth_t = first_t + second_t + third_t;
        first_t = second_t;
        second_t = third_t;
        third_t = forth_t;
    }
    return forth_t;
}

int main() {
    printf("n = 4\n *%d\nn = 36\n *%d", tribonacci(4), tribonacci(36));
}