#include "PQueue.h"
struct NodeType
{
	ItemType item;
	NodeType *next;
};

PQueue::PQueue()
{
	front = nullptr;
	rear = nullptr;
	len = 0;
}

PQueue::~PQueue()
{
	makeEmpty();
}

void PQueue::makeEmpty()
{
	NodeType *tempPtr = nullptr;

	while (front != nullptr)
	{
		tempPtr = front;
		front = front->next;
		delete tempPtr;
	}
	rear = nullptr;
}

void PQueue::enqueue(ItemType i)
{
	if (isFull())
	{
		throw FullQueue();
	}
	else
	{
		NodeType *newNode;

		newNode = new NodeType;
		newNode->item = i;
		newNode->next = nullptr;
		if (rear == nullptr)
		{
			front = newNode;
			front->next = rear;
		}
		else
		{
			rear->next = newNode;
		}
		rear = newNode;
		len++;
	}
}

void PQueue::dequeue(ItemType &i)
{
	if (isEmpty())
	{
		throw EmptyQueue();
	}
	else
	{
		NodeType *tempPtr;

		tempPtr = front;
		i = front->item;
		front = front->next;

		if (front == nullptr)
		{
			rear = nullptr;
		}

		delete tempPtr;
		len--;
	}
}

bool PQueue::isEmpty() const
{
	return (front == nullptr);
}

bool PQueue::isFull() const
{
	NodeType *loc;
	try
	{
		loc = new NodeType;
		delete loc;
		return false;
	}
	catch (std::bad_alloc exception)
	{
		return true;
	}
}

int PQueue::getLen()
{
	return len;
}