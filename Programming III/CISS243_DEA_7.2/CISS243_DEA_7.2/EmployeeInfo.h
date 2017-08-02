#ifndef EMPLOYEEINFO_H
#define EMPLOYEEINFO_H

#include<string>
using namespace std;

// the employee info object stores an employee ID
// and employee name with functions to evaluate
// employee info objects based on employee id
class EmployeeInfo 
{
private:
	int empID;
	string empName;

public:
	// constructors
	EmployeeInfo();
	EmployeeInfo(int, string);

	// mutator functions
	void setEmpID(int);
	void setEmpName(string);

	//accessor functions
	int getEmpID();
	string getEmpName();

	// must overload <, >, and == to use in a binary tree
	bool operator <(const EmployeeInfo &right);
	bool operator >(const EmployeeInfo &right);
	bool operator ==(const EmployeeInfo &right);

	// must overload = for copy function
	void operator =(const EmployeeInfo &right);
};

#endif
