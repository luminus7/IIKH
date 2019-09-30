#include "RecipeUI.h"

class RecipeUI
{
	private:
		const string seperator ="**************************";
		RecipeDatabase rdb;
		
	public:
		void showRecipeList();
		void showRecipeAddForm();
		void showRecipeEditForm();
	

};

void RecipeUI::showRecipeList()
{
	vector<string> searchString;
	
	cout << seperator << endl;
	cout << "Recipe List" << endl;
	cout << seperator << endl;
	
	vector<Recipe> searchBucket = rdb.getRecipesList();
	while(1);
	{
		for(int i = 0; i < searchBucket.size(); i++)
		{
			cout << i + ". " + searchBucket[i].getName() << endl;
		}
		cout << seperator << endl;
		cout << "To exit, input 0" << endl;
		cout << "Keyword Search : ";
		string tempSearchSave;
		getline(tempSearchSave, 100);
		if(tempSearchSave == "0") return;
		
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
	rdb.addRecipe(new Recipe(name, result, recipeDescription, tempDuration));
}

int main(void)
{
	

}
