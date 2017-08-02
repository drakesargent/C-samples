// Main function used to test customer data objects
#include <iostream>
#include <iomanip>
#include "CustomerData.h"

using namespace std;

// Prototype function to display formatted customer data on the screen
void displayCustomer(CustomerData c);

int main()
{
	// Declaring CustomerData object using default constructor
	CustomerData c1;
	// Using mutator functions to set all field values
	c1.setCustomerNumber(10001);
	c1.setMailingList(false);
	c1.setLastName("Stark");
	c1.setFirstName("Tony");
	c1.setAddress("10880 Malibu Point");
	c1.setCity("Malibu");
	c1.setState("CA");
	c1.setZip("90265");
	c1.setPhone("310-555-9212");
	
	//Declaring CustomerData object using full argument constructor
	CustomerData c2(10002, true, "Quill", "Peter", "132 Elm St", "Columbus", "OH", "43004", "614-555-6980");

	//Using displayCustomer function to test object creation
	displayCustomer(c1);
	displayCustomer(c2);

	return 0;
}

// Function definition
void displayCustomer(CustomerData c)
{
	// Using class Accessor functions to return formatted object information
	cout << setw(20) << left << "Customer Number: " << c.getCustomerNumber() << endl;
	cout << setw(20) << left << "Customer Name: " << c.getLastName();
	cout << ", " << c.getFirstName() << endl;
	cout << setw(20) << left << "Address: " << c.getAddress() << endl;
	cout << setw(20) << left << "" << c.getCity() << ", " << c.getState();
	cout << " " << c.getZip() << endl;
	cout << setw(20) << left << "Phone: " << c.getPhone() << endl;
	cout << setw(20) << left << "Mailing List: "; 
	//testing mail list field boolean to return yes or no as string text
	if (c.getMailingList() == 1)
	{
		cout << "Yes";
	}
	else
	{
		cout << "No";
	}
	cout << endl;
	cout << endl;
}