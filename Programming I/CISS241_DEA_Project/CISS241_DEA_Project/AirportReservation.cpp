/*Kenneth Drake-Sargent
*Course Project
*Airplane Flight Reservation
*/

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

//constants
const int F_CLASS_COLS = 4;
const int M_CABIN_COLS = 6;
const int F_CLASS_ROWS = 5;
const int M_CABIN_ROWS = 10;
const int TOTAL_ROWS = F_CLASS_ROWS + M_CABIN_ROWS;

//variables
bool fClassCabin[F_CLASS_ROWS][F_CLASS_COLS];
bool mainCabin[M_CABIN_ROWS][M_CABIN_COLS];
int fCLASSCOLS[] = { 1,2,3,4 };
int mCABINCOLS[] = { 1,2,3,4,5,6 };
const int fCLASSROWS[] = { 1,2,3,4,5 };
const int mCABINROWS[] = { 1,2,3,4,5,6,7,8,9,10 };
double rowPrices[TOTAL_ROWS];
double orderTotal = 0.0;
double salesTotal = 0.0;
int fCTotals = 0;
int mCTotals = 0;
int selRow = 0;
int selCol = 0;

//files
string pricesFName = "rowPrices.txt";
string planeSeatsFName = "planeSeats.txt";
fstream inputFile;
ofstream outputFile;

//prototypes
void displaySeats(bool[][F_CLASS_COLS],bool[][M_CABIN_COLS]);
void printHeads(int[], int);
void printSeats(bool[], int);
char seatChar(bool seat);
void seatsAvailable(bool[][F_CLASS_COLS], int&);//int& add to number of seats available
void seatsAvailable(bool[][M_CABIN_COLS], int&);//int& add to number of seats available
void seatsSold(bool[][F_CLASS_COLS], int&);//int& add to number of seats sold
void seatsSold(bool[][M_CABIN_COLS], int&);//int& add to number of seats sold
void emptySeatsRow(bool[][F_CLASS_COLS], bool[][M_CABIN_COLS]);
void displayMenu();
void reserveSeat(bool[][F_CLASS_COLS], bool[][M_CABIN_COLS], int&, int&);
void totalPlaneSales(bool[][F_CLASS_COLS], bool[][M_CABIN_COLS], double[] ,double&);
void savePlaneData(bool[][F_CLASS_COLS], bool[][M_CABIN_COLS]);
void resetPlaneData(bool[][F_CLASS_COLS], bool[][M_CABIN_COLS]);



int main()
{
	//load Row Prices
	int count = 0;
	inputFile.open(pricesFName);
	while (count < TOTAL_ROWS && inputFile >> rowPrices[count]) 
	{
		count++;
	}
	inputFile.close();

	//load Seats
	
	inputFile.open(planeSeatsFName);
	for (int i = 0; i < F_CLASS_ROWS; i++)
	{
		count = 0;
		for (int j = 0; j < F_CLASS_COLS; j++) {
			while (count < F_CLASS_COLS && inputFile >> fClassCabin[i][count])
			{
				count++;
			}
		}
	}
	for (int i = 0; i < M_CABIN_ROWS; i++)
	{
		count = 0;
		for (int j = 0; j < M_CABIN_COLS; j++) {
			while (count < M_CABIN_COLS && inputFile >> mainCabin[i][count])
			{
				count++;
			}
		}
	}
	inputFile.close();
	


	displayMenu();
	
	return 0;
}

//Functions

