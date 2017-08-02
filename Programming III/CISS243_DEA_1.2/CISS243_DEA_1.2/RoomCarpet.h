#ifndef ROOMCARPET_H
#define ROOMCARPET_H

#include "RoomDimension.h"

using namespace std;

//class declaration
class RoomCarpet
{
private:
	//class member fields
	double costSqFt;
	RoomDimension room;
public:
	//constructor declaration
	RoomCarpet();

	//accessor functions
	double getCostSqFt();
	RoomDimension getRoom();
	
	//calculated value function
	double getTotalCost();

	//mutator functions
	void setCostSqFt(double);
	void setRoom(RoomDimension &);
	void setRoom(int lf, int li, int wf, int wi);
};

#endif // !ROOMCARPET_H

