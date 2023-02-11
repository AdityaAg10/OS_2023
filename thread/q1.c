#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

void *func(void *var){
	char *tid = (char *)var;
	printf("My name is: %s\n", tid);
	printf("My registration number is: %s\n", "21BCE1688");
	printf("The thread id is: %ld\n", pthread_self());	
	pthread_exit(NULL);
}

int main(){
	pthread_t thread_id;
	pthread_create(&thread_id, NULL, func, (void *)"Aditya Agarwal");
	sleep(1);
	printf("The id of main thread is: %ld\n", pthread_self());
	pthread_join(thread_id, NULL);
	return 0;
}
