#include "RecipeUI.h"
using namespace std;

void RecipeUI::printRecipe(Recipe r)
{
	cout << seperator << endl;
	cout << "Selected Recipe" << endl;
	cout << seperator << endl;

	cout << "Name : " << r.getName() << endl;
	cout << "Expected Cooking Time : " << r.getDuration() << endl;
	cout << "Ingredients List : " << endl;
	for(int i=0; i<r.getIngredient().size(); i++)
	{
		cout << i+1 << ". " << r.getIngredient()[i].getName() << " : " << r.getIngredient()[i].getAmount() << endl;
	}
	cout << endl;
	cout << "How to Cook : " << endl;
	cout << r.getDescription();
	
}

int RecipeUI::showRecipeList()
{
	vector<string> searchString;
    vector<Recipe> searchBucket = rdb.getRecipesList();
	while(1)
	{
		cout << seperator << endl;
		cout << "Recipe List" << endl;
		cout << seperator << endl;
    
	    int i = 0;
		for(i = 0; i < searchBucket.size(); i++)
		{
			cout << (i+1) << ". " << searchBucket[i].getName() << endl;
		}
		cout << seperator << endl;
		cout << "To stop Search, input 0" << endl;
		cout << "Keyword Search : ";
		string tempSearchSave;
		getline(cin, tempSearchSave);
		if(tempSearchSave == "0")
		{
			cout << "Which Recipe do you want to choose? (0 to Exit) : ";
			int targetRecipe;
			cin >> targetRecipe;
			if(targetRecipe == 0) return -1;
            cin.ignore(INT_MAX, '\n');
            printRecipe(searchBucket[i - 1]);
            cout << "Enter to Continue : " << endl;
            string dummy;
            getline(cin, dummy);
            return searchBucket[i - 1].getId();
		}
		
		stringstream tempSearchStream(tempSearchSave);
		istream_iterator<string> tempSearchIter(tempSearchStream);
		istream_iterator<string> token;
	    vector<string> results(tempSearchIter, token);
		
		searchString = results;
		searchBucket = rdb.searchRecipes(results);
		system("cls");
	}
	
}
void RecipeUI::showRecipeAddForm()
{
	cout << seperator << endl;
	cout << "Recipe Add" << endl;
	cout << seperator << endl;
	
	cout << "Enter a Name of Recipe : ";
	string name;
    cin >> name;

    vector<Ingredient> ingredients;

    for (int idx = 1; ; idx++) {
        string tempIngName;
        int tempIngAmount;

        cout << "Enter Ingredient #" << idx << " name (0 to exit) : ";
        cin >> tempIngName;

        if (tempIngName == "0")
            break;

        cout << "Enter Ingredient #" << idx << " amount : ";
        cin >> tempIngAmount;

        Ingredient tempIng;
        tempIng.setName(tempIngName);
        tempIng.setAmount(tempIngAmount);
        ingredients.push_back(tempIng);
    }
	
	

    cin.ignore(INT_MAX, '\n');
	
	string recipeDescription;
	string tempDescriptionSave = "a";
	while(tempDescriptionSave.size() != 0)
	{
		cout << "Enter Descriptions (Enter to Exit): ";
		getline(cin, tempDescriptionSave);
		recipeDescription += tempDescriptionSave + "\n";
	} 
	cout << "Enter Duration : ";
	int tempDuration;
	cin >> tempDuration;
    cin.ignore(INT_MAX, '\n');
	rdb.addRecipe(name, ingredients, recipeDescription, tempDuration);
}

void RecipeUI::showRecipeEditForm()
{
	cout << seperator << endl;
	cout << "Recipe Edit" << endl;
	cout << seperator << endl;

    vector<Recipe> allRecipeList = rdb.getRecipesList();
	for(int i=0; i<allRecipeList.size();i++)
	{
		cout << (i+1) << ". " << allRecipeList[i].getName() << endl;
	}
	
	cout << "Select Number for Edit (0 to Exit) : ";
	int recipeNumber;
	cin >> recipeNumber;
    cin.ignore(INT_MAX, '\n');
    Recipe targetRecipe = allRecipeList[recipeNumber - 1];
	printRecipe(targetRecipe);
	
	cout << "Do you really want to Delete / Recreate this (1 to Continue) : ";
	int tempCheck;
	cin >> tempCheck;
	if (tempCheck != 1) return;
	if (rdb.removeRecipe(targetRecipe.getId()))
	{
		cout << "Removed Successfully, continue to Add? (1 to Continue) : " << endl;
		cin >> tempCheck;
		if (tempCheck != 1) return;
		showRecipeAddForm();
	}
	else cout <<"양운천 잘못임 제 잘못 아님";
}
