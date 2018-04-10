#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <bits/stdc++.h>

using namespace std;
vector< int> Available;
vector< vector< int > > Request;
vector< vector< int > > Allocation;
vector<int> finish;
vector<int > work;
int n,m;


void addvector(vector<int> &a,vector<int> &b)
{
	for(int i=0;i<a.size();i++)
	{
		a[i]=a[i]+b[i];
	}
}

void subvector(vector<int> &a,vector<int> &b)
{
	for(int i=0;i<a.size();i++)
	{
		a[i]=a[i]-b[i];
	}
}



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
	}
	//cout<<"Check= "<<check<<endl;
	
	
	return true;
}


bool allfinish()
{
	for(int i=0;i<finish.size();i++)
	{
		if(!finish[i])
		{
		//	cout<<"FAlse\n";
			return false;
		}
	}
	return true;
}


bool isZero(vector<int> a)
{
	for(int i=0;i<n;i++)
	{
		if(!a[i])
		{
			return false;
		}
	}
	return true;
}


bool detectDeadlock()
{
	work=Available;
	cout<<"Inside Detect DeadLock\n";
	int i;
	bool check=false;
	for(i=0;i<n;i++)
	{
		finish.push_back(0);
	}
	for(i=0;i<n;i++)
	{
		if(!isZero(Allocation[i]))
		{
			finish[i]=0;
		}
		else
		{
			finish[i]=1;
		}
	}
	while(!allfinish())
	{
		check=false;
		//cout<<"Assigning Check to false\n";
		for(int i=0;i<n;i++)
		{
			if(finish[i]==0&&XlessThanY(Request[i],work))
			{
				cout<<"Executing Process "<<i<<endl;
				addvector(work,Allocation[i]);
				finish[i]=true;
				check=true;
				break;
			}
		}

		if(allfinish())
		{
			return false;
		}

		if(!allfinish()&&check==false)
		{
			return true;
		}
	}
	return false;

}





int main(int argc, char const *argv[])
{
	int input;
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
	cout<<"Enter Request Values of Resources\n";
	for(int i=0;i<n;i++)
	{
		vector<int> cur;
		for(int j=0;j<m;j++)
		{
			cin>>input;
			cur.push_back(input);
		}
		Request.push_back(cur);
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

	if(detectDeadlock())
	{
		cout<<"Deadlock Detected\n";
	}
	else
	{
		cout<<"Deadlock Not Detected\n";
	}
	return 0;
}
