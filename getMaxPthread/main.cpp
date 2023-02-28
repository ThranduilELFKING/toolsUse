#include <stdio.h>
#include <pthread.h>
#include <error.h>
#include <string.h>
#include <unistd.h>

void *thread(void *vargp){
	while(1){
		sleep(10);
	}
}

int main(){
	int err = 0, count = 0;
	pthread_t tid;
	
	while(err == 0){
		err = pthread_create(&tid, NULL, thread, NULL);
		count++;
		printf("count = %d\n", count);
	}

	printf("create thread error: %s \n", strerror(err));
	printf("maximum number of thread within a Process is : %d \n", count);

	getchar();
	return 0;
}