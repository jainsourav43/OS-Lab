#include <stdio.h>
#include <semaphore.h>
#include <stdlib.h>
#include <unistd.h>
sem_t full,empty,mutex;
int buffer[20],in=0,out=0,size=10,val=0;
void produce()
{
	while(1){
	sem_wait(&empty);
	sem_wait(&mutex);
	in=(in+1)%size;
	buffer[in]=val++;
	//sleep(1);
	printf("Producing =%d \n",val-1 );
	sem_post(&mutex);
	sem_post(&full);
	}
}
void consumer()
{
	while(1){
	sem_wait(&full);
	sem_wait(&mutex);
	out=(out+1)%size;
//	sleep(1);
	printf("Consuming  =%d \n",buffer[out] );
	sem_post(&mutex);
	sem_post(&empty);
	}
}
int main()
{
	sem_init(&full,0,0);
	sem_init(&empty,0,10);
	sem_init(&mutex,0,1);
	pthread_t tid1,tid2;
	pthread_create(&tid1,NULL,produce,NULL);
	pthread_create(&tid2,NULL,consumer,NULL);
	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);


}