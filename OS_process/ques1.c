#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
	pid_t pid, mypid,ppid;
	
	
	pid = fork();
	if(pid == 0){
		printf("This is the child Process\n");
		mypid = getpid();
		ppid = getppid();
		printf("The child processes id is: %d, the parents pid is: %d\n", mypid, ppid); 
		printf("My name is: %s\nMy registration number is: %s\n", "Aditya Agarwal", "21BCE1688");
		printf("The child process ends\n");
	}
	
	else{
		wait(NULL);
		printf("This is the parent process\n");
		mypid = getpid();
		printf("The id of parent process is: %d\n", mypid);
		printf("parent process ends\n");
	
	}



	return 0;
}
