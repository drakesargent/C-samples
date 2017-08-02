#include "ExamRoom.h"

void ExamRoom::setSpec()
{
	spec = Doc.getSpec();
}

ExamRoom::ExamRoom()
{
	int roomNum = 0;
}

// room specialty is set with doctor assignment
void ExamRoom::setDoc(Doctor d)
{
	Doc = d;
	spec = d.getSpec();
}

// sets the exam room patient with one from the queue
// checks if there is a patient already in the room
// throws errors if there is a patient already,
// if there are no patients in the queue,
// or if there isn't a doctor in the room.
void ExamRoom::setPat()				
{
	if (!hasPat())
	{
		if (!hasDoc())
		{
			throw NoDoctors();
		}
		try
		{
			Pat = nextPat();
		}
		catch(NoPats)
		{
			throw EmptyLine();
		}
	}
	else
	{
		throw RoomInUse();
	}
}

void ExamRoom::setRoomNum(int n)
{
	roomNum = n;
}

// all doctors have a room preference if the room preference
// for the doctor object is 0, then there isn't a doctor
bool ExamRoom::hasDoc()
{
	if (Doc.getRoomPref() == 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}
// all patients have an age, returns false if age is 0
bool ExamRoom::hasPat()
{
	if (Pat.getAge() == 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool ExamRoom::patsInQ()
{
	if (PQ.isEmpty())
	{
		return false;
	}
	else
	{
		return true;
	}
}

string ExamRoom::currentPat()
{
	return Pat.getName();
}

string ExamRoom::currentDoc()
{
	return Doc.getName();
}

void ExamRoom::clearDoc()
{
	Doctor Clear;
	Doc = Clear;
}

void ExamRoom::clearPat()
{
	Patient Clear;
	Pat = Clear;
}

// used when emptying a room when a doctor leaves,
// or used by setPat(), throws error when queue is empty
Patient ExamRoom::nextPat()
{
	Patient p;
	try
	{
		PQ.dequeue(p);
	}
	catch (EmptyQueue)
	{
		return p;
		throw NoPats();
	}
	return p;
}

void ExamRoom::enquePat(Patient p)
{
	try {
		PQ.enqueue(p);
	}
	catch(FullQueue)
	{
		
	}
}

int ExamRoom::queueLen()
{
	return PQ.getLen();
}

int ExamRoom::getRoomNum()
{
	return roomNum;
}

Specialty ExamRoom::getSpec()
{
	return spec;
}