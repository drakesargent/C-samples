#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

//structure definition
struct Division
{
	string name;
	double quarters[4];
	double avgQtr;
	double annSales;
};

//prototype functions
void DisplayCorpInformation(const Division&, const Division&, const Division&, const Division&);
void FindTotalAndAverageSales(Division&);
void GetDivisionSales(Division&);
//prototype validation
void validate(Division&, int);

//variable declaration for divisions
Division divs[4];
//division names array and enumeration
string dnames[4] = { "East", "West","North","South" };
enum Div {EAST, WEST, NORTH, SOUTH};
//quarter enumeration
enum Qtrs {FIRST, SECOND, THIRD, FOURTH};
int index;

int main()
{
	//loop to assign names, get sales data, and run totals and averages
	for (index = EAST; index <= SOUTH; index++)
	{
		divs[index].name = dnames[index];
		GetDivisionSales(divs[index]);
		FindTotalAndAverageSales(divs[index]);
	}

	//display information
	DisplayCorpInformation(divs[EAST], divs[WEST], divs[NORTH], divs[SOUTH]);

	system("pause");
	return 0;
}

//function descriptions
void DisplayCorpInformation(const Division &east, const Division &west, const Division &north, const Division &south)
{
	//print out annual sales data for each division
	cout << "Total Annual Sales: " << endl;
	cout << "\t" << east.name << " Division: $";
	cout << fixed << showpoint << setprecision(2);
	cout << east.annSales <<endl;
	cout << "\t" << west.name << " Division: $";
	cout << fixed << showpoint << setprecision(2);
	cout << west.annSales << endl; 
	cout << "\t" << north.name << " Division: $";
	cout << fixed << showpoint << setprecision(2);
	cout << north.annSales << endl; 
	cout << "\t" << south.name << " Division: $";
	cout << fixed << showpoint << setprecision(2);
	cout << south.annSales << endl;
	//print out average sales data for each division
	cout << "Average Quarterly Sales: " << endl;
	cout << "\t" << east.name << " Division: $";
	cout << fixed << showpoint << setprecision(2);
	cout << east.avgQtr << endl;
	cout << "\t" << west.name << " Division: $";
	cout << fixed << showpoint << setprecision(2);
	cout << west.avgQtr << endl;
	cout << "\t" << north.name << " Division: $";
	cout << fixed << showpoint << setprecision(2);
	cout << north.avgQtr << endl;
	cout << "\t" << south.name << " Division: $";
	cout << fixed << showpoint << setprecision(2);
	cout << south.avgQtr << endl;
}
void FindTotalAndAverageSales(Division &div)
{
	//initialize annual sales variable
	div.annSales = 0.0;

	//loop through each quarter adding it to the annual sales variable
	for (int i = 0; i < 4; i++)
	{
		div.annSales += div.quarters[i];
	}

	//initalize the average sales variable with the annual sales divided by the number of quarters
	div.avgQtr = div.annSales / 4;
}
void GetDivisionSales(Division &div)
{
	//print user entry prompt
	cout << "Enter the quarterly sales for the " << div.name << " Division:" << endl;
	//loop through each quarter
	for (int i = 0; i < 4; i++)
	{
		cout << "\t";
		switch (i)
		{
		case FIRST:
			cout << "First ";
			break;
		case SECOND:
			cout << "Second ";
			break;
		case THIRD:
			cout << "Third ";
			break;
		case FOURTH:
			cout << "Fourth ";
			break;
		default:
			break;
		}
		cout << "Quarter: ";
		cin >> div.quarters[i];
		//validate each quarter's input
		validate(div, i);
	}
}

void validate(Division &div, int qtr)
{
	bool valid = false;
	while (!valid)
	{
		if (div.quarters[qtr] < 0)
		{
			cout << "Please enter a positive sales value: ";
			cin >> div.quarters[qtr];
		}
		else
		{
			valid = true;
		}
	}
}