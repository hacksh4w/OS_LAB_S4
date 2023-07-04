// Simulation of ls unix command
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
void main(){
	char dirname[10];
	DIR *dirp;
	struct dirent *d;
	printf("Enter directory name: ");
	scanf("%s",dirname);
	dirp = opendir(dirname);
	if (dirp == NULL){
		perror("Cannot find directory");
		exit(-1);
	}
	while (d = readdir(dirp))
		printf("%s\n",d->d_name);
}


