#include<string>
#include<vector>
#include"CD.h"

using namespace std;

//private function definition
void CD::calcAlbumLength()
{
	int totalLength = 0;
	for (int val : songLengths)
	{
		totalLength += val;
	}
	albumLength = totalLength;
}

//constructors
CD::CD(string album, string artist, string songs[], int lengths[], int numSongs)
{
	albumName = album;
	artistName = artist;
	//loop to add titles and lengths
	for (int i = 0; i < numSongs; i++)
	{
		songTitles.push_back(songs[i]);
		songLengths.push_back(lengths[i]);
	}
	//calculate album length after lenghts exist
	calcAlbumLength();
}

CD::CD(string album, string artist, vector<string> songs, vector<int> lengths)
{
	albumName = album;
	artistName = artist;
	//vector limited loops to add tracks and lengths
	for (string track : songs)
	{
		songTitles.push_back(track);
	}
	for (int len : lengths)
	{
		songLengths.push_back(len);
	}
	//calculate album length after lenghts exist
	calcAlbumLength();
}

CD::CD()
{
	//set strings to empty, vectors are already empty, album length to 0
	albumName = "";
	artistName = "";
	albumLength = 0;
}

//accessor functions
string CD::getAlbumName()
{
	return albumName;
}
string CD::getArtistName()
{
	return artistName;
}
vector<string> CD::getSongTitles()
{
	return songTitles;
}
vector<int> CD::getSongLengths()
{
	return songLengths;
}
int CD::getAlbumLength()
{
	calcAlbumLength();
	return albumLength;
}

//mutator functions
void CD::setAlbumName(string album)
{
	albumName = album;
}
void CD::setArtistName(string artist)
{
	artistName = artist;
}
//set song titles and lengths via array
void CD::setSongTitles(string songs[], int numSongs)
{

	for (int i = 0; i < numSongs; i++)
	{
		songTitles.push_back(songs[i]);
	}
}
void CD::setSongLengths(int lengths[], int numSongs)
{
	for (int i = 0; i < numSongs; i++)
	{
		songLengths.push_back(lengths[i]);
	}
	calcAlbumLength();
}

//set song titles and lengths via vector
void CD::setSongTitles(vector<string> sTitles)
{
	//if songtitles isn't empty, empty it
	if (!songTitles.empty())
	{
		songTitles.clear();
	}
	//add all songtitles passed to function
	for (string title : sTitles)
	{
		songTitles.push_back(title);
	}
}
void CD::setSongLengths(vector<int> sLengths)
{
	//if songlengths isn't empty, empty it
	if (!songLengths.empty())
	{
		songLengths.clear();
	}
	//add all songlengths passed to function
	for (int length : sLengths)
	{
		songLengths.push_back(length);
	}
	calcAlbumLength();
}

//functions created to modify object field vector data
void CD::setSongName(string newName, int songNum)
{
	songTitles[songNum] = newName;
}

void CD::setSongLength(int newLength, int songNum)
{
	songLengths[songNum] = newLength;
}

void CD::addSong(string song, int length)
{
	songTitles.push_back(song);
	songLengths.push_back(length);
}