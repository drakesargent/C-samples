#ifndef ROOMDIMENSION_H
#define ROOMDIMENSION_H

#include "FeetInches.h"

using namespace std;
//class declaration
class RoomDimension
{
private:
	FeetInches length;
	FeetInches width;
public:
	//constructors
	RoomDimension(FeetInches &l, FeetInches &w);
	RoomDimension();

	//mutator functions
	void setLength(FeetInches &);
	void setWidth(FeetInches &);
	void setLength(int f, int i);
	void setWidth(int f, int i);
	
	//accessor functions
	FeetInches getLength();
	FeetInches getWidth();
	FeetInches getArea();
};
#endif // !ROOMDIMENSION_H

