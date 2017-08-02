// Implementation file for PersonData Class
#include "PersonData.h"
using namespace std;

// Constructors
// Default constructor sets all string variables to empty string
PersonData::PersonData()
{
	lastName = "";
	firstName = "";
	address = "";
	city = "";
	state = "";
	zip = "";
	phone = "";
}

// Full constructor arguments assigned to appropriate member variables
PersonData::PersonData(string l, string f, string a, string c, string s, string z, string p)
{
	lastName = l;
	firstName = f;
	address = a;
	city = c;
	state = s;
	zip = z;
	phone = p;
}

// Mutator function definitions
void PersonData::setLastName(string l)
{
	lastName = l;
}
void PersonData::setFirstName(string f)
{
	firstName = f;
}
void PersonData::setAddress(string a)
{
	address = a;
}
void PersonData::setCity(string c)
{
	city = c;
}
void PersonData::setState(string s)
{
	state = s;
}
void PersonData::setZip(string z)
{
	zip = z;
}
void PersonData::setPhone(string p)
{
	phone = p;
}

// Accessor function definitions
string PersonData::getLastName()
{
	return lastName;
}
string PersonData::getFirstName() 
{
	return firstName;
}
string PersonData::getAddress()
{
	return address;
}
string PersonData::getCity()
{
	return city;
}
string PersonData::getState()
{
	return state;
}
string PersonData::getZip()
{
	return zip;
}
string PersonData::getPhone()
{
	return phone;
}