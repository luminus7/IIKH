#pragma once
#include "Recipe.h"
#include <vector>
using namespace std;

class Meal {
private:
    vector<Recipe> menus;
    int people;

public:
    Meal() : people(1) {}
    Meal(int people) : people(people) {}

    void addMenu(Recipe recipe);
    bool removeMenu(int id);

    vector<Recipe> getMenus() {
        return menus;
    }

    int getPeople() {
        return people;
    }

    void setPeople(int people) {
        this->people = people;
    }
};