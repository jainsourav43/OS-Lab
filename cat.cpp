

#include <iostream>
#include <fstream>
using namespace  std;
int main(int argc, char* arg[])
{
	ifstream fin1,fin2;
	int linecount=0;
	if(argc==3)
	{

		string s;
		fin1.open(arg[1]);
		while(!fin1.eof())
		{
			linecount++;
			getline(fin1,s);
			cout<<s;
			cout<<"$\n";
		}
		fin2.open(arg[2]);
		while(!fin2.eof())
		{
			linecount++;
			getline(fin2,s);
			cout<<s;
			cout<<"$\n";
		}
		fin1.close();
		fin2.close();
		cout<<linecount<<endl;
	}
	else if(argc==2)
	{
		string s;
		fin1.open(arg[1]);
		while(!fin1.eof())
		{
			linecount++;
			getline(fin1,s);
			cout<<s;
			cout<<"$\n";
		}
		fin1.close();
		cout<<linecount<<endl;
	}
	else
	{
		cout<<"WAit for Right INput ";
	}




}
