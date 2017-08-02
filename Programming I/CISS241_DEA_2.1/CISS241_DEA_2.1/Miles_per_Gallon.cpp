/*Kenneth Drake-Sargent
*CISS241_DEA
*Chapter 2
*Miles per Gallon
*/
/*
Determine and print Miles-per-Gallon for town and highway
Given 16 gallon tank size
Average of 345 miles in town
Average of 460 miles on highway

Declare double variables for tank size, town miles, highway miles, miles per gallon town, and miles per gallon highway
Perform MPG calculation for town and highway storing the value in the respective variable
Print the results to the console
*/
#include <iostream>
using namespace std;

int main() 
{
	//declaring variables for the problem
	double tankSize, avgMilesTown, avgMilesHighway, mpgTown, mpgHighway;

	//initializing known values
	tankSize = 16;
	avgMilesTown = 345;
	avgMilesHighway = 460;

	//performing calculations to store into remaining variables
	mpgTown = avgMilesTown / tankSize;
	mpgHighway = avgMilesHighway / tankSize;

	//printing results of calculations
	cout << "The average miles per gallon when traveling in town is " << mpgTown << "." << endl;
	cout << "The average miles per gallon when traveling by highway is " << mpgHighway << "." << endl;

	return 0;
}

