#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
bool kmp(char  str[],char pat[],int ,int );
int main(int argc, char* arg[])
{
	ifstream fin;
	char s[1000];
	if(argc==3)
	{
		fin.open(arg[1]);
		
		while(!fin.eof())
		{
			fin.getline(s,1000);
			int n=strlen(s),m=strlen(arg[2]);
			if(kmp(s,arg[2],n,m))// Matching The Pattern IN O(N) 
			{
				cout<<s<<endl;// Printing The Pattern iF match Found  In  the line
			}
			
		}
	}
	else if(argc==4)	// Ignoring the Case if The argument "i" Is Given As Last Argument 	
	{

		fin.open(arg[1]);
		while(!fin.eof())
		{
			fin.getline(s,1000);
			for(int i=0;i<strlen(arg[2]);i++)
			{
				if(arg[2][i]>=65&&arg[2][i]<=90)
				{
					arg[2][i]=arg[2][i]+32;
				}
			}
			int n=strlen(s),m=strlen(arg[2]);
			if(kmp(s,arg[2],n,m))
			{
				cout<<s<<endl;
			}
			
		}	
	}

}
void calculatelps(char pat[],int lps[],int n)
{
	int len=0;
	lps[0]=0;
	int i=1;
	while(i<n)
	{
		if(pat[i]==pat[len])
		{
			lps[i]=++len;
			i++;
		}
		else
		{
			if(len!=0)
			{
				len=lps[len-1];
			}
			else
			{
				lps[i]=0;
				i++;
			}
		}
	}
}
bool kmp(char  str[],char pat[],int n,int m)
{
	int lps[strlen(pat)+1];
	calculatelps(pat,lps,m);
	int i=0,j=0;
	while(i<n)
	{
		if(str[i]==pat[j])
		{
			i++;
			j++;
		}
 		if(j==m)
		{
			return true;
			//j=lps[j-1];
		}
		else
		{
			if(i<n&&str[i]!=pat[j])
			{
				if(j!=0)
				{
					j=lps[j-1];
				}
				else
				i++;
			}
		}
		
		
	}

return false;


	
}