//accepts a columns array and the number of columns
void printHeads(int cc[], int cols)
{
	//divides 
	int half = cols / 2;

	for (int i = 0; i < half; i++)
	{
		cout << cc[i] << " ";
	}
	
	cout << setw(2)<<" ";
	
	for (int i = half; i < cols; i++)
	{
		if (i < 3) {
			cout << "  ";
		}
		cout << cc[i] << " ";
	}

}
//used in the displaySeats function
void printSeats(bool cc[], int cols)
{
	//divides 
	int half = cols / 2;

	for (int i = 0; i < half; i++)
	{
		cout << seatChar(cc[i]) << " ";
	}

	cout << setw(2) << " ";

	for (int i = half; i < cols; i++)
	{
		if (i < 3) {
			cout << "  ";
		}
		cout << seatChar(cc[i]) << " ";
	}

}
//used to create the char value for the t/f value for seat occupation
char seatChar(bool seat) {
	if (seat) {
		return '#';
	}
	else
	{
		return '*';
	}
}
//displays map of the plane and empty/full seats
void displaySeats(bool fC[][F_CLASS_COLS], bool mC[][M_CABIN_COLS]) 
{
	cout << "---------------------------------------------------" << endl;
	cout << setw(10) << " ";
	printHeads(fCLASSCOLS, F_CLASS_COLS);
	cout << endl;

	for (int i = 0; i < F_CLASS_ROWS; i++)
	{
		cout << setw(2) << left << "Row " << setw(6) << fCLASSROWS[i];
		printSeats(fC[i], F_CLASS_COLS);
		cout << endl;
	}
	
	cout << setw(10) << " ";
	printHeads(mCABINCOLS, M_CABIN_COLS);
	cout << endl;

	for (int i = 0; i < M_CABIN_ROWS; i++)
	{
		cout << setw(2) << left << "Row " << setw(6)<< mCABINROWS[i]+F_CLASS_ROWS;
		printSeats(mC[i], M_CABIN_COLS);
		cout << endl;
	}
	cout <<"---------------------------------------------------"<< endl;
	cout << endl;
}
//displays option menu
void displayMenu() {
	bool valid = false;
	
	int selection;

		cout << "Please select from the following options: " << endl;
		cout << "-----------------------------------------" << endl;
		cout << "1: Reserve seat(s)" << endl;
		cout << "2: Display total number of seats sold by Cabin" << endl;
		cout << "3: Display number of empty seats by Row" << endl;
		cout << "4: Display total number of empty seats by Cabin" << endl;
		cout << "5: Display total amount of sales" << endl;
		cout << "6: Save Plane Data" << endl;
		cout << "7: Reset Plane Data: All Seats Available" << endl;
		cout << "8: Exit" << endl;
		cin >> selection;
	//menu selection validation
	while (!valid)
	{
		if (selection < 1 || selection > 8)
		{
			cout << "Please enter a valid menu option: ";
			cin >> selection;
		}
		else
		{
			valid = true;
		}
	}
	valid = false;
		switch (selection)
		{
		case 1://reserve seat(s)
			reserveSeat(fClassCabin, mainCabin, selRow, selCol);
			break;
		case 2://total number of seats sold by cabin
			seatsSold(fClassCabin, fCTotals);
			seatsSold(mainCabin, mCTotals);
			cout << "---------------------------------------------------" << endl;
			cout << "|" << setw(10)<<" "<< "Number of Seats Sold by Cabin" <<setw(11) <<"|" << endl;
			cout << "---------------------------------------------------" << endl;
			cout << "| " << setw(10) << fCTotals << " First Class Seats Sold" << setw(16) << "|"<< endl;
			cout << "| " << setw(10) << mCTotals << " Main Cabin Seats Sold " << setw(16)<< "|" <<endl;
			cout << "---------------------------------------------------" << endl;
			cout << endl;
			break;
		case 3://total number of empty seats by row
			cout << "---------------------------------------------------" << endl;
			cout << "|" << setw(10) << "" << "Number of Empty Seats by Row" << setw(12) << "|" << endl;
			cout << "---------------------------------------------------" << endl;
			emptySeatsRow(fClassCabin, mainCabin);
			cout << "---------------------------------------------------" << endl;
			cout << endl;
			break;
		case 4://total number of empty seats by cabin
			seatsAvailable(fClassCabin, fCTotals);
			seatsAvailable(mainCabin, mCTotals);
			cout << "---------------------------------------------------" << endl;
			cout << "|" << setw(10) << "" << "Number of Empty Seats by Cabin" << setw(10) << "|" << endl;
			cout << "---------------------------------------------------" << endl;
			cout << "| " << setw(11) << fCTotals << " First Class Seats Empty" << setw(14) << "|" << endl;
			cout << "| " << setw(11) << mCTotals << " Main Cabin Seats Empty " << setw(14) << "|" << endl;
			cout << "---------------------------------------------------" << endl;
			cout << endl;
			break;
		case 5://total amount of sales
			totalPlaneSales(fClassCabin, mainCabin, rowPrices, salesTotal);
			cout << "---------------------------------------------------" << endl;
			cout << "|" << setw(15) << " " << "Airplane Sales Total" << setw(15) << "|" << endl;
			cout << "---------------------------------------------------" << endl;
			cout << "|" << setw(15)<< " " << "$" << setw(8) <<setprecision(2) << fixed << salesTotal << setw(26) << "|" << endl;
			cout << "---------------------------------------------------" << endl;
			cout << endl;
			break;
		case 6://save plane data
			savePlaneData(fClassCabin, mainCabin);
			break;
		case 7://reset plane data
			resetPlaneData(fClassCabin, mainCabin);
			break;
		case 8://exit
			cout << endl;
			cout << "Thank you for using this application." << endl;
			cout << "Good day to you." << endl;
			cout << endl;
			exit(0);
			break;
		default:
			cout << "Something went wrong here." << endl;
			cout << "Please restart and try again." << endl;
			cout << endl;
			exit(1);
			break;
		}
		//display menu until exit is selected
		displayMenu();
}
//used to calculated seats available/sold by cabin
void seatsAvailable(bool fC[][F_CLASS_COLS], int &fCTotal)
{
	fCTotal = 0;
	for (int i = 0; i < F_CLASS_ROWS; i++) 
	{
		for (int j = 0; j < F_CLASS_COLS; j++) 
		{
			if (fC[i][j]) 
			{
				fCTotal++;
			}
		}
	}
}
void seatsAvailable(bool mC[][M_CABIN_COLS], int &mCTotal)
{
	mCTotal = 0;
	for (int i = 0; i < M_CABIN_ROWS; i++)
	{
		for (int j = 0; j < M_CABIN_COLS; j++)
		{
			if (mC[i][j])
			{
				mCTotal++;
			}
		}
	}
}
void seatsSold(bool fC[][F_CLASS_COLS], int &fCTotal)
{
	fCTotal = 0;
	for (int i = 0; i < F_CLASS_ROWS; i++)
	{
		for (int j = 0; j < F_CLASS_COLS; j++)
		{
			if (!fC[i][j])
			{
				fCTotal++;
			}
		}
	}
}
void seatsSold(bool mC[][M_CABIN_COLS], int &mCTotal)
{
	mCTotal = 0;
	for (int i = 0; i < M_CABIN_ROWS; i++)
	{
		for (int j = 0; j < M_CABIN_COLS; j++)
		{
			if (!mC[i][j])
			{
				mCTotal++;
			}
		}
	}
}

