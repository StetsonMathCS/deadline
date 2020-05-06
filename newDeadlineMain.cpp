#include <iostream>
#include <sstream>
#include <cstring>
#include <vector>
#include <string>
#include <map>
#include <unistd.h>
#include <fstream>
#include<stdlib.h>
#include<string.h>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/map.hpp>
#include <boost/serialization/vector.hpp>
using namespace std;

//Rachel Babikow, extra credit
//what I did:
//edited functions so they all worked together without error
//added a way to show details/edit a temp file for deadlines (cannot edit name/date but can edit notes)
//edited makefile for new main file

//defined date structures (Harrison)
vector < map<string, string> > myPersonal;
vector < map<string, string> > myClass;
vector < map<string, string> > myPersonalHidden;
vector < map<string, string> > myClassHidden;

map<string, string> myMapPersonal;
map<string, string> myMapClass;
map<string, string> myMapPersonalHidden;
map<string, string> myMapClassHidden;

//add and remove functions (Carson)
void addDeadline(string list, string name, string date)
{
	if(list == "Class") {
		myMapClass.insert(make_pair(name, date));
		myClass.push_back(myMapClass);
		myMapClass.clear();
	}

	else if(list == "Personal") {
		myMapPersonal.insert(make_pair(name, date));
		myPersonal.push_back(myMapPersonal);
		myMapPersonal.clear();
	}

	else if(list == "Personal Hidden") {
		myMapPersonalHidden.insert(make_pair(name, date));
		myPersonalHidden.push_back(myMapPersonalHidden);
		myMapPersonalHidden.clear();
	}

	else if(list == "Class Hidden") {
		myMapClassHidden.insert(make_pair(name, date));
		myClassHidden.push_back(myMapClassHidden);
		myMapClassHidden.clear();
	}
}

void removeDeadline(string list, string name, string date)
{
	if(list == "Class") {
		for(int i =0; i < myClass.size(); i ++){
			 for(auto const& pair: myClass[i] ) {
                                                if(name == pair.first && date == pair.second){
							myClass.erase(myClass.begin() + i);
							break;
                        	                }
			}
		}
	}

	else if(list == "Personal") {
		for(int i =0; i < myPersonal.size(); i ++){
                         for(auto const& pair: myPersonal[i] ) {
                                                if(name == pair.first && date == pair.second){
                                                        myPersonal.erase(myPersonal.begin() + i);
							break;
                               		         }
                        }
                }
	}

	else if(list == "Personal Hidden") {
		 for(int i =0; i < myPersonalHidden.size(); i ++){
                         for(auto const& pair: myPersonalHidden[i] ) {
                                                if(name == pair.first && date == pair.second){
                                                        myPersonalHidden.erase(myPersonalHidden.begin() + i);
							break;
         	                               }
                        }
                }
	}

	 else if(list == "Class Hidden") {
                 for(int i =0; i < myClassHidden.size(); i ++){
                         for(auto const& pair: myClassHidden[i] ) {
                                                if(name == pair.first && date == pair.second){
                                                        myClassHidden.erase(myClassHidden.begin() + i);
							break;
                	                        }
                        }
                }
        }
}

//time conversions (done by Ethan)
time_t strtot(std::string strtime)
{
	time_t deadtime;
	int yy, mon, dd, hh, mm;
	struct tm tmform;
	const char *chtime = strtime.c_str();
	sscanf(chtime, "%d-%d-%d %d:%d", &yy, &mon, &dd, &hh, &mm);
	tmform.tm_year = yy - 1900;
	tmform.tm_mon = mon - 1;
	tmform.tm_mday = dd;
	tmform.tm_hour = hh;
	tmform.tm_min = mm;
	tmform.tm_isdst = -1;
	deadtime = mktime(&tmform);
	return deadtime;
}

