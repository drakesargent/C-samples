#include "InventoryItem.h"
#include <cstring>
#include <iomanip>

// definition for private member function to calculate boolean
// for taxable char.
bool InventoryItem::calcTaxable(char t)
{
	switch (t)
	{
	case 'T':
		return true;
		break;
	case 'N':
		return false;
		break;
	default:
		return false;
		break;
	}
}

// constructor defintions
// default constructor
InventoryItem::InventoryItem()
{
	productNumber = -1;
	description = "";
	price = 0.00;
	taxable = false;
}
// fully attributed constructor
InventoryItem::InventoryItem(int pNum, char *pName, double pr, char tax)
{
	productNumber = pNum;
	description = new char[strlen(pName) + 1];
	strcpy(description, pName);
	price = pr;
	taxable = calcTaxable(tax);
}

// destructor definition
// commented out due to runtime error caused by compiler
//InventoryItem::~InventoryItem()
//{
//	delete [] description;
//}

// accessor funtion definitions
int  InventoryItem::getProductNumber()
{
	return productNumber;
}
char*  InventoryItem::getDescription() const
{
	return description;
}
double  InventoryItem::getPrice()
{
	return price;
}
bool  InventoryItem::getTaxable()
{
	return taxable;
}
char InventoryItem::getTaxableChar()
{
	if (getTaxable())
	{
		return 'T';
	}
	else
	{
		return 'N';
	}
}

// mutator function definitions
void  InventoryItem::setProductNumber(int pNum)
{
	productNumber = pNum;
}
void  InventoryItem::setDescription(char *pName)
{
	description = new char[strlen(pName + 1)];
	strcpy(description, pName);
}
void  InventoryItem::setPrice(double pr)
{
	price = pr;
}
void  InventoryItem::setTaxable(bool tax)
{
	taxable = tax;
}
void  InventoryItem::setTaxable(char tax)
{
	taxable = calcTaxable(tax);
}

// copy constructor by overloading = operator
void InventoryItem::operator = (const InventoryItem &item)
{
	productNumber = item.productNumber;
	description = item.description;
	price = item.price;
	taxable = item.taxable;
}

bool InventoryItem::operator == (const InventoryItem &item)
{
	if (productNumber == item.productNumber)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// << operator overload definition to print object by reference
std::ostream& operator << (std::ostream &strm, InventoryItem &obj)
{
	strm << std::setw(6)  << std::left  << obj.productNumber;
	strm << std::setw(13) << std::left  << obj.description;
	strm << std::setw(5)  << std::left  << obj.price;
	strm << std::setw(2)  << std::right << obj.getTaxableChar();
	return strm;
}

// << operator overload definition to print object by pointer
std::ostream& operator << (std::ostream &strm, InventoryItem *obj)
{
	strm << std::setw(6) << std::left << obj->getProductNumber();
	strm << std::setw(13) << std::left << obj->getDescription();
	strm << std::setw(5) << std::left << obj->getPrice();
	strm << std::setw(2) << std::right << obj->getTaxableChar() << std::endl;
	return strm;
}

