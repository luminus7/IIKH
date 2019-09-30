#include <iostream>
#include <fstream>
#include <string>
#include "Plan.h"
using namespace std;

void Plan::printPlan()
{
	vector<Ingredient> shoppingList;
	for (Date d : plan) {
		int btime = 0, ltime = 0, dtime = 0;
		Meal breakfast = d.getBreakfast(), lunch = d.getLunch(), dinner = d.getDinner();
		cout << d.getYear() << '/' << d.getMonth() << '/' << d.getDay() << '\n' << '\n';
		cout << "*******BREAKFAST*******" << '\n' << '\n';
		for (Recipe r : breakfast.getMenus()) {
			cout << '<' << r.getName() << '>' << '\n';
			cout << "Ingredients" << '\n';
			for (Ingredient i : r.getIngredient()) {
				cout << " -" << i.getName() << " " << i.getAmount()*breakfast.getPeople() << "g" << '\n';
				bool inshoppinglist = false;
				for (int s = 0; s < shoppingList.size(); s++) {
					if (shoppingList[s].getName() == i.getName()) shoppingList[s].setAmount(shoppingList[s].getAmount() + i.getAmount());
					inshoppinglist = true;
				}
				if (!inshoppinglist) shoppingList.push_back(i);
			}
			cout << "Description" << '\n';
			cout << " " << r.getDescription() << '\n';
			cout << "Duration : " << r.getDuration() << "minutes" << '\n' << '\n';
			btime += r.getDuration();
		}
		cout << "Total Duration : " << btime << "minutes" << '\n' << '\n';
		cout << "*******LUNCH*******" << '\n' << '\n';
		for (Recipe r : lunch.getMenus()) {
			cout << '<' << r.getName() << '>' << '\n';
			cout << "Ingredients" << '\n';
			for (Ingredient i : r.getIngredient()) {
				cout << " -" << i.getName() << " " << i.getAmount()*lunch.getPeople() << "g" << '\n';
				bool inshoppinglist = false;
				for (int s = 0; s < shoppingList.size(); s++) {
					if (shoppingList[s].getName() == i.getName()) shoppingList[s].setAmount(shoppingList[s].getAmount() + i.getAmount());
					inshoppinglist = true;
				}
				if (!inshoppinglist) shoppingList.push_back(i);
			}
			cout << "Description" << '\n';
			cout << " " << r.getDescription() << '\n';
			cout << "Duration : " << r.getDuration() << "minutes" << '\n' << '\n';
			ltime += r.getDuration();
		}
		cout << "Total Duration : " << ltime << "minutes" << '\n' << '\n';
		cout << "*******DINNER*******" << '\n' << '\n';
		for (Recipe r : dinner.getMenus()) {
			cout << '<' << r.getName() << '>' << '\n';
			cout << "Ingredients" << '\n';
			for (Ingredient i : r.getIngredient()) {
				cout << " -" << i.getName() << " " << i.getAmount()*dinner.getPeople() << "g" << '\n';
				bool inshoppinglist = false;
				for (int s = 0; s < shoppingList.size(); s++) {
					if (shoppingList[s].getName() == i.getName()) shoppingList[s].setAmount(shoppingList[s].getAmount() + i.getAmount());
					inshoppinglist = true;
				}
				if (!inshoppinglist) shoppingList.push_back(i);
			}
			cout << "Description" << '\n';
			cout << " " << r.getDescription() << '\n';
			cout << "Duration : " << r.getDuration() << "minutes" << '\n' << '\n';
			dtime += r.getDuration();
		}
		cout << "Total Duration : " << dtime << "minutes" << '\n' << '\n';
		cout << '\n';
	}
	cout << '\n';
	cout << "*******SHOPPING LIST*******" << '\n';
	for (Ingredient i : shoppingList) cout << i.getName() << " " << i.getAmount() << '\n';
}

void Plan::writePlanToFile(string filename)
{
	vector<Ingredient> shoppingList;
	ofstream file;
	file.open((filename + ".txt").c_str());
	for (Date d : plan) {
		int btime = 0, ltime = 0, dtime = 0;
		Meal breakfast = d.getBreakfast(), lunch = d.getLunch(), dinner = d.getDinner();
		file << d.getYear() << '/' << d.getMonth() << '/' << d.getDay() << '\n' << '\n';
		file << "*******BREAKFAST*******" << '\n' << '\n';
		for (Recipe r : breakfast.getMenus()) {
			file << '<' << r.getName() << '>' << '\n';
			file << "Ingredients" << '\n';
			for (Ingredient i : r.getIngredient()) {
				file << " -" << i.getName() << " " << i.getAmount()*breakfast.getPeople() << "g" << '\n';
				bool inshoppinglist = false;
				for (int s = 0; s < shoppingList.size(); s++) {
					if (shoppingList[s].getName() == i.getName()) shoppingList[s].setAmount(shoppingList[s].getAmount() + i.getAmount());
					inshoppinglist = true;
				}
				if (!inshoppinglist) shoppingList.push_back(i);
			}
			file << "Description" << '\n';
			file << " " << r.getDescription() << '\n';
			file << "Duration : " << r.getDuration() << "minutes" << '\n' << '\n';
			btime += r.getDuration();
		}
		file << "Total Duration : " << btime << "minutes" << '\n' << '\n';
		file << "*******LUNCH*******" << '\n' << '\n';
		for (Recipe r : lunch.getMenus()) {
			file << '<' << r.getName() << '>' << '\n';
			file << "Ingredients" << '\n';
			for (Ingredient i : r.getIngredient()) {
				file << " -" << i.getName() << " " << i.getAmount()*lunch.getPeople() << "g" << '\n';
				bool inshoppinglist = false;
				for (int s = 0; s < shoppingList.size(); s++) {
					if (shoppingList[s].getName() == i.getName()) shoppingList[s].setAmount(shoppingList[s].getAmount() + i.getAmount());
					inshoppinglist = true;
				}
				if (!inshoppinglist) shoppingList.push_back(i);
			}
			file << "Description" << '\n';
			file << " " << r.getDescription() << '\n';
			file << "Duration : " << r.getDuration() << "minutes" << '\n' << '\n';
			ltime += r.getDuration();
		}
		file << "Total Duration : " << ltime << "minutes" << '\n' << '\n';
		file << "*******DINNER*******" << '\n' << '\n';
		for (Recipe r : dinner.getMenus()) {
			file << '<' << r.getName() << '>' << '\n';
			file << "Ingredients" << '\n';
			for (Ingredient i : r.getIngredient()) {
				file << " -" << i.getName() << " " << i.getAmount()*dinner.getPeople() << "g" << '\n';
				bool inshoppinglist = false;
				for (int s = 0; s < shoppingList.size(); s++) {
					if (shoppingList[s].getName() == i.getName()) shoppingList[s].setAmount(shoppingList[s].getAmount() + i.getAmount());
					inshoppinglist = true;
				}
				if (!inshoppinglist) shoppingList.push_back(i);
			}
			file << "Description" << '\n';
			file << " " << r.getDescription() << '\n';
			file << "Duration : " << r.getDuration() << "minutes" << '\n' << '\n';
			dtime += r.getDuration();
		}
		file << "Total Duration : " << dtime << "minutes" << '\n' << '\n';
		file << '\n';
	}
	file << '\n';
	file << "*******SHOPPING LIST*******" << '\n';
	for (Ingredient i : shoppingList) cout << i.getName() << " " << i.getAmount() << '\n';
	file.close();
}