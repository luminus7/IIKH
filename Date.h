#pragma once
#include "Meal.h"

class Date {
private:
    int year, month, day;
    Meal breakfast, lunch, dinner;

public:
    bool init(int year, int month, int day);
    void setBreakfast(Meal breakfast) { this->breakfast = breakfast; }
    void setLunch(Meal lunch) { this->lunch = lunch; }
    void setDinner(Meal dinner) { this->dinner = dinner; }
    int getYear() { return year; }
    int getMonth() { return month; }
    int getDay() { return day; }
    Meal getBreakfast() { return breakfast; }
    Meal getLunch() { return lunch; }
    Meal getDinner() { return dinner; }
    Date getTomorrow();
    bool compareTime(Date& date);
};