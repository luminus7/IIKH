#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "Date.h"

class Plan {
private:
    std::vector<Date> dates;

public:
    Plan() {}
    Plan(std::vector<Date> dates) { this->dates = dates; }
    void setDates(std::vector<Date> dates) { this->dates = dates; }
    std::vector<Date>& getDates() { return dates; }
    void printPlan();
    void writePlanToFile(std::ostream& file);
    void writePlanToFile(std::string filename);
};