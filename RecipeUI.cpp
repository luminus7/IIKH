#include "RecipeUI.h"
#include "util.h"
#include <cstdlib>
using namespace std;

void RecipeUI::printRecipe(Recipe r)
{
    system("cls");
    cout << endl;
    cout << " #############################" << endl;
    cout << " ##                         ##" << endl;
    cout << " ##     Selected Recipe     ##" << endl;
    cout << " ##                         ##" << endl;
    cout << " #############################" << endl;
    cout << endl;

    cout << " Name : " << r.getName() << endl;
    cout << " Cooking Time : " << r.getDuration() << " minutes" << endl;

    if (r.getIngredient().size())
    {
        cout << endl;
        cout << " <Ingredients List>" << endl;
        for (int i = 0; i < r.getIngredient().size(); i++)
        {
            cout << " " << i + 1 << ". " << r.getIngredient()[i].getName() << " (" << r.getIngredient()[i].getAmount() << "g)" << endl;
        }
    }

    if (r.getDescription().size())
    {
        string formattedDescription = ReplaceAll(r.getDescription(), "\n", "\n > ");
        cout << endl;
        cout << " <How to Cook>" << formattedDescription;
    }

    cout << endl << endl;
}

int RecipeUI::showRecipeList()
{
    if (rdb.getRecipesList().empty())
    {
        cout << endl;
        cout << " You don't have any recipes!" << endl;
        cout << " Please add some recipes to the database." << endl;
        cout << endl;
        cout << " Press Enter to Continue... ";
        waitEnter();
        return -1;
    }

    vector<string> searchString;
    vector<Recipe> searchBucket = rdb.getRecipesList();
    while(1)
    {
        cout << endl;
        cout << " ############################" << endl;
        cout << " ##                        ##" << endl;
        cout << " ##       Recipe List      ##" << endl;
        cout << " ##                        ##" << endl;
        cout << " ############################" << endl;
        cout << endl;
    
        int i = 0;
        for(i = 0; i < searchBucket.size(); i++)
        {
            cout << "  " << (i+1) << ". " << searchBucket[i].getName() << endl;
        }
        
        cout << endl;
        cout << " ############################" << endl;
        cout << endl;
        cout << " Want to start new search? (Y/N) : ";
        string ynSelect;
        cin >> ynSelect;
        cin.ignore(INT_MAX, '\n');

        if (ynSelect == "y" || ynSelect == "Y")
        {
            cout << " Search keywords : ";
            string tempSearchSave;
            getline(cin, tempSearchSave);

            stringstream tempSearchStream(tempSearchSave);
            istream_iterator<string> tempSearchIter(tempSearchStream);
            istream_iterator<string> token;
            vector<string> results(tempSearchIter, token);

            searchString = results;
            searchBucket = rdb.searchRecipes(results);
            system("cls");
        }
        else
        {
            cout << " Which Recipe do you want to choose? (0 to Cancel) : ";
            int targetRecipe;
            cin >> targetRecipe;
            cin.ignore(INT_MAX, '\n');
            if (targetRecipe == 0) return -1;
            if (targetRecipe > searchBucket.size())
            {
                while (targetRecipe > searchBucket.size())
                {
                    cout << " Invalid Number!" << endl << endl;
                    cout << " Which Recipe do you want to choose? (0 to Cancel) : ";
                    cin >> targetRecipe;
                    cin.ignore(INT_MAX, '\n');
                    if (targetRecipe == 0) return -1;
                }
            }
            printRecipe(searchBucket[targetRecipe - 1]);
            cout << " Press Enter to Continue... " << endl;
            waitEnter();
            return searchBucket[targetRecipe - 1].getId();
        }
    }
    
}
void RecipeUI::showRecipeAddForm()
{
    system("cls");
    cout << endl;
    cout << " ############################" << endl;
    cout << " ##                        ##" << endl;
    cout << " ##       Recipe Form      ##" << endl;
    cout << " ##                        ##" << endl;
    cout << " ############################" << endl;
    cout << endl;
    
    cout << " Recipe name : ";
    string name;
    cin >> name;
    cout << endl;
    cin.ignore(INT_MAX, '\n');

    if(name == "EasterEgg")
    {
        system("cls");
        easteregg();
        waitEnter();
        return;
    }

    vector<Ingredient> ingredients;

    for (int idx = 1; ; idx++) {
        string tempIngName;
        int tempIngAmount;

        cout << " Ingredient #" << idx << " name (0 to exit) : ";
        cin >> tempIngName;

        if (tempIngName == "0")
            break;

        while (true)
        {
            cout << " Ingredient #" << idx << " amount : ";
            cin >> tempIngAmount;
            if (!cin.fail())
                break;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
        }

        cout << endl;

        Ingredient tempIng;
        tempIng.setName(tempIngName);
        tempIng.setAmount(tempIngAmount);
        ingredients.push_back(tempIng);
    }
    
    cout << endl;
    cin.ignore(INT_MAX, '\n');
    
    string recipeDescription;
    string tempDescriptionSave = "a";

    cout << " Describe \"How to Cook?\"" << endl << " (If you finish writing, Press Enter Twice.)" << endl << endl;
    while (true)
    {
        cout << " > ";
        getline(cin, tempDescriptionSave);
        if (tempDescriptionSave.empty()) break;
        recipeDescription += "\n" + tempDescriptionSave;
    }
    cout << endl;

    int tempDuration;
    while (true)
    {
        cout << " Cooking Time Duration : ";
        cin >> tempDuration;
        if (!cin.fail())
            break;
        cin.clear();
        cin.ignore(INT_MAX, '\n');
    }
    cin.ignore(INT_MAX, '\n');
    rdb.addRecipe(name, ingredients, recipeDescription, tempDuration);
}

void RecipeUI::showRecipeEditForm()
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
    
    int selectedRecipeId = showRecipeList();

    if (selectedRecipeId == -1) return;

    rdb.removeRecipe(selectedRecipeId);
    showRecipeAddForm();
}


void RecipeUI::easteregg()
{
    cout << "Recipe UI / Main Menu Formatting : KZRT(방석현)" << endl;
    cout << "Planner UI / Modules Design / Debugging : njw1204(나종우)" << endl; 
    cout << "Recipe Database / Searching Engine : UCYang(양운천)" << endl;
    cout << "Date / Escape Master : robinjoo1015(주영석)" << endl;
    cout << "Report / Presentation : Joohee_Cho(조주희)" << endl;
}
