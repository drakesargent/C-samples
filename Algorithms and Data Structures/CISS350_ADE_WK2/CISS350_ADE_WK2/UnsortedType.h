#ifndef UNSORTEDTYPE_H
#define UNSORTEDTYPE_H
#include "Client.h"
#include <iostream>

using namespace std;

/*
Structure to hold and manipulate client data;
*/
class UnsortedType
{
public:
	// constructor
	UnsortedType();
	// resets lenght pointer to fill from the beginning
	// of structure
	void makeEmpty();
	// tests if structure is full
	bool isFull() const;
	// returns number of items in the structure
	int getLength() const;
	// returns the item assigning it if it is found
	Client getItem(Client item, bool &found);
	// adds an item to the structure
	void putItem(Client item);
	// removes an item from the structure
	void deleteItem(Client item);
	// resets the counter to the beginning of the structure
	void resetList();
	// returns the next item and increments the counter
	Client getNextItem();
private:
	int len;
	Client info[MAX_ITEMS];
	int currentPos;
};

#endif // !UNSORTEDTYPE_H

// constructor
UnsortedType::UnsortedType()
{
	len = 0;
	resetList();
}

void UnsortedType::makeEmpty()
{
	len = 0;
	resetList();
}

bool UnsortedType::isFull() const
{
	return (len == MAX_ITEMS);
}

int UnsortedType::getLength() const
{
	return len;
}

Client UnsortedType::getItem(Client item, bool &found)
{
	bool contSearch;
	int location = 0;
	found = false;

	contSearch = (location < len);

	while (contSearch && !found)
	{
		switch (item.comparedTo(info[location]))
		{
		case LESS:
		case GREATER:
			location++;
			contSearch = (location < len);
			break;
		case EQUAL:
			found = true;
			item = info[location];
			break;
		}
	}
	return item;
}

void UnsortedType::putItem(Client item)
{
	info[len]=item;
	len++;
}

void UnsortedType::deleteItem(Client item)
{
	int loc = 0;
	while (item.comparedTo(info[loc]) != EQUAL)
	{
		loc++;
	}

		info[loc] = info[len];
		info[loc] = info[len - 1];
		len--;
}

void UnsortedType::resetList()
{
	currentPos = -1;
}

Client UnsortedType::getNextItem()
{
	currentPos++;
	return info[currentPos];
}