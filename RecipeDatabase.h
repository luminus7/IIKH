#pragma once
#include <vector>
#include <string>
using namespace std;

class RecipeDatabase {
private:
    vector<Recipe> recipesList;

public:
    void addRecipe(Recipe recipe);
    Recipe getRecipe(int id);
    bool removeRecipe(int id);
    vector<Recipe> getRecipesList();
    vector<Recipe> searchRecipes(vector<string> keywords);
};
