#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#define noOfThread 4




struct word
{
	char s[15];
	int count;
};

int noOfword;

struct word arr[200];
int sizeofhash=0;

void* increase(void* p)
{
	int i;
	char *a = (char*)p;
	int flag=0;
	for(i=0;i<sizeofhash;i++)
	{
		if(strcmp(arr[i].s,a)==0)
		{
			flag=1;
			arr[i].count++;
			break;
		}
	}
	if(flag==0)
	{
		strcpy(arr[sizeofhash].s,a);
		arr[sizeofhash].count=1;
		sizeofhash++;
	}
}
 int main(int argc, char const *argv[])
{
	FILE *fp;
	int i=0;
	char buffer[200][15];
	fp=fopen("a.txt","r");
	

	while(1)
	{
		int count=fscanf(fp,"%s",buffer[i]);
		if(count<1)
		{
			break;
		}
		i++;
	}




	noOfword=i;
	pthread_t tid[noOfThread];
	int wordPerThread=noOfword/noOfThread;
	printf("Word Per Thread = %d\n",wordPerThread );
	int j,k;
	for(j=0;j<noOfThread;j++)
	{
		for(k=0;k<wordPerThread;k++)
		{
			printf(" Word is %s\n", buffer[j+k]);
			pthread_create(&tid[j],NULL,increase,(void*) buffer[j*wordPerThread+k]);
		}

	}
	for(j=0;j<noOfThread;j++)
	{
		pthread_join(tid[j],NULL);
	}
	printf("Size of Hash = %d\n",sizeofhash );
	for(j=0;j<sizeofhash;j++)
	{
		printf("%s\n",arr[j].s );
		printf("%d\n", arr[j].count);
	}


	return 0;
}
