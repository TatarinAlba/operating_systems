#include <unistd.h>
#include <time.h>
#include <stdio.h>

int main() {
    clock_t first_proc_time = clock(), second_proc_time, third_proc_time;
    pid_t main_id = getpid();
    pid_t third_process;
    pid_t parent_of_main_id = getppid();
    printf("Main process that has next id: %d, his parent is %d\n", main_id, parent_of_main_id);
    pid_t second_process = fork();
    if (second_process == 0) {
        second_proc_time = clock();
        pid_t second_id = getpid();
        pid_t parent_of_second_id = getppid();
        printf("Second process has next id: %d, his parent is %d\n", second_id, parent_of_second_id);
    } else {
        third_process = fork();
        third_proc_time = clock();
        if (third_process == 0) {
            pid_t third_id = getpid();
            pid_t parent_of_third_id = getppid();
            printf("Third process has next id: %d, his parent is %d\n", third_id, parent_of_third_id);
        }
    }
    if (main_id == getpid()) {
        printf("Execution time for the first process is %f\n", ((float) (-first_proc_time + clock())/CLOCKS_PER_SEC) * 1000);
    } else if(second_process == 0) {
        printf("Execution time for the second process is %f\n", ((float)(-second_proc_time + clock())/CLOCKS_PER_SEC) * 1000);
    } else if(third_process == 0) {
        printf("Execution time for the third process is %f\n", ((float)(-third_proc_time + clock())/CLOCKS_PER_SEC) * 1000);
    }
    return 0;
}