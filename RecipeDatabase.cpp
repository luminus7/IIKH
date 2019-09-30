#include "RecipeDatabase.hpp"
#include <cassert>

using namespace std;

std::vector<Recipe>::iterator RecipeDatabase::_findRecipe(int id)
{
	return find(recipes.begin(), recipes.end(),
		[](auto recipe) { return recipe.getId() == id});
}

void RecipeDatabase::addRecipe(const string& name,
	const std::vector<Ingredient>& ingreds,
	const string& desc, int duration)
{
	Recipe recipe(id++);

	recipe.setName(name);
	for (const auto& ingred : ingreds)
		recipe.addIngredient(ingred);
	recipe.setDescription(desc);
	recipe.setDuration(duration);

	recipes.emplace_back(recipe);
}

bool RecipeDatabase::removeRecipe(int id)
{
	auto it = _findRecipe(id);
	if (it == recipes.cend())
		return false;
	recipes.erase(it);
	return true;
}

// id must valid.
Recipe RecipeDatabase::getRecipe(int id)
{
	auto it = _findRecipe(id);
	assert(it != recipes.cend());
	return *it;
}

std::vector<Recipe> RecipeDatabase::getRecipesList()
{
	return recipes;
}

// Currently developing...
std::vector<Recipe> RecipeDatabase::searchRecipes(
	const std::vector<std::string>& keywords)
{
	return recipes;
}