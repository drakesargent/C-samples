#include "InventoryItem.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;
// global variables
// file object declarations
fstream drive; // for driver input file
fstream output; // for driver output
fstream receipts; // for register output
fstream invent; // for inventory input

const int INVENTORY_COUNT = 50;
InventoryItem inventory[INVENTORY_COUNT];
const double TAX_RATE = .075;

// prototype function declarations
// file operations
bool openFile(fstream&, char, string);
void closeFile(fstream&);

// main functions
void vehicle(fstream&, fstream&); // drives ADT testing output to output.txt
void readInventory(fstream&, fstream&, InventoryItem[INVENTORY_COUNT]); // reads in invent.dat to inventory array
void transactions(fstream&, InventoryItem[INVENTORY_COUNT]); // processes transactions and creates receipts
// called by readInventory
void addItem(InventoryItem[INVENTORY_COUNT], int, InventoryItem); // searches inventory for item adds if doesn't exist
// called by addItem
bool searchInventory(InventoryItem[INVENTORY_COUNT], InventoryItem); // returns true if item exists false if not
// called by transactions
bool transact(fstream&, InventoryItem[INVENTORY_COUNT]); // processes the inventory selection and calculations for one order
// called by transact
// selectItem requests user input for item and quantity, does error checking and calculation for tax/subtotal
bool selectItem(InventoryItem&, fstream&, InventoryItem[INVENTORY_COUNT], double&, double&); 
void calcSubTotal(double&, InventoryItem, int);
void calcTax(double&, InventoryItem, int, const double);
void calcGrandTotal(double&, double, double);
bool nextCustomer(); // requests user input returns true if there is a next customer order
// called by selectItem
bool searchInventory(InventoryItem[INVENTORY_COUNT], InventoryItem&, int); // searches inventory for item by item number
void inputItemQty(int&, int&); // requests item and qty entry


int main()
{
	// initialize driver to test ADT Inventory Item object class
	// driven through InventoryDriver.dat and output to output.log
	vehicle(drive, output);
	readInventory(invent, receipts, inventory);
	transactions(receipts, inventory);
	
	return 0;
}

bool openFile(fstream &file, char rw, string fName)
{
	switch (rw) // opens file based on read or write char flag argument
	{
	case 'R':
	case 'r':
		file.open(fName, ios::in);
		break;
	case 'W':
	case 'w':
		file.open(fName, ios::out);
	}

	if (file.fail()) // returns file open status
	{
		return false;
	}
	else
	{
		return true;
	}
}
void closeFile(fstream &file)
{
	if (file.is_open()) // closes file if file is open
	{
		file.close();
	}
}

