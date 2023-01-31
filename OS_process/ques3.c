#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>

int main()
{
	pid_t pid1, pid2, pid3;
	pid1 = fork();
	
	if(pid1 == 0){
		sleep(2);	
		printf("This is child 1\n");
		printf("child1 pid is %d, parents pid is: %d\n", getpid(), getppid());
	}
	else{	
		pid2 = fork();
		if(pid2 == 0){
			sleep(1);
			printf("This is child 2\n");
			printf("child2 pid is %d, parents pid is: %d\n", getpid(), getppid());
		}
		else{

			pid3 = fork();
			if(pid3 == 0){
				printf("This is child 3\n");
				printf("child3 pid is %d, parents pid is: %d\n", getpid(), getppid());
			}
			else{
				sleep(3);
				printf("This is supposed to be the parent\n");
				printf("Parents process id is: %d\n", getpid());
			}
		}

	}
	
	
	return 0;
}

