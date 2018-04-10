#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>




int main(int argc, char const *argv[])
{
	pthread_t tid1,tid2;


	pthread_create(&tid1,NULL,read,NULL);
	pthread_create(&tid2,NULL,write,NULL);
	return 0;
}