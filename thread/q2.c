#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct add_no{
	int n1, n2;
}add;

void *func1(void *(var1)){
	add *n;
	n = (add *) var1;
	printf("The sum of %d and %d is: %d\n", n->n1, n->n2, n->n1 + n->n2); 
	printf("Thread1 id is: %ld\n", pthread_self());
	pthread_exit(NULL);
}

void *func2(void *var2){
	int *a = (int *) var2;
	if((*a) % 2 == 0)
		printf("The number is even\n");
	printf("The number is odd\n");
	printf("Thread2 id is: %ld\n", pthread_self());
	pthread_exit(NULL);
}



int main()
{
	pthread_t thread_id[2];
	add num;
	num.n1=2;
	num.n2=3;
	
	int b = 7;
	pthread_create(&thread_id[0], NULL, func1, (void *)&num);
	pthread_create(&thread_id[1], NULL, func2, (void *)&b);
	
	pthread_join(thread_id[0], NULL);
    	pthread_join(thread_id[1], NULL);
    	return 0;
}
