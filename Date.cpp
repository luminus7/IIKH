#include "Date.h"
using namespace std;

bool Date::init(int year, int month, int day)
{
	if (year < 0 || month < 1 || month > 12 || day < 1) return false;
	else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
		if (day > 31) return false;
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11) {
		if (day > 30) return false;
	}
	else if (month == 2) {
        if (year % 400 == 0) {
            if (day > 29) return false;
        }
        else if (year % 100 == 0) {
            if (day > 28) return false;
        }
        else if (year % 4 == 0) {
            if (day > 29) return false;
        }
		else if (day > 28) return false;
	}
	this->year = year;
	this->month = month;
	this->day = day;
	return true;
}