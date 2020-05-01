//Save and Load for Spring 2020 CSCI 221 Deadline Project
//(Serialize and Deserialize)
//Made by Mathew Nitz

//TODO:
//	Put class files into /var/lib/






#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/map.hpp>
#include <boost/serialization/vector.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

// map<string, string> myMapPersonal;
// map<string, string> myMapClass;
// map<string, string> myMapPersonalHidden;
// map<string, string> myMapClassHidden;

template <typename T, typename S> 
ostream& operator<<(ostream& os, const map<T, S>& v) 
{ 
    for (auto it : v)  
        os << it.first << " , " 
           << it.second << "\n"; 
      
    return os; 
} 

void saveDeadline(string type, bool hidden, string title, string time)
{
	if(type == "Personal")
	{
		if(!hidden)
		{
			myMapPersonal.insert(pair<string, string>(title, time));
			ofstream file((string)getenv("HOME") + "/personal.deadline");
			boost::archive::text_oarchive oa(file);
			oa << myMapPersonal;
		}
		else
		{
			myMapPersonalHidden.insert(pair<string, string>(title, time));
			ofstream file((string)getenv("HOME") + "/personalhidden.deadline");
			boost::archive::text_oarchive oa(file);
			oa << myMapPersonalHidden;
		}
	}

	else if(type == "Class")
	{
		if(!hidden)
		{
			myMapClass.insert(pair<string, string>(title, time));
			ofstream file((string)getenv("HOME") + "/class.deadline");
			boost::archive::text_oarchive oa(file);
			oa << myMapClass;
		}
		else
		{
			myMapClassHidden.insert(pair<string, string>(title, time));
			ofstream file((string)getenv("HOME") + "/classhidden.deadline");
			boost::archive::text_oarchive oa(file);
			oa << myMapClassHidden;
		}
	}
	else
		cout << "Error (saveDeadline), please specify the type: Personal or Class and if it's hidden (1 for yes, 0 for no)" << endl;

}

void loadDeadlines()
{

	//use iterators and operator overload to display
	//personal
	ifstream file0((string)getenv("HOME") + "/personal.deadline");
	boost::archive::text_iarchive ia0(file0);
	ia0 >> myMapPersonal;
	cout << "Personal Deadlines:\n" << myMapPersonal << endl;

	//personal hidden
	ifstream file1((string)getenv("HOME") + "/personalhidden.deadline");
	boost::archive::text_iarchive ia1(file1);
	ia1 >> myMapPersonalHidden;
	cout << "Personal Hidden Deadlines:\n" << myMapPersonalHidden << endl;

	//class
	ifstream file2((string)getenv("HOME") + "/class.deadline");
	boost::archive::text_iarchive ia2(file2);
	ia2 >> myMapClass;
	cout << "Class Deadlines:\n" << myMapClass << endl;

	//class hidden
	ifstream file3((string)getenv("HOME") + "/classhidden.deadline");
	boost::archive::text_iarchive ia3(file3);
	ia3 >> myMapClassHidden;
	cout << "Class Hidden Deadlines:\n" << myMapClassHidden << endl;


}

int main()
{

// 	vector < map<string, string> > myPersonal;
// 	vector < map<string, string> > myClass;
// 	vector < map<string, string> > myPersonalHidden;
// 	vector < map<string, string> > myClassHidden;

// 	myPersonal.push_back(myMapPersonal);
// 	myClass.push_back(myMapClass);
// 	myPersonalHidden.push_back(myMapPersonalHidden);
// 	myClassHidden.push_back(myMapClassHidden);

	saveDeadline("Personal", 0, "Walk the dog", "2020-05-24 16:35");
	saveDeadline("Personal", 1, "Hide the dog", "2020-06-14 14:35");
	saveDeadline("Class", 0, "Current Class", "2020-08-03 16:35");
	saveDeadline("Class", 1, "Future Class", "2020-10-12 16:20");
	loadDeadlines();
}

