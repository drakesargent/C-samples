#include <iostream>
#include <iomanip>
#include "Employee.h"
using namespace std;

//prototype function
void displayEmployee(Employee* const e);

int main()
{
	//declare employee variables
	
	//constructor with full data
	Employee e1("Susan Meyers", 47899, "Accounting", "Vice President");
	
	//constructor with partial data
	Employee e2("Mark Jones", 39119);
	//using mutator functions to add in remaining information
	e2.setDepartment("IT");
	e2.setPosition("Programmer");
	
	//constructor with no data
	Employee e3;
	//using mutator functions for each field
	e3.setName("Joy Rogers");
	e3.setId(81774);
	e3.setDepartment("Manufacturing");
	e3.setPosition("Engineer");	
	
	//display table header
	cout << setw(25) << left;
	cout << "Name";
	cout << setw(25) << left;
	cout << "ID Number";
	cout << setw(25) << left;
	cout << "Department";
	cout << setw(25) << left;
	cout << "Position";
	cout << endl;
	for (int i = 0; i<100; i++)
	{
		cout << "_";
	}
	cout << endl;
	
	//display employee object information with these functions
	displayEmployee(&e1);
	displayEmployee(&e2);
	displayEmployee(&e3);
	
	//close program
	system("pause");
	return 0;
}

//define function
void displayEmployee(Employee* const e)
{
	//iomanip to set field widths
	cout << setw(25) << left;
	//return field information via accessor functions
	cout << e->getName();
	cout << setw(25) << left;
	cout << e->getId();
	cout << setw(25) << left;
	cout << e->getDepartment();
	cout << setw(25) << left;
	cout << e->getPosition();
	cout << endl;
	cout << endl;
}

