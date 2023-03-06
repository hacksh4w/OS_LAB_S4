#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

// Driver code
int main()
{


    // On the success of a fork() system call:
    //   The Process ID (PID) of the child process is returned to the parent process.
    //   0 is returned to the child process.
    int a = 10;
    printf("%d \n",&a);
    printf("parent");
   int id = fork();

	if  (id == 0){
    
	a = a+1;

	printf("child");
	}
	pid_t pid2=  getpid();
	printf("%d\n",a);  
    // All statements below the (fork) are executed in both parent and child process
}
