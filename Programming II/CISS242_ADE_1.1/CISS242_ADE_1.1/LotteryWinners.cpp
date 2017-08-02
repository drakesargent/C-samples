/*
Kenneth Drake-Sargent
Chapter 8
Assignment 1
Lottery Winners
*/

#include <iostream>
using namespace std;

//variables
const int NUM_ELEMENTS = 10;
int luckyTicket[NUM_ELEMENTS] = { 13579, 62483, 26791, 77777, 26792,
79422, 33445, 85647, 55555, 93121 };
int winningNumber,
sListPos,
bSearchPos;

//prototypes of functions
int searchList(const int[], int, int);
int binarySearch(const int[], int, int);
void selectionSort(int[], int);

int main()
{
	//request user input for winning number
	cout << "Enter this week's 5-digit winning number: ";
	cin >> winningNumber;

	//run search list and store returned value
	sListPos = searchList(luckyTicket, NUM_ELEMENTS, winningNumber);
	
	//sort the ticket array for the binary search
	selectionSort(luckyTicket, NUM_ELEMENTS);
	
	//run binary search and store returned value
	bSearchPos = binarySearch(luckyTicket, NUM_ELEMENTS, winningNumber);

	//evaluate returned values
	if (sListPos > -1 && bSearchPos > -1)
	{
		cout << "We have a winner." << endl;
		cout << "Search List array element " << sListPos << endl;
		cout << "Binary Search array element " << bSearchPos << endl;
	}
	else
	{
		cout << "No winning match found." << endl;
		cout << "Search List returned " << sListPos << endl;
		cout << "Binary Search returned " << bSearchPos << endl;
	}
}

int searchList(const int list[], int numElems, int value)
{
	int index = 0,
		position = -1;
	bool found = false;

	while (index < numElems && !found)
	{
		if (list[index] == value)
		{
			found = true;
			position = index;
		}
		index++;
	}
	return position;
}

//must use array sort before use of binarySearch
int binarySearch(const int array[], int numElements, int value)
{
	int first = 0,
		last = numElements - 1,
		middle,
		position = -1;
	bool found = false;

	while (!found && first <= last)
	{
		middle = (first + last) / 2;
		if (array[middle] == value)
		{
			found = true;
			position = middle;
		}
		else if (array[middle] > value)
		{
			last = middle - 1;
		}
		else
			first = middle + 1;
	}
	return position;
}

void selectionSort(int array[], int size)
{
	int startScan, minIndex, minValue;

	for (startScan = 0; startScan < (size - 1); startScan++)
	{
		minIndex = startScan;
		minValue = array[startScan];
		for (int index = startScan + 1; index < size; index++)
		{
			if (array[index] < minValue)
			{
				minValue = array[index];
				minIndex = index;
			}
		}
		array[minIndex] = array[startScan];
		array[startScan] = minValue;
	}
}