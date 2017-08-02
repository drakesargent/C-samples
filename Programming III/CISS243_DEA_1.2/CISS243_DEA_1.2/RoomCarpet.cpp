#include "RoomCarpet.h"

using namespace std;

//constructor definition
RoomCarpet::RoomCarpet()
{
	costSqFt = 0.0;
}

//accessor definitions
double RoomCarpet::getCostSqFt()
{
	return costSqFt;
}

RoomDimension RoomCarpet::getRoom()
{
	return room;
}

//calculated value
double RoomCarpet::getTotalCost()
{
	double total = 0.0;
	
	//create object to store area data
	FeetInches area;
	//get area data from this object
	area = room.getArea();
	//multiply double form of data with the cost assigning it to the total
	total = area.operator double() * costSqFt;

	return total;
}

//mutator functions
void RoomCarpet::setCostSqFt(double c)
{
	costSqFt = c;
}

void RoomCarpet::setRoom(RoomDimension &r)
{
	room.setLength(r.getLength());
	room.setWidth(r.getWidth());
}

void RoomCarpet::setRoom(int lf, int li, int wf, int wi)
{
	room.setLength(lf, li);
	room.setWidth(wf, wi);
}