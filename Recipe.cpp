#include <iostream>
#include <vector>
#include <cstdlib>
#include "Recipe.h"
#include "util.h"
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

void Recipe::printRecipe()
{
    cout << endl;
    cout << " #############################" << endl;
    cout << " ##                         ##" << endl;
    cout << " ##     Selected Recipe     ##" << endl;
    cout << " ##                         ##" << endl;
    cout << " #############################" << endl;
    cout << endl;

    cout << " Name : " << getName() << endl;
    cout << " Cooking Time : " << getDuration() << " minutes" << endl;

    if (getIngredient().size())
    {
        cout << endl;
        cout << " <Ingredients List>" << endl;
        for (int i = 0; i < getIngredient().size(); i++)
        {
            cout << " " << i + 1 << ". " << getIngredient()[i].getName() << " (" << getIngredient()[i].getAmount() << "g)" << endl;
        }
    }

    if (getDescription().size())
    {
        string formattedDescription = ReplaceAll(getDescription(), "\n", "\n > ");
        cout << endl;
        cout << " <How to Cook>" << formattedDescription;
    }

    cout << endl << endl;
}

bool Recipe::readFile(istream& in)
{
	string token;
	Ingredient ingred;

	getline(in, token, ';');
	if (in.eof())
		return false;
	id = stoi(token);
	getline(in, token, ';');
	duration = stoi(token);
	getline(in, name, ';');
	getline(in, description, ';');

	ingredientList.clear();
	while (ingred.readFile(in))
		ingredientList.emplace_back(ingred);

	return true;
}

bool Recipe::writeFile(ostream& out)
{
	out << id << ';'
		<< duration << ';'
		<< name << ';'
		<< description << ';';

	for (auto& ingred : ingredientList)
		if (!ingred.writeFile(out))
			return false;

    out << '\n';

	return true;
}
