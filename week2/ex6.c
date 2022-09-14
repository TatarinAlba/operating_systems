//
// Created by alber on 9/14/2022.
//
#include <stdio.h>

int main() {
    int counter = 1;
    for (int i = 0; i < 10; i++) {
        for(int j = 0; j < counter; j++) {
            putchar('*');
        }
        putchar('\n');
        counter++;
    }
    putchar('\n');
    counter = 1;
    for (int i = 0; i < 11; i++) {
        if (i > 5) {
            counter = i == 6? counter - 1: counter;
            counter--;
            for (int j = counter; j > 0; j--) {
                putchar('*');
            }
            putchar('\n');
        } else {
            for (int j = 0; j < counter; j++) {
                putchar('*');
            }
            counter++;
            putchar('\n');
        }
    }
    putchar('\n');
    for (int i = 0; i < 10; i++) {
        printf("**********\n");
    }
}