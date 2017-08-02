#include<iostream>
#include "Circle.h"

using namespace std;

//variable declaration
double rad;

int main()
{
	//request user input
	cout << "Enter the circle's radius: ";
	cin >> rad;

	//declare and initialize first circle with given radius
	Circle c1(rad);//constructor that accepts radius argument
	
	//call member functions for first circle assigning return values to variables
	double c1Area = c1.getArea();
	double c1Circum = c1.getCircumfrence();
	double c1Diam = c1.getDiameter();
	double c1Rad = c1.getRadius();
	
	//print out the results
	cout << "With the radius of " << c1Rad << " the circle's measurements are: " << endl;
	cout << "Diameter: " << c1Diam << endl;
	cout << "Circumfrence: " << c1Circum << endl;
	cout << "Area: " << c1Area << endl;

	cout << endl;
	
	
	//declare circle variable that uses default constructor
	Circle c2;
	//call member function that sets radius for second circle
	c2.setRadius(rad);
	
	//call member functions to return the values and store in variables
	double c2Area = c2.getArea();
	double c2Circum = c2.getCircumfrence();
	double c2Diam = c2.getDiameter();
	double c2Rad = c2.getRadius();
	
	//print out second circle member values
	cout << "A second circle was created with the following measurements: " << endl;
	cout << "With the radius of " << c2Rad << " the 2nd circle's measurements are: " << endl;
	cout << "Diameter: " << c2Diam << endl;
	cout << "Circumfrence: " << c2Circum << endl;
	cout << "Area: " << c2Area << endl;

	system("pause");
	return 0;
}