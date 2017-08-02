// Implementation file for Rectangle Class
#include "Circle.h"

// Constructor
Circle::Circle(long x, long y, double r)
{
	centerX = x; // assign center x coordinate value
	centerY = y; // assign center y coordinate value
	radius = r; // assign radius value
	calcArea(); // calculate area with Circle Class override
}

//***********************************************
// Overriding calcArea Function from base class *
// BasicShape. Sets area equal to truncated PI  *
// value multiplied by the radius twice         *
//***********************************************
void Circle::calcArea()
{
	area = 3.1459*radius*radius;
}

//Class accessor definitions
long Circle::getCenterX()
{
	return centerX;
}
long Circle::getCenterY()
{
	return centerY;
}
