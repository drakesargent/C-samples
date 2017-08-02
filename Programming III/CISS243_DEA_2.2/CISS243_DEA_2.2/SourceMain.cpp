// Main program to display class functionality
#include <iostream>
#include "Circle.h"
#include "Rectangle.h"

using namespace std;
// prototype function to print area of any derrived class
// of BasicShape base class
void DisplayArea(BasicShape* shape);

int main()
{
	// declare and initialize Circle
	Circle cShape1(0, 0, 3.5);
	// declare and initialize Rectangle
	Rectangle rShape1(5, 10);

	//use funtion to show area of shapes
	DisplayArea(&cShape1);
	DisplayArea(&rShape1);

	return 0;
}

// funtion specification
void DisplayArea(BasicShape* shape)
{
	cout << "Area of shape: " << shape->getArea() << endl;
}