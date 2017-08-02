#ifndef INVENTORYITEM_H
#define INVENTORYITEM_H

#include <string>

using namespace std;
// Declaration for Inventory Item class which stores data for
// serial number, lot number, and manufacture date.
class InventoryItem
{

private:
	// fields to store inventory item data
	int serialNum, lotNum;
	string manufactDate;

public:
	// constructors defined in InvetoryItem.cpp
	InventoryItem(int, int, string);
	InventoryItem();

	// mutator functions defined in InventoryItem.cpp
	void setSerialNum(int);
	void setLotNum(int);
	void setManufactDate(string);

	// accessor functions defined in InventoryItem.cpp
	int getSerialNum();
	int getLotNum();
	string getManufactDate();

	// Override for = defined in InventoryItem.cpp
	void operator = (const InventoryItem &right);
};
#endif // !INVENTORYITEM_H

