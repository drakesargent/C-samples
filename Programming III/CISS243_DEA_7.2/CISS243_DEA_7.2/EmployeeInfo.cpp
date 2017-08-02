#include "EmployeeInfo.h"

// constructors
// default constructor sets id to 0 and name to an empty string
EmployeeInfo::EmployeeInfo()
{
	empID = 0;
	empName = "";
}

// fully attributed constructor sets both id and name
EmployeeInfo::EmployeeInfo(int id, string name)
{
	empID = id;
	empName = name;
}

// mutator functions
// sets employee id
void EmployeeInfo::setEmpID(int id)
{
	empID = id;
}
// sets employee name
void EmployeeInfo::setEmpName(string name)
{
	empName = name;
}

// accessor functions
// returns employee id
int EmployeeInfo::getEmpID()
{
	return empID;
}
// returns employee name
string EmployeeInfo::getEmpName()
{
	return empName;
}

// Overload for binary tree compairing empIDs for structure organization
// overload for <
bool EmployeeInfo::operator <(const EmployeeInfo &right)
{
	bool status;

	if (empID < right.empID)
	{
		status = true;
	}
	else
	{
		status = false;
	}

	return status;
}

// overload for >
bool EmployeeInfo::operator >(const EmployeeInfo &right)
{
	bool status;

	if (empID > right.empID)
	{
		status = true;
	}
	else
	{
		status = false;
	}

	return status;
}

// overload for ==
bool EmployeeInfo::operator ==(const EmployeeInfo &right)
{
	bool status;

	if (empID == right.empID)
	{
		status = true;
	}
	else
	{
		status = false;
	}

	return status;
}

// overload for =
void EmployeeInfo::operator =(const EmployeeInfo &right)
{
	empID = right.empID;
	empName = right.empName;
}