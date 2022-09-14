//
// Created by alber on 9/13/2022.
//

#include<stdio.h>
#include<string.h>

int main() {
    char input[257]; //why 257 (look down)
    char output[257]; // why 257 (look down)
    fgets(input, 257, stdin); // because by default null string included to this number
    char* find_symbol = strchr(input, '.');
    int index =  (int) (find_symbol - input);
    if (find_symbol != NULL) {
        for (int i = index - 1; i >= 0; i--) {
            output[index - i - 1] = input[i];
        }
        output[index] = '\0'; //for excluding trash symbols in the end of the output
    } else {
        for (int i = (int) strlen(input) - 2; i >= 0; i--) { // -2 because of excluding trash symbols + \n
                                                                 // if it will be the case for non using \n just change
                                                                 // to -1
            output[(int) strlen(input) - 2 - i] = input[i];
        }
        output[(int) strlen(input)] = '\0'; //for excluding trash symbols in the end of the output
    }
    printf("\"%s\"", output);
    return 0;
}
