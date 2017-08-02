#ifndef PQUEUE_H
#define PQUEUE_H
#include "Patient.h"


typedef Patient ItemType;
struct NodeType;

class FullQueue{};
class EmptyQueue{};

/*
Queue with typeof Patient for use by ExamRoom Class.
Dynamically Queues Patient objects while keeping track
of the number in queue. Functions available to add to,
remove from, and test if queue is full or empty.
*/

class PQueue
{
public:
	PQueue();
	~PQueue();
	void makeEmpty();
	void enqueue(ItemType);
	void dequeue(ItemType&);
	bool isEmpty() const;
	bool isFull() const;
	int getLen();

private:
	NodeType *front;
	NodeType *rear;
	int len;
};

#endif // !PQUEUE_H
