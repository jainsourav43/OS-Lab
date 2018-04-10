#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#define time_quanta 10
int arrival[10],bursttime[10];
int max(int a,int b)
{
	if(a>b) return a;
	return b;
}
int check(int f[])
{
	return 1;
}
void fcfs(int n)
{
	int i,total=0,j,nextprocess=0;
	int totaltime,min,prev=0,waitingtime=0;
	for(i=0;i<n;i++)
	{
		
			if(arrival[i]>=total)
			{
			waitingtime+=0;
			total=total+bursttime[i];
			}
			else
			{
			waitingtime=waitingtime+total-arrival[i];
			total=total+bursttime[i];
			}
	}
	printf("%d, %d \n",waitingtime , total );
	double averageWaitingTime=(double)waitingtime/(double)n;
	printf("Average time under FCFS is %f\n",averageWaitingTime);

}

void sjf(int n)
{
	int i,total=0,j;
	int totaltime=0;

	int finished[n],min,nextprocess=0,waitingtime=0;
	memset(finished,0,sizeof(finished));
	for(i=0;i<n;i++)
	{
		totaltime=totaltime+bursttime[i];
	}
	totaltime=max(totaltime,arrival[n-1]+bursttime[n-1]);
	for(i=0;i<totaltime;i++)
	{
		min=INT_MAX;
		for(j=0;j<n;j++)
		{
			if(finished[j]==0&&min>bursttime[j]&&arrival[j]<=i)
			{
				min=bursttime[j];
				nextprocess=j;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(finished[j]==0&&min>bursttime[j])
			{
				min=bursttime[j];
				nextprocess=j;
			}
		}
		waitingtime+=total;
		total=total+bursttime[nextprocess];
		finished[nextprocess]=1;
	}	
	double averageWaitingTime=(double)waitingtime/(double)n;
	printf("Average time under SJF is %f\n",averageWaitingTime);

}
void sjfPreemptive(int n)
{
	int i,total=0,j,prev=0;
	int finished[n],min,nextprocess,waitingtime=0;
	int previous[n],prevproc=0,prevproctime=0;
	memset(finished,0,sizeof(finished));
	memset(previous,0,sizeof(finished));
	int totaltime=0;
	for(i=0;i<n;i++)
	{
		totaltime+=bursttime[i];
	}
	for(i=0;i<totaltime;i++)
	{
		min=INT_MAX;nextprocess=INT_MIN;
		for(j=0;j<n;j++)
		{
			if(finished[j]==0&&min>bursttime[j])
			{
				min=bursttime[j];
				nextprocess=j;
			}
		}
		if(nextprocess==INT_MIN)
		{
			break;
		}
		if(prev==nextprocess)
		{
			bursttime[nextprocess]=bursttime[nextprocess]-1;
			if(bursttime[nextprocess]==0)
			{
				finished[nextprocess]=1;
			}
			continue;
		}
		else
		{
			waitingtime+=i - max(previous[nextprocess],arrival[nextprocess]);
			prev=nextprocess;
		}
		
	}
	double averageWaitingTime=(double)waitingtime/(double)n;
	printf("Average time under SJF Preemptive is  is %f\n",averageWaitingTime);

}
void RoundRobin(int n)
{
	int i,total=0,j;
	int finished[n],min,nextprocess=0,waitingtime=0;
	memset(finished,0,sizeof(finished));
	int totaltime=0;
	while(1)
	{
		if(check(finished))
		{
			break;
		}

		if(bursttime[nextprocess]<=time_quanta)
		{
			bursttime[nextprocess]=0;
			finished[nextprocess]=1;
			waitingtime=total-arrival[nextprocess];
			total = total;



			nextprocess=(nextprocess+1)%n;
		}



	}

	double averageWaitingTime=(double)total/(double)n;
	printf("Average time under SJF Preemptive is  is %f\n",averageWaitingTime);

}

int  main(int argc, char const *argv[])
{
	FILE *fp;
	fp=fopen("in.txt","r");
	int n;
	char buffer[100][10],i=0;
	while(1)
	{
		int count=fscanf(fp,"%s",buffer[i]);
		printf("%s\n",buffer[i] );
		if(count<1)
		{
			break;
		}
		i++;
	}
	n=i/2;
	for(i=0;i<n;i++)
	{
		arrival[i]=atoi(buffer[i]);
		bursttime[i]=atoi(buffer[i+n]);
	}
	for(i=0;i<n;i++)
	{
		printf(" Arrival %d\n",arrival[i] );
		printf("BUrst  %d\n",bursttime[i] );
	}
	fcfs(n);

	return 0;
}