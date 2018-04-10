#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <sys/types.h>
#include <pthread.h>
#include <unistd.h>
int full=0,empty=10,mutex=1;
int buffer[100];
int size=10,c=0;
int in=0,out=0;
void wait(int *s)
{
	while(s<=0);
	s--;
}
void signal(int *s)
{
	s++;
}
void put()
{
	wait(&empty);
	wait(&mutex);
	in=(in+1)%size;
	buffer[in]=c++;
	printf("Producer = %d\n",buffer[in] );
	sleep(1);
	signal(&mutex);
	signal(&full);
	
}
void get()
{
	wait(&full);
	wait(&mutex);
	printf("Consumer =%d \n",buffer[out]);
	sleep(1);
	out=(out+1)%size;
	signal(&mutex);
	signal(&empty);
}
void *producer(void* p)
{
	while(1)
	{
		put();
	}
}
void *consumer(void *p)
{
	while(1)
	{
		get();
		//consume it 
	}
}






int main(int argc, char const *argv[])
{
	/* code */


	pthread_t tid1,tid2;
	pthread_create(&tid1,NULL,producer,NULL);
	pthread_create(&tid2,NULL,consumer,NULL);
	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);


	return 0;
}