//delta calculation (done by Ethan)
std::string strdelta(time_t deldeadline)
{
	time_t curtime = time(0);
	double delta = difftime(deldeadline, curtime);
	char pos;
	if(delta > 0)
	{
		pos = '+';
	}
	else
	{
		pos = '-';
	}
	int delday = (int)(delta/86400);
	delta = delta - delday*86400;
	int delhour = (int)(delta/3600);
	delta = delta - delhour*3600;
	int delmin = (int)(delta/60);
	std::ostringstream os;
	os << "(" << pos << delday << "d, " << delhour << "h" << delmin << "m)";
	std::string dif = os.str();
	return dif;
}

//print deadline (done my Moe)
void printDeadline(map<string,string> deadline) {
  string deadlineName = deadline.begin()->first;
  string deadlineDate = deadline.begin()->second;
  string timeDifference = strdelta(strtot(deadlineDate));
  cout<<deadlineName<<" - "<<deadlineDate<<" "<<timeDifference<<endl;
}

//print deadlines (done my Moe)
void printDeadlines(vector<map<string,string>> deadlines) {
  int i = 1;
  vector<map<string,string>>::iterator it;

  for(it=deadlines.begin();it!=deadlines.end();it++) {
    cout<<i<<". ";
    printDeadline(*it);
  }
}


//save vectors (done by Mathew)
void saveDeadlines()
{
	//personal
	ofstream ofile0((string)getenv("HOME") + "/personal.deadline");
	boost::archive::text_oarchive oa0(ofile0);
	oa0 << myPersonal;

	//personal hidden
	ofstream ofile1((string)getenv("HOME") + "/personalhidden.deadline");
	boost::archive::text_oarchive oa1(ofile1);
	oa1 << myPersonalHidden;
	
	//class
	ofstream ofile2("/var/lib/deadline/class.deadline");
	boost::archive::text_oarchive oa2(ofile2);
	oa2 << myClass;

	//class hidden
	ofstream ofile3("/var/lib/deadline/classhidden.deadline");
	boost::archive::text_oarchive oa3(ofile3);
	oa3 << myClassHidden;
}

//load vectors (done by Mathew)
void loadDeadlines()
{
	//personal
	ifstream file0((string)getenv("HOME") + "/personal.deadline");
	boost::archive::text_iarchive ia0(file0);
	ia0 >> myPersonal;
	// cout << "Personal Deadlines:\n" << myPersonal << endl;

	//personal hidden
	ifstream file1((string)getenv("HOME") + "/personalhidden.deadline");
	boost::archive::text_iarchive ia1(file1);
	ia1 >> myPersonalHidden;
	// cout << "Personal Hidden Deadlines:\n" << myPersonalHidden << endl;

	//class
	ifstream file2("/var/lib/deadline/class.deadline");
	boost::archive::text_iarchive ia2(file2);
	ia2 >> myClass;
	// cout << "Class Deadlines:\n" << myClass << endl;

	//class hidden
	ifstream file3("/var/lib/deadline/classhidden.deadline");
	boost::archive::text_iarchive ia3(file3);
	ia3 >> myClassHidden;
	// cout << "Class Hidden Deadlines:\n" << myClassHidden << endl;

}

//check if the deadline # is an int
bool validInt(string deadline) {
	for (int i = 0; i < deadline.length(); i++) {
        	if (isdigit(deadline[i]) == false) { 
            		return false; 
  		}
	}
	return true;
}

