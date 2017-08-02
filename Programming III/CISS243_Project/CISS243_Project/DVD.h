#ifndef DVD_H
#define DVD_H

#include "Media.h"

#include <string>
#include <ostream>

using namespace std;

class DVD : public Media
{
private:
	// song structure
	struct actor
	{
		string name;
		string character;
	};

	//object fields
	LList<actor> actors;
	int yearReleased;

public:
	//constructors
	DVD(string title, int year, int playTime, string names[], string characters[], int numActors);

	DVD();

	//accessors
	int getYearReleased();
	LList<actor> getActors();

	//mutators
	void setYearReleased(int year);
	void setMovieTitle(string name);
	//overloaded to accept multiple data formats
	void setActors(string names[], string characters[], int numActors);
	//used to better access/change object data
	/*void addSong(string song, int lenght);
	void setSongName(string newName, int songNum);
	void setSongLength(int newLength, int songNum);*/

	friend ostream &operator << (ostream &, const DVD &);

	friend ostream &operator << (ostream &strm, const DVD::actor &obj);


};
#endif // !CD_H

