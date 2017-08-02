#include <iostream>
#include "BinTree.h"
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{
	// Initialize int and char binary trees
	BinTree<int> nums;
	BinTree<char> chars;

	// set random seed
	srand(time(NULL));

	// declare string variables to print out the list of inserted values
	string num_list;
	string char_list;

	// Append 20 random values for both binary trees
	for (int i = 0; i < 20; i++)
	{
		int numInserted = rand() % 100 + 1;
		char charInserted = rand() % 93 + 33;
		nums.insertNode(numInserted);
		chars.insertNode(charInserted);
		
		// append values to the declared strings
		num_list.append(to_string(numInserted));
		num_list.append(" ");
		char_list += charInserted;
		char_list.append(" ");
	}

	// display strings
	cout << "Numbers added to num tree: " << num_list << endl;
	cout << "Chars added to char tree: " << char_list << endl;

	// Demonstrate the tree display functions
	cout << "Display nums tree PreOrder: " << endl;
	nums.displayPreOrder();
	cout << endl;

	cout << "Display nums tree InOrder: " << endl;
	nums.dislplayInOrder();
	cout << endl;

	cout << "Display nums tree PostOrder: " << endl;
	nums.displayPostOrder();
	cout << endl;

	cout << "Display chars tree PreOrder: " << endl;
	chars.displayPreOrder();
	cout << endl;

	cout << "Display chars tree InOrder: " << endl;
	chars.dislplayInOrder();
	cout << endl;

	cout << "Display chars tree PostOrder: " << endl;
	chars.displayPostOrder();
	cout << endl;

	// Demonstrate search, remove, and insert for num tree
	cout << "\nSearching the num tree for a random value." << endl;
	cout << "If the value is found, it will remove it." << endl;
	cout << "If the value is not found, it will insert it." << endl;
	cout << "When at least one search, one remove, and one insert \nhas been processed the loop will end." << endl;
	bool loop = true, search=false, remove=false, insert=false;

	// while search, remove, and insert functions have not been run
	// loop
	while (loop)
	{
		// search for a random value in the tree
		int numSearch = rand() % 100 + 1;
		cout << "\nSearching for " << numSearch << endl;
		search = true; // set search to true
		
		if (nums.searchNode(numSearch)) // if the number searched was found remove it from the tree
		{
			cout << numSearch << " was found!\nRemoving " << numSearch << " from tree." << endl;
			nums.remove(numSearch);
			remove = true; // set remove to true
		}
		else // if the number searched for was not found add it to the tree
		{
			cout << numSearch << " was not found!\nAdding " << numSearch << " to tree." << endl;
			nums.insertNode(numSearch);
			insert = true; // set insert to true
		}
		
		if (search && remove && insert) // if search, remove, and insert have all been performed
		{
			loop = false; // stop loop
			cout << "\n New Contents of num tree in order: " << endl;
			nums.dislplayInOrder(); // display tree in order
		}
	}

	// Demonstrate search, remove, and insert for char tree
	cout << "\nSearching the char tree for a random value." << endl;
	cout << "If the value is found, it will remove it." << endl;
	cout << "If the value is not found, it will insert it." << endl;
	cout << "When at least one search, one remove, and one insert \nhas been processed the loop will end." << endl;
	loop = true, search = false, remove = false, insert = false;
	
	string response = ""; // to display char value
	
	// while search, remove, and insert functions have not been run
    // loop
	while (loop)
	{
		// search for a random value in the tree
		int charSearch = rand() % 93 + 33;
		response += charSearch;
		cout << "\nSearching for " << response << endl;
		search = true; // set search to true
		

		if (chars.searchNode(charSearch)) // if the number searched was found remove it from the tree
		{
			cout << response << " was found!\nRemoving " << response << " from tree." << endl;
			chars.remove(charSearch);
			remove = true;  // set remove to true
		}
		else // if the number searched for was not found add it to the tree
		{
			cout << response << " was not found!\nAdding " << response << " to tree." << endl;
			chars.insertNode(charSearch);
			insert = true; // set insert to true
		}

		if (search && remove && insert) // if search, remove, and insert have all been performed
		{
			loop = false; // stop loop
			cout << "\n New Contents of char tree in order: " << endl;
			chars.dislplayInOrder(); // display tree in order
		} 
		response = "";
	}
	return 0;
}