#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd[2];
    pipe(fd);
    pid_t publisher = fork();
    if (publisher == 0) {
        close(fd[0]);
        while (1) {
            char message[1024];
            fgets(message, 1024, stdin);
            write(fd[1], message, 1024);
        }
        close(fd[1]);
    } else {
        pid_t subscriber = fork();
        if (subscriber == 0) {
            close(fd[1]);
            while(1) {
                char output[1024];
                read(fd[0], output, 1024);
                printf("Subscriber recieved: %s", output);
            }
            close(fd[0]);
        }
    }
    while(wait(NULL) > 0);
    return 0;
}