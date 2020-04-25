#include <dirent.h>
#include <sys/stat.h>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <string>

using namespace std;

/* All our files will be stored in the /var/lib/deadline directory
   of delenn so they can be accessed easily by the user

   This code will list all the files present in the directory
   to help keep list of what we have

   Attempting to change the file permissions of all files in the
   directory to allow rwx by group members and file owners
*/

void open(char *dir_name)
{
        DIR *dir; // pointer to directory
        struct dirent *component; // directory contents
        struct stat info;

	int chmod(const char *dir_name, mode_t mode);

        // open direcotry
        dir = opendir(dir_name);

        if(!dir)
        {
                cout << "\nDirectory Not Found\n" << endl;
                return;
        }

        // read 
	while((component = readdir(dir)) != NULL)
        {
                if(component->d_name[0] != '.')
                {
                        string path = string(component->d_name);
                        cout << "File: " << path << "\t \t \t***in directory" << ": " << string(dir_name) << endl;
                        stat(path.c_str(), &info); // get information from this path
                        if(S_ISDIR(info.st_mode))
                        {
                                open((char*)path.c_str());
                        	chmod(path.c_str(), S_IRWXO);	
			}
                }
        }
        closedir(dir);
}

int main()
{
        open((char*) "/var/lib/deadline");
        return 0;
}                                         
