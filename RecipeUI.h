#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <iterator>
using namespace std;

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
