#include <stdio.h>
#include <stdlib.h>
#define size 10

int mutex = 1;
int full=0, empty = size, x = 0;

int wait(int s){
	return --s;
}

int signal(int s){
	return ++s;
}

void producer(){
	mutex=wait(mutex);
	empty = wait(empty);
	full = signal(full);
	mutex = signal(mutex);
	x++;
	printf("Producer produces item: %d\n",x);
}

void consumer(){
	mutex = wait(mutex);
	full = wait(full);
	mutex = signal(mutex);
	empty = signal(empty);
	printf("Consumer comsumes: %d\n",x);
	x--;
}


void main(){
	int n, i;
	printf("\n1. Press 1 for Producer\n2. Press 2 for Consumer\n3. Press 3 for Exit");
    for (i = 1; i > 0; i++) {
        printf("\nEnter your choice:");
        scanf("%d", &n);
        switch (n) {
        case 1:
            if ((mutex == 1)&& (empty != 0))
                producer();
            
            else 		
                printf("Buffer is full!\n");
            break;
        case 2:
            if ((mutex == 1)&& (full != 0))
                consumer();
 
            else 
                printf("Buffer is empty!\n");
            break;
        case 3:
            exit(0);
            break;
        }
    }
}
