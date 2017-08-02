#include <iostream>
#include <iomanip>
#include "CashRegister.h"
#include "InventoryItem.h"

using namespace std;

//constant for stock items
const int STOCK_ITEMS = 5;

//prototype function
void displayItems(InventoryItem[], const int);

//declare cashregister object
CashRegister sale;

//setup inventory array
InventoryItem stock[STOCK_ITEMS] = { InventoryItem("Adjustable Wrench", 5.50, 10),
		InventoryItem("Screwdriver", 2.25, 20),
		InventoryItem("Pliers", 3.66, 35),
		InventoryItem("Ratchet", 7.22, 10),
		InventoryItem("Adjustable Wrench", 9.95, 7) };

int main()
{
	//bool set for cycling through do-while loop
	bool contSale = true;
	//loop the first time
	do
	{
		//declare and initialize variables for purchase
		int itemNum = 0;
		int units = 0;
		
		//display items from inventory array
		displayItems(stock, STOCK_ITEMS);

		//request item input from user
		cout << "Which item above is being purchsed? ";
		cin >> itemNum;
		cin.ignore(0);
		
		//request number of units
		cout << "How many units? ";
		cin >> units;
		cin.ignore();

		//validation of units
		bool valid = false;
		
		while (!valid)
		{
			if (units < 0)
			{
				cout << "Please enter a positive quantity: ";
				cin >> units;
				cin.ignore();
			}
			else
			{
				valid = true;
			}
		}
		
		//decrement item number to match array index
		itemNum--;

		//run mutator functions to set the fields in the cash register object
		sale.calcUnitPrice(stock[itemNum].getCost(), sale.getProfitMargin());
		sale.calcSubTotal(sale.getUnitPrice(), units);
		sale.calcTax(sale.getSubTotal(), sale.getSalesTax());
		sale.calcTotal(sale.getSubTotal(), sale.getTax());
		
		//print subtotal
		cout << setw(11) << left << "Subtotal: " << "$";
		cout << setprecision(2) << fixed << showpoint;
		cout << sale.getSubTotal() << endl;

		//print sales tax
		cout << setw(11) << left << "Sales Tax: " << "$";
		cout << setprecision(2) << fixed << showpoint;
		cout << sale.getTax() << endl;

		//print total
		cout << setw(11) << left << "Total: " << "$";
		cout << setprecision(2) << fixed << showpoint;
		cout << sale.getTotal() << endl;

		//reduce inventory
		stock[itemNum].sellUnits(units);

		//request user input to continue with another sale
		char cont;
		cout << "Do you want to purchase another item? (y|n):";
		cin >> cont;

		//evaluate response, default to no otherwise
		switch (cont)
		{
		case 'y':
		case 'Y':
			break;
		case 'n':
		case 'N':
			contSale = false;
			break;
		default:
			contSale = false;
			break;
		}

	} while (contSale);

	system("pause");
	return 0;
}

//function to display inventory
void displayItems(InventoryItem items[], const int NUM)
{
	cout << setw(7) << left << '#';
	cout << setw(20) << left << "Item";
	cout << setw(15) << left << "qty on Hand" << endl;
	for (int i = 0; i < 42; i++)
	{
		cout << '-';
	}
	cout << endl;
	for (int i = 0; i < NUM; i++)
	{
		cout << setw(7) << left << i + 1;
		cout << setw(20) << left << items[i].getDescription();
		cout << setw(15) << left << items[i].getUnits() << endl;
	}
}