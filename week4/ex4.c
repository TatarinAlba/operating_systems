#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(int argc, char **argv) {
    printf("Welcome!\n\nI am glad to introduce you super Shell:\n\n");
    char* command = NULL;
    size_t line = 256;
    printf(">> ");
    while (getline(&command, &line, stdin)) {
        command[strlen(command)-1] = '\0';
        if (strcmp(command, "directory") == 0) {
            system("pwd");
        }
        else if (strcmp(command, "where_am_i") == 0) {
            system("ls");
        } else if (strcmp(command, "process_tree") == 0) {
            system("pstree");
        } else if (strcmp(command, "make_directory") == 0) {
            system("mkdir");
        } else if (strcmp(command, "run") == 0) {
            system("execve"); 
        }
        printf(">> ");
    }
    return 0;
}