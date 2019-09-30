#pragma once

#include <string>
#include <vector>
#include "Recipe.h"

class RecipeDatabase
{
protected:
	std::vector<Recipe> recipes;
	int id = 0;

	std::vector<Recipe>::iterator _findRecipe(int id);

public:
	RecipeDatabase() = default;
	RecipeDatabase(RecipeDatabase&&) = default;
	RecipeDatabase(std::initializer_list<Recipe> list)
		: recipes(list) {}
	RecipeDatabase(const std::vector<Recipe>& val) : recipes(val) {}
	RecipeDatabase(std::vector<Recipe>&& val) : recipes(std::move(val)) {}
	RecipeDatabase& operator=(RecipeDatabase&&) = default;

	void addRecipe(const string& name,
		const std::vector<Ingredient>& ingreds,
		const string& desc, int duration);
	bool removeRecipe(int id);
	Recipe getRecipe(int id);
	std::vector<Recipe> getRecipesList();
	std::vector<Recipe> searchRecipes(
		const std::vector<std::string>& keywords);
};