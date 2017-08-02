/*Kenneth Drake-Sargent
*Chapter 7
*Assigment 1
*Rainfall Array Processing
*/
#include <iostream>
#include <string>

using namespace std;

//array size constant
const int NUM_MONTHS = 12;
//variable declarations
int lowestIndex = 0;
int highestIndex = 0;
double average;
double total;

double rainfall[NUM_MONTHS];
const string MONTHS[NUM_MONTHS] =
{
	"January", "February", "March", "April", "May", "June",
	"July", "August", "September", "October", "November", "December"
};

//function prototypes
double getTotal(double[], int);
double getAverage(double[], int);
double getLowest(double[], int, int&);
double getHighest(double[], int, int&);


int main() 
{
	//request rainfall for each month
	for (int i = 0; i < NUM_MONTHS; i++) {
		cout << "Enter the amount of rainfall for " << MONTHS[i] << ":";
		cin >> rainfall[i];
	}
	//begin to display data
	cout << endl;
	cout << "Total rainfall: "<<getTotal(rainfall, NUM_MONTHS) << endl; 
	cout << "Average rainfall: "<<getAverage(rainfall, NUM_MONTHS) << endl; 
	
	//run highest and lowest calculations
	getLowest(rainfall, NUM_MONTHS, lowestIndex);
	getHighest(rainfall, NUM_MONTHS, highestIndex);
	
	//display results with indexes set
	cout << "Month with lowest rainfall: " << MONTHS[lowestIndex] << endl; 
	cout << "Month with highest rainfall: "<< MONTHS[highestIndex] << endl; 

	return 0;
}

//process through rainfall array adding each value to total, returning total
double getTotal(double rfall[], int numMonths)
{
	double Total = 0.0;
	for (int i = 0; i < numMonths; i++)
	{
		Total += rfall[i];
	}

	return Total;
}

//call get total and divide by number of months for average
double getAverage(double rfall[], int numMonths)
{
	double Average = getTotal(rfall, numMonths) / numMonths;
	
	return Average;
}

//determine lowest set lIndex to the index containing lowest value
double getLowest(double rfall[], int numMonths, int& lIndex)
{
	double lowest = rfall[0];
	for (int i = 0; i < numMonths; i++) {
		if (rfall[i] < lowest) {
			lowest = rfall[i];
			lIndex = i;
		}
	}
	return lowest;
}
//determine highest set hIndex to the index containing the highest value
double getHighest(double rfall[], int numMonths, int& hIndex)
{
	double highest = rfall[0];
	for (int i = 0; i < numMonths; i++) {
		if (rfall[i] > highest) {
			highest = rfall[i];
			hIndex = i;
		}
	}
	return highest;
}