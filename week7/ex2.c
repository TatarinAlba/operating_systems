#include <stdlib.h>
#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    int* array = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        array[i] = i;
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    free(array);
    return 0;
}
