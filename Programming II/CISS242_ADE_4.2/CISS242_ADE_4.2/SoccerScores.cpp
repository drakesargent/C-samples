#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

//structure definition
struct Player
{
	string name;
	int number;
	int points;
};

//function prototypes
void getPlayerInfo(Player&);
void showInfo(Player);
int getTotalPoints(Player[], int);
void showHighest(Player[], int);
//validation prototypes
void validateNumber(Player&);
void validatePoints(Player&);

//team size constant
const int TEAM_SIZE = 12;

//team structure initialization
Player players[TEAM_SIZE];

int main()
{
	//loop through initialize player data 
	for (int i = 0; i < TEAM_SIZE; i++)
	{
		cout << "PLAYER #" << i + 1 << endl;
		cout << "----------" << endl;
		getPlayerInfo(players[i]);
		cout << endl;
	}
	
	//heading for the player output
	cout << setw(25) << left;
	cout << "NAME";
	cout << setw(10) << left;
	cout << "NUMBER";
	cout << setw(15) << left;
	cout << "POINTS SCORED" << endl;

	//loop through and output all players
	for (int i = 0; i < TEAM_SIZE; i++)
	{
		showInfo(players[i]);
	}

	//display total points
	cout << "TOTAL POINTS: ";
	cout << getTotalPoints(players, TEAM_SIZE) << endl;

	//display highest scoring player
	cout << "The player who scored the most points is: ";
	showHighest(players, TEAM_SIZE);
	cout << endl;

	system("pause");
	return 0;
}
//function definitions
void getPlayerInfo(Player &p)
{
	//get player name
	cout << "Player name: ";
	getline(cin, p.name);
	
	//get player number
	cout << "Player's number: ";
	cin >> p.number;
	//ignore new line character
	cin.ignore();
	//validate this player's number
	validateNumber(p);
	
	//get this player's points scored
	cout << "Points scored: ";
	cin >> p.points;
	//ignore newline character
	cin.ignore();
	//validate this player's points scored
	validatePoints(p);
}
void showInfo(Player p)
{
	//output player data formatted for one line
	cout << setw(25) << left;
	cout << p.name;
	cout <<" "<< setw(10) << left;
	cout <<p.number;
	cout <<" "<< setw(15) << left;
	cout <<p.points << endl;
}
int getTotalPoints(Player p[], int team)
{
	//declare and initialize total points variable
	int totalPoints = 0;

	//loop through team and add point to total points for each player
	for (int i = 0; i < team; i++)
	{
		totalPoints += p[i].points;
	}
	//return total points
	return totalPoints;
}
void showHighest(Player p[], int team)
{
	//set a highest points variable
	int highest = p[0].points;
	//set the index for the player with the highest points
	int h_index = 0;
	//loop through each team member
	for (int i = 0; i < team; i++)
	{
		//if the team member has higher points scored than the highest recorded
		if (highest < p[i].points)
		{
			//set the highest point value to that player's
			highest = p[i].points;
			//set the index to that player's index
			h_index = i;
		}
	}
	//print out the name of the player with the highest points scored using the highest points index
	cout << p[h_index].name;
}

void validatePoints(Player &p)
{
	bool valid = false;
	while (!valid)
	{
		if (p.points < 0)
		{
			cout << "Please enter a positive point value: ";
			cin >> p.points;
			cin.ignore();
		}
		else
		{
			valid = true;
		}
	}
}

void validateNumber(Player &p)
{
	bool valid = false;
	while (!valid)
	{
		if (p.number < 0)
		{
			cout << "Please enter a positive number value: ";
			cin >> p.number;
			cin.ignore();
		}
		else
		{
			valid = true;
		}
	}
}