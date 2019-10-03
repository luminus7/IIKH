#include "Meal.h"

void Meal::addMenu(Recipe recipe) {
    menus.push_back(recipe);
}

bool Meal::removeMenu(int id) {
    for (int i = 0; i < menus.size(); i++) {
        if (menus[i].getId() == id) {
            menus.erase(menus.begin() + i);
            return true;
        }
    }
    return false;
}