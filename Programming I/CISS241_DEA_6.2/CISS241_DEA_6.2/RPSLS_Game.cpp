/*Kenneth Drake-Sargent
*Chapter 6
*Assigment 2
*Rock Paper Scissors Lizard Spock
*/
/*
Rock Paper Scissors Lizard Spock Game
User input versus computer choice
Random number btw 1 & 5
do - while loop
User input their choice
Display computer's choice
functions - --int getUserChoice()
				cin to assign value to variable
				return variable
			int getComputerChoice()
				rand function to assign value to variable
				return variable
			void determineWinner(int, int)
				take int values from userChoice and computer choice
				if else if statements to determine winning and output
				if same answer 
					cout response 
					continue to loop again
				return 0 to exit game
			void displayChoice(int)
				cout int choice value with switch

*/
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

//global variables
int userChoice;
int computerChoice;
bool gameOver = false;

//prototype functions
int getUserChoice();
int getComputerChoice();
void determineWinner(int, int);
void displayChoice(int);
void gameMenu();

//main function
int main() {
	//loop through game until there is a winner
	do {
		//print game menu
		gameMenu();
		cout << endl;
		
		//get and store choices
		userChoice = getUserChoice();
		computerChoice = getComputerChoice();
		
		//print choices
		cout << "You chose ";
		displayChoice(userChoice);
		cout << " and the computer chose ";
		displayChoice(computerChoice);
		cout << "." << endl;
		
		//determine outcome
		determineWinner(userChoice, computerChoice);
		cout << endl;
	} while (!gameOver);
	//close program
	return 0;
}

//prints game menu
void gameMenu() {
	cout << "1 - Rock" << endl;
	cout << "2 - Paper" << endl;
	cout << "3 - Scissors" << endl;
	cout << "4 - Lizard" << endl;
	cout << "5 - Spock" << endl;
}

//requests, validates, and returns user's choice
int getUserChoice() {
	
	int num;
	cout << "Select an option from the above list: ";
	cin >> num;
	
	bool valid = false;

	while (!valid) {
		if (num < 1 || num > 5) {
			
			gameMenu();
			cout << "\nPlease select a valid option from this list: ";
			cin >> num;
		}
		else {
			valid = true;
		}
	}

	valid = false;
	return num;
}

//sets and returns computer's choice
int getComputerChoice() {
	
	int randNum;
	//set random seed
	srand(time(NULL));
	//get random number
	randNum = rand() % 5 + 1;
	
	return randNum;
}

//takes the int choice and prints the text value
void displayChoice(int choice) {
	switch (choice) {
	case 1:
		cout << "Rock";
		break;
	case 2:
		cout << "Paper";
		break;
	case 3:
		cout << "Scissors";
		break;
	case 4:
		cout << "Lizard";
		break;
	case 5:
		cout << "Spock";
		break;
	default:
		cout << "Something went horribly wrong. Please run the program again." << endl;
		exit(1);
		break;
	}
}

//evaluate choices and determine winner
void determineWinner(int uChoice, int cChoice) {
	//if the choices are not the same continue to evaluate
	if (uChoice != cChoice) {
		switch (uChoice) {
		//case the user chose rock, paper, scissors, lizard, spock
		//user chose rock
		case 1:
			switch (cChoice) {
			//computer chose paper
			case 2:
				cout << "Paper covers rock." << endl;
				cout << "Computer wins!" << endl;
				gameOver = true;
				break;
			//computer chose scissors
			case 3:
				cout << "Rock breaks scissors." << endl;
				cout << "You win!" << endl;
				gameOver = true;
				break;
			//computer chose lizard
			case 4:
				cout << "Rock crushes lizard." << endl;
				cout << "You win!" << endl;
				gameOver = true;
				break;
			//computer chose spock
			case 5:
				cout << "Spock vaporizes rock." << endl;
				cout << "Computer win!" << endl;
				gameOver = true;
				break;
			default:
				cout << "Something went horribly wrong. Please run the program again." << endl;
				exit(1);
				break;
			}
			break;
		//user chose paper
		case 2:
			switch (cChoice) {
			//computer chose rock
			case 1:
				cout << "Paper covers rock." << endl;
				cout << "You win!" << endl;
				gameOver = true;
				break;
			//computer chose scissors
			case 3:
				cout << "Scissors cut paper." << endl;
				cout << "Computer wins!" << endl;
				gameOver = true;
				break;
			//computer chose lizard
			case 4:
				cout << "Lizard eats paper." << endl;
				cout << "Computer wins!" << endl;
				gameOver = true;
				break;
			//computer chose spock
			case 5:
				cout << "Paper disproves Spock." << endl;
				cout << "You win!" << endl;
				gameOver = true;
				break;
			default:
				cout << "Something went horribly wrong. Please run the program again." << endl;
				exit(1);
				break;
			}
			break;
		//user chose scissors
		case 3:
			switch (cChoice) {
			//computer chose rock
			case 1:
				cout << "Rock breaks Scissors." << endl;
				cout << "Computer wins!" << endl;
				gameOver = true;
				break;
			//computer chose paper
			case 2:
				cout << "Scissors cut paper." << endl;
				cout << "You win!" << endl;
				gameOver = true;
				break;
			//computer chose lizard
			case 4:
				cout << "Scissors decapitate lizard." << endl;
				cout << "You win!" << endl;
				gameOver = true;
				break;
			//computer chose spock
			case 5:
				cout << "Spock melts scissors." << endl;
				cout << "Computer wins!" << endl;
				gameOver = true;
				break;
			default:
				cout << "Something went horribly wrong. Please run the program again." << endl;
				exit(1);
				break;
			}
			break;
		//user chose lizard
		case 4:
			switch (cChoice) {
			//computer chose rock
			case 1:
				cout << "Rock crushes lizard." << endl;
				cout << "Computer wins!" << endl;
				gameOver = true;
				break;
			//computer chose paper
			case 2:
				cout << "Lizard eats paper." << endl;
				cout << "You win!" << endl;
				gameOver = true;
				break;
			//computer chose scissors
			case 3:
				cout << "Scissors decapitate lizard." << endl;
				cout << "Computer wins!" << endl;
				gameOver = true;
				break;
			//computer chose spock
			case 5:
				cout << "Lizard poisons Spock." << endl;
				cout << "You win!" << endl;
				gameOver = true;
				break;
			default:
				cout << "Something went horribly wrong. Please run the program again." << endl;
				exit(1);
				break;
			}
			break;
		//user chose spock
		case 5:
			switch (cChoice) {
			//computer chose rock
			case 1:
				cout << "Spock vaporizes rock." << endl;
				cout << "You win!" << endl;
				gameOver = true;
				break;
			//computer chose paper
			case 2:
				cout << "Paper disproves Spock." << endl;
				cout << "Computer wins!" << endl;
				gameOver = true;
				break;
			//computer chose scissors
			case 3:
				cout << "Spock melts scissors." << endl;
				cout << "You win!" << endl;
				gameOver = true;
				break;
			//computer chose lizard
			case 4:
				cout << "Lizard poisons Spock." << endl;
				cout << "Computer wins!" << endl;
				gameOver = true;
				break;
			default:
				cout << "Something went horribly wrong. Please run the program again." << endl;
				exit(1);
				break;
			}
			break;
		//an improper value got passed, exit program
		default:
			cout << "Something went horribly wrong. Please run the program again." << endl;
			exit(1);
			break;
		}
	}
	else {
		cout << "You both choice ";
		displayChoice(uChoice);
		cout << ". Try again." << endl;
	}
}