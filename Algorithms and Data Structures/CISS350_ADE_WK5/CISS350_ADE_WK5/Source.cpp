#include <iostream>
using namespace std;

// proto type declaration function for recursive call
void towerH(int, char, char, char, int&);

int main()
{
	// initial value for steps
	int step_count = 0;
	// variable container for number of disks
	int disks;
	// requesting input from user for num disks
	cout << "How many disks would you like to use? ";
	cin >> disks;
	cin.ignore();

	towerH(disks, 'A', 'Z', 'K', step_count);
	return 0;
}

void towerH(int numDisks, char start, char end, char middle, int &count)
{
	// Base case which moves smallest possible disk
	if (numDisks == 1)
	{
		count++;
		cout << "Step " << count << ": Move disk " << numDisks << " from peg " << start << " to peg " << end << endl;
	}
	else
	{	// this executes recursively to base case where the "start" is start, and "end" is middle
		towerH(numDisks - 1, start, middle, end, count);

		// move the largest disk on start to the end peg
		count++;
		cout << "Step " << count << ": Move disk " << numDisks << " from peg " << start << " to peg " << end << endl;

		// move from the middle starting at the smallest over to the end
		towerH(numDisks - 1, middle, end, start, count);
	}
}