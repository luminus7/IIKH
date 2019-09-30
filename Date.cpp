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

Date Date::getTomorrow() {
    Date tomorrow = *this;
    int days[12] = {
        31,28,31,30,31,30,31,31,30,31,30,31
    };

    if (this->year % 400 == 0 || this->year % 100 != 0 && this->year % 4 == 0) {
        days[1] = 29;
    }

    if (this->day == 31 && this->month == 12) {
        tomorrow.day = 1;
        tomorrow.month = 1;
        tomorrow.year = this->year + 1;
    }
    else if (this->day == days[this->month - 1]) {
        tomorrow.day = 1;
        tomorrow.month = this->month + 1;
        tomorrow.year = this->year;
    }
    else {
        tomorrow.day = this->day + 1;
        tomorrow.month = this->month;
        tomorrow.year = this->year;
    }

    return tomorrow;
}

bool Date::compareTime(Date& date) {
    return (this->year == date.getYear() && this->month == date.getMonth() && this->day == date.getDay());
}