#include "RecipeDatabase.h"
#include <cassert>
#include <algorithm>
#include <fstream>

using namespace std;

vector<Recipe>::iterator RecipeDatabase::_findRecipe(int id)
{
    return find_if(recipes.begin(), recipes.end(),
        [id](auto recipe) { return recipe.getId() == id; });
}

void RecipeDatabase::addRecipe(const string& name,
    const vector<Ingredient>& ingreds,
    const string& desc, int duration)
{
    Recipe recipe(auto_inc_id++);

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

Recipe RecipeDatabase::getRecipe(int id)
{
    auto it = _findRecipe(id);
    assert(it != recipes.cend());
    return *it;
}

vector<Recipe> RecipeDatabase::getRecipesList()
{
    return recipes;
}

vector<Recipe> RecipeDatabase::searchRecipes(
    const vector<string>& keywords)
{
    vector<Recipe>::iterator it = recipes.begin();
    vector<Recipe> results;

    while (true)
    {
        it = find_if(it, recipes.end(), [&keywords](auto recipe) {
            const auto& name = recipe.getName();
            const auto& ingreds = recipe.getIngredient();

            for (const auto& k : keywords)
            {
                if (name.find(k) != string::npos)
                    return true;
                if (find_if(ingreds.begin(), ingreds.end(), [&k](auto ingred) {
                    return ingred.getName().find(k) != string::npos;
                }) != ingreds.end())
                    return true;
            }

            return false;
        });
        if (it == recipes.end())
            break;
        results.emplace_back(*it);
        ++it;
    }

    return results;
}


bool RecipeDatabase::readFile(const string& filename)
{
    ifstream fin(filename);
    Recipe recipe;
    string s;

    if (!fin.is_open())
        return false;

    getline(fin, s);
    if (s != "Prof. BongBong")
        return false;
    getline(fin, s);
    auto_inc_id = stoi(s);
    
    while (recipe.readFile(fin))
        recipes.emplace_back(recipe);

    fin.close();

    return true;
}

bool RecipeDatabase::writeFile(const string& filename)
{
    ofstream fout(filename);

    if (!fout.is_open())
        return false;

    fout << "Prof. BongBong" << '\n';
    fout << auto_inc_id << '\n';

	for (auto& recipe: recipes)
		if (!recipe.writeFile(fout))
			return false;

    fout.close();

    return true;
}
