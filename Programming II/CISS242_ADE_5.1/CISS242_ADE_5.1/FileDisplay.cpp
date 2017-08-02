#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//variable declaration
string fileName;
string line;
fstream displayfile;


int main()
{
	//request file name from user
	cout << "Enter the name of a file you would like to open: " << endl;
	cin >> fileName;
	
	//attempt to open file, read in only using ios::in flag
	displayfile.open(fileName, ios::in);
	
	//if file doesn't open or exist exit program
	if (!displayfile) {
		cout << fileName << " could not be opened." << endl;
		cout << "Program closing." << endl;
		system("pause");
		return 0;
	}
	//initialize counter
	int count = 0;

	//while file still has unread contents loop
	while (displayfile)
	{
		//get line of text and store it in string variable line
		getline(displayfile, line);

		//if counter is at 24 pause and reset counter
		if (count == 24)
		{
			count = 0;
			system("pause");
		}
		//print lines 0 - 23 before pausing increment counter
		cout << line << endl;
		count++;
	}

	//close file
	displayfile.close();

	//exit program
	system("pause");
	return 0;
}