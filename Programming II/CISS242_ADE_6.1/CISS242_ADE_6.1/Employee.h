#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include<string>
using namespace std;

class Employee
{
	//private class members
private:
	//field variable declarations
	string name;
	int idNumber;
	string department;
	string position;

	//public class members
public:
	//constructors
	//default constructor setting default values for all fields
	Employee()
	{
		name = "";
		idNumber = 0;
		department = "";
		position = "";
	}
	//partial information constructor setting default values for some fields
	Employee(string n, int id)
	{
		name = n;
		idNumber = id;
		department = " ";
		position = " ";
	}
	//full information constructor setting all fields to provided values
	Employee(string n, int id, string dep, string pos)
	{
		name = n;
		idNumber = id;
		department = dep;
		position = pos;
	}

	//mutator classes
	void setName(string n)
	{
		name = n;
	}
	void setId(int id)
	{
		idNumber = id;
	}
	void setDepartment(string dep)
	{
		department = dep;
	}
	void setPosition(string pos)
	{
		position = pos;
	}

	//accessor classes
	string getName() const
	{
		return name;
	}
	int getId() const
	{
		return idNumber;
	}
	string getDepartment() const
	{
		return department;
	}
	string  getPosition() const
	{
		return position;
	}
};
#endif
