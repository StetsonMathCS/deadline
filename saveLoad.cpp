//Save and Load for Spring 2020 CSCI 221 Deadline Project
//(Serialize and Deserialize)
//Made by Mathew Nitz

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

// template <typename T, typename S> 
// ostream& operator<<(ostream& os, const map<T, S>& v) 
// { 
//     for (auto it : v)  
//         os << it.first << " , " 
//            << it.second << "\n"; 
      
//     return os; 
// } 

void saveDeadlines()
{
	//personal
	ofstream ofile0((string)getenv("HOME") + "/personal.deadline");
	boost::archive::text_oarchive oa0(ofile0);
	oa0 << myMapPersonal;

	//personal hidden
	ofstream ofile1((string)getenv("HOME") + "/personalhidden.deadline");
	boost::archive::text_oarchive oa1(ofile1);
	oa1 << myMapPersonalHidden;

	//class
	ofstream ofile2("/var/lib/deadline/class.deadline");
	boost::archive::text_oarchive oa2(ofile2);
	oa2 << myMapClass;

	//class hidden
	ofstream ofile3("/var/lib/deadline/classhidden.deadline");
	boost::archive::text_oarchive oa3(ofile3);
	oa3 << myMapClassHidden;
}

void loadDeadlines()
{
	//personal
	ifstream file0((string)getenv("HOME") + "/personal.deadline");
	boost::archive::text_iarchive ia0(file0);
	ia0 >> myMapPersonal;
	// cout << "Personal Deadlines:\n" << myMapPersonal << endl;

	//personal hidden
	ifstream file1((string)getenv("HOME") + "/personalhidden.deadline");
	boost::archive::text_iarchive ia1(file1);
	ia1 >> myMapPersonalHidden;
	// cout << "Personal Hidden Deadlines:\n" << myMapPersonalHidden << endl;

	//class
	ifstream file2("/var/lib/deadline/class.deadline");
	boost::archive::text_iarchive ia2(file2);
	ia2 >> myMapClass;
	// cout << "Class Deadlines:\n" << myMapClass << endl;

	//class hidden
	ifstream file3("/var/lib/deadline/classhidden.deadline");
	boost::archive::text_iarchive ia3(file3);
	ia3 >> myMapClassHidden;
	// cout << "Class Hidden Deadlines:\n" << myMapClassHidden << endl;	
}

int main()
{
	// myMapPersonal.insert(pair<string, string>("Walk the dog", "2020-05-24 16:35"));
	// myMapPersonalHidden.insert(pair<string, string>("Hide the dog", "2020-05-24 16:35"));
	// myMapClass.insert(pair<string, string>("Class Project", "2020-05-24 16:35"));
	// myMapClassHidden.insert(pair<string, string>("Hidden Class Project", "2020-05-24 16:35"));

	saveDeadlines();

	loadDeadlines();


}
