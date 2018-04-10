#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
int n;
void *fib(void *a)
{
	int *f=(int*)a;
	int i,p;
	f[0]=0;
	f[1]=1;
	for(i=2;i<n;i++)
	{
		f[i]=f[i-1]+f[i-2];
	}
	return NULL;
}
int main(int *argc ,char  *argv[])
{
	n=atoi(argv[1]);
	int a[n+1],i;
	memset(a,0,sizeof(a));
	pthread_t tid;
	pthread_create(&tid,NULL,fib,(void*) a);
	pthread_join(tid,NULL);
	for(i=0;i<n;i++)
	{
		printf("  %d  ",a[i] );
	}
	printf("\n");

}
