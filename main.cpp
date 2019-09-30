#pragma once
#include "RecipeUI.h"

int main(void)
{
	RecipeDatabase rdb;
	RecipeUI rui(rdb);
	const string seperator = "*****************";
	
	while(1)
	{
		cout << seperator << endl;
		cout << "Main Menu" << endl;
		cout << seperator << endl;
		
		cout << endl;
		cout << "1. Show/Search Recipe List" << endl;
		cout << "2. Add Recipe" << endl;
		cout << "3. Edit/Replace Recipe" << endl;
		cout << "4. Make Plan" << endl;
		cout << endl;
	
		cout << "Which Operation Do You Want (0 to Exit) : ";
		int selector;
		cin >> selector;
		cin.ignore(INT_MAX, '\n');
	
		switch(seletor)
		{
			case 0:
				return 0;
			case 1:
				rui.showRecipeList();
				break;
			case 2:
				rui.showRecipeAddForm();
				break;
			case 3:
				rui.showRecipeEditForm();
				break;		
		}
	}

}
