#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int SUM=0,N;
void *isPerfect(void *p)
{
	int *a=(int*) p;
	int n=*a;
		printf("%d\n",n );

	if(N%n==0)
	{
		SUM+=n;
	}
}
int main(int argc, char const *argv[])
{
	int i,j;
	int p=atoi(argv[argc-1]);
	pthread_t tid1[p];
	N=atoi(argv[1]);
	for(i=1;i<=N/2;i+=p)
	{
			for(j=0;j<p&&j+i<=N/2;j+=1)
			{
			int *temp=(int *)(malloc(sizeof(int)));
			*temp = i+j;
			pthread_create(&tid1[j],NULL,isPerfect,(void*) temp);
			}
			for(j=0;j<p&&j+i<=N/2;j+=1)
			{
			pthread_join(tid1[j],NULL);
			}
	}
	if(SUM==N)
	{
		printf("IS  PERFECT\n");
	}
	else
	{
				printf("%d   %d \n",SUM,N );
				printf("NOT A PERFECT\n");

	}
	return 0;
}