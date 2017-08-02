#ifndef INVENTORYITEM_H
#define INVENTORYITEM_H
#include <ostream>

/* 
Class InventoryItem stores inventory item data values
which represent an item's Product Number, Description,
Price, and if the item is Taxable.
Declarations here, Definitions in InventoryItem.cpp
*/

class InventoryItem
{
private:
	// ADT Member Variables
	int productNumber; 
	char *description;
	double price;
	bool taxable;

	// Prototype private function to calculate boolean 
	// for taxable member variable
	bool calcTaxable(char);

public:
	// Constructors
	InventoryItem();
	InventoryItem(int, char*, double, char);
	//~InventoryItem();

	// Accessor function prototypes
	int getProductNumber();
	char* getDescription() const;
	double getPrice();
	bool getTaxable(); // returns boolean for functions
	char getTaxableChar(); // returns char for printing

	// Mutator function prototypes
	void setProductNumber(int);
	void setDescription(char*);
	void setPrice(double);
	void setTaxable(bool); // acceepts boolean
	void setTaxable(char); // overloaded to accept char

	void operator = (const InventoryItem &);
	bool operator == (const InventoryItem &);

	// overload << to print object lines, accepts refrence and pointer to objects
	friend std::ostream& operator << (std::ostream &, InventoryItem &);
	friend std::ostream& operator << (std::ostream &, InventoryItem *);
};

#endif // !INVENTORYITEM_H
