#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;
int main(int argc,char * arg[])
{

	ifstream fin;
	fin.open(arg[2]);
	string s;
	int len,maxlen=0,i;
	int wc=0,charcount=0,bytecount=0,linecount=0;
	while(!fin.eof())
	{

		linecount++;//Incrementing lINE COUNT
		getline(fin,s);//Readng data from file line by line
		i=0;
		len=s.length();// Calculating the length
		if(maxlen<len)// Checking for Maximum
		{
			maxlen=len;
		}
		while(i<len)
		{
			while(s[i]!=' '&&i<len)
			{
				bytecount++;charcount++;
				i++;
			}
			bytecount++;charcount++;
			i++;
			wc++;
		}
		



	}


	if(strcmp(arg[1],"L")==0)
	{
		cout<<maxlen<<endl;
	}
	else if(strcmp(arg[1],"l")==0)
	{
		cout<<linecount<<endl;
	}
	else if(strcmp(arg[1],"m")==0)
	{
		cout<<charcount<<endl;
	}




}
