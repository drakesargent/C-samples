#include <iostream>
#include <iomanip>
#include "Payroll.h"
using namespace std;

//using a constant for the number of employee payroll objects
const int numEmps = 7;

int main()
{
	//declare payroll array with constant
	Payroll employees[numEmps];
	
	//loop through the employee array
	for (int i = 0; i < numEmps; i++)
	{
		//declare hours variable
		double hours;
		
		//set payrate
		employees[i].setHourlyPayRate(7.59);
		
		//request number of hours from user
		cout << "Enter the number of hours worked for Employee " << i + 1 << ": ";
		cin >> hours;
		
		//validate that hours entered are <= 60
		bool valid = false;
		while (!valid)
		{
			if (hours > 60)
			{
				cout << "Hours invalid. Enter a value <60 : " << endl;
				cin >> hours;
			}
			else
			{
				valid = true;
			}
		}
		//set hours worked
		employees[i].setHoursWorked(hours);
		//set gross pay
		employees[i].calcGrossPay(hours, employees[i].getHoursWorked());
	}

	cout << endl;

	//loop through each employee
	for (int i = 0; i < numEmps; i++)
	{
		//print out the amount earned gross this week
		cout << "Employee " << i + 1 << " has earned $";
		cout << fixed << setprecision(2) << showpoint << employees[i].getGrossPay();
		cout << " gross for this week." << endl;
	}

	system("pause");
	return 0;
}
