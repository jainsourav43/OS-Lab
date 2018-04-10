#include <bits/stdc++.h>
using namespace std;
#define left 1
#define right 2
void fcfs(vector<int> sector)
{
	int head,i,j,sum=0;
	cout<<"Enter the Initial Head Position\n";
	cin>>head;
	for(i=0;i<sector.size();i++)
	{
		sum=sum+abs(head-sector[i]);
		head=sector[i];	
	}
	cout<<sum<<endl;
}
void sstf(vector<int> sector)
{
	int head;
	cout<<"Enter the Initial Head Position\n";
	cin>>head;
	vector<bool>finish(sector.size(),0);
	int i,j,sum=0;
	for(i=0;i<sector.size();i++)
	{
		int minDistance =INT_MAX;
		int next;
		for(j=0;j<sector.size();j++)
		{
			if(finish[j]==false)
			{
				if(minDistance>abs(sector[j]-head))
				{
					minDistance=abs(head-sector[j]);
					next=j;
				}
			}
		}
		finish[next]=true;
		sum=sum+abs(head-sector[next]);
		head=sector[next];	
	}
	cout<<sum<<endl;
}
void scan(vector<int> sector)
{
	int head,i,j,start ,end ;
	cout<<"Enter the Start of the Disk :  ";
	cin>>start;
	cout<<"Enter the End of the Disk : ";
	cin>>end;
	cout<<"Enter the Head of Disk : ";
	cin>>head;
	map<int,int> m;
	int sum=0;
	for(i=0;i<sector.size();i++)
	{
		m[sector[i]]=true;
	}
	int direction;
	int current=head;
	cout<<"Enter the Initial Diirection of Scanning 1 for left 2 for right\n";
	cin>>direction;
	while(m.size()>0)
	{
		if(direction==left)
		{
			if(m.find(current)!=m.end())
			{
				sum=sum+abs(current-head);
				head=current;
				m.erase(current);
				cout<<"\nFetching : "<<current<<endl;
			}
			current=current-1;
			if(current<start)
			{
				sum=sum+abs(start-head);
				head=start;
				current=start;
				direction=right;
				cout<<"\nFetching : "<<start<<endl;
			}
		}
		else
		{
			if(m.find(current)!=m.end())
			{
				sum=sum+abs(current-head);
				head=current;
				m.erase(current);
				cout<<"\nFetching : "<<current<<endl;
			}
			current=current+1;
			if(current>end)
			{
				sum=sum+abs(end-head);
				head=end;
				cout<<"\nFetching : "<<end<<endl;
				current=end;
				direction=left;
			}

		}
	} 
	cout<<sum<<endl;
	
}


