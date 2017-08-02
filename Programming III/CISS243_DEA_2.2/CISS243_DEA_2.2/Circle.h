// Derrived class specification for Circle Class
// inheriting from BasicShape class
#ifndef CIRCLE_H
#define CIRCLE_H
#include "BasicShape.h"

// Circle Class holds long int values for center x and y
// values and a double for the radius value
class Circle : public BasicShape
{
private:
	long centerX; // To hold value for center x coordinate
	long centerY; // To hold value for center y coordinate
	double radius; // To hold value for radius value
public:
	// Constructor
	Circle(long x, long y, double r);
	// Override virtual function calcArea from base class BasicShape
	// Implemented in Circle.cpp
	virtual void calcArea();
	//Accessor Functions
	long getCenterX();
	long getCenterY();
};

#endif // !CIRCLE_H
