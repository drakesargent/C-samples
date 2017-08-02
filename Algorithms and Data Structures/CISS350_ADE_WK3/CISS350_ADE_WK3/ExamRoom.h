#ifndef EXAMROOM_H
#define EXAMROOM_H
#include "Doctor.h"
#include "PQueue.h"

/*
ExamRoom class holds room number information, doctor, doctor's specialty,
patient, and a patient queue. There are functions to determine if any of the
doctor or patient slots are vacant and a way to determine how long the queue is.
*/

class NoDoctors{};
class NoPats{};
class RoomInUse{};
class EmptyLine {
private:
	string msg;
public:
	EmptyLine()
	{
		msg = "PATIENT QUEUE IS EMPTY";
	}
	string getMsg() { return msg; }
};

class ExamRoom
{
private:
	int roomNum;
	Specialty spec; // set by DR in room
	Doctor Doc;
	Patient Pat;
	PQueue PQ;

	void setSpec(); // called by setDoc

public:
	// constructor
	ExamRoom();
	
	void setDoc(Doctor);
	void setPat(); // set by next patient in queue
	void setRoomNum(int);


	bool hasDoc();
	bool hasPat();
	bool patsInQ();

	string currentPat();
	string currentDoc();
	
	void clearDoc();
	void clearPat();
	
	Patient nextPat();
	void enquePat(Patient);
	int queueLen();
	int getRoomNum();
	Specialty getSpec();
	
	

	
};
#endif // !EXAMROOM_H
