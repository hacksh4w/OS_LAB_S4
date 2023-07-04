// Simulation of cp unix command

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main(){
    int fd_handle1, fd_handle2;
    char buff;
    char f1[100], f2[100];

    printf("Enter name of file 1: ");
    scanf("%s",f1);
    printf("Enter name of file 2: ");
    scanf("%s",f2);

    fd_handle1 = open(f1, O_RDONLY);
    fd_handle2 = open(f2, O_CREAT|O_WRONLY|O_TRUNC, S_IRUSR|S_IWUSR);

    if (fd_handle1 == -1){
        printf("Error in opening %s",f1);
        close(fd_handle1);
        close(fd_handle2);
        exit(1);
    }

    printf("%d\n",fd_handle2);

    while (read(fd_handle1, &buff, 1) == 1){
        if (write(fd_handle2, &buff, 1) == -1) {
            printf("Error in writing to %s", f2);
            close(fd_handle1);
            close(fd_handle2);
            exit(1);
        }
    }

    fsync(fd_handle2);
    close(fd_handle1);
    close(fd_handle2);

    printf("Write successful\n");

    fd_handle2 = open(f2, O_RDONLY);
    printf("%d\n",fd_handle2);
    printf("Printing contents of copied file: \n");
    while(read(fd_handle2, &buff, 1) == 1){
        printf("%c", buff);
    }
    printf("\n");
    close(fd_handle2);

    return 0;
}
