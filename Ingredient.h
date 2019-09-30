#pragma once
#include <string>
using namespace std;

class Ingredient {
private:
	string name;
	int amount;
public:
	string getName() {
		return name;
	}
	int getAmount() {
		return amount;
	}
	void setName(string name) {
		this->name = name;
	}
	void setAmount(int amount) {
		this->amount = amount;
	}
};