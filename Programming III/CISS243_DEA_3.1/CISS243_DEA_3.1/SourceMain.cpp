#include <iostream>
#include "TestScores.h"

using namespace std;

int main()
{
	// define constante array size
	const int numscores = 5;

	// declare and define arrays of test scores
	double spellingScores[5] = { 98.5, 100, 87.6, 87.9, 75 };
	double mathScores[5] = { 98.5, -5, 87.6, 87.9, 75 };
	double geographyScores[5] = { 98.5, 101, 87.6, 87.9, 75 };

	// declare TestScores objects passing an array as the argument
	TestScores spelling(spellingScores);
	TestScores math(mathScores);
	TestScores geography(geographyScores);

	// demonstrate error handling with the try/catch blocks for each TestScores object
	try
	{
		double avg1 = spelling.getAverages(numscores);
		cout << "This is the average for the spelling test: " << avg1 << endl;
	}
	catch (TestScores::NegativeScore n)
	{
		cout << "Error: " << n.getScore();
		cout << " is not a valid spelling test score." << endl;
		cout << "All scores must be positive values." << endl;
	}
	catch (TestScores::TooLargeScore t)
	{
		cout << "Error: " << t.getScore();
		cout << " is not a valid spelling test score." << endl;
		cout << "All scores must not be greater than 100." << endl;
	}
	cout << endl;
	try
	{
		double avg2 = math.getAverages(numscores);
		cout << "This is the average for the math test: " << avg2 << endl;
	}
	catch (TestScores::NegativeScore n)
	{
		cout << "Error: " << n.getScore();
		cout << " is not a valid math test score." << endl;
		cout << "All scores must be positive values." << endl;
	}
	catch (TestScores::TooLargeScore t)
	{
		cout << "Error: " << t.getScore();
		cout << " is not a valid math test score." << endl;
		cout << "All scores must not be greater than 100." << endl;
	}
	cout << endl;
	try
	{
		double avg3 = geography.getAverages(numscores);
		cout << "This is the average for the geography test: " << avg3 << endl;
	}
	catch (TestScores::NegativeScore n)
	{
		cout << "Error: " << n.getScore();
		cout << " is not a valid geography test score." << endl;
		cout << "All scores must be positive values." << endl;
	}
	catch (TestScores::TooLargeScore t)
	{
		cout << "Error: " << t.getScore();
		cout << " is not a valid geography test score." << endl;
		cout << "All scores must not be greater than 100." << endl;
	}
	cout << endl;
	return 0;
}