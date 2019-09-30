#include <iostream>
#include <fstream>
#include <string>
#include "Plan.h"
using namespace std;

void Plan::printPlan()
{
	for (Date d : plan) {
		Meal breakfast = d.getBreakfast(), lunch = d.getLunch(), dinner = d.getDinner();
		cout << d.getYear() << '/' << d.getMonth() << '/' << d.getDay() << '\n' << '\n';
		cout << "*******BREAKFAST*******" << '\n' << '\n';
		for (Recipe r : breakfast.getMenus()) {
			cout << '<' << r.getName() << '>' << '\n';
			cout << "Ingredients" << '\n';
			for (Ingredient i : r.getIngredient()) cout << " -" << i.getName << " " << i.getAmount()*breakfast.getPeople() << "g" << '\n';
			cout << "Description" << '\n';
			cout << " " << r.getDescription << '\n';
			cout << "Duration : " << r.getDuration() << "minutes" << '\n' << '\n';
		}
		cout << "*******LUNCH*******" << '\n' << '\n';
		for (Recipe r : lunch.getMenus()) {
			cout << '<' << r.getName() << '>' << '\n';
			cout << "Ingredients" << '\n';
			for (Ingredient i : r.getIngredient()) cout << " -" << i.getName << " " << i.getAmount()*lunch.getPeople() << "g" << '\n';
			cout << "Description" << '\n';
			cout << " " << r.getDescription << '\n';
			cout << "Duration : " << r.getDuration() << "minutes" << '\n' << '\n';
		}
		cout << "*******DINNER*******" << '\n' << '\n';
		for (Recipe r : dinner.getMenus()) {
			cout << '<' << r.getName() << '>' << '\n';
			cout << "Ingredients" << '\n';
			for (Ingredient i : r.getIngredient()) cout << " -" << i.getName << " " << i.getAmount()*dinner.getPeople() << "g" << '\n';
			cout << "Description" << '\n';
			cout << " " << r.getDescription << '\n';
			cout << "Duration : " << r.getDuration() << "minutes" << '\n' << '\n';
		}
		cout << '\n';
	}
}

void Plan::writePlanToFile(string filename)
{
	ofstream file;
	file.open((filename + ".txt").c_str());
	for (Date d : plan) {
		Meal breakfast = d.getBreakfast(), lunch = d.getLunch(), dinner = d.getDinner();
		file << d.getYear() << '/' << d.getMonth() << '/' << d.getDay() << '\n' << '\n';
		file << "*******BREAKFAST*******" << '\n' << '\n';
		for (Recipe r : breakfast.getMenus()) {
			file << '<' << r.getName() << '>' << '\n';
			file << "Ingredients" << '\n';
			for (Ingredient i : r.getIngredient()) file << " -" << i.getName << " " << i.getAmount()*breakfast.getPeople() << "g" << '\n';
			file << "Description" << '\n';
			file << " " << r.getDescription << '\n';
			file << "Duration : " << r.getDuration() << "minutes" << '\n' << '\n';
		}
		file << "*******LUNCH*******" << '\n' << '\n';
		for (Recipe r : lunch.getMenus()) {
			file << '<' << r.getName() << '>' << '\n';
			file << "Ingredients" << '\n';
			for (Ingredient i : r.getIngredient()) file << " -" << i.getName << " " << i.getAmount()*lunch.getPeople() << "g" << '\n';
			file << "Description" << '\n';
			file << " " << r.getDescription << '\n';
			file << "Duration : " << r.getDuration() << "minutes" << '\n' << '\n';
		}
		file << "*******DINNER*******" << '\n' << '\n';
		for (Recipe r : dinner.getMenus()) {
			file << '<' << r.getName() << '>' << '\n';
			file << "Ingredients" << '\n';
			for (Ingredient i : r.getIngredient()) file << " -" << i.getName << " " << i.getAmount()*dinner.getPeople() << "g" << '\n';
			file << "Description" << '\n';
			file << " " << r.getDescription << '\n';
			file << "Duration : " << r.getDuration() << "minutes" << '\n' << '\n';
		}
		file << '\n';
	}
	file.close();
}