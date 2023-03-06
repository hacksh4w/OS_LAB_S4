#include<stdio.h> // printf()
#include<stdlib.h> // exit()
#include<sys/types.h> // pid_t
#include<sys/wait.h> // wait()
#include<unistd.h> // fork

int main(int argc, char **argv) {

pid_t pid;
pid = fork();

if(pid==0) {
	printf("This is the child process and pid is %d\n",getpid());

	int i=0;
	for(i=0;i<10;i++){
		printf("%d\n",i);
	}
	exit(0);
}
else if(pid > 0) {

	printf("This is the parent process and pid is %d\n",getpid());
	int status;
	wait(&status);
	printf("Child is reaped\n");
}
else {
	printf("Error in forking..\n");
	exit(EXIT_FAILURE);
}
return 0;
}
