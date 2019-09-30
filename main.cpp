#include "RecipeUI.h"
#include "PlannerUI.h"

int main(void)
{
	RecipeDatabase rdb;
	RecipeUI rui(rdb);
	PlannerUI pui(rdb);
	const string seperator = "*****************";
	
	while(1)
	{
		system("cls");
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
	
		switch(selector)
		{
			case 0:
				return 0;
			case 1:
				system("cls");
				rui.showRecipeList();
				break;
			case 2:
				system("cls");
				rui.showRecipeAddForm();
				break;
			case 3:
				system("cls");
				rui.showRecipeEditForm();
				break;
			case 4:
				system("cls");
				pui.showPlannerForm();
				break;
		}
	}

}
