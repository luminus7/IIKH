#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <iterator>
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
