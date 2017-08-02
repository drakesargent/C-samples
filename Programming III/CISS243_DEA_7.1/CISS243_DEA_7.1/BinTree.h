#ifndef BINTREE_H
#define BINTREE_H

#include<iostream>
using namespace std;

// Template for binary tree. Class accepts user defined datatype
// and creates a binary tree data structure that stores declared
// datatype.

template <class T>
class BinTree
{
private:
	// Definition of TreeNode Structure
	struct TreeNode
	{
		T value; // Value node contains
		TreeNode *left;  // pointer to left child node
		TreeNode *right; // pointer to right child node
	};

	TreeNode *root; // Pointer to first tree node structure

	// Private function declarations defined below class.
	void insert(TreeNode *&, TreeNode *&);
	void destroySubTree(TreeNode*);
	void deleteNode(T, TreeNode *&);
	void makeDeletion(TreeNode *&);
	void displayInOrder(TreeNode *) const;
	void displayPreOrder(TreeNode *) const;
	void displayPostOrder(TreeNode *) const;

public:
	// Constructor
	BinTree();

	// Destructor
	~BinTree();

	// Binary Tree Operations
	void insertNode(T);
	bool searchNode(T);
	void remove(T);

	// Public access for private functions
	void dislplayInOrder() const;
	void displayPreOrder() const;
	void displayPostOrder() const;

};

// Private Function Definitions

// Called by insertNode accepts two tree node structure pointers
// that allow for data manipulation. One is the root node the
// second is the new structure created in the insertNode function.
template <class T>
void BinTree<T>::insert(TreeNode *&nodePtr, TreeNode *&newNode)
{
	// if this node doesn't contain a value
	if (nodePtr == nullptr)
	{
		nodePtr = newNode; // make the new node the value
	}
	else if (newNode->value < nodePtr->value) // otherwise if the new value is less than the current node
	{
		insert(nodePtr->left, newNode); // traverse left
	}
	else
	{
		insert(nodePtr->right, newNode); // otherwise traverse right
	}
}

// Called by the destructor this function accepts a pointer to the 
// TreeNode Structure and traverses to the end branches through
// recursion and deletes the nodes.
template <class T>
void BinTree<T>::destroySubTree(TreeNode *nodePtr)
{
	if (nodePtr) // if a value exists
	{
		if (nodePtr->left) // and a value exists on the left
		{
			destroySubTree(nodePtr->left); // traverse left
		}
		if (nodePtr->right) // or a value exists on the right
		{
			destroySubTree(nodePtr->right); // traverse right
		}
		delete nodePtr; // at leaf, delete the node
	}
}

// called by the public function remove, this function
// accepts a user defined data type item, and a mutatable
// reference to a TreeNode data structure.
template <class T>
void BinTree<T>::deleteNode(T item, TreeNode *&nodePtr)
{
	if (item < nodePtr->value) // if the item is less than the node's value
	{
		deleteNode(item, nodePtr->left); // traverse left
	}
	else if (item > nodePtr->value) // if the item is greater than the node's value
	{
		deleteNode(item, nodePtr->right); // traverse right
	}
	else
	{
		makeDeletion(nodePtr); // otherwise the item is equivelent and the deletion needs to happen
	}
}

// makeDeletion is called by the private deleteNode function.
// this accepts the TreeNode pointer to the node that needs to be deleted
// this function checks for values to the right and left of the
// node and attaches them the data structure.
template <class T>
void BinTree<T>::makeDeletion(TreeNode *&nodePtr)
{
	TreeNode *tempNodePtr = nullptr;

	if (nodePtr == nullptr) // checks that the node isn't empty
	{
		cout << "Cannot delete empty node." << endl;
	}
	else if (nodePtr->right == nullptr) // checks if there are values to the right
	{
		tempNodePtr = nodePtr;  // if not, assign the node to a temp holder
		nodePtr = nodePtr->left; // traverse to the left assigning the value
		delete tempNodePtr; // delete the tempNode.
	}
	else if (nodePtr->left == nullptr) // checks if there are values to the left
	{
		tempNodePtr = nodePtr; // if not, assign the node to a temp holder
		nodePtr = nodePtr->right; // traverse to the right assigning the value
		delete tempNodePtr; // delete the tempNode.
	}
	else // otherwise there are values to both the left and right
	{
		// traverse to the right
		tempNodePtr = nodePtr->right;

		// get to the end of the left sub-tree
		while (tempNodePtr->left)
		{
			tempNodePtr = tempNodePtr->left;
		}
		// attach the left sub-tree
		tempNodePtr->left = nodePtr->left;
		tempNodePtr = nodePtr;

		// attach the right sub-tree
		nodePtr = nodePtr->right;
		// delete the node
		delete tempNodePtr;
	}
}

// called by public function displayInOrder
template <class T>
void BinTree<T>::displayInOrder(TreeNode *nodePtr) const
{
	// if the nodePtr has a value
	if (nodePtr)
	{
		// recursively traverse left
		displayInOrder(nodePtr->left);
		// print value 
		cout << nodePtr->value << endl;
		// recursively traverse right
		displayInOrder(nodePtr->right);
	}
}

// called by public function displayPreOrder
template <class T>
void BinTree<T>::displayPreOrder(TreeNode *nodePtr) const
{
	// if the nodePtr has a value
	if (nodePtr)
	{
		// print value 
		cout << nodePtr->value << endl;
		// recursively traverse left
		displayPreOrder(nodePtr->left);
		// recursively traverse right
		displayPreOrder(nodePtr->right);
	}
}

// called by the public function displayPostOrder
template <class T>
void BinTree<T>::displayPostOrder(TreeNode *nodePtr) const
{
	// if the nodePtr has a value
	if (nodePtr)
	{
		// recursively traverse left
		displayPostOrder(nodePtr->left);
		// recursively traverse right
		displayPostOrder(nodePtr->right);
		// print value 
		cout << nodePtr->value << endl;
	}
}
// Constructor
template <class T>
BinTree<T>::BinTree()
{
	root = nullptr;
}
// Destructor
template <class T>
BinTree<T>::~BinTree()
{
	destroySubTree(root);
}

// Public function definitions

// insertNode creates a treeNode structure with the 
// item given in the argument and calls the private
// insert function to assign where it goes.
template <class T>
void BinTree<T>::insertNode(T item)
{
	TreeNode *newNode = nullptr;

	newNode = new TreeNode;
	newNode->value = item;
	newNode->left = newNode->right = nullptr;

	insert(root, newNode);
}

// searchNode accepts an item argment traverses
// the data structure looking for the item.
// if it is found it returns true, if not false.
// items greater than the node's value traverse right,
// items smaller than the node's value traverse left.
template <class T>
bool BinTree<T>::searchNode(T item)
{
	TreeNode *nodePtr = root;

	while (nodePtr)
	{
		if (nodePtr->value == item)
		{
			return true;
		}
		else if (item < nodePtr->value)
		{
			nodePtr = nodePtr->left;
		}
		else
		{
			nodePtr = nodePtr->right;
		}
	}
	return false;
}

// the following functions call private functions that
// either use the root value or the item passed and the
// root value.
template <class T>
void BinTree<T>::remove(T item)
{
	deleteNode(item, root);
}
template <class T>
void BinTree<T>::dislplayInOrder() const
{
	displayInOrder(root);
}
template <class T>
void BinTree<T>::displayPreOrder() const
{
	displayPreOrder(root);
}
template <class T>
void BinTree<T>::displayPostOrder() const
{
	displayPostOrder(root);
}

#endif // !BINTREE_H

