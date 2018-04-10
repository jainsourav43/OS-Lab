#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <pthread.h>
int shared=1;
int  cp=0;
pthread_mutex_t lock;
void *producer(void *p)
{
	while(1)
	{
		if(cp==1)
		sleep(1);
		pthread_mutex_lock(&lock);
		shared++;
		printf("Producer : %d \n",shared);
		cp=1;
	    pthread_mutex_unlock(&lock);	
	    sleep(1);
		
	}
	return NULL;
}

void *consumer(void *p)
{
	while(1)
	{
		if(cp==0)
		sleep(1);
		pthread_mutex_lock(&lock);
		printf("Consumer : %d \n",shared);
		cp=0;
		pthread_mutex_unlock(&lock);		
		sleep(1);

	}
}

int main(int *argc ,char  *argv[])
{
	pthread_t tid1,tid2;
	pthread_create(&tid1,NULL,producer,NULL);
	pthread_create(&tid2,NULL,consumer,NULL);
	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);
	return 0;

}
