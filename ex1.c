#include <unistd.h>
#include <time.h>
#include <stdio.h>

int main() {
    pid_t first_process = fork();
    // if (first_process == 0) {
    //     pid_t second_process = fork();
    // }
    printf("%d HEllo world", first_process);

    return 0;
}