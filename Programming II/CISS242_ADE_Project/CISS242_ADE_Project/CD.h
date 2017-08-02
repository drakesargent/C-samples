#ifndef CD_H
#define CD_H
#include <vector>
#include <string>

using namespace std;

class CD
{
public:
	//constructors
	CD(string album, string artist, string songs[], int lengths[], int numSongs);
	CD(string album, string artist, vector<string> songs, vector<int> lengths);
	CD();

	//accessors
	string getAlbumName();
	string getArtistName();
	vector<string> getSongTitles();
	vector<int> getSongLengths();
	int getAlbumLength();

	//mutators
	void setAlbumName(string album);
	void setArtistName(string artist);
	//overloaded to accept multiple data formats
	void setSongTitles(string songs[], int numSongs);
	void setSongTitles(vector<string> songTitles);
	void setSongLengths(int lengths[], int numSongs);
	void setSongLengths(vector<int> songLengths);
	//used to better access/change object data
	void addSong(string song, int lenght);
	void setSongName(string newName, int songNum);
	void setSongLength(int newLength, int songNum);


private:
	//object fields
	vector<string> songTitles;
	vector<int> songLengths;
	string artistName;
	string albumName;
	int albumLength;
	//private function
	void calcAlbumLength();
};
#endif // !CD_H
