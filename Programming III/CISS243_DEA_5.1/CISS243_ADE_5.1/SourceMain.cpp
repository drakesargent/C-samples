#include <iostream>
#include "DynamicStack.h"
#include <string>

using namespace std;

int main() 
{
	// declare stack variables
	DynamicStack<int> nums; // to store ints
	DynamicStack<string> words; // to store strings

	// variables to hold pop values
	string word;
	int num;

	// push strings to the string stack
	words.push("I?");
	words.push("am");
	words.push("Sam,");
	words.push("I");
	words.push("Am");

	// push ints to the int stack
	for (int i = 0; i < 5; i++)
	{
		nums.push(i + 1);
	}

	// pop strings from the string stack
	while (words.pop(word))
	{
		cout << word << " ";
	}
	cout << endl;

	// pop ints from the int stack
	while (nums.pop(num))
	{
		cout << num << endl;
	}
	// stick the landing
	cout << "Boom." << endl;

	return 0;
}