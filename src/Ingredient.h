#pragma once
#include <iostream>
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
	bool readFile(istream& in) {
        string token;

        if (in.peek() == '\n') {
            in.ignore();
            return false;
        }

        getline(in, name, ';');
        getline(in, token, ';');
        amount = stoi(token);

        return true;
    }
	bool writeFile(ostream& out) {
        out << name << ';'
            << amount << ';';

        return true;
    }
};
