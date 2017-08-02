#include <iostream>

using namespace std;
// prototype function to sum a set of numbers
int sum(int n);

int main()
{
	// test function on different sets of numbers
	for (int i = 0; i < 10; i++)
	{

		cout << "Sum int set of " << i + 1 << ": ";
		cout << sum(i + 1) << endl;
	}

	return 0;
}

// function definition accepts an int adds each number from
// one to the given int
int sum(int n)
{
	if (n==0) // base case
	{
		// when the counter is 0 end recursion
		return 0;
	}
	// add the given number to one less the given number
	// until number reaches base case
	return n + sum(n - 1);
}