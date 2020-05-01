#include <iostream>
#include <sstream>
#include <cstring>
#include <vector>
#include <string>
#include <map>
#include <unistd.h>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/map.hpp>
#include <boost/serialization/vector.hpp>
#include <fstream>
using namespace std;

//Rachel Babikow, deadline project part 2, task #4

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

	//loadDeadlines();

	  // used to test (can erase)
 //	  vector< map <string, string> > myClass;
 //       vector< map <string, string> > myPersonal;
 //       vector< map <string, string> > myClassHidden;
 //       vector< map <string, string> > myPersonalHidden;
 //       map<string, string> deadlineOne;
 //       map<string, string> deadlineTwo;
 //       map<string, string> deadlineThree;
 //       map<string, string> deadlineFour;
 //       deadlineOne.insert(make_pair("Walk dog", "2001-05-24 10:50"));
 //       deadlineTwo.insert(make_pair("Make dinner", "2020-04-18 07:15"));
 //       deadlineThree.insert(make_pair("Go to work", "2020-09-18 09:09"));
 //       deadlineFour.insert(make_pair("take test", "2021-08-09 10:00"));
 //       myClass.push_back(deadlineThree);
 //       myPersonal.push_back(deadlineOne);
 //       myClassHidden.push_back(deadlineTwo);
 //       myPersonalHidden.push_back(deadlineFour);


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
			string list = "myPersonal";

			// FUNCTION NEEDED:
			// addDeadlines(list, (string) argv[3], time);

			//saveDeadlines();

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
						list = "myClass";	
					}
				}
				else if(stoi(argv[2]) <= (int) (myClass.size() + myPersonal.size()) ) {
					for(auto const& pair: myPersonal[(myPersonal.size()+myClass.size())-stoi(argv[2])] ) {
                                                name = pair.first;
                                                date = pair.second;
						list = "myPersonal";
                                        }
				}
				time_t myTime = strtot(date);
				cout << "Removed deadline " << '"' << name << '"' << " " << strdelta(myTime) << endl;

				// FUNCTION NEEDED:
				// removeDeadline(list, name, date);

				//saveDeadlines();

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
						list = "myClass";
						hiddenList = "myClassHidden";
                                        }
                                }
                                else if(stoi(argv[2]) <= (int) (myPersonal.size() + myClass.size()) ) {
                                        for(auto const& pair: myPersonal[(myPersonal.size()+myClass.size())-stoi(argv[2])] ) {
                                                name = pair.first;
                                                date = pair.second;
						list = "myPersonal";
						hiddenList = "myPersonalHidden";
                                        }
                                }
				time_t myTime = strtot(date);
				cout << "Hiding deadline " << '"' << name << '"' << " " << strdelta(myTime) << endl;
				
				// FUNCTIONS NEEDED:
				// addDeadline(hiddenList, name, date);
				// removeDeadline(list, name, date);

				//saveDeadlines();
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
		
		cout << "Print hidden deadlines" << endl;
		
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
						list = "myClass";
						hiddenList = "myClassHidden";
                                	}
				}
				else {
					for(auto const& pair: myPersonalHidden[myClassHidden.size() + myPersonalHidden.size() - stoi(argv[2])] ) {
                                                name = pair.first;
                                                date = pair.second;
						list = "myPersonal";
						hiddenList = "myPersonalHidden";
                                        }
				}
				time_t myTime = strtot(date);
				cout << "Unhiding deadline " << '"' << name << '"' << " " << strdelta(myTime) << endl;

				// FUNCTIONS NEEDED:
				// addDeadline(list, name, date);
                                // removeHiddenDeadline(hiddenList, name, date);

				//saveDeadlines();
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
 			if(stoi(argv[2]) <= (int) (myPersonal.size() + myClass.size()) && stoi(argv[2]) > 0 ) {
				cout << "show details" << endl;

				// FUNTION NEEDED:
				// showDetails(stoi(argv([2]);

				//saveDeadlines();
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
                        if(stoi(argv[2]) <= (int) myClass.size() && stoi(argv[2]) > 0) {
				string name;
				for(auto const& pair: myClass[stoi(argv[2])-1] ) {
                                        name = pair.first;
                                }
				cout << "You cannot edit " << '"' << name << '"' << " since you are not the owner (jeckroth is)." << endl;
			}
			else if(stoi(argv[2]) > (int) myClass.size() && stoi(argv[2]) <= (int) (myClass.size() + myPersonal.size()) && stoi(argv[2]) > 0) {
                                cout << "edit deadline " << stoi(argv[2]) << endl;
				
				//FUNCTION NEEDED:
				// editDeadline(stoi(argv[2]);

				//saveDeadlines();
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
