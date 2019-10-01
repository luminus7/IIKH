#pragma once
#include <vector>
#include <string>
#include "Ingredient.h"
using namespace std;

class Recipe {
private:
	int id;
	int duration;
	string name;
	string description;
	vector<Ingredient> ingredientList;

public:
	Recipe() {}
	Recipe(int id) { this->id = id; }
	void addIngredient(Ingredient ingredient);
	bool removeIngredient(string name);
    void printRecipe();
	int getId() {
		return id;
	}
	string getName() {
		return name;
	}
	string getDescription() {
		return description;
	}
	int getDuration() {
		return duration;
	}
	vector<Ingredient>& getIngredient() {
		return ingredientList;
	}
	void setName(string name) {
		this->name = name;
	}
	void setDescription(string description) {
		this->description = description;
	}
	void setDuration(int duration) {
		this->duration = duration;
	}
	// bool readFile(istream& in);
	// bool writeFile(ostream& out);
};
