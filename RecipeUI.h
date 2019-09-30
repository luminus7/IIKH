#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <iterator>
#include "Recipe.h"
#include "RecipeDatabase.h"
#include <climits>

using namespace std;

class RecipeUI
{
private:
	const string seperator = "**************************";
	RecipeDatabase rdb;
	void printRecipe(Recipe r);

public:
	int showRecipeList();
	void showRecipeAddForm();
	void showRecipeEditForm();
};
