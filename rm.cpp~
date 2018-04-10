#include <iostream>
#include <sys/types.h>
#include <unistd.h> 
#include <stdio.h> 
#include <vector>
#include <string>
#include <dirent.h>
using namespace std;
typedef std:: vector< std::string >stringvec;

void read_directory(const std::string& name,stringvec &v,string str )
{
	DIR *dirp=opendir(name.c_str());
	struct dirent *dp;
	while((dp=readdir(dirp))!=NULL)
	{
		v.push_back(dp->d_name);


	}


	closedir(dirp);
}
int main(int argc, char* argv[])
{
	int status=remove(argv[1]);
	if(!status)
	{
		cout<<"Successful\n";
	}
	else
	{
		cout<<"Unsuccessful\n";
	}
}

