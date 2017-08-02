#include<string>
#include<iomanip>
#include<vector>
#include"CD.h"

using namespace std;

//private function definition
void CD::calcAlbumLength()
{
	song *sLen = nullptr;
	int totalLength = 0;
	int songsLength = songs.getLen();
	for (int i = 0; i< songsLength; i++)
	{
		sLen = &songs.returnVal(i);
		totalLength += sLen->length;
	}
	length = totalLength;
}

//constructors
CD::CD(string album, string artist, string tracks[], int lengths[], int numSongs) : Media(album)
{
	artistName = artist;
	//loop to add titles and lengths
	for (int i = 0; i < numSongs; i++)
	{
		song track;
		track.title = tracks[i];
		track.length = lengths[i];
		songs.appendNode(track);
	}
	//calculate album length after lenghts exist
	calcAlbumLength();
}

CD::CD(string album, string artist, vector<string> tracks, vector<int> lengths) : Media(album)
{
	artistName = artist;
	
	//vector limited loops to add tracks and lengths
	int tracksLength = tracks.size();
	
	for (int i = 0; i < tracksLength; i++)
	{
		song track;
		track.title = tracks[i];
		track.length = lengths[i];
		songs.appendNode(track);
	}

	//calculate album length after lenghts exist
	calcAlbumLength();
}

CD::CD()
{
	//set strings to empty, vectors are already empty, album length to 
	artistName = "";
}

//accessor functions

string CD::getArtistName()
{
	return artistName;
}


//mutator functions
void CD::setAlbumName(string album)
{
	title = album;
}
void CD::setArtistName(string artist)
{
	artistName = artist;
}
//set song titles and lengths via array
void CD::setSongs(string tracks[], int lengths[], int numSongs)
{
	if (!songs.empty())
	{
		songs.clear();
	}
	
	for (int i = 0; i < numSongs; i++)
	{
		song track;
		track.title = tracks[i];
		track.length = lengths[i];
		songs.appendNode(track);
	}

}


//set song titles and lengths via vector
void CD::setSongTitles(vector<string> sTitles, vector<int> sLengths)
{
	//if songtitles isn't empty, empty it
	if (!songs.empty())
	{
		songs.clear();
	}
	//add all songtitles passed to function
	int len = sTitles.size();

	for (int i = 0; i < len; i++)
	{
		song track;
		track.title = sTitles[i];
		track.length = sLengths[i];
		songs.appendNode(track);
	}
}

 LList<CD::song> CD::getSongs()
{
	return songs;
}

//functions created to modify object field vector data
//void CD::setSongName(string newName, int songNum)
//{
//	songTitles[songNum] = newName;
//}
//
//void CD::setSongLength(int newLength, int songNum)
//{
//	songLengths[songNum] = newLength;
//}
//
//void CD::addSong(string song, int length)
//{
//	songTitles.push_back(song);
//	songLengths.push_back(length);
//}

ostream &operator << (ostream &strm, const CD &obj)
{
	string albumLength = "";
	int mins = obj.length / 60;
	int secs = obj.length % 60;
	albumLength.append(to_string(mins));
	albumLength.append(":");
	if (secs < 10) {
		albumLength.append("0");
	}
	albumLength.append(to_string(secs));
	
	strm << setw(15) << left << obj.artistName;
	strm << setw(20) << left << obj.title;
	strm << setw(15) << left << albumLength;
	obj.songs.displayList(53);
	//strm << setw(10) << left << obj.songs;
	return strm;
}


ostream &operator << (ostream &strm, const CD::song &obj)
{
	string albumLength = "";
	int mins = obj.length / 60;
	int secs = obj.length % 60;
	albumLength.append(to_string(mins));
	albumLength.append(":");
	if (secs < 10) {
		albumLength.append("0");
	}
	albumLength.append(to_string(secs));

	strm << setw(30) << left << obj.title;
	strm << setw(10) << right << albumLength;
	return strm;
}

