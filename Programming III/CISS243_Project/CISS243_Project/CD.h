#ifndef CD_H
#define CD_H
#include <vector>
#include "Media.h"

#include <string>
#include <ostream>

using namespace std;

class CD : public Media
{
private:
	// song structure
	struct song
	{
		string title;
		int length;
	};

	//object fields
	LList<song> songs;
	string artistName;
	
	//private function
	void calcAlbumLength();

public:
	//constructors
	CD(string album, string artist, string tracks[], int lengths[], int numSongs);
	CD(string album, string artist, vector<string> tracks, vector<int> lengths);
	CD();

	//accessors
	string getArtistName();
	LList<song> getSongs();

	//mutators
	void setAlbumName(string album);
	void setArtistName(string artist);
	//overloaded to accept multiple data formats
	void setSongs(string songs[], int lengths[], int numSongs);
	void setSongTitles(vector<string> songTitles, vector<int> sLenghts);
	//used to better access/change object data
	/*void addSong(string song, int lenght);
	void setSongName(string newName, int songNum);
	void setSongLength(int newLength, int songNum);*/

	friend ostream &operator << (ostream &, const CD &);

	friend ostream &operator << (ostream &strm, const CD::song &obj);
	

};
#endif // !CD_H
