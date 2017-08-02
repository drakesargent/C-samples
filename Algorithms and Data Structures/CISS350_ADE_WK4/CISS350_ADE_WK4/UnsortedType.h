#ifndef UNSORTEDTYPE_H
#define UNSORTEDTYPE_H

template <class ItemType>
struct NodeType
{
	ItemType info;
	NodeType<ItemType> *next;
};

/* Assumption:  ItemType is a type for which the operators
"<" and "==" are defined—either an appropriate built-in type or a class that overloads these operators. */

template <class ItemType>
class UnsortedType
{
public:
	// Class constructor, destructor, and copy constructor
	UnsortedType();
	/*~UnsortedType();*/
	UnsortedType(const UnsortedType<ItemType>&);

	void operator=(UnsortedType<ItemType>);

	bool IsFull() const;
	// Determines whether list is full.
	// Post: Function value = (list is full)

	int  GetLength() const;
	// Determines the number of elements in list.
	// Post: Function value = number of elements in list.

	void RetrieveItem(ItemType& item, bool& found);
	// Retrieves list element whose key matches item's key 
	// (if present).
	// Pre:  Key member of item is initialized.
	// Post: If there is an element someItem whose key matches  
	//     item's key, then found = true and item is a copy of
	//     someItem; otherwise found = false and item is 
	//     unchanged.
	//     List is unchanged.


	void InsertItem(ItemType item);
	// Adds item to list.
	// Pre:  List is not full.
	//       item is not in list. 
	// Post: item is in list.

	void DeleteItem(ItemType item);
	// Deletes the element whose key matches item's key.
	// Pre:  Key member of item is initialized.
	//       One and only one element in list has a key matching 
	//       item's key.
	// Post: No element in list has a key matching item's key.

	void ResetList();
	// Initializes current position for an iteration through the 
	// list.   
	// Post: Current position is prior to list.

	void GetNextItem(ItemType&);
	// Gets the next element in list.
	// Pre:  Current position is defined.
	//       Element at current position is not last in list.
	// Post: Current position is updated to next position.
	//       item is a copy of element at current position.

private:
	NodeType<ItemType>* listData;
	int length;
	NodeType<ItemType>* currentPos;
};
#endif // !UNSORTEDTYPE_H

template <class ItemType>
UnsortedType<ItemType>::UnsortedType()
{
	length = 0;
	listData = nullptr;
	currentPos = nullptr;
}

//template <class ItemType>
//UnsortedType<ItemType>::~UnsortedType()
//{
//	// Create location pointer
//	NodeType<ItemType> *location = nullptr;
//	
//	while (listData != nullptr)
//	{
//		location = listData->next;
//		listData = location->next;
//		delete location;
//	}
//}

template <class ItemType>
UnsortedType<ItemType>::UnsortedType(const UnsortedType<ItemType>&list)
{
	length = list.length;
	listData = list.listData;
	currentPos = list.currentPos;
}

template <class ItemType>
void UnsortedType<ItemType>::operator=(UnsortedType<ItemType>list)
{
	length = list->length;
	listData = list->listData;
	currentPos = list->currentPos;
}

template <class ItemType>
bool UnsortedType<ItemType>::IsFull() const
// Determines whether list is full.
// Post: Function value = (list is full)
{
	NodeType<ItemType> *location;
	try
	{
		location = new NodeType<ItemType>;
		delete location;
		return false;
	}
	catch (std::bad_alloc exception)
	{
		return true;
	}
}

template <class ItemType>
int UnsortedType<ItemType>::GetLength() const
// Determines the number of elements in list.
// Post: Function value = number of elements in list.
{
	return length;
}

template <class ItemType>
void UnsortedType<ItemType>::RetrieveItem(ItemType& item, bool& found)
// Retrieves list element whose key matches item's key 
// (if present).
// Pre:  Key member of item is initialized.
// Post: If there is an element someItem whose key matches  
//     item's key, then found = true and item is a copy of
//     someItem; otherwise found = false and item is 
//     unchanged.
//     List is unchanged.
{
	bool moreToSearch;
	NodeType<ItemType> *location;

	location = listData;
	found = false;
	moreToSearch = length>0;
	// check for empty list
	if (location == nullptr)
	{
		found = false;
	}
	else
	{
		// start at beginning of list
		location = location->next;
		while (moreToSearch && !found)
		{
			if (item == location->info)
			{
				found = true;
				item = location->info;
			}
			// check that if location  last location
			else if (location->next == listData->next)
			{
				moreToSearch = false;
			}
			// search next location
			else
			{
				location = location->next;
			}
		}
	}
}

template <class ItemType>
void UnsortedType<ItemType>::InsertItem(ItemType item)
// Adds item to list.
// Pre:  List is not full.
//       item is not in list. 
// Post: item is in list.
{
	bool found;
	RetrieveItem(item, found);
	// if item isn't in the list add it
	if (!found && !IsFull())
	{
		NodeType<ItemType> *location;
		location = new NodeType<ItemType>;
		location->info = item;
		
		// case empty list initialize list data
		if (listData == nullptr)
		{
			listData = location;
			location->next = location;
		}
		else // using unsorted list insert node at end
		{
			location->next = listData->next;
			listData->next = location;
			listData = location;
		}
		// increment length
		length++;
	}

}

template <class ItemType>
void UnsortedType<ItemType>::DeleteItem(ItemType item)
// Deletes the element whose key matches item's key.
// Pre:  Key member of item is initialized.
//       One and only one element in list has a key matching 
//       item's key.
// Post: No element in list has a key matching item's key.
{
	// Check if list exists
	if (listData != nullptr)
	{
		// Check if item exists
		bool found;
		RetrieveItem(item, found);

		if (found)
		{
			NodeType<ItemType> *location;
			NodeType<ItemType> *prev;

			// set location to start of list
			location = listData->next;
			// set previous node to start
			prev = listData;
			// traverse list
			while (location->info != item)
			{
				prev = location;
				location = location->next;
			}
			// location is pointing to the item to be deleted
			// link previous to location's next
			prev->next = location->next;
			// delete location
			delete location;
			location = nullptr;
			// decrement length
			length--;
		}
	}
}

template <class ItemType>
void UnsortedType<ItemType>::ResetList()
// Initializes current position for an iteration through the 
// list.   
// Post: Current position is prior to list.
{
	currentPos = listData;
}

template <class ItemType>
void UnsortedType<ItemType>::GetNextItem(ItemType &item)
// Gets the next element in list.
// Pre:  Current position is defined.
//       Element at current position is not last in list.
// Post: Current position is updated to next position.
//       item is a copy of element at current position.
{
	// test that there are items in the list
	if (listData != nullptr)
	{
		// test if currentPos has been set
		if (currentPos == nullptr)
		{
			ResetList();
		}
		currentPos = currentPos->next;
		item = currentPos->info;
	}
}