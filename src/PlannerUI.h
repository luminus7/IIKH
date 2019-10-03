#pragma once
#include <iostream>
#include "Date.h"
#include "RecipeDatabase.h"
using namespace std;

class PlannerUI {
private:
    RecipeDatabase& rdb;
    void makeDailyPlan(Date& date);

public:
    PlannerUI(RecipeDatabase& rdb) : rdb(rdb) {}
    void showPlannerForm();
};