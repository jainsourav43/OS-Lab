#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
void *prime(void *a)
{
	int *r=(int*)a;
	int n=*r;
	int pr[n+1];
	memset(pr,0,sizeof(pr));
	int i,p;
	for(p=2;p*p<=n;p++)
	{
		for(i=2*p;i<=n;i+=p)
		{
			pr[i]=1;
		}
	}


	for(i=2;i<=n;i++)
	{
		if(pr[i]==0)
		{
			printf("   %d  ",i );
		}
	}
	printf("\n");

	return NULL;
}
int main(int *argc ,char  *argv[])
{
	int n=atoi(argv[1]);
	pthread_t tid;
	pthread_create(&tid,NULL,prime,(void*) &n);
	pthread_join(tid,NULL);

}
