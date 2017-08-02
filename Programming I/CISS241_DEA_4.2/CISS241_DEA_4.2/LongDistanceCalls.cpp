/*Kenneth Drake-Sargent
*Chapter 4
*Problem 2
*Long Distance Calls
*/
/*
declare variables for starttime, number of minutes,validation, timecheck and constants for values in table
display request for start time in HH.MM format
Store start time in memory
validate loop start time
	request new start time if invalid numbers entered
	store new value in start time
	end loop
re-initialize validation loop variable
display request for the number of minutes for the call
store minutes in membory
validate loop number of minutes
	request new number of minutes if negitive value entered
	store new value in number of minutes
	end loop
re-initialize validation loop variable
if else if statements to determine start time tier and rate
perform calculation for specified tier
display result
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main() {

	float startTime;
	float numMinutes;
	bool valid = false;

	const float T1MINS = 6.59f;
	const float T2MINS = 12.59f;
	const float T3MINS = 19.00f;
	const float T4MINS = 23.59f;
	const float T1RPM = .12f;
	const float T2RPM = .23f;
	const float T3RPM = .55f;
	const float T4RPM = .35f;

	float totalCost;

	cout << "Please enter the start time of the call: ";
	cin >> startTime;

	while (!valid) {
		int hours = static_cast<int>(startTime);
		float testTime = startTime - hours;
		if (testTime > 0.599f || hours > 23) {
			cout << "\nPlease enter a valid start time: ";
			cin >> startTime;
		}
		else {
			valid = true;
		}
	}
	valid = false;
	cout << valid;
	cout << "\nPlease enter the duration of the call in minutes: ";
	cin >> numMinutes;

	while (!valid) {
		if (numMinutes < 0) {
			cout << "\nPlease enter a valid start time: ";
			cin >> numMinutes;
		}
		else {
			valid = true;
		}
	}
	valid = false;

	if (startTime <= T1MINS) {
		totalCost = numMinutes * T1RPM;
		cout << "Total cost for the call is : $" << setprecision(2) << fixed <<totalCost << endl;
	}
	else if (startTime <= T2MINS) {
		totalCost = numMinutes * T2RPM;
		cout << "Total cost for the call is : $" << setprecision(2) << fixed << totalCost << endl;
	}
	else if (startTime <= T3MINS) {
		totalCost = numMinutes * T3RPM;
		cout << "Total cost for the call is : $" << setprecision(2) << fixed << totalCost << endl;
	}
	else if (startTime <= T4MINS) {
		totalCost = numMinutes * T4RPM;
		cout << "Total cost for the call is : $" << setprecision(2) << fixed << totalCost << endl;
	}
	else {
		cout << "Something went wrong. Please try again." << endl;
	}

	return 0;
}