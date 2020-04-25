//Boost serialization for CSCI 221 deadline project
//Example on complex STL data structures
//https://www.boost.org/doc/libs/1_71_0/libs/serialization/doc/index.html
//Mathew Nitz, Spring 2020

// vector < map<string, string> > deadlineVec;
// map<string, string> deadlineMap;
// deadlineMap.insert(pair<string, string>("title", "dateTime"));
// deadlineVec.push_back(deadlineMap);

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <boost/serialization/map.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>

using namespace std;

class deadline
{
	friend class boost::serialization::access;
	vector < map<string, string> > deadlineVec;
	string title;
	string dateTime;
	template<class Archive>
	void serialize(Archive & ar, const unsigned int version)
	{
		ar & deadlineVec;
	}
public:
	deadline(){};
	deadline(string t, string dt) : title (t), dateTime (dt) {}
	string getTitle() const;
	string getDateTime() const;
	vector < map<string, string> > & getCopy();
};

string deadline::getTitle() const
{
	return this->title;
}

string deadline::getDateTime() const
{
	return this->dateTime;
}

vector < map<string, string> > & deadline::getCopy()
{
	return deadlineVec;
}

int main()
{
	map<string, string> deadlineMap;
	vector < map<string, string> > vecCopy;


	deadline d("Walk the dog", "2020-05-24 18:00:00");
	deadline e("Feed the cat", "2020-05-02 11:30:00");
	deadline f("CSCI proj due", "2020-05-06 23:59:59");
	
	vecCopy = d.getCopy();

	deadlineMap.insert(pair<string, string>(d.getTitle(), d.getDateTime()));
	deadlineMap.insert(pair<string, string>(e.getTitle(), e.getDateTime()));
	deadlineMap.insert(pair<string, string>(f.getTitle(), f.getDateTime()));

	vecCopy.push_back(deadlineMap);


	ofstream ofs("./temp.txt");

	{
		boost::archive::text_oarchive oa(ofs);
		oa << vecCopy;
	}

	vector < map<string, string> > newVecCopy;

	{
		ifstream ifs("./temp.txt");
		boost::archive::text_iarchive ia(ifs);
		ia >> newVecCopy;
	}
}




