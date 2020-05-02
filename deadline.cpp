#include <iostream>
#include <cstring>
#include <unistd.h>
using namespace std;

//Rachel Babikow, deadline project task #2

int main(int argc, char** argv){
	
	//command line: deadline
	if(argc == 1) {
		
		cout << "Print the list of deadlines" << endl;
	}
	
	//command line: deadline add me "_____"
	else if(strcmp(argv[1], "add") == 0 && strcmp(argv[2], "me") == 0) {
		
		cout << "Add deadline to personal list " << endl;
	}
	
	//command line: deadline rm #
	else if(strcmp(argv[1], "rm") == 0 && argc == 3) {
		
		cout << "Remove deadline " << stoi(argv[2]) << endl;
	}
		
	//command line: deadline hide #
	else if(strcmp(argv[1], "hide") == 0 && argc == 3){
		
		cout << "Hide deadline " << stoi(argv[2]) << endl;
	}
		
	//command line: deadline hidden
	else if(strcmp(argv[1], "hidden") == 0 && argc == 2){
	
		cout << "Show hidden deadlines" << endl;
	}
	
	//command line: deadline unhide #
	else if(strcmp(argv[1], "unhide") == 0 && argc == 3){

               cout << "Unhide deadline " << stoi(argv[2]) << endl;
       }

	//command line: deadline details #
	else if(strcmp(argv[1], "details") == 0 && argc == 3) {
		
		cout << "Get details for deadline " << stoi(argv[2]) << endl;
	}
	
	//command line: deadline edit #
	else if(strcmp(argv[1], "edit") == 0 && argc == 3) {
		
		cout << "If deadline " << stoi(argv[2]) << " is personal, edit. Otherwise, cannot edit" << endl;
	}
	
	//command line: invalid arguements
	else {
		
		//print invalid
		cout << "Invalid arguement" << endl;
	}
}
