#include<iostream>
#include "Payroll.h"

using namespace std;

//default constructor setting values to 0
Payroll::Payroll() 
{
	hoursWorked = 0.0;
	hourlyPayRate = 0.0;
	grossPay = 0.0;
}

//mutator functions
void Payroll::setHourlyPayRate(double rate)
{
	hourlyPayRate = rate;
}

void Payroll::setHoursWorked(double hours)
{
	hoursWorked = hours;
}

//calculated fields should be returned values rather than assigned to variables.
//following instructions from the assignment
void Payroll::calcGrossPay(double hours, double rate)
{
	grossPay = hours * rate;
}

//accessor functions
double Payroll::getHourlyPayRate()
{
	return hourlyPayRate;
}

double Payroll::getHoursWorked()
{
	return hoursWorked;
}

double Payroll::getGrossPay()
{
	return grossPay;
}