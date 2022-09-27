#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE* inputFile;
    FILE* outputFile;
    fclose(fopen("temp.txt", "w")); // for excluding moment when data already in temp.txt
    inputFile = fopen("temp.txt", "r");
    outputFile = fopen("temp.txt", "a+");
    int sum_of_vectors = 0;
    char string_num[256];
    float u[120], v[120];
    for (int i = 0; i < 120; i++) {
        u[i] = rand() % 100;
        v[i] = rand() % 100;
    }
    int number_of_processes;
    int processes[10];
    scanf("%d", &number_of_processes);
    for (int i = 0; i < number_of_processes; i++) {
        processes[i] = fork();
        if (processes[i] == 0) {
            int suma = 0;
            for (int j = (120 / number_of_processes) * i; j < (120 / number_of_processes) * (i + 1); j++) {
                suma += v[j] * u[j];
            }
            sprintf(string_num, "%d", suma);
            fprintf(outputFile, "%s ",string_num);
            return EXIT_SUCCESS;
        }
    }
    while(wait(0)>0);
    int num;
    for (int i = 0; i < number_of_processes; i++) {
        fscanf(inputFile, "%d", &num);
        sum_of_vectors += num;
    }
    fclose(outputFile);
    outputFile = fopen("temp.txt", "w");
    sprintf(string_num, "%d ", sum_of_vectors);
    fprintf(outputFile, "%s", string_num);
    fclose(outputFile);
    fclose(inputFile);
    return 0;
}