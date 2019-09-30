#include "RecipeUI.h"
#include "RecipeDatabase.h"

class RecipeUI
{
private:
	const string seperator = "**************************";
	RecipeDatabase rdb;
	void printRecipe(Recipe r);
public:
	int showRecipeList();
	void showRecipeAddForm();
	void showRecipeEditForm();
	
	RecipeUI()
	{
		
	}
};

void RecipeUI::printRecipe(Recipe r)
{
	cout << seperator << endl;
	cout << "Selected Recipe" << endl;
	cout << seperator << endl;

	cout << "Name : " r.getName() << endl;
	cout << "Expected Cooking Time : " + r.getDuration() << endl;
	cout << "How to Cook : " << endl;
	cout << r.getDescription();
	
}

int RecipeUI::showRecipeList()
{
	vector<string> searchString;
	
	cout << seperator << endl;
	cout << "Recipe List" << endl;
	cout << seperator << endl;
	
	vector<Recipe> searchBucket = rdb.getRecipesList();
	while(1)
	{
		for(int i = 0; i < searchBucket.size(); i++)
		{
			cout << (i+1) + ". " + searchBucket[i].getName() << endl;
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
			cin.ignore();
			return searchBucket[i-1].getId;
		}
		
		stringstream tempSearchStream(tempSearchSave);
		istream_iterator<string> tempSearchIter(tempSearchStream);
		istream_iterator<string> token;
	    vector<string> results(tempSearchIter, token);
		
		searchString = results;
		rdb.searchRecipes(results);
		
	}
	
}
void RecipeUI::showRecipeAddForm()
{
	cout << seperator << endl;
	cout << "Recipe Add" << endl;
	cout << seperator << endl;
	
	cout << "Enter a Name of Recipe : ";
	string name;
	getline(cin, name);
	
	cout << "Enter Ingredients : ";
	string tempIngredientsSave;
	getline(cin, tempIngredientsSave);
	
	stringstream tempIngredientsStream(tempIngredientsSave);
	istream_iterator<string> tempIngredientsIter(tempIngredientsStream);
	istream_iterator<string> token;
	vector<string> results(tempIngredientsIter, token);
	
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
	cin.ignore();
	rdb.addRecipe(name, result, recipeDescription, tempDuration);
}

void RecipeUI::showRecipeEditForm()
{
	cout << seperator << endl;
	cout << "Recipe Edit" << endl;
	cout << seperator << endl;

	vector<Recipe> allRecipeList = rdb.getRecipesList();
	for(int i=0; i<allRecipeList.size();i++)
	{
		cout << (i+1) + ". " + allRecipeList[i].getName << endl;
	}
	
	cout << "Select Number for Edit (0 to Exit) : ";
	int recipeNumber;
	cin >> recipeNumber;
	cin.ignore();
	Recipe targetRecipe = rdb.getRecipe(recipeNumber);
	printRecipe(targetRecipe);
	
	cout << "Do you really want to Delete / Recreate this (1 to Continue) : ";
	int tempCheck;
	cin >> tempCheck;
	if (tempCheck != 1) return;
	if(rdb.removeRecipe(targetRecipe.getId()))
	{
		cout << "Removed Successfully, continue to Add? (1 to Continue) : " << endl;
		cin >> tempCheck;
		if (tempCheck != 1) return;
		showRecipeAddForm();
	}
	else cout <<"양운천 잘못임 제 잘못 아님";
}
