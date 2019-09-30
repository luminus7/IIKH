#pragma once
#include <vector>
#include <string>
#include "Date.h"

class Plan {
private:
    vector<Date> dates;

public:
    Plan() {}
    Plan(vector<Date> dates) { this->dates = dates; }
    void setDates(vector<Date> plan) { this->dates = dates; }
    vector<Date> getDates() { return dates; }
    void printPlan();
    void writePlanToFile(string filename);
};