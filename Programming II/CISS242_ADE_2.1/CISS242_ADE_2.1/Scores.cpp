/*
Kenneth Drake-Sargent
Chapter 9
Assignment 1
Scores
*/
#include <iostream>
#include <iomanip>
using namespace std;

//prototype functions
void getGrades(double*, int);
void displayGrades(double*, int, double);
void sort(double*, int);
double average(double*, int);

int main()
{
	//variables
	double* scores = nullptr,
		avg;
	int numScores;
	bool valid = false;

	//get number of scores to be entered
	cout << "How many sores will you be entering? ";
	cin >> numScores;
	
	//validate number of test scores
	while (!valid)
	{
		if (numScores < 0)
		{
			cout << "Please enter a number 0 or greater. ";
			cin >> numScores;
		}
		else
		{
			valid = true;
		}
	}
	//reset validation
	valid = false;

	//initialize scores pointing to new dynamically sized array address
	scores = new double[numScores];

	//call get grades function
	getGrades(scores, numScores);
	
	//call sort function
	sort(scores, numScores);
	
	//get and store the average
	avg = average(scores, numScores);

	//display the results
	displayGrades(scores, numScores, avg);

	//clear memory space
	delete[] scores;
	scores = nullptr;

	//pause
	system("Pause");
	return 0;
}

//functions
void getGrades(double* score, int size)
{
	for (int i = 0; i < size; i++)
	{
		bool valid = false;
		cout << "Enter score " << i + 1 << ": ";
		cin >> *(score + i);
		//validate score grade
		while (!valid)
		{
			if (*(score+i) < 0)
			{
				cout << "Please enter a number 0 or greater. ";
				cin >> *(score+i);
			}
			else
			{
				valid = true;
			}
		}
		//reset validation
		valid = false;
	}
}

void displayGrades(double* score, int size, double avg)
{
	cout << fixed << showpoint << setprecision(2);
	cout << "Scores: " << endl;
	for (int i = 0; i < size; i++)
	{
		cout << *(score+i) << endl;
	}
	cout << "Average Score: ";
	cout << avg << endl;
}

void sort(double* score, int size) 
{
	int startScan, minIndex;
	double minElem;
	for (startScan = 0; startScan < (size - 1); startScan++)
	{
		minIndex = startScan;
		minElem = *(score+startScan);
		for (int index = startScan + 1; index < size; index++)
		{
			if (*(score+index) < minElem)
			{
				minElem = *(score+index);
				minIndex = index;
			}
			*(score+minIndex) = *(score+startScan);
			*(score+startScan) = minElem;
		}
	}
}

double average(double* score, int numScores)
{
	double average = 0.0;
	double sum = 0.0;
	for (int i = 0; i < numScores; i++)
	{
		sum += *(score+i);
	}
	average = sum / numScores;
	return average;
}