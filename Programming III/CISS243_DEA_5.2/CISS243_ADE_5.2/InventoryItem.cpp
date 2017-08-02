#include "InventoryItem.h"

// constructor that accepts arguments for all field values
InventoryItem::InventoryItem(int s, int l, string m)
{
	serialNum = s;
	lotNum = l;
	manufactDate = m;
}

// empty constructor that sets all fields to 0 or empty string
InventoryItem::InventoryItem()
{
	serialNum = 0;
	lotNum = 0;
	manufactDate = "";
}

// mutator functions
void InventoryItem::setSerialNum(int s)
{
	serialNum = s;
}

void InventoryItem::setLotNum(int l)
{
	lotNum = l;
}

void InventoryItem::setManufactDate(string m)
{
	manufactDate = m;
}

// accessor functions
int InventoryItem::getSerialNum()
{
	return serialNum;
}

int InventoryItem::getLotNum()
{
	return lotNum;
}

string InventoryItem::getManufactDate()
{
	return manufactDate;
}

// override function for = operator
void InventoryItem::operator = (const InventoryItem &right)
{
	serialNum = right.serialNum;
	lotNum = right.lotNum;
	manufactDate = right.manufactDate;
}