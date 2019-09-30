#pragma once
#include <vector>
#include <string>
#include "Date.h"

class Plan {
private:
	vector<Date> plan;

public:
	Plan(vector<Date> plan) { this->plan = plan; }
	void setPlan(vector<Date> plan) { this->plan = plan; }
	vector<Date> getPlan() { return plan; }
	//void addDate(Date date);fuckshit
	void printPlan();
	void writePlanToFile(string filename);
};