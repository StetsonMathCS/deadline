#include <iostream>
#include <ctime>
#include <time.h>
int main()
{
	time_t curtime = time(0);
	char* curdt = ctime(&curtime);
	std::cout << curdt << std::endl;

	tm demodeadline;
	demodeadline.tm_year = 120; //2020
	demodeadline.tm_mon = 4; //may
	demodeadline.tm_mday = 2; //2
	demodeadline.tm_hour = 12; //noon
	demodeadline.tm_min = 0; //on the hour
	demodeadline.tm_sec = 0;
	demodeadline.tm_isdst = 1; //account for dst
	time_t ttdd = mktime(&demodeadline); //convert tm to time_t
	double delta = difftime(ttdd, curtime);
	int delday = (int)(delta/86400);
	delta = delta - delday*86400;
	int delhour = (int)(delta/3600);
	delta = delta - delhour*3600;
	int delmin = (int)(delta/60);
	std::cout <<"(+" << delday << "d, " << delhour << "h" << delmin << "m)"<< std::endl;

}
