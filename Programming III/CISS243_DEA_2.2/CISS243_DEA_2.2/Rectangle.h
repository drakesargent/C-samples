// Derrived class specification for Rectangle Class
// inheriting from BasicShape class
#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "BasicShape.h"

// Rectangle Class holds long int values for width and length
class Rectangle : public BasicShape
{
private:
	long width; // To hold value for width
	long length; // To hold value for length
public:
	// Constructor
	Rectangle(long w, long l);
	// Override virtual function calcArea from base class BasicShape
	// Implemented in Rectangle.cpp
	virtual void calcArea();
	//Accessor Functions
	long getWidth();
	long getLength();
};

#endif // !RECTANGLE_H

