#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
	clock_t  start, end, sum=0;
	start = clock();
	for(int i=1; i<=10000000; i++){
		sum+=i;
	}
	end = clock();
	double t = ((double)(end-start))/CLOCKS_PER_SEC;
	printf("Time taken is: %f", t);
	return 0;
}
