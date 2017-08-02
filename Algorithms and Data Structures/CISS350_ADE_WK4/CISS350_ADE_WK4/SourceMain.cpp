#include<iostream>
#include<fstream>
#include<string>
#include "UnsortedType.h"
#include "Ingredient.h"

using namespace std;

void testIngredient();

bool openFile(ifstream&, string);
bool openFile(ofstream&, string);
void closeFile(ifstream&);
void closeFile(ofstream&);

ifstream recipeIngredients;

UnsortedType<Ingredient> chiliRecipe;

int main()
{
	//testIngredient class
	testIngredient();
	// show length of empty structure
	cout << "Before loading ingredients, structure has ";
	cout << chiliRecipe.GetLength() << " elements." << endl;
	// read in ingredients
	if (openFile(recipeIngredients, "chili.txt"))
	{
		// add to UnsortedType Circular list
		while (recipeIngredients.peek()!= EOF)
		{
			string name;
			int mScale;
			double amt;

			recipeIngredients >> name;
			recipeIngredients >> mScale;
			recipeIngredients >> amt;

			Ingredient toAdd;

			toAdd.setName(name);
			toAdd.setScale(mScale);
			toAdd.setAmount(amt);

			chiliRecipe.InsertItem(toAdd);
		}
	}
	// show length of structure after elements loaded
	cout << "After loading ingredients, structure has ";
	cout << chiliRecipe.GetLength() << " elements." << endl;
	// test is full
	if (chiliRecipe.IsFull())
	{
		cout << "\nThe data structure is full." << endl;
	}
	else
	{
		cout << "\nThe data structure is not full." << endl;
	}
	// test retrieve item
	bool found;
	cout << "\nLet's see if Cayanne_Pepper is in the recipe." << endl;
	Ingredient search;
	search.setName("Cayanne_Pepper");
	chiliRecipe.RetrieveItem(search,found);
	if (found)
	{
		cout << "Cayanne_Pepper is in the recipe." << endl;
	}
	else
	{
		cout << "Cayanne_Pepper is not in the recipe." << endl;
	}
	// test delete item
	cout << "\nI don't want to make the chili too spicy." << endl;
	cout << "Let's remove the Cayanne_Pepper." << endl;
	chiliRecipe.DeleteItem(search);
	chiliRecipe.RetrieveItem(search, found);
	if (found)
	{
		cout << "Cayanne_Pepper is in the recipe." << endl;
	}
	else
	{
		cout << "Cayanne_Pepper is not in the recipe." << endl;
	}
	// test get length
	cout << "After deleting an ingredient, structure has ";
	cout << chiliRecipe.GetLength() << " elements.\n" << endl;
	// test get next item
	Ingredient toPrint;
	for (int i = 0; i < chiliRecipe.GetLength(); i++)
	{
			chiliRecipe.GetNextItem(toPrint);
			cout << "Ingredient " << i + 1 << ": " << toPrint.print() << endl;
	}
	// reset list
	chiliRecipe.ResetList();

	// show list is circular by printing all items twice
	cout << "\nI can show that the list is circular." << endl;
	cout << "Let's get next item twice.\n" << endl;
	
	// print all items again
	for (int i = 0; i < chiliRecipe.GetLength()*2; i++)
	{
			chiliRecipe.GetNextItem(toPrint);
			cout << toPrint.print() << endl;
	}
	return 0;
}

bool openFile(ifstream &file, string fName)
{

	file.open(fName);


	if (file.fail() && !file.is_open()) // returns file open status
	{
		return false;
	}
	else
	{
		return true;
	}
}
bool openFile(ofstream &file, string fName)
{

	file.open(fName);


	if (file.fail() && !file.is_open()) // returns file open status
	{
		return false;
	}
	else
	{
		return true;
	}
}
void closeFile(ifstream &file)
{
	if (file.is_open()) // closes file if file is open
	{
		file.close();
	}
}
void closeFile(ofstream &file)
{
	if (file.is_open()) // closes file if file is open
	{
		file.close();
	}
}

void testIngredient()
{
	ifstream testInstruct;
	ofstream testResults;
	// open input test file;
	if (openFile(testInstruct, "ingtest.txt") && openFile(testResults, "test.out"))
	{
		string line="";
		Ingredient testI;
		Ingredient copy;

		while (line!="Quit")
		{
			getline(testInstruct, line);
			if (line == "Initialize")
			{
				testResults << "Creating new Ingredient" << endl;
				// test constructor
			}
			// test mutator functions
			else if (line == "SetName")
			{
				string name;
				testInstruct >> name;
				testI.setName(name);
				testResults << "Set name to " << name << endl;
			}
			else if (line == "SetScale")
			{
				int scale;
				testInstruct >> scale;
				testI.setScale(scale);
				testResults << "Set weight scale to " << testI.weightScale(testI.getScale()) << endl;
			}
			else if (line == "SetAmount")
			{
				double amount;
				testInstruct >> amount;
				testI.setAmount(amount);
				testResults << "Set amount to " << amount << endl;
			}
			// test accessor functions
			else if (line == "GetName")
			{
				testResults << "Name is " << testI.getName() << endl;
			}
			else if (line == "GetScale")
			{
				testResults << "Scale is " << testI.weightScale(testI.getScale()) << endl;
			}
			else if (line == "GetAmount")
			{
				testResults << "Amount is " << testI.getAmount() << endl;
			}
			// test copy constructor
			else if (line == "Copy")
			{
				copy = testI;
				testResults << "Copy made." << endl;
			}
			else if (line == "Equal")
			{
				// test == operator
				if (copy == testI)
				{
					testResults << "Test value and copy are the same." << endl;
				}
				// test != operator
				if (copy != testI)
				{
					testResults << "Test value and copy are not the same." << endl;
				}
			}
			// test print()
			else if (line == "Print")
			{
				testResults <<"Test value: " << testI.print() << endl;
				testResults << "Copy value: " << copy.print() << endl;
			}
							
		}
	}
	closeFile(testInstruct);
	closeFile(testResults);
}
