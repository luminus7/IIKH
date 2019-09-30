#include "PlannerUI.h"
#include "RecipeUI.h"
#include "RecipeDatabase.h"
#include "Date.h"
#include "Plan.h"
#include "util.h"
#include <climits>
using namespace std;


void PlannerUI::showPlannerForm()
{
    if (rdb.getRecipesList().empty())
    {
        cout << endl;
        cout << " You don't have any recipes!" << endl;
        cout << " Please add some recipes to the database." << endl;
        cout << endl;
        cout << " Press Enter to Continue... ";
        waitEnter();
        return;
    }

    RecipeUI rui = RecipeUI(rdb);
    cout << "####################" << endl;
    cout << "#                  #" << endl;
    cout << "#   Meal Planner   #" << endl;
    cout << "#                  #" << endl;
    cout << "####################" << endl;

    Plan plan;
    vector<Date>& dates = plan.getDates();

    for (int i = 1; ; i++)
    {
        int year, month, day;
        Date date;

        cout << endl;
        cout << "****************************************" << endl;
        cout << endl;
        cout << "[No." << i << "]" << endl;
        cout << "Date (yyyy mm dd) (Input -1 to exit) : ";
        cin >> year;

        if (year == -1)
        {
            break;
        }
        
        cin >> month >> day;
        
        if (!date.init(year, month, day))
        {
            cout << "Invalid Date! Please write again." << endl;
            i--;
            continue;
        }
    }
}