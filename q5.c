#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *isPrime1(void *p)
{
	int *a=(int*) p;
	int n=*a,i;
	int flag=0;
	for( i=2;i*i<=n;i++)
	{
		if(n%i==0)
		{
			flag=1;
			break;
		}
	}
	if(flag==0)
	{
		printf("%d ",n );
		printf("IS PRIME \n");
	}

}
int main(int argc, char const *argv[])
{
	int n,i;
	printf("%s\n", "Enter n");
	scanf("%d",&n);
	int a[n];
	printf("%s\n","Enter Elements" );
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	pthread_t tid1;
	for(i=0;i<n;i+=1)
	{
	pthread_create(&tid1,NULL,isPrime1,(void*) &a[i]);
	pthread_join(tid1,NULL);
	}
	return 0;
}