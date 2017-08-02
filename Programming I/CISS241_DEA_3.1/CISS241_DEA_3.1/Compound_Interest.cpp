/*Kenneth Drake-Sargent
*Chapter 2
*Problem 1
*Compound Interest
*/
/*
Declare variables for principal, interest rate, number of times compounded
	interest amount, and new balance
Display request to input principal
Store value in principal variable
Display request to input interest rate
Store value in interest rate variable
Display request to input number of times compounded
Store value in number of times compounded variable

Perform calculation for Interest
Store in interest amount variable
Perform calculation for new balance
Store in new balance variable

Display formatted interest rate, times compounded, principal, interest, and
	amount in savings
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	//declare variables
	double principal, 
		interestRate, 
		xCompounded, 
		interestAmount, 
		newBalance;

	//request and store user input
	cout << "Please enter in the principal amount." << endl;
	cin >> principal;
	cout << "Please enter in the interest rate." << endl;
	cin >> interestRate;
	cout << "Please enter in the number of times compounded." << endl;
	cin >> xCompounded;

	//perform and store calculations
	interestRate = interestRate / 100;
	newBalance = principal * pow((1+(interestRate / xCompounded)), xCompounded);
	interestAmount = newBalance - principal;
	interestRate = interestRate * 100;

	//display formatted results
	cout << endl;
	cout <<"Interest Rate: " << setw(19) << interestRate << "%" << endl;
	cout <<"Times Compounded: " << setw(17) << xCompounded << endl;
	cout <<"Principal: " << setw(13) << "$" << setw(11) << showpoint << principal << endl;
	cout <<"Interest: " << setw(14) << "$" << setw(11) << setprecision(4) << interestAmount << endl;
	cout <<"Amount in Savings: " << setw(5) <<"$"<< setw(11) << setprecision(6) <<newBalance << endl;
	return 0;
}