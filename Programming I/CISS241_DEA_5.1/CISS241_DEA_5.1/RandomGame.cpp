/*Kenneth Drake-Sargent
*Chapter 5
*Assigment 1
*Random Game
*/
/*
Variables for random number, guess, numGuesses

Loop
Generate random number btw 1 & 100
Display request for guess
validate that guess is between 1 & 100 if not make new guess
if too high display "Too high, try again."
if too low display "Too low, try again."
End Loop if guess 10 is wrong

Evaluate if numGuesses is in a range display specific messages

*/
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main() {
	//declare variables
	int randNum,
		guess,
		numGuesses;
	bool guessed = false;
	bool valid = false;
	
	//initialize guess counter
	numGuesses = 0;
	
	//set random seed
	srand(time(NULL));
	
	//initilize random number
	randNum = rand() % 100 + 1;

	//display game question
	cout << "Guess a number between 1 and 100: ";
	
	while (!guessed) {
		//test to see if number of guesses is less than 10
		if (numGuesses < 10) {
			//store guess
			cin >> guess;
			
			//validation loop
			while (!valid) {
				if (guess < 1 || guess>100) {
					cout << "\nPlease make another guess between 1 and 100: ";
					cin >> guess;
				}
				else {
					valid = true;
				}
			}
			//validation reset
			valid = false;
			
			//increment number of guesses
			numGuesses++;
			
			//test if guess == random number
			if (!(randNum == guess)) {
				//if not and guess is too high
				if (guess > randNum) {
					cout << "Too high, try again.\n";
				}
				//otherwise guess is too low
				else {
					cout << "Too low, try again.\n";
				}
			}
			else {
				//guess was correct evaluate number of guesses
				if (numGuesses < 5) {
					cout << "Either you know the secret or you got lucky!" << endl;
					guessed = true;
				}
				else if (numGuesses <= 7){
					cout << "You're pretty good at this!" << endl;
					guessed = true;
				}
				else {
					cout << "You'll do better next time." << endl;
					guessed = true;
				}
			}
		}
		else {
			//there were 10 guesses quit the loop
			guessed = true;
			cout << "\nSorry - You have taken too many guesses." << endl;
		}
	}
	return 0;
}