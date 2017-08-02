#ifndef NUMDAYS_H
#define NUMDAYS_H

using namespace std;

//Class declaration
class NumDays
{
private:
	//class fields
	double days;
	double hours;
	//private class functions
	double calcDays(double hrs);
	double calcHours(double day);

public:
	//constructors
	NumDays(double hrs);
	NumDays();

	//mutator functions
	void setHours(double hrs);
	void setDays(double day);
	
	//accessor functions
	double getHours();
	double getDays();

	//operator overloads
	NumDays operator + (const NumDays &);
	NumDays operator - (const NumDays &);
	NumDays operator ++ ();
	NumDays operator -- ();
	NumDays operator ++ (int);
	NumDays operator -- (int);
};
#endif // !NUMDAYS_H