void vehicle(fstream &in, fstream &out)
{
	// opens file objects 
	if (openFile(in, 'R', "InventoryDriver.dat") && openFile(out,'W',"output.log"))
	{
		string line;
		InventoryItem *item = new InventoryItem;
		
		// argument variables for item
		int itemNumber;
		char desc[13];
		double price;
		char tax;

		// based on lines read in from InventoryDriver.dat test functions of
		// InventoryItem class
		while (line != "Quit")
		{
			in >> line;
			if (line == "Initialize")
			{
				out << "Input product number." << endl;
				in >> itemNumber;
				out << "Input description." << endl;
				in >> desc;
				out << "Input price." << endl;
				in >> price;
				out << "Input tax." << endl;
				in >> tax;
				out << endl;
			} 
			else if (line == "Verify")
			{
				out << "---Variables contain---" << endl;
				out << "Product Number: " << itemNumber << endl;
				out << "Description: " << desc << endl;
				out << "Price: " << price << endl;
				out << "Tax: " << tax << endl;
				out << endl;
			}
			else if (line == "SetProductNumber")
			{
				item->setProductNumber(itemNumber);
				out << "Product Number set as " << itemNumber << endl;
				out << endl;
			}
			else if (line == "SetDescription")
			{
				item->setDescription(desc);
				out << "Description set as " << desc << endl;
				out << endl;
			}
			else if (line == "SetPrice")
			{
				item->setPrice(price);
				out << "Price set as " << price << endl;
				out << endl;
			}
			else if (line == "SetTaxableChar")
			{
				item->setTaxable(tax);
				out << "Tax set as " << tax << endl;
				out << endl;
			}
			else if (line == "Print")
			{
				out << "---Printing item object---" << endl;
				out << item << endl;
				out << endl;
			}
			else if (line == "Clear")
			{
				out << "---Removing item data from object---" << endl;
				delete item;
				out << endl;
			}
			else if (line == "Create")
			{
				out << "---Creating new InventoryItem---" << endl;
				item = new InventoryItem(itemNumber, desc, price, tax);
				out << endl;
			}
			else if (line == "GetProductNumber")
			{
				out << "Getting product number " << item->getProductNumber() << endl;
				out << endl;
			}
			else if (line == "GetDescription")
			{
				out << "Getting description " << item->getDescription() << endl;
				out << endl;
			}
			else if (line == "GetPrice")
			{
				out << "Getting price " << item->getPrice() << endl;
				out << endl;
			}
			else if (line == "GetTaxable")
			{
				if (item->getTaxable())
				{
					out << "Getting taxable: True" << endl;
					out << endl;
				}
				else
				{
					out << "Getting taxable: False" << endl;
				}
			}
			else if (line == "GetTaxableChar")
			{
				out << "Getting taxable character " << item->getTaxableChar() << endl;
				out << endl;
			}
		}
	}
	closeFile(in);
	closeFile(out);
}
void readInventory(fstream &inventFile, fstream&receiptFile, InventoryItem invent[INVENTORY_COUNT])
{
	// read in inventory information from "Invent.dat"
	if (openFile(inventFile, 'R', "Invent.dat") && openFile(receiptFile, 'W', "Receipts.out"))
	{
		receipts << "Invent.dat opened successfully.\n" << endl;
		
		int index = 0;
		int prodNum;
		char desc[13];
		double price;
		char tax;
		

		while (inventFile >> prodNum)
		{
			inventFile >> desc;
			inventFile >> price;
			inventFile >> tax;

			InventoryItem item(prodNum, desc, price, tax);

			try
			{
				// error check each item versus what is in the inventory
				addItem(invent, index, item);
				// Print inventory to Recipts.out
				receiptFile << "Item " << invent[index] << " added." << endl;
				index++;
			}
			catch (InventoryItem e)
			{	// skip duplicate and print to Recipts.out
				receiptFile << e << " exists. Not added to inventory." << endl;
			}

		}
		closeFile(inventFile);
	}
}
void transactions(fstream &receiptFile, InventoryItem invent[INVENTORY_COUNT])
{
	// while there is a next customer start customer transaction
	receiptFile << "\n\n------------------------------------------" << endl;
	int customer = 1;
	bool next;
	do
	{
		receiptFile << __TIMESTAMP__ << endl;
		receiptFile << "Customer " << customer << endl;
		next = transact(receiptFile, invent);
		customer++;
		receiptFile << "\n\n------------------------------------------" << endl;
	} while (next);

	// after last customer order close output file
	closeFile(receiptFile);
}

void addItem(InventoryItem invent[INVENTORY_COUNT], int index, InventoryItem item)
{
	if (searchInventory(invent, item)) // if item exists
	{
		throw item; // throw the item in error
	}
	else
	{
		invent[index] = item; // otherwise add the item to the inventory
	}
}

bool searchInventory(InventoryItem invent[INVENTORY_COUNT], InventoryItem item)
{
	for (int i = 0; i < INVENTORY_COUNT; i++) // simple search should be augmented with larger scale system
	{
		if (invent[i] == item)
		{
			return true;
		}
	}
	return false;
}

