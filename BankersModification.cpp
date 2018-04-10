
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <bits/stdc++.h>

using namespace std;
vector< int> Available;
vector< vector< int > > Max;
vector< vector< int > > Allocation;
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
	}
	//cout<<"Check= "<<check<<endl;
	
	
	return true;
}
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

bool  safetyAlgorithm()
{
	//cout<<"Inside safety Algorithm\n";
	work=Available;
	int s=0;
	for(int i=0;i<n;i++)
	{
		finish.push_back(0);
	}
	//cout<<"After Assigning finish\n";
	bool check=false;

	while(!allfinish())
	{
		check=false;
		//cout<<"Assigning Check to false\n";
		for(int i=0;i<n;i++)
		{
			if(finish[i]==0&&XlessThanY(Need[i],work))
			{
				cout<<"Executing Process "<<i<<endl;
				addvector(work,Allocation[i]);
				finish[i]=s++;
				check=true;
				break;
			}
		}

		if(allfinish()||s>=n)
		{
			cout<<"System is in  a Safe State\n";
			return true;
		}

		if(!allfinish()&&check==false)
		{
			return false;
		}
		
	}
	return true;
}
void resourcesRequest()
{
	int i;
	int p;
	cout<<"Enter process\n";
	cin>>p;
	cout<<"Enter required resources \n";
	vector<int> request;
	for(i=0;i<m;i++)
	{
		int input;
		cin>>input;
		request.push_back(input);
	}
	if(!XlessThanY(request,Need[p]))
	{
		cout<<"Error Requested More Than Max\n";
		return ;
	}

	if(!XlessThanY(request,Available))
	{
		cout<<"Waiting for the resources to get complete\n";
		return ;
	}

	subvector(Available,request);
	addvector(Allocation[p],request);
	subvector(Need[p],request);
	if(!safetyAlgorithm())
	{
		addvector(Available,request);
		subvector(Allocation[p],request);
		addvector(Need[p],request);
		cout<<"Restoring All Vectors ........ Resources Couldn't Allocated\n";
	}
	else
	{
		cout<<"Resources Successfully Alloted\n";
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
	Need.assign(Allocation.begin(),Allocation.end());
	cout<<"Assigning Need For Processes\n";
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			Need[i][j]=Max[i][j]-Allocation[i][j];
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cout<<Need[i][j]<<" ";
		}
		cout<<endl;
	}
	safetyAlgorithm();

	resourcesRequest();
	return 0;
}