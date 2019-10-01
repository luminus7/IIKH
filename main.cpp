#include <string>
#include <cstdlib>
#include "RecipeUI.h"
#include "PlannerUI.h"
using namespace std;

int main(void)
{
    RecipeDatabase rdb;
    RecipeUI rui(rdb);
    PlannerUI pui(rdb);
    
    while(1)
    {
        system("cls");
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
