#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int n;
void *average(void *a)
{
	int i;
	int sum=0;
	int *p;
	p=(int*) a;
	printf("Inside Average Threads\n");
	for(i=0;i<n;i++)
	{
		sum+=p[i];
	}
	printf("Average of array is %d\n", sum/n);
	return NULL;
}

void *minimum(void *a)
{
	//sleep(1);
	printf("Inside Minimum Threads\n");
	int i;
	int *p=(int*) a;
	int min=p[0];
	for(i=0;i<n;i++)
	{
		printf("Inside Minimumn Threads\n");
		sleep(1);
		if(min>p[i])
		{
			min=p[i];
		}
	}
	printf("Minimum is %d\n", min);

	return NULL;
}
void *maximum(void *a)
{
	//sleep(1);
	printf("Inside Maximum Threads\n");
	int i;
	int *p=(int*)a;
	int max=p[0];
	for(i=0;i<n;i++)
	{
		printf("Inside Maximum Threads\n");
		sleep(1);
		if(max<p[i])
		{
			max=p[i];
		}
	}
	printf("Maximum is %d \n",max);
	return NULL;
}

int main()
{
	pthread_t tid1,tid2,tid3;
	int a[10];
	printf("Enter the size \n");
	scanf("%d",&n);
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Before Thread\n");
	 pthread_create(&tid1,NULL,average,(void*)a);
	pthread_create(&tid2,NULL,minimum,(void*) a);
	pthread_create(&tid3,NULL,maximum,(void*)a);
	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);
	pthread_join(tid3,NULL);
	printf("After Thread\n");
	exit(0);
}
