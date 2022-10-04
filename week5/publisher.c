#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    char * myfifo = "/tmp/ex1";
    mkfifo(myfifo, 0777);
    int fd = open(myfifo, O_WRONLY);
    while (1) {
        char string[1024];
        fgets(string, 1024, stdin);
        write(fd, string, 1024);
    }
    close(fd);
    return 0;
}