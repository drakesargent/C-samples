#include <iostream>
#include "LList.h"
using namespace std;

// Constructor definition
template <class T>
LList<T>::LList()
{
	// initialize head structure with nullPtr
	head = nullptr;
}

// Destructor definition
/*template <class T>
LList<T>::~LList()
{
	// Declare two listnode pointers
	LNode *nodePtr;
	LNode *nextNode;

	// Initialize the nodePtr pointing to head
	nodePtr = head;

	// loop while the value of nodePtr isn't nullptr
	while (nodePtr != nullptr)
	{
		// set nextNode equal to the next pointer of nodePtr
		nextNode = nodePtr->next;
		delete nodePtr;
		// nodePtr now equals the nextNode and the loop begins again
		nodePtr = nextNode;
	}
}
*/

// Function definitions

// appendNode definition accepts a new value of user declared data-type
// creates new node, assigns the new value to the val field and links
// it to the end value's next value, setting it's next value to nullptr
template <class T>
void LList<T>::appendNode(T newVal)
{
	// declare newNode and nodePtr
	LNode *newNode;
	LNode *nodePtr;

	// set newNode as a LNode structure
	newNode = new LNode;
	// assign argument value to data structure's value field
	newNode->val = newVal;
	// set next field to nullptr
	newNode->next = nullptr;

	// if the list doesn't have any values
	if (!head)
	{
		// set the first value to that of the appended node
		head = newNode;
	}
	else
	{
		// otherwise traverse the linked list
		nodePtr = head;
		while (nodePtr->next)
		{
			nodePtr = nodePtr->next;
		}
		// when at the end of the list append the new node as
		// the next node of the last node. new node is the new
		// last node.
		nodePtr->next = newNode;
	}
}

// insertNode acts like appendNode except it finds the place in an 
// ordered list where it would belong based on the value.
template <class T>
void LList<T>::insertNode(T newVal)
{
	// declare pointers to LNode structures for the new value
	// the nodePtr used to traverse the list, and a previous node
	// to be able to appropriately link the new node within the list.
	LNode *newNode;
	LNode *nodePtr;
	LNode *previousNode = nullptr;

	// newNode is assigned new structure and the value is set to the
	// argument newVal
	newNode = new LNode;
	newNode->val = newVal;

	// if the list doesn't have any values 
	if (!head)
	{
		// set the first value to that of the appended node
		head = newNode;
		// and the next to nullptr
		newNode->next = nullptr;
	}
	else
	{
		// otherwise assign the head to nodePtr and traverse the list
		nodePtr = head;
		
		// order is assumed to be smallest to largest
		// loop to traverse the list so long as nodePtr isn't set to
		// nullptr and the new value is greater than the current value
		while (nodePtr != nullptr && nodePtr->val < newVal)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		// if the while loop didn't run and set a new value for 
		// previous node, the head is the only value and greater than
		// the new value
		if (previousNode == nullptr)
		{
			//set head to the new node
			head = newNode;
			// the next value is set to the nodePtr which is
			// the previous value of the head.
			newNode->next = nodePtr;
		}
		else
		{
			// set the next value of the node ahead of where the
			// new node belongs to that of the new node, and the
			// next value of the new node to that of the node that
			// belongs after it.
			previousNode->next = newNode;
			newNode->next = nodePtr;
		}
	}
}

// deleteNode takes the argument value and traverses the linked list
// looking for it. when it is found the node is deleted and the next
// pointer of the previous node is set to the next node to that of
// the next value of the deleted node.
template <class T>
void LList<T>::deleteNode(T delVal)
{
	// declare node pointer and previous to traverse linked list
	// while tracking the previous node to the one being pointed to
	LNode *nodePtr;
	LNode *previousNode = nullptr;

	// if there aren't any nodes, there isn't anything to delete
	// end function
	if (!head)
	{
		return;
	}

	// if the head value is the value that needs to be deleted,
	
	if (head->val == delVal)
	{
		// set the node pointer to the next node pointed to from head
		nodePtr = head->next;
		// delete the head value
		delete head;
		// set the head value to the node pointed to by nodePtr
		head = nodePtr;
	}
	else
	{
		// otherwise traverse the list
		nodePtr = head;

		// Loop until at the end of the linked list, or
		// the value of nodePtr is the value that needs to be deleted
		while (nodePtr != nullptr && nodePtr->val != delVal)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		// so long as there is a value for nodePtr
		
		if (nodePtr)
		{
			// link the next value of the previous node to the next 
			// node linked to nodePtr
			previousNode->next = nodePtr->next;

			delete nodePtr;
		}
	}
}

// displayList traverses the list from the head
// printing each value on it's own line untill
// the end of the list
template <class T>
void LList<T>::displayList() const
{
	// declare a pointer for the node structure
	LNode *nodePtr;

	// set the head as the pointer
	nodePtr = head;

	// loop while the pointer has a value
	while (nodePtr)
	{
		// print the value of the structure
		cout << nodePtr->val << endl;
		// move to the next node
		nodePtr = nodePtr->next;
	}
}

// searchList traverses the linked list incrementing a counter
// when the argument value matches the value of the current node
// the counter is returned indicating the argument's location in
// the linked list. 
template <class T>
int LList<T>::searchList(T searchVal)
{
	// declare and initalize a counter to 0
	int count = 0;

	// create a LNode pointer to traverse the list
	LNode *nodePtr;

	// if the linked list is empty, return -1 as there isn't a value
	// that will match

	if (!head)
	{
		return -1;
	}

	// traverse the list
	nodePtr = head;
	// loop while notePtr is pointing to a value
	while (nodePtr)
	{
		// set a matching value of the classe's declared data-type
		// to that of the node's value
		T matchVal = nodePtr->val;
		
		// if the node's value matches the argument value
		if (matchVal == searchVal)
		{
			return count;
		}
		else
		{
			// otherwise increment the counter
			count++;
			// set the nodePtr to the next node
			nodePtr = nodePtr->next;
		}
	}

	// if the loop ends without finding a matching value
	return -1;
}
// Returns the total number of nodes in a linked list
template <class T>
int LList<T>::numNodes()
{
	// declare pointer to traverse list
	LNode *nodePtr;
	// declare and initialize counter
	int numNodes = 0;

	// if there isn't a first node
	if (!head)
	{
		return numNodes;
	}
	
	// set head as first node
	nodePtr = head;
	// increment counter
	numNodes++;
		// loop while there is a node to point to
		while (nodePtr)
		{
			// set next node as pointer
			nodePtr = nodePtr->next;

			// increment counter so long as the next node exists
			if (nodePtr)
			{
				numNodes++;
			}	
		}
	// return the counter
	return numNodes;

}


// returns the value of the node argument
template <class T>
T LList<T>::returnVal(int node)
{
	// declare node pointer for list traversal
	LNode *nodePtr;
	
	// if the list is empty throw an exception
	if (!head)
	{
		string exception = "this is an empty list.";
		throw exception;
	}
	else
	{
		// otherwise set the pointer to the head
		nodePtr = head;

		// loop while the counter is < node argument
		for (int i = 0; i <= node; i++)
		{
			// when the counter is at the node argument return
			// the value of the node
			if (i == node)
			{
				return nodePtr->val;
			}
			else
			{
				// otherwise traverse the node
				nodePtr = nodePtr->next;
			}
		}
	}

}

template <class T>
int LList<T>::getLen()
{
	int count = 0;
	LNode *nodePtr;

	if (!head)
	{
		return count;
	}
	else
	{
		nodePtr = head;
		count++;
		while (nodePtr)
		{
			nodePtr = nodePtr->next;
			count++;
		}
		return count;
	}
}