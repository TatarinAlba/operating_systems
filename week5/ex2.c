#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <stdlib.h>


struct Thread{
    pthread_t id;
    int i;
    char message[256]; 
};


void* display_info(void* thread) {
    struct Thread* thread1 = (struct Thread*) thread;
    printf("id: %lu\nmessage: %s\n", thread1->id, thread1->message);
}


int main() {
    int n;
    scanf("%d", &n);
    struct Thread** thread = (struct Thread*) malloc(sizeof(struct Thread) * n);
    for (int i = 0; i < n; i++) {
        thread[i] = (struct Thread*) malloc(sizeof(struct Thread));
        thread[i]-> i = i;  
        char symb[128];
        sprintf(symb, "%d", i);
        char temp[128] = "Hello from thread ";
        strcat(temp, symb);
        strcpy(thread[i]->message, temp);
        pthread_create(&(thread[i]->id), NULL, &display_info, thread[i]);
        printf("Thread %d is created\n", i);
    }
    return 0;
}