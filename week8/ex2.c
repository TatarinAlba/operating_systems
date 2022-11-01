#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>

// If we will run this program si and so will be zeroes. But when we will assign the value of
// INT_MAX then there will be a result, but 10 MB is not enough for swapping
// it depends on the initial computers memory
// but when i stop executing my program and in the next time i am again executing my program
// there the same value of the resting memory as it was before executing.
// We see that after checking top command precentage of %MEM increases with the VIRT (virtual memory) and RES (all occupied physical memory). We see that current process occupies more and more avaliable physical memory (ratio increases)
int main() {
    int *a;	
    counter = 0;
    while (counter < 10) {
        a = malloc(10 * 1024 * 1024); // 10 MB
        memset(a, 0, 10 * 1024 * 1024); // FILL BY ZEROES
        sleep(1);
        counter++;
    }
    return 0;
}
