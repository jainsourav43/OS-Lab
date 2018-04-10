#include <stdeio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <vector.h>
#include <bits/stdc++.h>

vector< int> Available;
vector< vector< int > > Max;
vector <vector< int > > Allocation;
vector < vector <int> > Need;
vector< int> work;
vector< int> finish;
int m,input,n;
bool XlessThanY(vector<int> x,vector <int> y)
{
	int i=0;
	bool check=false;
	for(i=0;i<x.size();i++)
	{
		if(x[i]>y[i])
		{
			return false;
		}
		if(x[i]<y[i])
		{
			check=true;
		}
	}
	if(check)
	return true;
	
	return false;
}
void addvector(vector<int> &a,vector<int> &b)
{
	for(int i=0;i<a.size();i++)
	{
		a[i]=a[i]+b[i];
	}
}
bool allfinish()
{
	for(int i=0;i<finish.size();i++)
	{
		if(!finish[i])
		{
			return false;
		}
	}
	return true;
}

void safetyAlgorithm()
{
	work.assign(Available);
	finish.assign(n,0);
	bool check=false;

	while(!allfinish())
	{
		check=false;
		for(i=0;i<n;i++)
		{
			if(finish[i]==false&&XlessThanY(Need[i],work))
			{
				cout<<"Executing Process "<<i<<endl;
				addvector(work,Allocation[i]);
				finish[i]=true;
				check=true;
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	cout<<"Enter the Number of Processes\n";
	cin>>n;
	cout<<"Enter the Number of Resources\n";
	cin>>m;
	cout<<"Enter available Resources\n";
	for(int i=0;i<m;i++)
	{
		cin>>input;
		Available.push_back(input);
	}
	cout<<"Enter Max Values of Resources\n";
	for(int i=0;i<n;i++)
	{
		vector<int> cur;
		for(int j=0;j<m;j++)
		{
			cin>>input;
			cur.push_back(input);
		}
		Max.push_back(cur);
	}
	cout<<"Enter Allocation Values of Allocation\n";
	for(int i=0;i<n;i++)
	{
		vector<int> cur;
		for(int j=0;j<m;j++)
		{
			cin>>input;
			cur.push_back(input);
		}
		Allocation.push_back(cur);
	}
	Need.assiign(Allocation);
	cout<<"Assigning Need For Processes\n";
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			Need[i][j]=Max[i][j]-Allocation[i][j];
		}
	}
	safetyAlgorithm();
	







	return 0;
}