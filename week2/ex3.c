//
// Created by alber on 9/13/2022.
//
#include <stdio.h>
#include <string.h>
#include <math.h>

void convert(long long number_previous, short old_system, short new_system) {
    long long number_in_tenth_system = 0;
    double exp = 0;
    char number_in_new_basis_reverse[256];
    char number_in_new_basis[256];
    while (number_previous != 0) {
        number_in_tenth_system += number_previous % 10 * pow((double) old_system, exp);
        number_previous = (long long) (number_previous / 10);
        exp++;
    }
    int counter = 0;
    while (number_in_tenth_system != 0) {
        number_in_new_basis_reverse[counter] = (char) ((number_in_tenth_system % new_system) + '0');
        counter++;
        number_in_tenth_system = (long long) number_in_tenth_system / new_system;
    }
    for (int i = 0; i < strlen(number_in_new_basis_reverse); i++) {
        number_in_new_basis[i] = number_in_new_basis_reverse[strlen(number_in_new_basis_reverse) - i - 1];
    }
    number_in_new_basis[counter] = '\0'; //for excluding trash symbols
    printf("%s", number_in_new_basis);
}


int main() {
    long long number;
    char num_as_string[256];
    short old_system, new_system;
    scanf("%s %hi %hi", num_as_string, &old_system, &new_system);
    if (old_system > 10 || old_system < 2 || new_system > 10 || new_system < 2) {
        printf("cannot convert!");
        return 1; // returning 1 as error code reporting about problems with bases
    }
    else {
        short digit;
        for (int i = 0; i < strlen(num_as_string); i++) {
            if (num_as_string[i] - 48 >= old_system) { //We use ASCII formula. Digits are placed in the positions
                                                       //from 48 to 57 (0 to 9), therefore if we will subtract current
                                                       // ascii code with 48 we can find actual number
                printf("cannot convert!");
                return 2; // returning 2 as error code for reporting a problem with starting number
            }
        }
        sscanf(num_as_string, "%lli", &number); // if everything is ok we convert number to the long long
                                                             // type and then use convert function

    }
    if (old_system == new_system) {
    	printf("%lli", number);
    	return 0;
    } 
    convert(number, old_system, new_system);
    return 0;
}
