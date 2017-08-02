/*Kenneth Drake-Sargent
*Chapter 4
*Problem 1
*Geometry Calculator
*/
/*
Display formatted menu
Request user choice
Store choice in memory
Switch statement to process entered choice
Declare variables for the possible measurements required
Validate data entered so that it is not a negative value
Calculate requested store in memory
Display requested calculation
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	
	char choice;
	const double PI = 3.14159;
	double radius;
	double length;
	double width;
	double base;
	double base2;
	double height;
	bool valid = false;
	double area;

	cout << "Geometry Calculator\n" << endl;
	cout << setw(4) << 1 << ". Calculate the Area of a Circle" << endl;
	cout << setw(4) << 2 << ". Calculate the Area of a Rectangle" << endl;
	cout << setw(4) << 3 << ". Calculate the Area of a Triangle" << endl;
	cout << setw(4) << 4 << ". Calculate the Area of a Trapezoid" << endl;
	cout << setw(4) << 5 << ". Calculate the Area of a Sphere" << endl;
	cout << setw(4) << 6 << ". Exit\n" << endl;
	cout << "Enter your Choice (1-6): ";

	cin >> choice;
	cout << endl;

	switch (choice) {
		case '1':
			//request and store Circle's radius
			cout << "Please enter the Circle's radius: ";
			cin >> radius;
			cout << endl;
			
			//validate given radius data
			while (!valid) {
				if (radius < 0) {
					cout << "Please enter a positive value for the radius: ";
					cin >> radius;
					cout << endl;
				}
				else {
					valid = true;
				}
			}
			//reset validation loop
			valid = false;
			
			//calculate and store area
			area = PI * pow(radius, 2);
			
			//display area
			cout << "The area of the Circle is: " << area << endl;
			
			//break out of case
			break;

		case '2':
			//request and store rectangle's length
			cout << "Please enter the Rectangle's length: ";
			cin >> length;
			cout << endl;

			//validate given length data
			while (!valid) {
				if (length < 0) {
					cout << "Please enter a positive value for the length: ";
					cin >> length;
					cout << endl;
				}
				else {
					valid = true;
				}
			}

			//reset validation loop
			valid = false;

			//request and store rectangle's width
			cout << "Please enter the Rectangle's width: ";
			cin >> width;
			cout << endl;

			//validate given width data
			while (!valid) {
				if (width < 0) {
					cout << "Please enter a positive value for the width: ";
					cin >> width;
					cout << endl;
				}
				else {
					valid = true;
				}
			}

			//reset validation loop
			valid = false;

			//calculate and store area
			area = length * width;

			//display area
			cout << "The area of the Rectangle is: " << area << endl;

			//break out of case
			break;
		
		case '3':
			//request and store triangle's base
			cout << "Please enter the Triangle's base: ";
			cin >> base;
			cout << endl;

			//validate given base data
			while (!valid) {
				if (base < 0) {
					cout << "Please enter a positive value for the base: ";
					cin >> base;
					cout << endl;
				}
				else {
					valid = true;
				}
			}

			//reset validation loop
			valid = false;

			//request and store triangle's height
			cout << "Please enter the Triangle's height: ";
			cin >> height;
			cout << endl;

			//validate given height data
			while (!valid) {
				if (height < 0) {
					cout << "Please enter a positive value for the height: ";
					cin >> height;
					cout << endl;
				}
				else {
					valid = true;
				}
			}

			//reset validation loop
			valid = false;

			//calculate and store area
			area = (base * height) * .5;

			//display area
			cout << "The area of the Triangle is: " << area << endl;

			//break out of case
			break;
		
		case '4':
			//request and store trapezoid's first base
			cout << "Please enter the Trapezoid's first base: ";
			cin >> base;
			cout << endl;

			//validate given base data
			while (!valid) {
				if (base < 0) {
					cout << "Please enter a positive value for the base: ";
					cin >> base;
					cout << endl;
				}
				else {
					valid = true;
				}
			}

			//reset validation loop
			valid = false;

			//request and store trapezoid's second base
			cout << "Please enter the Trapezoid's second base: ";
			cin >> base2;
			cout << endl;

			//validate given base data
			while (!valid) {
				if (base2 < 0) {
					cout << "Please enter a positive value for the base: ";
					cin >> base2;
					cout << endl;
				}
				else {
					valid = true;
				}
			}

			//reset validation loop
			valid = false;

			//request and store trapezoid's height
			cout << "Please enter the Trapezoid's height: ";
			cin >> height;
			cout << endl;

			//validate given height data
			while (!valid) {
				if (height < 0) {
					cout << "Please enter a positive value for the height: ";
					cin >> height;
					cout << endl;
				}
				else {
					valid = true;
				}
			}

			//reset validation loop
			valid = false;

			//calculate and store area
			area = (height / 2)*(base + base2);

			//display area
			cout << "The area of the Trapezoid is: " << area << endl;

			//break out of case
			break;
		
		case '5':
			//request and store Sphere's radius
			cout << "Please enter the Sphere's radius: ";
			cin >> radius;
			cout << endl;

			//validate given radius data
			while (!valid) {
				if (radius < 0) {
					cout << "Please enter a positive value for the radius: ";
					cin >> radius;
					cout << endl;
				}
				else {
					valid = true;
				}
			}
			//reset validation loop
			valid = false;

			//calculate and store area
			area = 4 * PI * pow(radius, 2);

			//display area
			cout << "The area of the Sphere is: " << area << endl;

			//break out of case
			break;
	
		case '6':
			//break to exit
			break;
		
		default:
			//anything not on the menu list will get this message
			cout << "You entered an option that is not available. Please choose an option from 1-6." << endl;
			break;
	}
	
	return 0;
}