#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_NO_OF_THREADS 4
#define MAX_NO_OF_ELEMENTS 10000000

typedef struct arg_data {
    int thread_number;
} arg_data;

static int arr[MAX_NO_OF_ELEMENTS];

static long long int sum;

void* worker_sum(void* arg)
{
    arg_data* current_thread_data = (arg_data*)arg;
 
    printf("Current thread no is : %d\n", current_thread_data->thread_number);
 
    int endpart = (current_thread_data->thread_number) * (MAX_NO_OF_ELEMENTS / MAX_NO_OF_THREADS);
    int startpart = endpart - (MAX_NO_OF_ELEMENTS / MAX_NO_OF_THREADS);

    printf("Here we will sum %d to %d\n", arr[startpart], arr[endpart - 1]);

    long long int current_thread_sum = 0;
    for (int i = startpart; i < endpart; i++) {
        current_thread_sum += arr[i];
    }
    sum += current_thread_sum;
 
    return NULL;
}

int main()
{
    for (int i = 0; i < MAX_NO_OF_ELEMENTS; i++)
        arr[i] = i + 1;    
    pthread_t id[MAX_NO_OF_THREADS];    
    arg_data arg_arr[MAX_NO_OF_THREADS];    
    int no_of_threads = MAX_NO_OF_THREADS;
    printf("Creating %d number of threads...\n", no_of_threads);
    clock_t start, end;
    double cpu_time_taken;
    start = clock();
    int thread_no = 1;    
    for (thread_no = 1; thread_no <= MAX_NO_OF_THREADS; thread_no++) {
        arg_arr[thread_no - 1].thread_number = thread_no;
        pthread_create(&id[thread_no - 1], NULL, worker_sum, &arg_arr[thread_no - 1]);
    } 
    for (int i = 1; i <= MAX_NO_OF_THREADS; i++)
        pthread_join(id[i - 1], NULL);
    end = clock();
    cpu_time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("All child threads has finished their works...\n");
    printf("Total sum: %lld\n", sum);
    printf("Time taken to sum all the numbers are %lf\n", cpu_time_taken);

    return 0;
}
