#include <iostream>
#include <string>
#include "EmployeeInfo.h"
#include "BinTree.h"

using namespace std;

// function prototype for the inital data
void loadSampleData(BinTree<EmployeeInfo> &);

int main()
{
	// declare binary tree of employeeinfo
	BinTree<EmployeeInfo> employeeTree;
	// load sample data into employee tree
	loadSampleData(employeeTree);
	
	// loop boolean
	bool loop = true;
	
	// run at least once
	do {
		// declare id hoder
		int id;
		
		// request user input
		cout << "Enter an Employee ID to search: ";
		cin >> id;
		cin.ignore(); // ignore carriage return
		
		// validate entry
		while (id < 0)
		{
			cout << "\nPlease enter a positive value: ";
			cin >> id;
			cin.ignore();
		}

		// create a test object
		EmployeeInfo test;
		// set id
		test.setEmpID(id);

		// if the employee with the testid exists
		if (employeeTree.searchNode(test))
		{
			employeeTree.copyNode(test); // copy the employee data to the test employee info object
			cout << "\nRecord found!" << endl; // display object information
			cout << "Employee #: " << test.getEmpID() << endl;
			cout << "Employee Name: " << test.getEmpName() << endl;
		}
		else // otherwise display that the employee was not found
		{
			cout << "\nEmployee with ID #" << id << " was not found." << endl;
		}

		// find out if user woul like to continue
		char choice;

		cout << "\nWould you like to look up another Employee? (Y|N): ";
		cin >> choice;
		cout << endl;

		// if they would like to run again choose break out of switch
		// and loop again
		switch (choice)
		{
		case 'Y':
		case 'y':
			break;
			// otherwise exit by setting loop to false
		case 'N':
		case 'n':
			cout << "\nThank you for using this program." << endl;
			cout << "Exiting\n" << endl;
			loop = false;
			break;
		default:
			// if an invalid choice is entered exit
			cout << "Invalid choice entered. Exiting.\n" << endl;
			loop = false;
			break;
		}

	} while (loop);

	return 0;
}

// loads sample data into the binary tree by creating employee info objects and 
// running insert node function from the binary tree
void loadSampleData(BinTree<EmployeeInfo> &et)
{
	int empIds[8] = { 1021,1057,2487,3769,1017,1275,1899,4218 };
	string empNames[8] = {"John Williams", "Bill Witherspoon", "Jennifer Twain",
		"Sophia Lancaster", "Debbie Reece", "George McMullen", "Ashley Smith", "Josh Plemmons"};

	for (int i = 0; i < 8; i++)
	{
		EmployeeInfo emp(empIds[i], empNames[i]);
		et.insertNode(emp);
	}
}

