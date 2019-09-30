#include "PlannerUI.h"
#include "RecipeUI.h"
#include "RecipeDatabase.h"
#include "Date.h"
#include <climits>
using namespace std;


void PlannerUI::showPlannerForm()
{
    RecipeUI rui = RecipeUI(rdb);
    cout << "[Let's make Plan]" << endl;

    int year, month, day;
    Date startDate, endDate;

    do
    {
        cout << "Starting Date (YYYY mm dd) : ";
        cin >> year >> month >> day;    
    } while (!startDate.init(year, month, day));

    do
    {
        cout << "End Date (YYYY mm dd) : ";
        cin >> year >> month >> day;
    } while (!endDate.init(year, month, day));

    Date nowDate = startDate;
    bool breakFor = false;

    for (int i = 1; !breakFor; i++)
    {
        if (nowDate.compareTime(endDate) == true)
        {
            breakFor = true;
        }

        cin.ignore(INT_MAX, '\n');
        cout << endl << "[" << nowDate.getYear() << "/" << nowDate.getMonth() << "/" << nowDate.getDay() << "]" << endl;
    
        while (true) {
            int selected = rui.showRecipeList();
            if (selected == -1) break;
            Recipe recipe = rdb.getRecipe(selected);
            nowDate = nowDate.getTomorrow();
        }
    }
}
