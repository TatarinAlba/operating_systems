#include <stdio.h>
#include <stdlib.h>

int number_of_processes; 
int time_counter = 0;
float average_turnaround = 0; 
float average_waiting = 0;
int counter = 0;



struct Process {
    int arrivial_time, burst_time, turnaround_time, waiting_time, exit_time, time_left;
};

void print_info (struct Process process) {
    printf("Turn around time is: %d\n", process.turnaround_time);
    printf("Waiting time is: %d\n\n", process.waiting_time);
}

void kill_process(struct Process* process) {
    process -> arrivial_time = 999999;
    process -> burst_time = 999999;
}

void decrement(struct Process* task_queue) {
    for (int i = 0; i < number_of_processes; i++) {
        task_queue[i].time_left = task_queue[i].burst_time;
    }
}

int find_fastest_time(struct Process* task_queue, int quantum_time) {
    int fastest_time = 1000;
    for (int i = 0; i < number_of_processes; i++) {
        if (task_queue[i].arrivial_time < fastest_time && task_queue[i].burst_time == task_queue[i].time_left) {
            fastest_time = task_queue[i].arrivial_time;
        }
    }
    if (time_counter < fastest_time) {
        decrement(task_queue);
        fastest_time = find_fastest_time(task_queue, quantum_time);
    }
    return fastest_time;
}

int main() {
    int arrivial_time, burst_time;
    int quantum_time;
    scanf("%d %d", &number_of_processes, &quantum_time);
    struct Process processes[128];
    for (int i = 0; i < number_of_processes; i++) {
        scanf("%d %d", &arrivial_time, &burst_time);
        processes[i].arrivial_time = arrivial_time;
        processes[i].burst_time = burst_time;
        processes[i].time_left = burst_time;
    }
    int fastest = find_fastest_time(processes, quantum_time);
    struct Process* need_processes[128];
    while (counter != number_of_processes) {
        for (int i = 0; i < number_of_processes; i++) {
            if (processes[i].arrivial_time == fastest && processes[i].burst_time == processes[i].time_left) {
                int diff = 0;
                if (time_counter < processes[i].arrivial_time) {
                    diff = processes[i].arrivial_time - time_counter;    
                }
                processes[i].time_left -= quantum_time;
                time_counter += quantum_time + diff;
                if (processes[i].time_left <= 0) {
                    processes[i].exit_time = time_counter;
                    processes[i].turnaround_time = processes[i].exit_time - processes[i].arrivial_time;
                    processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
                    average_turnaround += processes[i].turnaround_time;
                    average_waiting += processes[i].waiting_time;
                    counter++;
                    printf("Info about P[%d]\n", counter);
                    print_info(processes[i]);
                    kill_process(processes + i);
                }
            }
        }
        printf("%d\n", time_counter);
        fastest = find_fastest_time(processes, quantum_time);
    }
    printf("Complete time is: %d\n", time_counter);
    printf("Average waiting time is: %f\n", average_waiting / number_of_processes);
    printf("Average turnaround time is: %f\n", average_turnaround / number_of_processes);
    return 0;
}