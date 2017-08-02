#ifndef DYNAMICSTACK_H
#define DYNAMICSTACK_H

// Template class creates a dynamic stack of the 
// declared datatype.
template <class T>
class DynamicStack {

private:
	// structure definition
	struct StackNode
	{
		T val;
		StackNode *next;
	};

	// initial structure pointer
	StackNode *top;

public:

	// Constructor defined below class declaration
	DynamicStack();

	// Destructor defined below class declaration
	~DynamicStack();

	// Stack Operations defined below class declaration
	bool pop(T &item);
	void push(T item);


};
#endif // !DYNAMICSTACK_H

// Constructor definition, sets structure pointer to nullptr
template <class T>
DynamicStack<T>::DynamicStack()
{
	top = nullptr;
}

// Destructor definition cycles through stack deleting each node
template <class T>
DynamicStack<T>::~DynamicStack()
{
	StackNode *nodePtr, *nextNode;

	// Beginning of stack
	nodePtr = top;

	// Loop while there are nodes
	while (nodePtr != nullptr)
	{
		nextNode = nodePtr->next; // set next node from nodePtr
		delete nodePtr; // delete current nodePtr
		nodePtr = nextNode; // cycle next node to current node
	}
}

// Function definitions
// pop function assigns value of the top node to the data item
// passed into function by reference and returns true if able
// to do so, false if stack is empty.
template <class T>
bool DynamicStack<T>::pop(T &item)
{
	// stack node pointer to hold next value
	StackNode *temp = nullptr;

	// test if there is a top of the stack
	if (!top)
	{
		return false;
	}
	else
	{
		item = top->val;	// set item to the top value
		temp = top->next;	// set the temp node to the next node
		delete top;			// delete the top node
		top = temp;			// set the top node as the next node
		return true;
	}
}

// push function adds passed value as the top node of the stack
// pushing back other nodes
template <class T>
void DynamicStack<T>::push(T item)
{
	// structure pointer
	StackNode *newNode = nullptr;
	// create new stacknode structure
	newNode = new StackNode;
	// set value as argument value
	newNode->val = item;

	// if the top isn't set set the top as the newnode
	if (top == nullptr)
	{
		top = newNode;
		newNode->next = nullptr;
	}
	else
	{
		// otherwise set the next value of the new node to the top node
		newNode->next = top;
		// and set the top node as the new node
		top = newNode;
	}
}