// Implementation file for CustomerData Class
#include "CustomerData.h"
using namespace std;

// Constructors
// Default constructor sets CustomerNubmber to 0
// and mailing list to false, calls PersonData default constructor
CustomerData::CustomerData() : PersonData()
{
	customerNumber = 0;
	mailingList = false;
}

// Full constructor assigns int and bool to respective CustomerData fields
// and Passes string arguments to PersonData full constructor
CustomerData::CustomerData(int cn, bool ml, string l, string f, string a, string c, string s, string z, string p) : PersonData(l, f, a, c, s, z, p)
{
	customerNumber = cn;
	mailingList = ml;
}

// Mutator function definitions
void CustomerData::setCustomerNumber(int cn)
{
	customerNumber = cn;
}
void CustomerData::setMailingList(bool ml)
{
	mailingList = ml;
}

// Accessor function definitions
int CustomerData::getCustomerNumber()
{
	return customerNumber;
}
bool CustomerData::getMailingList()
{
	return mailingList;
}