#include<iostream>
#include<fstream>
#include<string>

using namespace std;

//prototype functions
void displayAllLines(ifstream &infile);
void displayLastLine(ifstream &infile);

//variable declarations
ifstream joke;
ifstream punchline;
//file name initialization
string jFileName = "joke.txt";
string pFileName = "punchline.txt";

int main()
{
	// open files with set names
	joke.open(jFileName);
	punchline.open(pFileName);

	//if the files opened run the function with the file
	if (joke)
	{
		displayAllLines(joke);
	}
	if (punchline)
	{
		displayLastLine(punchline);
	}

	//exit program
	system("pause");
	return 0;
}
//function definitions
void displayAllLines(ifstream &infile)
{
	//create a line variable
	string line;
	//while the file still has lines to read loop
	while (infile)
	{
		//get line of text, store in variable
		getline(infile, line);
		//print line of text
		cout << line << endl;
	}
	//when no more text to print, close file
	infile.close();
}
void displayLastLine(ifstream &infile)
{
	//create line string variable
	string line;
	//while there are still lines of text to read, loop
	while (infile)
	{
		//cycle through each line storing in line variable
		getline(infile, line);
	}
	//print the last line stored
	cout << line << endl;
	//close file
	infile.close();
}