bool transact(fstream &receiptFile, InventoryItem invent[INVENTORY_COUNT])
{
	// transaction variables
	bool moreItems;
	InventoryItem item;
	double subtotal = 0.00;
	double taxtotal = 0.00;
	double grandtotal = 0.00;

	do
	{
		// while there are more items to enter continue to select items
		moreItems = selectItem(item, receiptFile, invent, subtotal, taxtotal);

	} while (moreItems);

	// when all items have been selected calculate grand total
	calcGrandTotal(grandtotal, subtotal, taxtotal);

	// print total line
	receiptFile << setw(20) << left << " ";
	receiptFile << setw(10) << left << fixed << showpoint << setprecision(2) << "Subtotal" << setw(10) << right << subtotal << endl;
	receiptFile << setw(20) << left << " ";
	receiptFile << setw(10) << left << fixed << showpoint << setprecision(2) << "Tax" << setw(10) << right << taxtotal << endl;
	receiptFile << endl;
	receiptFile << setw(10) << left << " ";
	receiptFile << setw(10) << left << fixed << showpoint << setprecision(2) << "Total" << setw(10) << right << grandtotal << endl;

	// return true or false if there is a next customer order
	return nextCustomer();
}

bool selectItem(InventoryItem &item, fstream &receiptFile, InventoryItem invent[INVENTORY_COUNT], double &subtotal, double &taxtotal)
{
	int itemNum, qty;
	// try to enter the item number and quantity
	try
	{
		inputItemQty(itemNum, qty);
	}
	// handle bounds exceptions for int and qty
	catch (int itemNum)
	{
		if (itemNum == 0)
		{
			return false; // if a zero is entered return false to end transaction
		}
		else
		{
			// otherwise item number entered isn't in the inventory bounds
			receiptFile << "*** item " << itemNum << " not in inventory ***" << endl;
		}
		return true;
	}
	catch (char q)
	{
		q; // catch thrown char to indicate a qty bounds exception
		receiptFile << "*** qty exceeds bounds of 1 to 100 ***" << endl;
		return true;
	}

	// if the item exists in the inventory
	if (searchInventory(invent, item, itemNum))
	{
		// print to the receipt
		receiptFile << setw(15) << left << item.getDescription();
		receiptFile << setw(4) << right << qty << " @ ";
		receiptFile << setw(6) << right << item.getPrice();
		receiptFile << setw(8) << right << fixed << showpoint << setprecision(2) << item.getPrice()*qty;
		if (item.getTaxable())
		{
			receiptFile << setw(3) << right << "TX" << endl;
		}
		else
		{
			receiptFile << endl;
		}
		calcSubTotal(subtotal, item, qty); // then calculate the subtotal
		calcTax(taxtotal, item, qty, TAX_RATE); // and tax total
		return true; // enter next item
	}
	else // otherwise the item isn't in the inventory proceed to next item
	{
		receiptFile << "*** item " << itemNum << " not in inventory ***" << endl; 
		return true;
	}
}
void calcSubTotal(double &sub, InventoryItem item, int qty)
{
	sub += (item.getPrice()*qty);
}
void calcTax(double &taxTotal, InventoryItem item, int qty, const double TAXRATE)
{
	if (item.getTaxable())
	{
		taxTotal += ((item.getPrice()*qty)*TAXRATE);
	}
}
void calcGrandTotal(double &grandT, double sub, double tax)
{
	grandT = sub + tax;
}
bool nextCustomer()
{
	char choice;
	cout << "Enter new customer order (Y|N): ";
	cin >> choice;
	switch (choice)
	{
	case 'Y':
	case 'y':
		return true;
		break;
	case 'N':
	case 'n':
	default:
		cout << "Thank you, and have a nice day!" << endl;
		return false;
		break;
	}
}

bool searchInventory(InventoryItem invent[INVENTORY_COUNT], InventoryItem &item, int itemNum)
{
	for (int i = 0; i < INVENTORY_COUNT; i++)
	{
		if (invent[i].getProductNumber() == itemNum)
		{
			item = invent[i];
			return true;
		}
	}
	return false;
}
void inputItemQty(int &itemNum, int &qty)
{
	cout << "Enter item # and quantity: ";
	cin >> itemNum >>qty;
	cin.ignore();

	if (itemNum < 10000 || itemNum > 99999)
	{
		throw itemNum;
	}
	if (qty < 1 || qty > 100)
	{
		char q = 'O';
		throw q;
	}

}



