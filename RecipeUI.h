#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <iterator>
#include "Recipe.h"
#include "RecipeDatabase.h"
using namespace std;

class RecipeUI
{
private:
	const string seperator = "**************************";
	RecipeDatabase rdb;
	void printRecipe(Recipe r);

public:
    RecipeUI(RecipeDatabase rdb);
	int showRecipeList();
	void showRecipeAddForm();
	void showRecipeEditForm();
};