void cscan(vector<int> sector)
{
	int head,i,j,start ,end ;
	cout<<"Enter the Start of the Disk :  ";
	cin>>start;
	cout<<"Enter the End of the Disk : ";
	cin>>end;
	cout<<"Enter the Head of Disk : ";
	cin>>head;
	map<int,int> m;
	int sum=0;
	for(i=0;i<sector.size();i++)
	{
		m[sector[i]]=true;
	}
	int direction;
	int current=head;
	cout<<"Enter the Initial Diirection of Scanning 1 for left 2 for right\n";
	cin>>direction;
	while(m.size()>0)
	{
		if(direction==left)
		{
			if(m.find(current)!=m.end())
			{
				sum=sum+abs(current-head);
				head=current;
				m.erase(current);
				cout<<"\nFetching : "<<current<<endl;
			}
			current=current-1;
			if(current<start)
			{
				sum=sum+abs(start-head);
				head=end;
				current=end;
				direction=left;
				cout<<"\nFetching : "<<start<<endl;
			}
		}
		else
		{
			if(m.find(current)!=m.end())
			{
				sum=sum+abs(current-head);
				head=current;
				m.erase(current);
				cout<<"\nFetching : "<<current<<endl;
			}
			current=current+1;
			if(current>end)
			{
				sum=sum+abs(end-head);
				head=0;
				cout<<"\nFetching : "<<end<<endl;
				current=0;
				direction=right;
			}

		}
	} 
	cout<<sum<<endl;
	
}
void look(vector<int> sector)
{
	int head,i,j,start ,end ;
	cout<<"Enter the Head of Disk : ";
	cin>>head;
	map<int,int> m;
	int sum=0;
	for(i=0;i<sector.size();i++)
	{
		m[sector[i]]=true;
	}
	start = *min_element(sector.begin(),sector.end());
	end = *max_element(sector.begin(),sector.end());
	int direction;
	int current=head;
	cout<<"Enter the Initial Diirection of Scanning 1 for left 2 for right\n";
	cin>>direction;
	while(m.size()>0)
	{
		if(direction==left)
		{
			if(m.find(current)!=m.end())
			{
				sum=sum+abs(current-head);
				head=current;
				m.erase(current);
				cout<<"\nFetching : "<<current<<endl;
			}
			current=current-1;
			if(current<start)
			{
				sum=sum+abs(start-head);
				head=start;
				current=start;
				direction=right;
			//	cout<<"\nFetching : "<<start<<endl;
			}
		}
		else
		{
			if(m.find(current)!=m.end())
			{
				sum=sum+abs(current-head);
				head=current;
				m.erase(current);
				cout<<"\nFetching : "<<current<<endl;
			}
			current=current+1;
			if(current>end)
			{
				sum=sum+abs(end-head);
				head=end;
				//cout<<"\nFetching : "<<end<<endl;
				current=end;
				direction=left;
			}

		}
	} 
	cout<<sum<<endl;
	
}
void clook(vector<int> sector)
{
	int head,i,j,start ,end ;
	cout<<"Enter the Head of Disk : ";
	cin>>head;
	map<int,int> m;
	int sum=0;
	for(i=0;i<sector.size();i++)
	{
		m[sector[i]]=true;
	}
	start = *min_element(sector.begin(),sector.end());
	end = *max_element(sector.begin(),sector.end());
	int direction;
	int current=head;
	cout<<"Enter the Initial Diirection of Scanning 1 for left 2 for right\n";
	cin>>direction;
	while(m.size()>0)
	{
		if(direction==left)
		{
			if(m.find(current)!=m.end())
			{
				sum=sum+abs(current-head);
				head=current;
				m.erase(current);
				cout<<"\nFetching : "<<current<<endl;
			}
			current=current-1;
			if(current<start)
			{
				sum=sum+abs(start-head);
				head=end;
				current=end;
				direction=left;
				cout<<"\nFetching : "<<start<<endl;
			}
		}
		else
		{
			if(m.find(current)!=m.end())
			{
				sum=sum+abs(current-head);
				head=current;
				m.erase(current);
				cout<<"\nFetching : "<<current<<endl;
			}
			current=current+1;
			if(current>end)
			{
				sum=sum+abs(end-head);
				head=0;
				cout<<"\nFetching : "<<end<<endl;
				current=0;
				direction=right;
			}

		}
	} 
	cout<<sum<<endl;
	
}
int main()
{
	int n;
	cout<<"Enter The Number of Sectors to Access\n";
	cin>>n;
	vector<int> sectors;
	cout<<"Enter Sectors\n";
	for(int i=0;i<n;i++)
	{
		int temp;cin>>temp;
		sectors.push_back(temp);
	}
	cout<<"\nTotal head Accesses in FCFS : ";
	fcfs(sectors);
	cout<<"\n Total Head Access in SSTF : ";
	sstf(sectors);
	cout<<"\nTotal Head Access in Scan :  ";
	scan(sectors);
	cout<<"\nTotal Head Access in CScan :  ";
	cscan(sectors);
	cout<<"\nTotal Head Access in LOOk :  ";
	look(sectors);
	cout<<"\nTotal Head Access in LOOk :  ";
	clook(sectors);
}