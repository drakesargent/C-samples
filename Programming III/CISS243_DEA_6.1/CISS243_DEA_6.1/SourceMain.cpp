#include <iostream>

using namespace std;

// prototype template function defined below main
template <class T>
T power(T num, int exp);

int main()
{
	// testing recursive function with different numerical data types
	cout << "Double test values: " << endl;
	cout << "6.5 to the power of 3: " << power<double>(6.5, 3) << endl;
	cout << "5.2 to the power of 5: " << power<double>(5.2, 5) << endl;
	cout << "3.2 to the power of 8: " << power<double>(3.2, 8) << endl;
	
	cout << "Int test values: " << endl;
	cout << "5 to the power of 5: " << power<int>(5, 5) << endl;
	cout << "2 to the power of 8: " << power<int>(2, 8) << endl;
	cout << "3 to the power of 6: " << power<int>(3, 6) << endl;


	return 0;
}

// power function definition: accpts a user defined numerical value
// and recursively multiplies it by the submitted number until the 
// second value is reduced to 0
template <class T>
T power(T num, int exp)
{
	if (exp == 0) // base case when exponent value reaches 0
	{
		return 1;
	}
	else
	{
		// recursively call funtion using exp as a count down
		return num * power(num, exp-1); 
	}
}