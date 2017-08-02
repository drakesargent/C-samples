#include<iostream>
#include<iomanip>
#include "NumDays.h"

using namespace std;

int main()
{
	//create objects for examples
	NumDays emp1(12);
	NumDays emp2(10);
	//create empty objects for demonstration use
	NumDays sum;
	NumDays diff;
	NumDays after;

	//show first object info
	cout << "Employee 1 Hours Entered - " << emp1.getHours() << endl;
	cout << "Employee 1 worked " << emp1.getDays() << " 8 hour days." << endl;
	cout << endl;

	//show second object info
	cout << "Employee 2 Hours Entered - " << emp2.getHours() << endl;
	cout << "Employee 2 worked " << emp2.getDays() << " 8 hour days." << endl;
	cout << endl;

	//Operator demonstrations
	//Binary math operations
	cout << "Demonstrating + operator:" << endl;
	sum = emp1 + emp2;
	cout << "The sum of Employee 1's hours entered and Emplyee 2's hours is " << sum.getHours() << endl;
	cout << "This is equals " << sum.getDays() << " 8 hour days." << endl;
	cout << endl;

	cout << "Demonstrating - opperator:" << endl;
	diff = emp1 - emp2;
	cout << "The difference of Employee 1's hours entered and Emplyee 2's hours is " << diff.getHours() << endl;
	cout << "This is equals " << diff.getDays() << " 8 hour days." << endl;
	cout << endl;

	//Unary demonstrations using loops 
	cout << "Demonstrating ++ prefix operator" << endl;
	for (int x = 0; x < 8; x++)
	{
		after = ++emp1;
		cout << "Val 1 hours: " << after.getHours() << " is " <<setw(5)<<left <<after.getDays() <<setw(13)<<left<<" in days.";
		cout << "Val 2 hours: " << emp1.getHours() << " is " << setw(5) << left << emp1.getDays() << setw(13) << left << " in days." << endl;
	}

	cout << endl;

	cout << "Demonstrating ++ postfix operator" << endl;
	for (int x = 0; x < 8; x++)
	{
		after = emp1++;
		cout << "Val 1 hours: " << after.getHours() << " is " << setw(5) << left << after.getDays() << setw(13) << left << " in days.";
		cout << "Val 2 hours: " << emp1.getHours() << " is " << setw(5) << left << emp1.getDays() << setw(13) << left << " in days." << endl;
	}
	
	cout << endl;

	cout << "Demonstrating -- prefix operator" << endl;
	for (int x = 0; x < 8; x++)
	{
		after = --emp1;
		cout << "Val 1 hours: " << after.getHours() << " is " << setw(5) << left << after.getDays() << setw(13) << left << " in days.";
		cout << "Val 2 hours: " << emp1.getHours() << " is " << setw(5) << left << emp1.getDays() << setw(13) << left << " in days." << endl;
	}

	cout << endl;

	cout << "Demonstrating -- postfix operator" << endl;
	for (int x = 0; x < 8; x++)
	{
		after = emp1--;
		cout << "Val 1 hours: " << after.getHours() << " is " << setw(5) << left << after.getDays() << setw(13) << left << " in days.";
		cout << "Val 2 hours: " << emp1.getHours() << " is " << setw(5) << left << emp1.getDays() << setw(13) << left << " in days." << endl;
	}
}