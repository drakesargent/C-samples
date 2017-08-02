/*Kenneth Drake-Sargent
*Chapter 3
*Problem 2
*Pizza Orders
*/

/*
Calculate the number of Slices a pizza of any size can be divided into
Calculate tne total number of pizzas needed given a number of people
Slice = 14.125 inches
Number of slices = Pizza Area / Slice (fixed point rounded to one decimal place)

Declare constants for slice size, PI, slices per person
Declare variables for number of slices, pizza diameter, pizza area, 
	number of people, number of pizzas

Display request for diamater of pizzas to order
Store value in pizza diameter variable
Display request for number of people at party
Store value in number of people

Calculate area of pizza
Store in variable pizza area
Calculate number of slices
Store in variable number of slices
Calculate number of pizzas
Store in variable number of pizzas

Display values

End program
*/

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main() {
	
	//declare constants
	const double SLICE_SIZE = 14.125,
		PI = 3.14159;
	
	const int SLICE_PER_PERSON = 3;
	
	//declare variables
	double numSlices,
		pizzaDiam,
		pizzaArea,
		numPeople,
		numPizzas,
		r,
		totalSlicesNeeded;
	
	//request input and store responses
	cout << "Enter how large you would like your pizza's diameter." << endl;
	cin >> pizzaDiam;
	cout << "How many people are you ordering for?" << endl;
	cin >> numPeople;
	
	//perform calculation
	r = pizzaDiam / 2.0;
	pizzaArea = PI * pow(r, 2.0);
	numSlices = pizzaArea / SLICE_SIZE;
	totalSlicesNeeded = SLICE_PER_PERSON * numPeople;
	
	//solving the problem for a whole number of pizzas needed
	numPizzas = static_cast<double>(totalSlicesNeeded) / numSlices;
	numPizzas = round(numPizzas + .5);
	int totalPizzas = static_cast<int>(numPizzas);

	//display output
	cout << "On a " << pizzaDiam << " inch pizza there are " << setprecision(1) << fixed << numSlices << " slices." << endl;
	cout << setprecision(0) << fixed << endl;
	cout << "You will have to order " << totalPizzas << " for a group of " << numPeople << "." << endl;

	/*
	testblock for calculation responses
	cout << endl << "radius: " << r << endl;
	cout <<"area: "<< pizzaArea << endl;
	cout << "number of slices on a pizza: " << setprecision(1) << fixed << numSlices << endl;
	cout << "total slices needed: " <<totalSlicesNeeded << endl;
	cout << "number of pizzas required: " << numPizzas << endl;
	*/

	return 0;
}