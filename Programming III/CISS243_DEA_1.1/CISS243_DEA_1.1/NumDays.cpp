#include <iostream>
#include "NumDays.h"

using namespace std;

//private member function definitions
double NumDays::calcDays(double hrs)
{
	double d = 0.0;
	d = hrs / 8;

	return d;
}

double NumDays::calcHours(double day)
{
	double h = 0.0;
	h = day * 8;

	return h;
}

//constructors
NumDays::NumDays(double hrs)
{
	hours = hrs;
	//set days via private function
	days = calcDays(hours);
}

NumDays::NumDays()
{
	hours = 0.0;
	days = 0.0;
}

//mutator functions
void NumDays::setHours(double hrs)
{
	hours = hrs;
	//recalculate days after hours set
	days = calcDays(hours);
}

void NumDays::setDays(double day)
{
	days = day;
	//recalculate hours after days set
	hours = calcHours(days);
}

//accessor function definitions
double NumDays::getDays()
{
	return days;
}

double NumDays::getHours()
{
	return hours;
}

//overloaded operator definitions
NumDays NumDays::operator+(const NumDays &opr)
{
	NumDays temp;

	temp.hours = hours + opr.hours;
	temp.days = calcDays(temp.hours);

	return temp;
}

NumDays NumDays::operator-(const NumDays &opr)
{
	NumDays temp;

	temp.hours = hours - opr.hours;
	temp.days = calcDays(temp.hours);

	return temp;
}

NumDays NumDays::operator++()
{
	++hours;
	days = calcDays(hours);
	return *this;
}

NumDays NumDays::operator++(int)
{
	NumDays temp(hours);
	hours++;
	days = calcDays(hours);
	return temp;
}

NumDays NumDays::operator--()
{
	--hours;
	days = calcDays(hours);
	return *this;
}

NumDays NumDays::operator--(int)
{
	NumDays temp(hours);
	hours--;
	days = calcDays(hours);
	return temp;
}