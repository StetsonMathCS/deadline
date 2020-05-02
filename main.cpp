#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <ctime>
using namespace std;

void show(map<string, map<string, string> > *myMap, map<string, map<string, int> > *count, vector<string> *myvec){
    map<string, map<string, string> >::const_iterator it;
    map<string, string>::const_iterator another;


    for (it = myMap->begin(); it != myMap->end(); it++){
        for(x = it->second.begin(); x != it->second.end(); x++){
            cout << "User " << it->first << " " << x->first << " " << count->at(it->first).at(x            ->first)  << " time(s)" << endl;
        }
    }
}

int main() {
    map<string, map<string, string> > myMap;
    map<string, map<string, int> > count;
    vector<string> myvec;

    while (true){
        string x = "";
        string user_input = getCommand();
        time_t thetime = time(0);
        string mytime = asctime(localtime(&thetime));

        if ((user_input.compare("stats") == 0)){
            display(&myMap, &count, &myvec);    
        }else if(user_input.compare("recent") == 0){
            cout << "Most recent command: " << endl;
            cout << "'" << myvec.back() << "'" << endl; 
        }else{
            string textInput;
            cout << user_input << ": ";
            cin >> textInput;
            myMap[user_input][textInput] = mytime;
            x.append(user_input);
            x.append(": ");
            x.append(textInput);
            x.append(" at ");
            x.append(mytime);
            myvec.push_back(another);   

            if (myMap.count(user_input)){
                if (myMap[user_input].count(textInput)){
                    count[user_input][textInput] += 1;
                }else {
                    count[user_input][textInput] = 1;
                }
            }else{
                count[user_input][textInput] = 1;
            }
        }
    }
    return 0;
