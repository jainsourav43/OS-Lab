#include<iostream>
#include<cstdlib>
#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
#include <sys/wait.h>
#include<signal.h>
using namespace std;
void parentprocess()
{
	for(int i=1;i<=100;i++)
	cout<<i<<" ";
	cout<<endl;
}
void childprocess()
{
	for(int i=101;i<=200;i++)
	cout<<i<<" ";
	cout<<endl;
}
int main()
{
	pid_t pid,pid2,pid3;
	pid=fork();
	pid2=fork();
	pid3=fork();
	cout<<"pid1,pid2,pid3= "<<pid<<"  "<<pid2<<"  "<<pid3<<endl; 
	if(pid<0||pid2<0||pid3<0)
	{
		fprintf(stderr,"fork failed");
	}
	else if(pid==0||pid2==0||pid3==0)
	{
		printf("Child Process\n");
		childprocess();
		printf("PID of Child Process is %d\n",getpid());
		kill(getpid(),SIGKILL);
		printf("After child\n");
	}
	else
	{
		wait(NULL);
		printf("Parent Process\n");
		parentprocess();
		printf("PID of Parent Process is %d\n",getpid());
		printf("After Parent\n");
	}
	//printf("Hii There\n");




}

