#include<bits/stdc++.h>
using namespace std;
void printFrames(vector<int > frames)
{
	for(unsigned int i=0;i<frames.size();i++)
	{
		cout<<frames[i]<<endl;
	}
	cout<<endl<<endl<<endl;
}
void fifo(vector<int> a)
{
	  
	unsigned int n,i,j,pageFault=0,m=0;
	cout<<"Enter the Number of Frames\n";
	cin>>n;
	cout<<endl<<endl;
	vector<int> frames(n,-1);
	for( i=0;i<a.size();i++)
	{
		for(j=0;j<frames.size();j++)
		{
			if(a[i]==frames[j])
			{
				break;
			}
		}
		if(j==frames.size())
		{
			pageFault++;
			frames[m]=a[i];
			m=(m+1)%n;
			
		}
		printFrames(frames);
		
	}
	cout<<"Total NO of PageFault = ";
	cout<<pageFault<<endl;
}
void optimal(vector<int> a)
{
	 int n,i,j,pageFault=0,k;
	cout<<"Enter the Number of Frames\n";
	cin>>n;
	cout<<endl<<endl;
	vector<int> frames;
	for( i=0;i<a.size();i++)
	{
		for(j=0;j<frames.size();j++)
		{
			if(a[i]==frames[j])
			{
				break;
			}
		}
		if(j==frames.size())
		{
			pageFault++;
			if(frames.size()==n)
			{
				int maxdist=0,next;
				for(j=0;j<frames.size();j++)
				{
					for(k=i+1;k<=a.size();k++)
					{
						if(a[k]==frames[j])
						{
							if(maxdist<(i-k))
							{
								maxdist=i-k;
								next=j;
							}
							break;
						}
					}
					if(k==a.size())
					{
						next=j;
					}
				}
				cout<<"next = "<<next<<endl;
				frames[next]=a[i];
			
			}
			else
			{
				frames.push_back(a[i]);
			}
			
		}
		printFrames(frames);
		
	}
	cout<<"Total NO of PageFault = ";
	cout<<pageFault<<endl;
}
void lruCounter(vector<int>a)
{
	unsigned int n,i,j,pageFault=0,counter=0,next;
	cout<<"Enter the Number of Frames\n";
	cin>>n;
	cout<<endl<<endl;
	vector<pair<int,int> > frames(n,make_pair(-1,-1));
	for( i=0;i<a.size();i++)
	{
		for(j=0;j<frames.size();j++)
		{
			if(a[i]==frames[j].first)
			{
				frames[j].second=++counter;
				
				break;
			}
		}
		if(j==frames.size())
		{
			pageFault++;
			int minCounter=INT_MAX;
			if(frames.size()==n)
			{
				for(j=0;j<frames.size();j++)
				{
					if(frames[j].second<minCounter)
					{
						minCounter=frames[j].second;
						next=j;
					}
				}
				frames[next] = make_pair(a[i],++counter);
			}

			
		}
		for(int k=0;k<frames.size();k++)
		{
			cout<<frames[k].first<<"  "<<frames[k].second<<endl;
		}
		cout<<endl<<endl;
		
		
	}
	cout<<"Total NO of PageFault = ";
	cout<<pageFault<<endl;
}
void lruStack(vector<int>a)
{
	unsigned int n,i,j,pageFault=0,k;
	cout<<"Enter the Number of Frames\n";
	cin>>n;
	cout<<endl<<endl;
	vector<int> frames;
	for( i=0;i<a.size();i++)
	{
		for(j=0;j<frames.size();j++)
		{
			if(a[i]==frames[j])
			{
				break;
			}
		}
		if(j==frames.size())
		{
			pageFault++;
			if(frames.size()==n)
			{
				for(k=0;k<frames.size()-1;k++)
				{
					frames[k]=frames[k+1];
				}
				frames[frames.size()-1]=a[i];
				
			}
			else
			{
				frames.push_back(a[i]);
			}
			
		}
		else
		{
				int temp=frames[j];
				for(k=j;k<frames.size()-1;k++)
				{
					frames[k]=frames[k+1];
				}
				frames[frames.size()-1]=temp;
		}
		for(int k=frames.size()-1;k>=0;k--)
		{
			cout<<frames[k]<<endl;
		}
		cout<<endl<<endl;
		
	}
	cout<<"Total NO of PageFault = ";
	cout<<pageFault<<endl;
}
int main()
{
	vector<int>a;
	int n;
	cout<<"Enter the Number of Pages \n";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int t;
		cin>>t;
		a.push_back(t);
	}
	fifo(a);
	optimal(a);
	lruCounter(a);
	lruStack(a);
}
