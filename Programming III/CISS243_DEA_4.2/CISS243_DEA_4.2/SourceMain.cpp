#include <iostream>
#include <string>
#include "WeatherStats.h"
#include "LList.cpp"

using namespace std;
// prototype function to display min and max values
void displayMinMax(LList<WeatherStats>);

int main()
{
	// variables
	int numMonths = 0; // to hold user supplied number of months
	LList<WeatherStats> months; // to hold WeatherStats objects in linked list
	
	// request user input
	cout << "For how many months do you wish to enter weather statistics? ";
	cin >> numMonths; // store in int variable
	cin.ignore(); // to ignore next line 

	// loop for the number of months indicated
	for (int i =0; i<numMonths; i++)
	{
		// variables for the WeatherStats objects
		double r, s;
		int ns;

		// Request User Input for each variable
		cout << "Month " << i + 1 << "- " << "Enter the amount of rainfall: ";
		cin >> r;
		cout << "Month " << i + 1 << "- " << "Enter the amount of snowfall: ";
		cin >> s;
		cout << "Month " << i + 1 << "- " << "Enter the number of sunny days: ";
		cin >> ns;
		cin.ignore();
		cout << endl;

		// Create a new object with the supplied values
		WeatherStats entry(r, s, ns);
		// append object to the linked list object
		months.appendNode(entry);
	}

	// demonstrate linked list display
	months.displayList();

	cout << endl;

	// demonstrate function display min max
	displayMinMax(months);
	
	return 0;
}

// function description takes linked list for weatherstats object
// evaluates each list entry for the min and max of each object field
// prints the min and max months to the screen

void displayMinMax(LList<WeatherStats> lPtr)
{
	// get the number of nodes in the list
	int numNodes = lPtr.numNodes();
	// create container objects
	WeatherStats lowest, highest, test;
	
	// lowest rain
	// if there aren't any nodes in the list, exit
	if (numNodes == 0)
	{
		return;
	}

	// set lowest as the first in the list
	lowest = lPtr.returnVal(0);

	// loop to test each node against eachother
	for (int i = 0; i < numNodes; i++)
	{
		// make sure test value isn't out of scope
		if ((i + 1) < numNodes)
		{
			// set test value
			test = lPtr.returnVal(i + 1);
		}
		// if lowest value is greater than test value lowest is now test
		if (lowest.getRain() > test.getRain())
		{
			lowest = test;
		}
	}
	// print out the lowest
	cout << "Lowest Rain Fall Month: " << 1+lPtr.searchList(lowest) << " with " << lowest.getRain() << " units."<<endl;
	
	// highest rain
	// set highest as the first in the list
	highest = lPtr.returnVal(0);

	// loop to test each node against eachother
	for (int i = 0; i < numNodes; i++)
	{
		// make sure test value isn't out of scope
		if ((i + 1) < numNodes)
		{
			// set test value
			test = lPtr.returnVal(i + 1);
		}
		// if highest value is less than test value highest is now test
		if (highest.getRain() < test.getRain())
		{
			highest = test;
		}
	}

	// if lowest value is greater than test value lowest is now test
	cout << "Highest Rain Fall Month: " << 1+lPtr.searchList(highest) << " with " << highest.getRain() << " units." << endl;

	// lowest snow
	// as above description throughout for each object field
	lowest = lPtr.returnVal(0);

	for (int i = 0; i < numNodes; i++)
	{
		if ((i + 1) < numNodes)
		{
			test = lPtr.returnVal(i + 1);
		}
		if (lowest.getSnow() > test.getSnow())
		{
			lowest = test;
		}
	}

	cout << "Lowest Snow Fall Month: " << 1 + lPtr.searchList(lowest) << " with " << lowest.getSnow() << " units." << endl;

	// highest snow

	highest = lPtr.returnVal(0);

	for (int i = 0; i < numNodes; i++)
	{
		if ((i + 1) < numNodes)
		{
			test = lPtr.returnVal(i + 1);
		}
		if (highest.getSnow() < test.getSnow())
		{
			highest = test;
		}
	}

	cout << "Highest Snow Fall Month: " << 1 + lPtr.searchList(highest) << " with " << highest.getSnow() << " units." << endl;

	// lowest sunny days

	lowest = lPtr.returnVal(0);

	for (int i = 0; i < numNodes; i++)
	{
		if ((i + 1) < numNodes)
		{
			test = lPtr.returnVal(i + 1);
		}
		if (lowest.getNumSunny() > test.getNumSunny())
		{
			lowest = test;
		}
	}

	cout << "Lowest Number of Sunny Days Month: " << 1 + lPtr.searchList(lowest) << " with " << lowest.getNumSunny() << " units." << endl;

	// highest rain

	highest = lPtr.returnVal(0);

	for (int i = 0; i < numNodes; i++)
	{
		if ((i + 1) < numNodes)
		{
			test = lPtr.returnVal(i + 1);
		}
		if (highest.getNumSunny() < test.getNumSunny())
		{
			highest = test;
		}
	}

	cout << "Highest Number of Sunny Days Month: " << 1 + lPtr.searchList(highest) << " with " << highest.getNumSunny() << " units." << endl;

}