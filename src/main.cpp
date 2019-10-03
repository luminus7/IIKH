#include <string>
#include <cstdlib>
#include "RecipeUI.h"
#include "PlannerUI.h"
#include "util.h"
using namespace std;

int main(void)
{
    RecipeDatabase rdb;
    RecipeUI rui(rdb);
    PlannerUI pui(rdb);

	rdb.readFile("data.db");
    
    while(1)
    {
        clrscr();
        cout << endl;
        cout << "   8888888   8888888   888    d8P    888    888" << endl;
        cout << "     888       888     888   d8P     888    888" << endl;
        cout << "     888       888     888  d8P      888    888" << endl;
        cout << "     888       888     888d88K       8888888888" << endl;
        cout << "     888       888     8888888b      888    888" << endl;
        cout << "     888       888     888  Y88b     888    888" << endl;
        cout << "     888       888     888   Y88b    888    888" << endl;
        cout << "   8888888   8888888   888    Y88b   888    888" << endl;
        cout << endl;
        cout << endl;

        cout << "       ###################################" << endl;
        cout << "       ##                               ##" << endl;
        cout << "       ##           Main Menu           ##" << endl;
        cout << "       ##                               ##" << endl;
        cout << "       ###################################" << endl;
        cout << "       ##                               ##" << endl;
        cout << "       ##  1. Show/Search Recipe List   ##" << endl;
        cout << "       ##  2. Add Recipe                ##" << endl;
        cout << "       ##  3. Edit Recipe               ##" << endl;
        cout << "       ##  4. Make your Meal Plan       ##" << endl;
        cout << "       ##  0. Exit                      ##" << endl;
        cout << "       ##                               ##" << endl;
        cout << "       ###################################" << endl;
        cout << endl;

        cout << "         Which Operation Do You Want : ";
        int selector;
        cin >> selector;
        cin.ignore(INT_MAX, '\n');
    
        switch(selector)
        {
            case 0:
				if (!rdb.writeFile("data.db"))
					return 0x1;
                return 0;
            case 1:
                clrscr();
                rui.showRecipeList();
                break;
            case 2:
                clrscr();
                rui.showRecipeAddForm();
                break;
            case 3:
                clrscr();
                rui.showRecipeEditForm();
                break;
            case 4:
                clrscr();
                pui.showPlannerForm();
                break;
        }
    }

}
