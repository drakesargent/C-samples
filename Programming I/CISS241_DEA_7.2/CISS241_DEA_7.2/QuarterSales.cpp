/*Kenneth Drake-Sargent
*Chapter 7
*Assigment 2
*Sales Information 2D Array Processing
*/
#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

//variables
const int NUM_DIVS = 5;
const int NUM_QTRS = 5;
const int COLS = 5;

string divName[NUM_DIVS] = { "North", "South", "East", "West", "Quarter Total" };
string qtrName[NUM_QTRS] = { "Quarter 1", "Quarter 2", "Quarter 3", "Quarter 4", "Division Total" };

int salesInfo[NUM_DIVS][NUM_QTRS];

//prototypes
int getTotal(int[][COLS]);

//double for average as it is unlikely to be a whole number
double getAverage(int[][COLS]);

int getRowTotal(int[][COLS], int);
int getColumnTotal(int[][COLS], int);
int getHighest(int[][COLS], int&, int&);
int getLowest(int[][COLS], int&, int&);

//reference variables for the getHighest and getLowest functions
int hDiv;
int hQtr;
int lDiv;
int lQtr;


int main()
{
	//get sales information from the user
	for (int i = 0; i < NUM_DIVS; i++) 
	{
		for (int j = 0; j < NUM_QTRS; j++)
		{
			if (j < NUM_QTRS-1 && i < NUM_DIVS-1)
			{
				cout << "Enter sales information for "
					<< divName[i] << " " << qtrName[j]
					<< ": ";
				cin >> salesInfo[i][j];
			} 
			//at the end of each row run the get row total and store in the last column;
			else if (i < NUM_DIVS-1)
			{
				cout << endl;
				salesInfo[i][j] = getRowTotal(salesInfo, i);
			}
			else
			//at the last row get the column total and store in each cell along the last row
			{
				salesInfo[i][j] = getColumnTotal(salesInfo, j);
			}
		}
	}

	//print top of table
	cout << left << setw(15) << "";
	for (int i = 0; i < COLS; i++) 
	{
		cout << setw(15) <<qtrName[i];
	}
	cout << endl;

	//print division columns and salesInfo inner data
	for (int i = 0; i < NUM_DIVS; i++) 
	{
		cout << setw(15)<< left << divName[i];
			for (int j = 0; j < NUM_QTRS; j++)
			{
				cout << setw(15) << salesInfo[i][j];
			}

		cout << endl;
	}
	cout << endl;

	//run the getHighest and getLowest to initialize the highest and lowest reference variables
	getHighest(salesInfo, hDiv, hQtr);
	getLowest(salesInfo, lDiv, lQtr);

	//print division and quarter with the highest value
	cout << divName[hDiv] << " " << qtrName[hQtr] << " has the highest value." << endl;
	//print division and quarter with the lowest value
	cout << divName[lDiv] << " " << qtrName[lQtr] << " has the lowest value." << endl;

	return 0;
}

//function definitions
int getTotal(int sInfo[][COLS])
{
	int total = 0;

	for (int i = 0; i < NUM_DIVS - 1; i++) 
	{
		for (int j = 0; j < NUM_QTRS - 1; j++) 
		{
			total += sInfo[i][j];
		}
	}

	return total;
}

double getAverage(int sInfo[][COLS])
{
	double average = (getTotal(sInfo) / ((NUM_DIVS - 1)*(NUM_QTRS - 1)));
	return average;
}

int getRowTotal(int sInfo[][COLS], int numRow)
{
	int rTotal = 0;
	for (int i = 0; i < NUM_QTRS - 1; i++)
	{
		rTotal += sInfo[numRow][i];
	}
	return rTotal;
}

int getColumnTotal(int sInfo[][COLS], int numCol)
{
	int cTotal = 0;
	for (int i = 0; i < NUM_DIVS - 1; i++)
	{
		cTotal += sInfo[i][numCol];
	}
	return cTotal;
}

int getHighest(int sInfo[][COLS], int& HDiv, int& HQtr)
{
	int highest = sInfo[0][0];
	for (int i = 0; i < NUM_DIVS - 1; i++)
	{
		for (int j = 0; j < NUM_QTRS - 1; j++)
		{
			if (sInfo[i][j] > highest) {
				highest = sInfo[i][j];
				HDiv = i;
				HQtr = j;
			}
		}
	}
	return highest;
}

int getLowest(int sInfo[][COLS], int& LDiv, int& LQtr)
{
	int lowest = sInfo[0][0];
	for (int i = 0; i < NUM_DIVS - 1; i++)
	{
		for (int j = 0; j < NUM_QTRS - 1; j++)
		{
			if (sInfo[i][j] < lowest) {
				lowest = sInfo[i][j];
				LDiv = i;
				LQtr = j;
			}
		}
	}
	return lowest;
}