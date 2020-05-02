#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

vector < map<string, string> > myPersonal;
vector < map<string, string> > myClass;
vector < map<string, string> > myPersonalHidden;
vector < map<string, string> > myClassHidden;

map<string, string> myMapPersonal;
map<string, string> myMapClass;
map<string, string> myMapPersonalHidden;
map<string, string> myMapClassHidden;

void addDeadline(string list, string name, string date)
{
	map<string, string>::iterator it;
	vector <map <string, string> >::iterator it_out;

	if(list == "Class") {

		myMapClass.insert(make_pair(name, date));
		myClass.push_back(myMapClass);

		for(it = myMapClass.begin(); it != myMapClass.end(); it++)
		{	
			cout << it->first << " ---> " << it->second << endl;
			// this next line was to test if the info was being stored right
			cout << myClass.at(0)[it->first] << endl;
		}
	}

	else if(list == "Personal") {

		myMapPersonal.insert(make_pair(name, date));
		myPersonal.push_back(myMapPersonal);

		for(it = myMapPersonal.begin(); it != myMapPersonal.end(); it++)
		{
			cout << it->first << " ---> " << it->second << endl;
		}
	}

	else if(list == "Personal Hidden") {

		myMapPersonalHidden.insert(make_pair(name, date));
		myPersonalHidden.push_back(myMapPersonalHidden);

		for(it = myMapPersonalHidden.begin(); it != myMapPersonalHidden.end(); it++)
		{
			//cout << it->first << " ---> " << it->second << endl;
		}
	}

	else {
		if(list == "Class Hidden") {

			myMapClassHidden.insert(make_pair(name, date));
			myClassHidden.push_back(myMapClassHidden);

			for(it = myMapClassHidden.begin(); it != myMapClassHidden.end(); it++)
			{       
				//cout << it->first << " ---> " << it->second << endl;
			}
		}
	}
}

void removeDeadline(string list, string target)
{
	map<string, string>::iterator it = myMapClass.find(target);
	vector <map <string, string> >::iterator it_out;

	if(list == "Class") {

		for(it_out = myClass.begin(); it_out != myClass.end(); it_out++) {

			for(it = myMapClass.begin(); it != myMapClass.end(); it++)
			{
				myMapClass.erase(it);
				
				if(it_out == target)
				{
					myClass.erase(it_out);
				}
				//myMapClass.clear();				
				//cout << it->first << " ---> " << it->second << endl;
				cout << myMapClass.size() << endl;
				//myClass.clear();                             
				//cout << it->first << " ---> " << it->second << endl;
				cout << myClass.size() << endl;

				break;
			}

			break;
		}		
	} 

	else if(list == "Personal") {

		for(it_out = myPersonal.begin(); it_out != myPersonal.end(); it_out++) {

			for(it = myMapPersonal.begin(); it != myMapPersonal.end(); it++)
			{
				myMapPersonal.erase(it);
				myPersonal.erase(it_out);
				//myMapClass.clear();                           
				//cout << it->first << " ---> " << it->second << endl;
				cout << myMapPersonal.size() << endl;
				//myClass.clear();                             
				//cout << it->first << " ---> " << it->second << endl;
				cout << myPersonal.size() << endl;

				break;
			}       

			break;
		}
	}

	else if(list == "Personal Hidden") {

		for(it_out = myPersonalHidden.begin(); it_out != myPersonalHidden.end(); it_out++) {

			for(it = myMapPersonalHidden.begin(); it != myMapPersonalHidden.end(); it++)
			{
				myMapPersonalHidden.erase(it);
				myPersonalHidden.erase(it_out);
				//myMapClass.clear();                           
				//cout << it->first << " ---> " << it->second << endl;
				cout << myMapPersonalHidden.size() << endl;
				//myClass.clear();                             
				//cout << it->first << " ---> " << it->second << endl;
				cout << myPersonalHidden.size() << endl;

				break;
			}

			break;
		}
	}

	else {
		if(list == "Class Hidden"){
			for(it_out = myPersonal.begin(); it_out != myPersonal.end(); it_out++) {

				for(it = myMapPersonal.begin(); it != myMapPersonal.end(); it++)
				{
					myMapPersonal.erase(it);
					myPersonal.erase(it_out);
					//myMapClass.clear();                           
					//cout << it->first << " ---> " << it->second << endl;
					cout << myMapPersonal.size() << endl;
					//myClass.clear();                             
					//cout << it->first << " ---> " << it->second << endl;
					cout << myPersonal.size() << endl;

					break;
				}

				break;
			}
		}
	}
}
void updateDeadline(string name, string date, string update)
{
	map<string, string>::iterator it;
	vector <map <string, string> >::iterator it_out;

}

int main()
{
	addDeadline("Class", "CHEM EXAM", "2020-04-30");
	addDeadline("Personal", "Cook dinner", "2020-05-01" );
	addDeadline("Personal Hidden", "Gym 6:30pm", "2020-05-01");
	addDeadline("Class Hidden", "Review C++ syntax", "2020-05-09");

	removeDeadline("Class", "CHEM EXAM");
	removeDeadline("Personal Hidden", "Gym 6:30pm");

	return 0;
}
