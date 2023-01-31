#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
   int a=0, b=1, n=a+b,i,ii;
   pid_t pid;


      pid = fork();
      if (pid == 0)
      {
      		int ii, j=1;
            printf("Enter the number to find the factorial of\n");
            scanf("%d", &ii);
            for(int i=2; i<=ii; i++){
            	j*=i;
            }
		printf("The factorial of %d is: %d\n", ii, j);	
            printf("Child ends\n"); 
      }
      
      else 
      {
         wait(NULL);
         printf("Enter the number of a Fibonacci Sequence:\n");
            scanf("%d", &ii);
            if (ii < 0)
                printf("Please enter a non-negative integer!\n");
            printf("%d %d ",a,b);
            for (i=0;i<ii;i++)
            {
                n=a+b;
                printf("%d ", n);
                a=b;
                b=n;
            }
         printf("Parent ends\n");
      }
      
   return 0;
}
