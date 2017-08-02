// Implementation file for Rectangle Class
#include "Rectangle.h"

// Constructor
Rectangle::Rectangle(long w, long l)
{
	width = w; // assign width value
	length = l; // assign length value
	calcArea(); // calculate area with Rectangle Class override
}

//***********************************************
// Overriding calcArea Function from base class *
// BasicShape. Sets area equal to rectangle     *
// width multiplied by rectangle length         *
//***********************************************
void Rectangle::calcArea()
{
	area = width * length;
}
// Class accessor definitions
long Rectangle::getWidth()
{
	return width;
}

long Rectangle::getLength()
{
	return length;
}
