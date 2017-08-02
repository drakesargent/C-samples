// Base Class header for PersonData Class
#ifndef PERSONDATA_H
#define PERSONDATA_H
#include <string>

using namespace std;

// The PersonData Class holds string values for
// biographic information attributable to a person
// including last name, first name, address, city,
// state, zip code, and phone number

class PersonData
{
private:
	// To hold biographic data
	string lastName, firstName, address, city, state, zip, phone;
public:
	// Constructors implemented in PersonData.cpp
	PersonData();
	PersonData(string l, string f, string a, string c, string s, string z, string p);

	// Mutator Functions implemented in PersonData.cpp
	void setLastName(string l);
	void setFirstName(string f);
	void setAddress(string a);
	void setCity(string c);
	void setState(string s);
	void setZip(string z);
	void setPhone(string p);

	// Accessor Functions implemented in PersonData.cpp
	string getLastName();
	string getFirstName();
	string getAddress();
	string getCity();
	string getState();
	string getZip();
	string getPhone();
};

#endif // !PERSONDATA_H
#pragma once
