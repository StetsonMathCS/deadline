#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
        map<string, int> myMapPersonal;
        map<string, int> myMapClass;
        map<string, int> myMapHidden;

        vector<myMapPersonal> myPersonal;
        vector<myMapClass> myClass;
        vector<myMapHidden> myHidden;

        string personalTask //giives the title of the task
        int personalTime // gives the time for the task is due by

        string classTask //giives the title of the task
        int classTime // gives the time for the task is due by

        string hiddenTask //giives the title of the task
        int hiddenTime // gives the time for the task is due by

        myMapPersonal.insert(pair<string, int>(personalTask, personalTime));
        myMapClass.insert(pair<string, int>(classTask, classTime));
        myMapHidden.insert(pair<string, int>(hiddenTask, hiddenTime));

        myPersonal.push_back(myMapPersonal);
        myClass.push_back(myMapClass);
        myHidden.push_back(myMapHidden);
}
