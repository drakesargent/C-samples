#pragma once
#ifndef PAYROLL_H
#define PAYROLL_H

using namespace std;

//class definition
class Payroll {
	//private fields
	private:
		double hourlyPayRate;
		double hoursWorked;
		double grossPay;
	
	//public members
	public:
		//constructor
		Payroll();
		
		//mutator functions
		void setHourlyPayRate(double);
		void setHoursWorked(double);
		void calcGrossPay(double, double);
		
		//accessor functions
		double getHourlyPayRate();
		double getHoursWorked();
		double getGrossPay();
};
#endif // !PAYROLL_H
