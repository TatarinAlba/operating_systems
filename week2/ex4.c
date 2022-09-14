//
// Created by alber on 9/14/2022.
//
#include<stdio.h>
#include<string.h>

int count(char string[256], char symbol_for_counting) { //actually in the exercise was pointed that we should write the
                                                        // function that return number of occurrences of given symbol
    if (symbol_for_counting > 64 && symbol_for_counting < 91) {
        symbol_for_counting = symbol_for_counting + 32;
    }
    int counter = 0;
    for (int i = 0; i < strlen(string); i++) {
        if (string[i] > 64 && string[i] < 91) {
            if (string[i] + 32 == symbol_for_counting) counter++;
        } else {
            if (string[i] == symbol_for_counting) counter++;
        }
    }
    return counter;
}

void countAll(char string[256]) { // function that PRINT characters and their number of occurrences
    for (int i = 0; i < strlen(string); i++) {
        char symbol_for_counting = string[i];
        if (symbol_for_counting > 64 && symbol_for_counting < 91) {
            symbol_for_counting = symbol_for_counting + 32;
        }
        if (i != strlen(string) - 1) {
            printf("%c:%d, ", symbol_for_counting, count(string, symbol_for_counting));
        } else {
            printf("%c:%d", symbol_for_counting, count(string, symbol_for_counting));
        }
    }
}

int main() {
    char input[256];
    gets(input);
    countAll(input);
}