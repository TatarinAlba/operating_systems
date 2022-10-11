#include <stdio.h>
#include <stdlib.h>

struct Process {
    int arrivial_time, burst_time, turnaround_time, waiting_time, exit_time;
};

void print_info (struct Process process) {
    printf("Turn around time is: %d\n", process.turnaround_time);
    printf("Waiting time is: %d\n\n", process.waiting_time);
}

void kill_process(struct Process* process) {
    process -> arrivial_time = 999999;
    process -> burst_time = 99999;
}

int find_fastest_time(struct Process* task_queue, int number_of_processes) {
    int fastest_time = 1000;
    for (int i = 0; i < number_of_processes; i++) {
        if (task_queue[i].arrivial_time < fastest_time) {
            fastest_time = task_queue[i].arrivial_time;
        }
    }
    return fastest_time;
}

int main() {
    int number_of_processes, arrivial_time, burst_time;
    int time_counter = 0;
    int process_num = 0;
    scanf("%d", &number_of_processes);
    struct Process processes[128];
    for (int i = 0; i < number_of_processes; i++) {
        scanf("%d %d", &arrivial_time, &burst_time);
        processes[i].arrivial_time = arrivial_time;
        processes[i].burst_time = burst_time;
    }
    float average_turnaround, average_waiting;
    int fastest = find_fastest_time(processes, number_of_processes);
    while (process_num != number_of_processes) {
        for (int i = 0; i < number_of_processes; i++) {
            if (processes[i].arrivial_time == fastest) {
                int diff = 0;
                if (time_counter < processes[i].arrivial_time) {
                    diff = processes[i].arrivial_time - time_counter;    
                }
                time_counter += processes[i].burst_time + diff;
                processes[i].exit_time = time_counter;
                processes[i].turnaround_time = processes[i].exit_time - processes[i].arrivial_time;
                processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
                average_turnaround += processes[i].turnaround_time;
                average_waiting += processes[i].waiting_time;
                process_num++;
                printf("Info about P[%d]\n", process_num);
                print_info(processes[i]);
                kill_process(processes + i);
            }
        }
        fastest = find_fastest_time(processes, number_of_processes);
    }
    printf("Complete time is: %d\n", time_counter);
    printf("Average waiting time is: %f\n", average_waiting / number_of_processes);
    printf("Average turnaround time is: %f\n", average_turnaround / number_of_processes);
    return 0;
}