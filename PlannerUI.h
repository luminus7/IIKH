#pragma once
#include <iostream>
#include "RecipeDatabase.h"
using namespace std;

class PlannerUI {
private:
    RecipeDatabase& rdb;

public:
    PlannerUI(RecipeDatabase& rdb) : rdb(rdb) {}
    void showPlannerForm();
};