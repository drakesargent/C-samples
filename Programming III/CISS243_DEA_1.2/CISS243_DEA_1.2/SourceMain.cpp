#include <iostream>
#include <iomanip>
#include "RoomCarpet.h"

using namespace std;

int main()
{
	//set up loop for UI
	bool again = true;
	do
	{
		//create empty room carpet object
		RoomCarpet eval;

		//declare variables
		int lFeet = 0, lInches = 0, wFeet = 0, wInches = 0;
		double costSq = 0.0, totalCost = 0.0;
		char response;
		
		//request user input for room lenght and width
		cout << "Enter the lenght of the room in feet inches (10 8): ";
		cin >> lFeet >> lInches;
		cin.ignore(); //discard endline character
		cout << "Enter the width of the room in feet inches (8 11): ";
		cin >> wFeet >> wInches;
		cin.ignore(); //discard endline character
		cout << "Enter the cost per square foot: ";
		cin >> costSq;
		cout << endl;

		//create objects from entered values

		
		//set up room dimension and cost data for roomcarpet object
		eval.setRoom(lFeet, lInches, wFeet, wInches);
		eval.setCostSqFt(costSq);

		//calculate and store total cost
		totalCost = eval.getTotalCost();
		
		//display calculation
		cout << "Total cost will be $" << setprecision(2) << fixed << totalCost << endl;

		//request user input to continue
		cout << "Do you wish to run another estimate? (Y|N): ";
		cin >> response;

		//evaluate user response, only continue if Y or y is entered
		switch (response)
		{
		case 'y':
		case 'Y':
			cout << endl;
			break;
		case 'n':
		case 'N':
		default:
			cout << endl;
			again = false;
			break;
		}
	} while (again);

	return 0;
}