// Class header and definition for LList Template Class
#ifndef LLIST_H
#define LLIST_H

// LList Template Class creates a linked list of a user defined
// data-type. Standard logic was used to create functions to append,
// instert, and delete nodes that belong to the linked list. This
// also includes a function to display all of the node's values
// and a function to search for the positioning of a node by value.
// The majority of this class was created using standard linked list
// logic.

template <class T>
class LList
{
private:

	// structure definition to hold user defined data-type
	// and create a pointer to the next link self-referencing
	// the structure
	struct LNode
	{

		T val;
		struct LNode *next;
	};

	// Declaration of the head (first) structure pointer
	LNode *head;

public:
	// Class constructor declaration
	// Defined in LList.cpp
	LList();

	// Class destructore declaration
	// Defined in LList.cpp
	~LList();

	// Class Functions
	// Defined in LList.cpp
	void appendNode(T); // adds node to end of linked list
	void insertNode(T); // adds node in sequence based on value
	void deleteNode(T); // removes node
	void displayList() const; // prints all nodes
	int searchList(T); // searches for value in linked list, returns position
	int getLen();
};

#endif // !LLIST_H

