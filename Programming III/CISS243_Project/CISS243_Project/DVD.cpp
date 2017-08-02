#include<string>
#include<iomanip>
#include"DVD.h"

using namespace std;


//constructors
DVD::DVD(string title, int year, int playTime, string names[], string characters[], int numSongs) : Media(title, playTime)
{
	yearReleased = year;
	//loop to add titles and characters
	for (int i = 0; i < numSongs; i++)
	{
		actor person;
		person.name = names[i];
		person.character = characters[i];
		actors.appendNode(person);
	}
	
}


DVD::DVD()
{
	//set strings to empty, vectors are already empty, album length to 
	yearReleased = 0;
}

//accessor functions

int DVD::getYearReleased()
{
	return yearReleased;
}


//mutator functions
void DVD::setMovieTitle(string name)
{
	title = name;
}
void DVD::setYearReleased(int year)
{
	yearReleased = year;
}
//set actor titles and characters via array
void DVD::setActors(string names[], string characters[], int numActors)
{
	if (!actors.empty())
	{
		actors.clear();
	}

	for (int i = 0; i < numActors; i++)
	{
		actor person;
		person.name = names[i];
		person.character = characters[i];
		actors.appendNode(person);
	}

}


LList<DVD::actor> DVD::getActors()
{
	return actors;
}

//functions created to modify object field vector data
//void DVD::setSongName(string newName, int actorNum)
//{
//	actorTitles[actorNum] = newName;
//}
//
//void DVD::setSongLength(int newLength, int actorNum)
//{
//	actorLengths[actorNum] = newLength;
//}
//
//void DVD::addSong(string actor, int length)
//{
//	actorTitles.push_back(actor);
//	actorLengths.push_back(length);
//}

ostream &operator << (ostream &strm, const DVD &obj)
{
	string movieLength = "";
	int mins = obj.length / 60;
	
	movieLength.append(to_string(mins));
	movieLength.append(" mins");
	

	strm << setw(20) << left << obj.title;
	strm << setw(15) << left << movieLength;
	strm << setw(15) << left << obj.yearReleased;
	obj.actors.displayList(53);
	return strm;
}


ostream &operator << (ostream &strm, const DVD::actor &obj)
{
	strm << setw(30) << left << obj.name;
	strm << setw(10) << left << obj.character;
	return strm;
}