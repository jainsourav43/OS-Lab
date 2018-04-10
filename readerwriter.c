#include <stdio.h>
#include <semaphore.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
sem_t Read,Write;
int readcount=0;
void *writer()
{
	while(1){
	sem_wait(&Write);
	printf("Writing Bro:)\n");
	printf("The Number Of Readers in Writer%d\n", readcount);
	sem_post(&Write);
	}
}
void *reader()
{
	while(1){
		sem_wait(&Read);
		readcount++;
		if(readcount==1)
		{
			sem_wait(&Write);
		}
		sem_post(&Read);
		sem_wait(&Read);
		printf("Reading the Novel\n");
		printf("The Number Of Readers %d\n", readcount);
		readcount--;
				printf("The Number Of Readers after decrement %d\n", readcount);
		if(readcount==0)
		{
			sem_post(&Write);
		}
		sem_post(&Read);
	}
}
int main()
{
	sem_init(&Read,0,1);
	sem_init(&Write,0,1);
	int i;
	pthread_t tid1[10],tid2;
	pthread_create(&tid2,NULL,writer,NULL);
	for(i=0;i<10;i++)
	pthread_create(&tid1[i],NULL,reader,NULL);
	
	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);


}