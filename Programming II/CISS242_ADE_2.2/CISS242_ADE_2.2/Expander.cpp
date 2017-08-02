/*
Kenneth Drake-Sargent
Chapter 9
Assignment 2
Array Expander
*/

#include <iostream>
using namespace std;

//function prototypes
int* expandArray(int[], int);
void showArray(int[], int);

int main()
{
	//variables
	int arr1[] = { 1, 2, 3, 4, 5 };
	int arrSize = 5;
	int* ptr = nullptr;

	//assign pointer to new array
	ptr = expandArray(arr1, arrSize);
	
	//print new array
	showArray(ptr, arrSize*2);

	//clear pointer memory space
	delete[] ptr;
	ptr = nullptr;

	system("pause");
	return 0;
}
//functions
int* expandArray(int arr[], int size)
{
	int* newArr = nullptr;
	int doubSize = size * 2;

	newArr = new int[doubSize];

	for (int i = 0; i < size; i++)
	{
		newArr[i] = arr[i];
	}
	for (int i = size; i < doubSize; i++)
	{
		newArr[i] = 0;
	}

	return newArr;
}

void showArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout <<endl;
}