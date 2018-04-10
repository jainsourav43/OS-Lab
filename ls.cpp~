#include <iostream>
#include <dirent.h>
#include <string>
#include <sys/types.h>
#include <vector>
#include <iterator>
using namespace std;
typedef std:: vector< std::string >stringvec;
void read_directory(const std::string& name,stringvec &v)
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
	stringvec v;
	read_directory(argv[1],v);
	std::copy(v.begin(),v.end(),std::ostream_iterator<std:: string > (std:: cout,"\n")  );

}