int main(int argc, char** argv){

	loadDeadlines();

	//command line: deadline
	if(argc == 1) {
		
		cout << "\ncsci 221:" << endl;
		printDeadlines(myClass);
		cout << "\npersonal:" << endl;
		printDeadlines(myPersonal);
		cout << "\n";
	}
	
	//command line: deadline add me "_____"
	else if(strcmp(argv[1], "add") == 0 && strcmp(argv[2], "me") == 0) { 	
		
		string deadline = "";
		for(int i = 4; i < argc; i ++) {
			deadline = deadline + (string) argv[i] + " ";
		}		
		bool valid = false;
		if(argc == 8 && ((string) argv[4]).length() == 4 && ((string) argv[5]).length() == 2 && ((string) argv[6]).length() == 2 && ((string) argv[7]).length() == 5) {
				if(validInt(deadline) == 0 && deadline.find(":") == 13) {
					valid = true;
				}
				else {
					valid = false;
				}
		}
		if(valid == false) {
			cout << "Invalid arguements. Enter date as yyyy mm dd hh:mm" << endl;
		}
		else {
			string time = (string) argv[4] + "-" + argv[5] + "-" + argv[6] + " " + argv[7];  
			time_t myTime = strtot(time);
                	cout << "Added deadline " << '"' << argv[3] << '"' << " " << strdelta(myTime) << endl;
			string list = "Personal";

			addDeadline(list, (string) argv[3], time);
			
			saveDeadlines();

		} 
	}
	
	//command line: deadline rm #
	else if(strcmp(argv[1], "rm") == 0 && argc == 3) {
		
		if(validInt(argv[2]) == true) {
			if(stoi(argv[2]) <= (int) (myPersonal.size() + myClass.size()) && stoi(argv[2]) > 0 ) {	
				string name;
				string date;
				string list;
				if(stoi(argv[2]) <= myClass.size()) {
					for(auto const& pair: myClass[stoi(argv[2])-1] ) {
						name = pair.first;
						date = pair.second;
						list = "Class";	
						break;
					}
				}
				else if(stoi(argv[2]) <= (int) (myClass.size() + myPersonal.size()) ) {
					for(auto const& pair: myPersonal[(stoi(argv[2]))-1-myClass.size()] ) {
						name = pair.first;
                                                date = pair.second;
						list = "Personal";
						break;
                                        }
				}
				time_t myTime = strtot(date);
				cout << "Removed deadline " << '"' << name << '"' << " " << strdelta(myTime) << endl;

				removeDeadline(list, name, date);
				std::string filename = "/tmp/.out." + (string (argv[2]));
                                // read from filename
                                unlink(filename.c_str());

				saveDeadlines();

			}
			else {
				cout << "Not a valid deadline" << endl;
			}
		}
		else{
			cout << "Invalid arguements" << endl;
		}
	}
		
	//command line: deadline hide #
	else if(strcmp(argv[1], "hide") == 0 && argc == 3){

		if(validInt(argv[2]) == true) {
                        if(stoi(argv[2]) <= (int) (myPersonal.size() + myPersonal.size()) && stoi(argv[2]) > 0) {
                                string name;
                                string date;
				string list;
				string hiddenList;
                                if(stoi(argv[2]) <= myClass.size()) {
                                        for(auto const& pair: myClass[stoi(argv[2])-1] ) {
                                                name = pair.first;
                                                date = pair.second;
						list = "Class";
						hiddenList = "Class Hidden";
                                        }
                                }
                                else if(stoi(argv[2]) <= (int) (myPersonal.size() + myClass.size()) ) {
                                        for(auto const& pair: myPersonal[(stoi(argv[2]))-1-myClass.size()] ) {
                                                name = pair.first;
                                                date = pair.second;
						list = "Personal";
						hiddenList = "Personal Hidden";
                                        }
                                }
				time_t myTime = strtot(date);
				cout << "Hiding deadline " << '"' << name << '"' << " " << strdelta(myTime) << endl;
				
				addDeadline(hiddenList, name, date);
				removeDeadline(list, name, date);

				saveDeadlines();
                        }
                        else {
                                cout << "Not a valid deadline" << endl;
                        }
                }
                else{
                        cout << "Invalid arguements" << endl;
                }
	}
		
	//command line: deadline hidden
	else if(strcmp(argv[1], "hidden") == 0 && argc == 2){
		
		cout << "Hidden Deadlines:" << endl;
		cout << "\ncsci 221:" << endl;
                printDeadlines(myClassHidden);
                cout << "\npersonal:" << endl;
                printDeadlines(myPersonalHidden);
                cout << "\n";

	}
	
	//command line: deadline unhide #
	else if(strcmp(argv[1], "unhide") == 0 && argc == 3) {
		
		if(validInt(argv[2]) == true) {
                        if(stoi(argv[2]) <= (int) myClassHidden.size() + myPersonalHidden.size() && stoi(argv[2]) > 0) {
				string name;
				string date;
				string list;
				string hiddenList;
				if(stoi(argv[2]) <= (int) myClassHidden.size()) {
					for(auto const& pair: myClassHidden[stoi(argv[2])-1] ) {
                                		name = pair.first;
                                		date = pair.second;
						list = "Class";
						hiddenList = "Class Hidden";
                                	}
				}
				else {
					for(auto const& pair: myPersonalHidden[stoi(argv[2])-1-myClassHidden.size()] ) {
                                                name = pair.first;
                                                date = pair.second;
						list = "Personal";
						hiddenList = "Personal Hidden";
                                        }
				}
				time_t myTime = strtot(date);
				cout << "Unhiding deadline " << '"' << name << '"' << " " << strdelta(myTime) << endl;

				addDeadline(list, name, date);
                                removeDeadline(hiddenList, name, date);

				saveDeadlines();
                        }
                        else {
                                cout << "Not a valid deadline" << endl;
                        }
                }
                else{
                        cout << "Invalid arguements" << endl;
                }
       }

	//command line: deadline details #
	else if(strcmp(argv[1], "details") == 0 && argc == 3) {
		
		if(validInt(argv[2]) == true) {
			string name;
			string date;
 			if(stoi(argv[2]) <= (int) (myPersonal.size() + myClass.size()) && stoi(argv[2]) > 0 ) {
				 if(stoi(argv[2]) < myClass.size()) {
                                        for(auto const& pair: myClass[stoi(argv[2])-1] ) {
                                                name = pair.first;
						date = pair.second;
						break;
                                        }
                                }
                                else if(stoi(argv[2]) <= (int) (myPersonal.size() + myClass.size()) ) {
                                        for(auto const& pair: myPersonal[(stoi(argv[2]))-1-myClass.size()] ) {
                                                name = pair.first;
						date = pair.second;
						break;
                                        }
                                }
				time_t myTime = strtot(date);
				cout << "\n" << (string) name << " (personal) \n \nDeadline: " << date << " " << strdelta(myTime) << "\n" << endl;
				std::string filename = "/tmp/.out." + (string (argv[2]));
                                std::cout << std::ifstream(filename). rdbuf();
				cout << "\n";
			}
                        else {
                                cout << "Not a valid deadline" << endl;
                        }
                }
                else{
                        cout << "Invalid arguements" << endl;
                }
	}
	
	//command line: deadline edit #
	else if(strcmp(argv[1], "edit") == 0 && argc == 3) {
		
		 if(validInt(argv[2]) == true) {
			string name;
                        if(stoi(argv[2]) <= (int) myClass.size() && stoi(argv[2]) > 0) {
				for(auto const& pair: myClass[stoi(argv[2])-1] ) {
                                        name = pair.first;
                                }
				cout << "You cannot edit " << '"' << name << '"' << " since you are not the owner (jeckroth is)." << endl;
			}
			  else if(stoi(argv[2]) <= (int) (myPersonal.size() + myClass.size()) ) {
                                        for(auto const& pair: myPersonal[(stoi(argv[2]))-1-myClass.size()] ) {
                                                name = pair.first;
                                        }
                       
				std::string filename = "/tmp/.out." + (string (argv[2]));
				std::string cmd = "/bin/nano " + filename;
								
				ofstream myfile;
  				myfile.open (filename);
  				myfile << "Notes:\n";
  				myfile.close();

				system(cmd.c_str());
			
			}
                        else {
                                cout << "Not a valid deadline" << endl;
                        }
                }
                else{
                        cout << "Invalid arguements" << endl;
                }
	}
	
	//command line: invalid arguements
	else {
		cout << "Invalid arguement" << endl;
	}
}
