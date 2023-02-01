#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main()
{
    pid_t pid;
    pid = fork();

    if (pid == 0) 
    {
        printf("Child process with PID %d\n", getpid());
        exit(0);
    }
    else 
    {
        printf("Parent process with PID %d\n", getpid());
        sleep(30);
    }
    return 0;
}
