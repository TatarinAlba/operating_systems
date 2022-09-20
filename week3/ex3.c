//
// Created by alber on 9/20/2022.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int num_of_items = 0;

struct File {
    struct Directory* parent;
    unsigned int id;
    char* name;
    unsigned int size;
    char* data;
};


struct Directory {
    struct File* files;
    struct Directory* directories;
    int nf;
    int nd;
    char* path;
};

void constructFile(char* name, struct File* file) {
    file -> name = malloc(64);
    strcpy(file -> name, name);
    file -> id = num_of_items++;
    file -> size = 1024;
    file -> data = malloc(file -> size);
    strcpy(file -> data, "");
}

void constructDir(char* name, struct Directory* src) {
    src -> path = malloc(64);
    strcpy(src -> path, name);
    src -> nf = 0;
    src -> nd = 0;
    src -> files = malloc(256 * sizeof(struct File));
    src -> directories = malloc(8 * sizeof(struct Directory));
    src -> path;
}

void add_file(struct File* file, struct Directory* dir) {
    dir -> files[dir -> nf++] = *file;
    file -> parent = dir;
}

void add_folder(struct Directory* to, struct Directory* src) {
    to -> directories[to -> nd++] = *src;
    char* new_path = malloc(64);
    strcpy(new_path, to -> path);
    strcat(new_path, src -> path);
    strcpy(src -> path, new_path);
}

void add_to_file(struct File* file, const char * str) {
    strcpy(file->data, str);
}

void append_to_file(struct File* file, const char * str) {
    file -> size += sizeof(char) * strlen(str);
    strcat(file->data, str);
}

void pwd_file(struct File* file) {
    printf("%s\\%s\n", file -> parent -> path, file -> name);
}


int main() {
    struct Directory root, home, bin;
    struct File bash, ex3_1, ex3_2;
    constructFile("bash", &bash);
    constructFile("ex3_1.c", &ex3_1);
    constructFile("ex3_2.c", &ex3_2);
    constructDir("\\", &root);
    constructDir("home", &home);
    constructDir("bin", &bin);
    add_folder(&root, &home);
    add_folder(&root, &bin);
    add_file(&bash, &bin);
    add_file(&ex3_1, &home);
    add_file(&ex3_2, &home);
    append_to_file(&ex3_1, "int printf(const char* format, ...);");
    append_to_file(&ex3_2, "//This is a comment in C language");
    append_to_file(&bash, "Bourne Again Shell!!");
    append_to_file(&ex3_1, "int main(){printf(\"Hello World!\")}");
    pwd_file(&bash);
    pwd_file(&ex3_1);
    pwd_file(&ex3_2);
    return 0;
}
