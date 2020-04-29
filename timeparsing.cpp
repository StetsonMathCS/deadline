#include <iostream>
#include <sstream>
#include <ctime>
#include <time.h>

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