//used to chose a seat, display the price, and mark a seat as reserved
void reserveSeat(bool fC[][F_CLASS_COLS], bool mC[][M_CABIN_COLS], int &row, int &col)
{	
	//char value for y|n|s menus
	char selection;
	bool valid = false;
	bool seatAvail = false;
	

	while (!seatAvail) {
		
		bool seatValid = false;

		displaySeats(fC, mC);
		cout << "---------------------------------------------------" << endl;
		cout << "| # - Seat Is Available  || * - Seat is Reserved  |" << endl;
		cout << "---------------------------------------------------" << endl;
		cout << "Enter desired row: ";
		cin >> row;

		//validate row choice

		while (!valid)
		{
			if (row < 1 || row > TOTAL_ROWS)
			{
				cout << "This plane has " << TOTAL_ROWS << " rows." << endl;
				cout << "Please enter a row that exists on this plane: ";
				cin >> row;
			}
			else
			{
				valid = true;
			}
		}

		valid = false;

		cout << "Enter desired seat in row " << row << ": ";
		cin >> col;

		//validate row choice

		while (!valid)
		{
			if (row < 6)
			{
				if (col < 1 || col > F_CLASS_COLS)
				{
					cout << "This row has " << F_CLASS_COLS << " seats." << endl;
					cout << "Please enter a seat that exists on this row: ";
					cin >> col;
				}
				else
				{
					valid = true;
				}
			}
			else if (row > 5)
			{
				if (col < 1 || col > M_CABIN_COLS)
				{
					cout << "This row has " << M_CABIN_COLS << " seats." << endl;
					cout << "Please enter a seat that exists on this row: ";
					cin >> col;
				}
				else
				{
					valid = true;
				}
			}
		}

		valid = false;

		if (row < 6)
		{
			if (fClassCabin[row-1][col-1])
			{
				while (!seatValid)
				{
					cout << "This seat costs: " << rowPrices[row-1] << endl;
					cout << "Continue with reservation? (Y = Yes, N = No, S = Select new seat): ";
					cin >> selection;
					switch (selection)
					{
					case 'Y':
					case 'y':
						seatValid = true;
						seatAvail = true;
						fClassCabin[row - 1][col - 1] = 0;
						cout << endl;
						cout << "Thank you for your reservation." << endl;
						cout << "---------------------------------------------------" << endl;
						break;
					case 'N':
					case 'n':
						seatValid = true;
						seatAvail = true;
						break;
					case 'S':
					case 's':
						seatValid = true;
						seatAvail = false;
						break;
					default:
						cout << "Please enter a valid selection. " << endl;
						break;
					}

				}
			}
			else
			{
				cout << "This seat has already been reserved." << endl;
				cout << "Please choose a new seat." << endl;
				seatAvail = false;
			}
		}
		if (row > 5)
		{
			if (mainCabin[row - 6][col-1])
			{
				cout << mainCabin[row - 6][col - 1] << " row " << row - 1 << " col " << col - 1 << endl;
				while (!seatValid)
				{
					cout << "This seat costs: " << rowPrices[row-1] << endl;
					cout << "Continue with reservation? (Y = Yes, N = No, S = Select new seat): ";
					cin >> selection;
					switch (selection)
					{
					case 'Y':
					case 'y':
						seatValid = true;
						seatAvail = true;
						mainCabin[row - 6][col-1] = 0;
						cout << endl;
						cout << "Thank you for your reservation." << endl;
						cout << "---------------------------------------------------" << endl;
						break;
					case 'N':
					case 'n':
						seatAvail = true;
						seatValid = true;
						break;
					case 'S':
					case 's':
						seatValid = true;
						seatAvail = false;
						break;
					default:
						cout << "Please enter a valid selection. " << endl;
						break;
					}
				}
			}
			else
			{
				cout << "This seat has already been reserved." << endl;
				cout << "Please choose a new seat." << endl;
				seatAvail = false;
			}
		}
	}
}
//used in menu option 3
void emptySeatsRow(bool fC[][F_CLASS_COLS], bool mC[][M_CABIN_COLS])
{
	int row = 1;
	for (int i = 0; i < F_CLASS_ROWS; i++)
	{
		int rowEmpty = 0;
		for (int j = 0; j < F_CLASS_COLS; j++)
		{
			if (fC[i][j])
			{
				rowEmpty++;
			}
		}
		cout << "|" << setw(10) << "Row " << setw(2) << row << setw(6) << "|";
		cout << setw(10) << rowEmpty << " Seats Empty" << setw(10) << "|" << endl;
		row++;
	}
	for (int i = 0; i < M_CABIN_ROWS; i++)
	{
		int rowEmpty = 0;
		for (int j = 0; j < M_CABIN_COLS; j++)
		{
			if (mC[i][j])
			{
				rowEmpty++;
			}
		}
		cout << "|" << setw(10) << "Row " << setw(2) << row << setw(6) << "|";
		cout << setw(10) << rowEmpty << " Seats Empty" << setw(10) << "|" << endl;
		row++;
	}
}
//used in menu option 5
void totalPlaneSales(bool fC[][F_CLASS_COLS], bool mC[][M_CABIN_COLS], double rT[], double &sTotal)
{
	sTotal = 0.0;
	for (int i = 0; i < F_CLASS_ROWS; i++)
	{
		for (int j = 0; j < F_CLASS_COLS; j++)
		{
			if (!fC[i][j])
			{
				sTotal += rT[i];
			}
		}
	}
	for (int i = 0; i < M_CABIN_ROWS; i++)
	{
		for (int j = 0; j < M_CABIN_COLS; j++)
		{
			if (!mC[i][j])
			{
				sTotal += rT[i];
			}
		}
	}
}
//used in menu option 6
void savePlaneData(bool fC[][F_CLASS_COLS], bool mC[][M_CABIN_COLS])
{
	bool valid = false;
	while (!valid)
	{
		char choice;
		cout << "\n\n\n\n\n\n\n\n\n\n\n";
		cout << "This operation will save over the current plane data." << endl;
		cout << "Are you sure you want to proceed? (Y = Yes | N = No): ";
		cin >> choice;
		switch (choice)
		{
		case 'y':
		case 'Y':
			valid = true;
			outputFile.open(planeSeatsFName);
			if (outputFile)
			{
				outputFile.clear();
				for (int i = 0; i < F_CLASS_ROWS; i++)
				{
					for (int j = 0; j < F_CLASS_COLS; j++)
					{
						if (fC[i][j])
						{
							outputFile << 1 << endl;
						}
						else
						{
							outputFile << 0 << endl;
						}
					}
				}
				for (int i = 0; i < M_CABIN_ROWS; i++)
				{
					for (int j = 0; j < M_CABIN_COLS; j++)
					{
						if (mC[i][j])
						{
							outputFile << 1 << endl;
						}
						else
						{
							outputFile << 0 << endl;
						}
					}
				}
				outputFile.close();
			} 
			else
			{
				cout << "Error opening file for saving." << endl;
				cout << "Exiting program" << endl;
				exit(1);
				
			}
			
			break;
		case 'n':
		case 'N':
			valid = true;
			cout << "Okay, returning to main menu." << endl;
			break;
		default:
			cout << "Invalid selection" << endl;
			valid = false;
			break;
		}
	}
}
//used in menu option 7
void resetPlaneData(bool fC[][F_CLASS_COLS], bool mC[][M_CABIN_COLS])
{
	bool valid = false;
	while (!valid)
	{
		char choice;
		cout << "\n\n\n\n\n\n\n\n\n\n\n";
		cout << "This operation will overwrite the plane data in memory." << endl;
		cout << "Are you sure you want to proceed? (Y = Yes | N = No): ";
		cin >> choice;
		switch (choice)
		{
		case 'y':
		case 'Y':
			valid = true;
			if (valid)
			{
				for (int i = 0; i < F_CLASS_ROWS; i++)
				{
					for (int j = 0; j < F_CLASS_COLS; j++)
					{
						fC[i][j] = true;
					}
				}
				for (int i = 0; i < M_CABIN_ROWS; i++)
				{
					for (int j = 0; j < M_CABIN_COLS; j++)
					{
						mC[i][j] = true;
					}
				}
			}
			break;
		case 'n':
		case 'N':
			valid = true;
			cout << "Okay, returning to main menu." << endl;
			break;
		default:
			cout << "Invalid selection" << endl;
			valid = false;
			break;
		}
	}
}