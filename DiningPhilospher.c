#include <stdio.h>
#include <semaphore.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
// enum states {"Hungry" = 0 ,"Eating" =1,"THINKING"=2};
sem_t chopstick[5];
void *work(void *p)
{
	int i=atoi(p);
	while(1)
	{
		sem_wait(&chopstick[i]);
		sem_wait(&chopstick[(i+1)%5]);
		printf("Eating  %d\n",i+1 );
		sem_post(&chopstick[i]);
		sem_post(&chopstick[(i+1)%5]);
		printf("Thinking  %d \n",i+1);
	}
}
int main(int argc, char const *argv[])
{
	int i;
	for(i=0;i<5;i++)
	{
		sem_init(&chopstick[i],0,1);
	}
	pthread_t tid[5];
	for(i=0;i<5;i++)
	{
		pthread_create(&tid[i],NULL,work,&i);
	}

	for(i=0;i<5;i++)
	{
		pthread_join(tid[i],NULL);
	}
	
	return 0;
}