/*Kenneth Drake-Sargent
*Chapter 6
*Assigment 1
*Drop Lowest Grade
*/

#include<iostream>
using namespace std;

//Declare Variables
int tval1,
	tval2,
	tval3,
	tval4,
	tval5,
	tval6;

//prototype functions
void getScore(int &);
void calcAverage(int, int, int, int, int, int);
int findLowest(int, int, int, int, int, int);

//main function
int main() {
	
	//calling get score for each variable
	getScore(tval1);
	getScore(tval2);
	getScore(tval3);
	getScore(tval4);
	getScore(tval5);
	getScore(tval6);

	//evaluating variable values and returning average of top 5
	calcAverage(tval1, tval2, tval3, tval4, tval5, tval6);

	return 0;
}

//function to get score input from user
void getScore(int &tval){
	cout << "Please enter a test score: ";
	cin >> tval;
	//validate user input
	bool valid = false;
	while (!valid) {
		if (tval < 0 || tval >100) {
			cout << "Please enter a valid test score: ";
			cin >> tval;
		}
		else {
			valid = true;
		}
	}
	valid = false;
}

//function to evaluate input print average of 5 largest valued variables
void calcAverage(int s1, int s2, int s3, int s4, int s5, int s6) {
	int sum = (s1 + s2 + s3 + s4 + s5 + s6) - findLowest(s1, s2, s3, s4, s5, s6);
	double avg = static_cast<double>(sum) / 5;
	cout << avg << endl;
}

//function to determine which is the lowest value
int findLowest(int s1, int s2, int s3, int s4, int s5, int s6) {
	int lowest = 0;
	if (s1 < s2 && s1 < s3 && s1 < s4 && s1 < s5 && s1 < s6) {
		lowest = s1;
	}
	else if (s2 < s3 && s2 < s4 && s2 < s5 && s2 < s6) {
		lowest = s2;
	}
	else if (s3 < s4 && s3 < s5 && s3 < s6) {
		lowest = s3;
	}
	else if (s4 < s5 && s4 < s6) {
		lowest = s4;
	}
	else if (s5 < s6) {
		lowest = s5;
	}
	else {
		lowest = s6;
	}
	return lowest;
}