/*Kenneth Drake-Sargent
*Chapter 5
*Assigment 2
*Working with files
*/
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
	//create ifstream object
	ifstream inputFile;
	
	//create input file name string
	string fileName = "Random.txt";
	
	//create variables
	int number,
		numCount,
		numSum,
		numMin,
		numMax;
	
	double numAvg = 0.0;

	//open inputFile
	inputFile.open(fileName);

	//initialize count, sum, and arbitrary values for min and max
	numCount = 0;
	numSum = 0;
	numMax = 0;
	numMin = 100000;
	
	//test if the file was opened
	if (inputFile) {

		//loop through file 
		while (inputFile >> number) {
			
			//increment counter
			numCount++;
			
			//add to sum
			numSum += number;
			
			//test if number is less than the current lowest number
			if (number < numMin) {
				numMin = number;
			}
			
			//test if the number is greater than the current highest number
			if (number > numMax) {
				numMax = number;
			}

		}

		//close the input file
		inputFile.close();
		
		//calculate the average of the numbers
		numAvg = static_cast<double>(numSum) / numCount;
		
		//display the results
		cout << "Number of entries: " << numCount << endl;
		cout << "Sum of entries: " << numSum << endl;
		cout << "Average of entries: " << numAvg << endl;
		cout << "Lowest Value: " << numMin << endl;
		cout << "Highest Value: " << numMax << endl;
	}
	//if the listfile did not open do this
	else {
		cout << "The file named " << fileName << " could not be opened." << endl;
		//return a value > 0 to indicate the program closed with an error
		return 1;
	}

	return 0;
}