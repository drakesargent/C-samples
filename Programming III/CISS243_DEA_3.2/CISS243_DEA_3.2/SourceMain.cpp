#include <iostream>
#include "MinMax.h"

using namespace std;

int main()
{
	// instances of the MinMax class for data types
	// int, double, and char
	MinMax<int> i(-5, 10);
	MinMax<double> d(-2.5, 87.5);
	MinMax<char> c('a', 'A');

	// demonstrating the evaluation accessor functions
	// for each instance of MinMax
	cout << "Min of i is: " << i.minimum() << endl;
	cout << "Max of i is: " << i.maximum() << endl;
	cout << endl;

	cout << "Min of d is: " << d.minimum() << endl;
	cout << "Max of d is: " << d.maximum() << endl;
	cout << endl;

	cout << "Min of c is: " << c.minimum() << endl;
	cout << "Max of c is: " << c.maximum() << endl;
	cout << endl;
}