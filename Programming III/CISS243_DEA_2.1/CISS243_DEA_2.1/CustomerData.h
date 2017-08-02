// Class header for CustomerData Class
// Inherits from PersonData Class
#ifndef CUSTOMERDATA_H
#define CUSTOMERDATA_H
#include "PersonData.h"

using namespace std;

// The CustomerData Class holds an int value for the
// customer number and a boolean value for whether or
// not the customer would like to be included on the mailing list.
// The biographic information comes from the inherited PersonData
// Class.

class CustomerData : public PersonData
{
private:
	int customerNumber; // To hold customer number
	bool mailingList; // To hold mailing list inclusion
public:
	// Constructors implemented in CustomerData.cpp
	CustomerData();
	CustomerData(int cn, bool ml, string l, string f, string a, string c, string s, string z, string p);
	
	// Mutator Functions implemented in CustomerData.cpp
	void setCustomerNumber(int);
	void setMailingList(bool);

	// Accessor Functions implemented in CustomerData.cpp
	int getCustomerNumber();
	bool getMailingList();
};
#endif // !CUSTOMERDATA_H

