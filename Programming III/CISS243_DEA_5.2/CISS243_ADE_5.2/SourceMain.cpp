#include <iostream>
#include <iomanip>
#include "DynamicStack.h"
#include "InventoryItem.h"

using namespace std;

// prototype function declarations
void popItem(DynamicStack<InventoryItem> *stack); // to retrieve items from the stack
void pushItem(DynamicStack<InventoryItem> *stack);// to send items to the stack
int menu(); // to display menu and return user choice

int main()
{
	// declaring stack variable for InventoryItem objects
	DynamicStack<InventoryItem> inventory;
	// declaring and initalizing choice variable for menu return;
	int choice = 0;

	// loop while choice is not the choice for exit program
	do
	{
		// error testing for choice item
		try {
			// set choice
			choice = menu();
		}
		catch (int reject)
		{
			// if the error is thrown display message
			cout << "Error #" << reject << ": Enter a valid menu option." << endl;
		}

		// make a decision based on choice
		switch (choice)
		{
			// if the choice is a 1
		case 1:
			// run pushItem
			pushItem(&inventory);
			break;
			// if the choice is a 2
		case 2:
			// run pop item
			popItem(&inventory);
			break;
			// if the choice is a 3
		case 3:
			// create item to hold objects
			InventoryItem item;
			// loop while its possible to pop objects from the list
			while (inventory.pop(item))
			{
				// display object data
				cout << setw(20) << left << "Serial Number: " << item.getSerialNum() << endl;
				cout << setw(20) << left << "Manufacture Date: " << item.getManufactDate() << endl;
				cout << setw(20) << left << "Lot Number: " << item.getLotNum() << endl;
				cout << endl;
			}
			break;
		}

	} while (choice != 3); // exit when the choice is a 3

	return 0;
}

// popItem accepts a reference to the InventoryItem stack
void popItem(DynamicStack<InventoryItem> *stack)
{
	// if the stack is empty create a new stack
	if (stack == nullptr)
	{
		stack = new DynamicStack<InventoryItem>;
	}

	// item to hold popped value
	InventoryItem item;

	// if the stack can pop a value assign it to the passed item
	if (stack->pop(item))
	{
		// display what is stored in the item
		cout << setw(20) << left <<"Serial Number: " << item.getSerialNum() << endl;
		cout << setw(20) << left <<"Manufacture Date: " << item.getManufactDate() << endl;
		cout << setw(20) << left <<"Lot Number: " << item.getLotNum() << endl;
	}
	else // otherwise display that the stack is empty
	{
		cout << "Stack is empty." << endl;
	}
}

// pushItem accepts a reference to the InventoryItem stack
// creates a new inventory item based on user input and
// pushes it onto the stack
void pushItem(DynamicStack<InventoryItem> *stack)
{
	// if there isn't any stack data, create a new stack
	if (stack == nullptr)
	{
		stack = new DynamicStack<InventoryItem>;
	}
	
	// declare variables to hold values
	int s, l;
	string m;

	// request user input for serial number
	cout << "Enter the item's serial number: ";
	cin >> s;
	cin.ignore();
	// request user input for manufacture date
	cout << "Enter the item's manufacture date: ";
	getline(cin, m);
	// request user input for lot number
	cout << "Enter the item's lot number: ";
	cin >> l;
	cin.ignore();

	// create item given user input
	InventoryItem item(s, l, m);

	// push the item onto the stack
	stack->push(item);
}

// menu displays choice options and requests user input
// throwing an error if the value input doesn't match 
// what is on the menu.

int menu()
{
	// variable to hold choice value
	int choice;

	// create line for the menu
	string head = "";
	for (int i = 0; i < 30; i++)
	{
		head += "-";
	}
	
	// menu with formatting
	cout << head << endl;
	cout << "|" << setw(22) << "Inventory System" <<setw(7)<< "|" << endl;
	cout << head << endl;
	cout << "|" << setw(6) <<"" <<"Select an option: " << setw(5) << "|" << endl;
	cout << "|" << setw(8) <<"" <<"1. Add Item" << setw(10) << "|" << endl;
	cout << "|" << setw(8) <<"" <<"2. Remove Item" << setw(7) << "|" << endl;
	cout << "|" << setw(8) <<"" <<"3. Exit" << setw(14) << "|" << endl;
	cout << head << endl;
	cout << setw(30) << "";
	
	// request user input
	cin >> choice;
	cin.ignore();
	// if the value of the input doesn't fall in range of the values, throw an error
	if (choice < 1 || choice > 3)
	{
		throw 23;
	}

	// otherwise return the input value
	return choice;
}