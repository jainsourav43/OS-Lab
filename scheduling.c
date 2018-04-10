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
{int n;
	int i=0;

	for(i=0;i<n;i++)
	{
		if(f[i]==0)
			return 0;
	}
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
	int finished[n],min,nextprocess=0,waitingtime=0;
	int totaltime=0;
	memset(finished,0,sizeof(finished));
	for(i=0;i<n;i++)
	{
		totaltime=totaltime+bursttime[i];
	}
	totaltime=max(totaltime,arrival[n-1]+bursttime[n-1]);
	for(i=0;i<totaltime;)
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
		waitingtime+=total-arrival[nextprocess];
		total=total+bursttime[nextprocess];
		finished[nextprocess]=1;
		i+=bursttime[nextprocess];
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
	totaltime=max(totaltime,arrival[n-1]+bursttime[n-1]);

	//printf("Total Time = %d \n", totaltime);
	for(i=0;i<=totaltime;i++)
	{
		min=INT_MAX;nextprocess=INT_MIN;
		for(j=0;j<n;j++)
		{
			if(finished[j]==0&&min>bursttime[j]&&arrival[j]<=i)
			{
				min=bursttime[j];
				nextprocess=j;
			}
		}
	//	printf(" New Next Process ,prev Process =  %d %d \n",nextprocess,prev);
	//	printf("Waiting time  and current time =%d  %d \n",waitingtime,i);
		if(nextprocess==INT_MIN)
		{
			break;
		}
		
	//	printf("Previour run time = %d \n",previous[nextprocess] );
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

			waitingtime+=(i) - max(arrival[nextprocess],previous[nextprocess]);

			bursttime[nextprocess]--;
			previous[prev]=i;
			prev=nextprocess;

		}
		//printf("Next Process ,prev Process =  %d %d \n",nextprocess,prev);

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
	for(i=0;i<n;i++)
	{
		totaltime+=bursttime[i];
	}
	for(i=0;i<totaltime;i++)
	{

	}
	double averageWaitingTime=(double)total/(double)n;
	printf("Average time under SJF Preemptive is  is %f\n",averageWaitingTime);
}
int priority[10];
void priorityscheduling(int n)
{
	
	int i,total=0,j;
	int finished[n],min,nextprocess=0,waitingtime=0;
	int totaltime=0;
	memset(finished,0,sizeof(finished));
	for(i=0;i<n;i++)
	{
		totaltime=totaltime+bursttime[i];
	}
	totaltime=max(totaltime,arrival[n-1]+bursttime[n-1]);
	for(i=0;i<totaltime;)
	{
		min=INT_MAX;
		for(j=0;j<n;j++)
		{
			if(finished[j]==0&&min>priority[j]&&arrival[j]<=i)
			{
				min=bursttime[j];
				nextprocess=j;
			}
		}
		waitingtime+=total-arrival[nextprocess];
		total=total+bursttime[nextprocess];
		finished[nextprocess]=1;
		i+=bursttime[nextprocess];
	}	
	double averageWaitingTime=(double)waitingtime/(double)n;
	printf("Average time under SJF is %f\n",averageWaitingTime);
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
	sjf(n);
	sjfPreemptive(n);
        RoundRobin(n);
	return 0;
}
