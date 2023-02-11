#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include<string.h>

void *vowels(void *(var1)){
	char *c1 = (char *)var1;
	int n=0;
	for(int i=0; i<strlen(c1); i++){
		if((c1[i]) == 'a' || (c1[i]) == 'A' || (c1[i]) == 'e' || (c1[i]) == 'E' || (c1[i]) == 'i' || (c1[i]) == 'I' || (c1[i]) == 'o' || (c1[i]) == 'O' || (c1[i]) == 'u' || (c1[i]) == 'U')
			n++; 
	}
	printf("The number of vowels is: %d\n", n);
	printf("Thread1 id is: %ld\n", pthread_self());
	pthread_exit(NULL);
}

void *consonants(void *var2){
	char *c2 = (char *)var2;
	int n = 0;
	for(int i=0; i<strlen(c2); i++){
		if((c2[i]) != 'a' && (c2[i]) != 'A' && (c2[i]) != 'e' && (c2[i]) != 'E' && (c2[i]) != 'i' && (c2[i]) != 'I' && (c2[i]) != 'o' && (c2[i]) != 'O' && (c2[i]) != 'u' && (c2[i]) != 'U' && (c2[i]) != ' ')
			n++; 
	}
	printf("The number of consonants is: %d\n", n);
	printf("Thread2 id is: %ld\n", pthread_self());
	pthread_exit(NULL);
}



int main()
{
	pthread_t thread_id[2];
	char *a = "Aditya Agarwal";
	pthread_create(&thread_id[0], NULL, vowels, (void *)a);
	pthread_create(&thread_id[1], NULL, consonants, (void *)a);
	
	pthread_join(thread_id[0], NULL);
    	pthread_join(thread_id[1], NULL);
    	return 0;
}
