#pragma once
#include <vector>
#include <string>
#include "Ingredient.h"
using namespace std;

class Recipe {
private:
	int id;
	vector<Ingredient> ingredientList;
	string name;
	string description;
	int duration;

public:
	Recipe(int id) { this->id = id; }
	void addIngredient(Ingredient ingredient);
	bool removeIngredient(string name);
	string getName() {
		return name;
	}
	string getDescription() {
		return description;
	}
	int getDuration() {
		return duration;
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
};