#include <iostream>
#include "RoomDimension.h"

using namespace std;

//constructor definitions
RoomDimension::RoomDimension(FeetInches &l, FeetInches &w)
{
	length = l;
	width = w;
}
//empty constructor
RoomDimension::RoomDimension()
{
	FeetInches l;
	FeetInches w;

	length = l;
	width = w;
}

//mutator functions
void RoomDimension::setLength(FeetInches &l)
{
	length = l;
}

void RoomDimension::setWidth(FeetInches &w)
{
	width = w;
}

void RoomDimension::setLength(int f, int i)
{
	FeetInches l(f, i);
	length = l;
}
void RoomDimension::setWidth(int f, int i)
{
	FeetInches w(f, i);
	width = w;
}

//accessor functions
FeetInches RoomDimension::getLength()
{
	return length;
}
FeetInches RoomDimension::getWidth()
{
	return width;
}

//calculated value function, object returned
FeetInches RoomDimension::getArea()
{
	FeetInches prod;
	prod = length.multiply(width);
	return prod;
}