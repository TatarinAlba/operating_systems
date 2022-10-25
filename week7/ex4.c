#include<stdlib.h>
#include<stdio.h>
#include<malloc.h>
#include<string.h>

void realloc_(void* ptr, int size_of) {
    if (ptr == NULL) {
        ptr = malloc(sizeof(void*) * size_of);
       	return;
    } else if (size_of == 0) {
        free(ptr);
        return;
    }
    void* temp = malloc(sizeof(void*) * size_of);
    int old_size = malloc_usable_size(ptr);
    memcpy(temp, ptr, old_size);
    ptr = temp;
    free(temp);
}
