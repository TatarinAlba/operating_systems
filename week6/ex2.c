#include <stdio.h>
#include <stdlib.h>

int number_of_processes; 
int time_counter = 0;
float average_turnaround = 0; 
float average_waiting = 0;
int counter = 0;



struct Process {
    int arrivial_time, burst_time, turnaround_time, waiting_time, exit_time;
};

void print_info (struct Process process) {
    printf("Turn around time is: %d\n", process.turnaround_time);
    printf("Waiting time is: %d\n\n", process.waiting_time);
}

void kill_process(struct Process* process) {
    process -> arrivial_time = 999999;
    process -> burst_time = 999999;
}

struct Process* find_fastest_job_and_calc(struct Process** task_queue, int number_of_loc_processes) {
    int count_loc = 0;
    int fastest = 9999;
    int pos = -1;
    while (count_loc != number_of_loc_processes) { 
        for (int i = 0; i < number_of_loc_processes; i++) {
            if (task_queue[i]->burst_time < fastest) {
                fastest = task_queue[i] -> burst_time;
                pos = i;
            }
        }
        int diff = 0;
        if (time_counter < task_queue[pos] -> arrivial_time) {
            diff = task_queue[pos] -> arrivial_time - time_counter;
        }
        time_counter += task_queue[pos] -> burst_time + diff;
        task_queue[pos] -> exit_time = time_counter;
        task_queue[pos] -> turnaround_time = task_queue[pos] -> exit_time - task_queue[pos] -> arrivial_time;
        task_queue[pos] -> waiting_time = task_queue[pos] -> turnaround_time - task_queue[pos] -> burst_time;
        average_turnaround += task_queue[pos] -> turnaround_time;
        average_waiting += task_queue[pos] -> waiting_time;
        counter++;
        count_loc++;
        printf("Info about P[%d]\n", counter);
        print_info(*task_queue[pos]);
        fastest = 9999;
        kill_process(task_queue[pos]);
        pos = -1;
    }
}

int find_fastest_time(struct Process* task_queue) {
    int fastest_time = 1000;
    for (int i = 0; i < number_of_processes; i++) {
        if (task_queue[i].arrivial_time < fastest_time) {
            fastest_time = task_queue[i].arrivial_time;
        }
    }
    return fastest_time;
}

int main() {
    int arrivial_time, burst_time;
    scanf("%d", &number_of_processes);
    struct Process processes[128];
    for (int i = 0; i < number_of_processes; i++) {
        scanf("%d %d", &arrivial_time, &burst_time);
        processes[i].arrivial_time = arrivial_time;
        processes[i].burst_time = burst_time;
    }
    int fastest = find_fastest_time(processes);
    struct Process* need_processes[128];
    int loc_counter = 0;
    while (counter != number_of_processes) {
        for (int i = 0; i < number_of_processes; i++) {
            if (processes[i].arrivial_time == fastest) {
                need_processes[loc_counter] = (processes + i);
                loc_counter++;
            }
        }
        find_fastest_job_and_calc(need_processes, loc_counter);
        loc_counter = 0;
        fastest = find_fastest_time(processes);
    }
    printf("Complete time is: %d\n", time_counter);
    printf("Average waiting time is: %f\n", average_waiting / number_of_processes);
    printf("Average turnaround time is: %f\n", average_turnaround / number_of_processes);
    return 0;
}