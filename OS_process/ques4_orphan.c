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
        printf("Orphan process with PID %d\n", getpid());
        sleep(5);
        printf("Orphan process with PID %d adopted by init process\n", getpid());
        printf("Now the ppid of this process is: %d\n", getppid());
        sleep(10);
    }
    else 
    {
        printf("Parent process with PID %d\n", getpid());
        exit(0);
    }
    return 0;
}
