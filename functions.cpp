#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include "boost/lexical_cast.hpp"

using namespace std;

vector < map<string, string> > myPersonal;
vector < map<string, string> > myClass;
vector < map<string, string> > myPersonalHidden;
vector < map<string, string> > myClassHidden;

map<string, string> myMapPersonal;
map<string, string> myMapClass;
map<string, string> myMapPersonalHidden;
map<string, string> myMapClassHidden;

// adding deadlines to Class, Personal, Personal Hidden, and Class Hidden
void addDeadline(string list, string name, string date)
{
	map<string, string>::iterator it;
	vector <map <string, string> >::iterator it_out;

	if(list == "Class") {

		myMapClass.insert(make_pair(name, date));
		myClass.push_back(myMapClass);

		// printing elements of map, left in here in case my syntax is different 
		for(it = myMapClass.begin(); it != myMapClass.end(); it++)
		{	
			//cout << it->first << " ---> " << it->second << endl;
			// this next line was to test if the info was being stored right
			//cout << myClass.at(0)[it->first] << endl;
		}
	}

	else if(list == "Personal") {

		myMapPersonal.insert(make_pair(name, date));
		myPersonal.push_back(myMapPersonal);

		for(it = myMapPersonal.begin(); it != myMapPersonal.end(); it++)
		{
			//cout << it->first << " ---> " << it->second << endl;
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

// function to update the deadline
void updateDeadline(string list, string target, string update)
{
        map<string, string>::iterator it = myMapClass.find(target);
        map<string, string>::iterator it1 = myMapPersonal.find(target);
        map<string, string>::iterator it2 = myMapPersonalHidden.find(target);
        map<string, string>::iterator it3 = myMapClassHidden.find(target);

        vector <map <string, string> >::iterator it_out;

        if(list == "Class") {

                for(it_out = myClass.begin(); it_out != myClass.end(); it_out++)
                {
                        for(it = myMapClass.begin(); it != myMapClass.end(); it++)
                        {
                                myMapClass[update] = it->second;
                                //cout << update << " ---> " << it->second << endl;
                                myMapClass.erase(it->first);
                                break;
                        }

                        break;
                }
        }

        else if(list == "Personal") {

                for(it_out = myPersonal.begin(); it_out != myPersonal.end(); it_out++)
                {
                        for(it1 = myMapPersonal.begin(); it1 != myMapPersonal.end(); it1++)
                        {
                                myMapPersonal[update] = it1->second;
                                //cout << update << " ---> " << it1->second << endl;
                                myMapPersonal.erase(it1->first);
                                break;
                        }

                        break;
                }
        }

        else if(list == "Personal Hidden") {

                for(it_out = myPersonalHidden.begin(); it_out != myPersonalHidden.end(); it_out++)
                {
                        for(it2 = myMapPersonalHidden.begin(); it2 != myMapPersonalHidden.end(); it2++)
                        {
                                myMapPersonalHidden[update] = it2->second;
                                //cout << update << " ---> " << it2->second << endl;
                                myMapPersonalHidden.erase(it2->first);
                                break;
                        }

                        break;
                }
        }

        else {

                if(list == "Class Hidden") {

                        for(it_out = myClassHidden.begin(); it_out != myClassHidden.end(); it_out++)
                        {
                                for(it3 = myMapClassHidden.begin(); it3 != myMapClassHidden.end(); it3++)
                                {
                                        myMapClassHidden[update] = it3->second;
                                        //cout << update << " ---> " << it3->second << endl;
                                        myMapClassHidden.erase(it3->first);
                                        break;
                                }

                                break;
                        }
                }
        }
}

void removeDeadline(string list, string target)
{
	vector <map <string, string> >::iterator it_out;
	map<string, string>::iterator it = myMapClass.find(target);
	map<string, string>::iterator it1 = myMapPersonal.find(target);
	map<string, string>::iterator it2 = myMapPersonalHidden.find(target);
	map<string, string>::iterator it3 = myMapClassHidden.find(target);

	if(list == "Class") {

		for(it_out = myClass.begin(); it_out != myClass.end(); it_out++) {

			for(it = myMapClass.begin(); it != myMapClass.end(); it++)
			{
				myMapClass.erase(it);
				//myClass.clear();                             
				break;
			}

			break;
		}
	}

	else if(list == "Personal") {

		for(it_out = myPersonal.begin(); it_out != myPersonal.end(); it_out++) {

			for(it1 = myMapPersonal.begin(); it1 != myMapPersonal.end(); it1++)
			{
				myMapPersonal.erase(it1);
				//myClass.clear();                             

				break;
			}       

			break;
		}
	}

	else if(list == "Personal Hidden") {

		for(it_out = myPersonalHidden.begin(); it_out != myPersonalHidden.end(); it_out++) {

			for(it2 = myMapPersonalHidden.begin(); it2 != myMapPersonalHidden.end(); it2++)
			{
				myMapPersonalHidden.erase(it2);
				//myClass.clear();                             

				break;
			}

			break;
		}
	}

	else {
		if(list == "Class Hidden"){

			for(it_out = myPersonal.begin(); it_out != myPersonal.end(); it_out++) {

				for(it3 = myMapPersonal.begin(); it3 != myMapPersonal.end(); it3++)
				{
					myMapPersonal.erase(it3);
					//myClass.clear();                             

					break;
				}

				break;
			}
		}
	}
}

int main()
{
	// main here for testing purposes
	addDeadline("Class", "Chem Exam", "April 30th, 2020");
	addDeadline("Personal", "Cook dinner", "May 1st, 2020" );
	addDeadline("Personal Hidden", "Gym", "May 2nd, 2020");
	addDeadline("Class Hidden", "Review C++", "May 9th, 2020");

	updateDeadline("Class", "Chem Exam", "Math Exam");
	updateDeadline("Personal", "Cook dinner", "Walk dog");
	
	removeDeadline("Class", "Chem Exam");
	removeDeadline("Personal", "Cook dinner");
	removeDeadline("Personal Hidden", "Gym");         
	removeDeadline("Class Hidden", "Review C++");	

	return 0;
}
