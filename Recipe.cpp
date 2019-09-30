#include <vector>
#include "Recipe.h"
using namespace std;

void Recipe::addIngredient(Ingredient ingredient)
{
	for (Ingredient i : ingredientList) {
		if (i.getName() == ingredient.getName()) {
			i.setAmount(i.getAmount() + ingredient.getAmount());
			return;
		}
	}
	ingredientList.push_back(ingredient);
}

bool Recipe::removeIngredient(string name)
{
	int size = ingredientList.size();
	for (int i = 0; i < size; i++) {
		if (ingredientList[i].getName() == name) {
			ingredientList.erase(ingredientList.begin() + i);
			return true;
		}
	}
	return false;
}