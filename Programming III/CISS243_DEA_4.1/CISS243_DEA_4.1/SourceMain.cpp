#include <iostream>
// Including LList.h presented link errors at compile time.
// After troubleshooting the error, the best solution that I found
// said to include the .cpp file rather than the .h file.
#include "LList.cpp"

using namespace std;

int main()
{
	// Initialize int and char linked lists
	LList<int> nums;
	LList<char> chars;
	
	// Append 20 values for both linked lists
	for (int i = 0; i < 20; i++)
	{
		nums.appendNode(i * 2);
		chars.appendNode(i+65);
	}

	// Demonstrate the displayList functions
	cout << "Display nums linked list: " << endl;
	nums.displayList();
	cout << endl;

	cout << "Display chars linked list: " << endl;
	chars.displayList();
	cout << endl;

	// Demonstrate the appendNode functions
	cout << "Append -5 to nums linked list: " << endl;
	nums.appendNode(-5);
	nums.displayList();
	cout << endl;

	cout << "Append 'a' to chars linked list: " << endl;
	chars.appendNode('a');
	chars.displayList();
	cout << endl;

	// Demonstrate the insertNode functions
	cout << "Insert 19 to the nums linked list: " << endl;
	nums.insertNode(19);
	nums.displayList();
	cout << endl;

	cout << "Insert '*' to the chars linked list: " << endl;
	chars.insertNode('*');
	chars.displayList();
	cout << endl;

	// Demonstrate the deleteNode functions
	cout << "Delete 20 from the nums linked list: " << endl;
	nums.deleteNode(20);
	nums.displayList();
	cout << endl;

	cout << "Delete 'G' from the chars linked list: " << endl;
	chars.deleteNode('G');
	chars.displayList();
	cout << endl;

	// Demonstrate the searchList functions
	cout << "Search for value '8' and display list location: " << endl;
	cout << nums.searchList(8) << endl;
	cout << endl;

	cout << "Search for value 'H' and display list location: " << endl;
	cout << chars.searchList('H') << endl;
	cout << endl;
	
	cout << chars.getLen() << endl;
	cout << nums.getLen() << endl;
	return 0;
}