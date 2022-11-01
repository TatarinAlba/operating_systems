#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/resource.h>
int main() {
    int *a;	
    counter = 0;
    while (counter < 10) {
    	struct rusage lib;
        a = malloc(10 * 1024 * 1024); // 10 MB
        memset(a, 0, 10 * 1024 * 1024); // FILL BY ZEROES
        getrusage(RUSAGE_SELF, &lib);
        printf("%li\n", lib.ru_maxrss);
        sleep(1);
        counter++;
    }
    return 0;
}
