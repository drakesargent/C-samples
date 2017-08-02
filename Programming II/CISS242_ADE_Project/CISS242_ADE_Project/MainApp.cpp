#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "CD.h"

using namespace std;

//initial cd library vector declaration
vector<CD>CD_Library;

//prototype function declaration
void displayMenu();
void runMenuChoice(vector<CD>&, bool&);
void displayAlbumArtist(vector<CD>);
void displayLibrary(vector<CD>);
void displayCD(CD);
CD addCD();
void removeCD(vector<CD>&);
void modifyCD(vector<CD>&);
void initialCDData(vector<CD>&);

int main()
{
	//initalize CD Library data
	initialCDData(CD_Library);
	//loop for menu -- menu choice stops loop
	bool proceed = true;
	do
	{
		displayMenu();
		runMenuChoice(CD_Library, proceed);

	} while (proceed);

	system("pause");
	return 0;
}

//Menu
void displayMenu()
{
	// display string variables
	string menuline = "----------------------------------";
	string spacer = "|";
	string display = "|  1. Display Album Library      |";
	string add = "|  2. Add an Album               |";
	string deleteA = "|  3. Delete an Album            |";
	string modify = "|  4. Modify an Album            |";
	string exitPro = "|  5. Exit CD TRACK              |";
	
	// loop to frame menu
	for(int i = 0; i < 32; i++)
	{
		spacer.append(" ");
	}
	spacer.append("|");

	// loop for line break
	for (int i = 0; i < 117; i++)
	{
		cout << '-';
	}
	cout << endl;
	//Program menu title
	cout << setw(66);
	cout << "WELCOME TO CD TRACK";
	cout << endl;
	// loop for line break
	for (int i = 0; i < 117; i++)
	{
		cout << '-';
	}
	cout << endl;
	// menu text out
	cout << setw(66) << menuline << endl;
	cout << setw(66) << "| Choose from an option below:   |" << endl;
	cout << setw(66) << menuline << endl;
	cout << setw(66) << spacer << endl;
	cout << setw(66) << display << endl;
	cout << setw(66) << add << endl;
	cout << setw(66) << deleteA << endl;
	cout << setw(66) << modify << endl;
	cout << setw(66) << exitPro << endl;
	cout << setw(66) << spacer << endl;
	cout << setw(66) << menuline << endl;

}
//process choice
void runMenuChoice(vector<CD> &lib, bool &cont)
{
	// get input
	cout << setw(66) << "";
	int choice;
	cin >> choice;
	cin.ignore();

	//process choice -- exit if choice not in scope
	switch (choice)
	{
	case 1:
		//function to display library
		displayLibrary(lib);
		break;
	case 2:
		//function to add cd
		lib.push_back(addCD());
		break;
	case 3:
		//function to remove cd
		removeCD(lib);
		break;
	case 4:
		//function to modify cd
		modifyCD(lib);
		break;
	case 5:
		cont = false;
		break;
	default:
		cont = false;
		break;
	}

}
//Display Library
void displayLibrary(vector<CD> lib)
{
	//table header
	cout << setw(15) << left;
	cout << "ARTIST";
	cout << setw(20) << left;
	cout << "ALBUM TITLE";
	cout << setw(15) << left;
	cout << "ALBUM LENGTH";
	cout << setw(30) << left;
	cout << "TRACK";
	cout << setw(10) << right;
	cout << "LENGTH" << endl;
	//line break
	for (int i = 0; i < 117; i++)
	{
		cout << '-';
	}
	cout << endl;

	//get library size
	int lib_len = lib.size();

	//loop to process each library component
	for (int i = 0; i < lib_len; i++)
	{
		//declare variables to hold tracks and lengths
		vector<string>tracks;
		vector<int>lengths;
		
		//loop to store tracks and lengths
		for (string str : lib[i].getSongTitles())
		{
			tracks.push_back(str);
		}
		
		for (int len : lib[i].getSongLengths())
		{
			lengths.push_back(len);
		}
		//process album length to be formatted mm:ss as a string
		string albumLength = "";
		int mins = lib[i].getAlbumLength() / 60;
		int secs = lib[i].getAlbumLength() % 60;
		albumLength.append(to_string(mins));
		albumLength.append(":");
		if (secs < 10) {
			albumLength.append("0");
		}
		albumLength.append(to_string(secs));

		//get number of tracks
		int numTracks = tracks.size();

		//out put first line including album/artist/length information
		cout << setw(15) << left;
		cout << lib[i].getArtistName();
		cout << setw(20) << left;
		cout << lib[i].getAlbumName();
		cout << setw(15) << left;
		cout << albumLength;
		
		//loop through for printing all track/lenght information
		for (int j = 0; j < numTracks; j++)
		{
			//if it is the first line format this way
			if (j == 0)
			{
				cout << setw(30) << left;
				cout << tracks[j];
				cout << setw(10) << right;
				cout << lengths[j] / 60 << ":";
				if (lengths[j] % 60 < 10)
				{
					cout << "0";
				}
					cout << lengths[j] % 60 << endl;

			}
			//each line after the first print this way
			else
			{
				cout << setw(15) << left << "";
				cout << setw(20) << left << "";
				cout << setw(15) << left << "";
				cout << setw(30) << left;
				cout << tracks[j];
				cout << setw(10) << right;
				cout << lengths[j] / 60 << ":";
				if (lengths[j] % 60 < 10)
				{
					cout << "0";
				}

					cout << lengths[j] % 60 << endl;

			}
		}
		//line break
		for (int i = 0; i < 117; i++)
		{
			cout << '-';
		}
		cout << endl;
	}
	//end of album list line break
	for (int i = 0; i < 117; i++)
	{
		cout << '-';
	}
	cout << endl;
}
//display information from a single CD -- used in other functions Identical to the above save for looping through the vector object
void displayCD(CD album)
{
	cout << setw(15) << left;
	cout << "ARTIST";
	cout << setw(20) << left;
	cout << "ALBUM TITLE";
	cout << setw(15) << left;
	cout << "ALBUM LENGTH";
	cout << setw(30) << left;
	cout << "TRACK";
	cout << setw(10) << right;
	cout << "LENGTH" << endl;
	for (int i = 0; i < 117; i++)
	{
		cout << '-';
	}
	cout << endl;
	
	vector<string>tracks;
	vector<int>lengths;

	for (string str : album.getSongTitles())
	{
		tracks.push_back(str);
	}

	for (int len : album.getSongLengths())
	{
		lengths.push_back(len);
	}
	string albumLength = "";
	int mins = album.getAlbumLength() / 60;
	int secs = album.getAlbumLength() % 60;


	albumLength.append(to_string(mins));
	albumLength.append(":");
	if (secs < 10) {
		albumLength.append("0");
	}
	albumLength.append(to_string(secs));

	int numTracks = tracks.size();

	cout << setw(15) << left;
	cout << album.getArtistName();
	cout << setw(20) << left;
	cout << album.getAlbumName();
	cout << setw(15) << left;
	cout << albumLength;

	for (int j = 0; j < numTracks; j++)
	{
		if (j == 0)
		{
			cout << setw(30) << left;
			cout << tracks[j];
			cout << setw(10) << right;
			cout << lengths[j] / 60 << ":";
			if (lengths[j] % 60 < 10)
			{
				cout << "0";
			}
			cout << lengths[j] % 60 << endl;

		}
		else
		{
			cout << setw(15) << left << "";
			cout << setw(20) << left << "";
			cout << setw(15) << left << "";
			cout << setw(30) << left;
			cout << tracks[j];
			cout << setw(10) << right;
			cout << lengths[j] / 60 << ":";
			if (lengths[j] % 60 < 10)
			{
				cout << "0";
			}

			cout << lengths[j] % 60 << endl;

		}
	}
	for (int i = 0; i < 117; i++)
	{
		cout << '-';
	}
	cout << endl;
}
//Display Album/Artist for List Processing
void displayAlbumArtist(vector<CD> lib)
{
	//Table header
	cout << setw(15) << left;
	cout << "RECORD NUMBER";
	cout << setw(15) << left;
	cout << "ARTIST";
	cout << setw(20) << left;
	cout << "ALBUM TITLE" << endl;
	//if nothing exists in the library object only display this line
	if (lib.empty())
	{
		cout << setw(30) << "No Records Exist" << endl;
	}
	//otherwise print out the data
	else
	{
		int count = 1;
		for (int i = 0; i < 117; i++)
		{
			cout << '-';
		}
		cout << endl;
		for (CD disk : lib)
		{
			cout << setw(5) << " " << setw(10) << count;
			cout << setw(15) << left << disk.getArtistName();
			cout << setw(20) << left << disk.getAlbumName() << endl;
			count++;
		}
		for (int i = 0; i < 117; i++)
		{
			cout << '-';
		}
		cout << endl;
	}
}
//Display specific CD tracks with track lengths
void displayTracksLenghts(vector<string> tracks, vector<int> lengths)
{
	//table header
	cout << setw(11) << " ";
	cout << setw(30) << left << "Track Title";
	cout << setw(10) << left << "Track Length (in seconds)" << endl;
	//line break
	for (int i = 0; i < 117; i++)
	{
		cout << '-';
	}
	cout << endl;
	//initialize counter for track numbers
	int count = 1;
	//loop through tracks
	for (string track : tracks)
	{
		//build single track number string
		string trackNo = "Track ";
		trackNo.append(to_string(count));
		trackNo.append(":");

		//create an index to use on parallel vector for song lengths 
		int lengthIndex = count - 1;
		cout << setw(11)<< left << trackNo;
		cout << setw(30) << left <<track <<setw(10)<<left<< lengths[lengthIndex] <<endl;
		//increment counter
		count++;
	}
	//line break
	for (int i = 0; i < 117; i++)
	{
		cout << '-';
	}
	cout << endl;
}
//Add CD
CD addCD()
{
	//declare variables required to instanciate a new CD
	string artistName;
	string albumName;
	vector<string> tracks;
	vector<int> lengths;
	//line break
	for (int i = 0; i < 117; i++)
	{
		cout << '-';
	}
	cout << endl;
	//get album name and artist name
	cout << setw(66) << "Enter Artist's Name: ";
	getline(cin, artistName);
	cout << setw(66) << "Enter Album Name: ";
	getline(cin, albumName);
	//line break
	for (int i = 0; i < 117; i++)
	{
		cout << '-';
	}
	cout << endl;
	//loop variables to get track information
	bool nextTrack = true;
	int trackNum = 1;
	do
	{
		//track name and length variables
		string track;
		int length;
		//request user input
		cout << setw(66);
		cout << "Enter the song title for track " << trackNum << ":";
		getline(cin, track);
		
		cout << setw(66);
		cout << "Enter the song length in seconds for track " << trackNum << ":";
		cin >> length;
		cin.ignore();
		
		//potential need for input validation

		// add user input to vector variables
		tracks.push_back(track);
		lengths.push_back(length);
		
		//check to see if user is finished track input
		char proceed;
		cout << setw(66);
		cout << "Is there a track " << ++trackNum << "? (y or n)";
		cin >> proceed;
		cin.ignore();
		switch (proceed)
		{
		case 'Y':
		case 'y':
			break;
		case 'N':
		case 'n':
		default:
			nextTrack = false;
			break;
		}

	} while (nextTrack);
	
	//create and return CD object
	CD addition(albumName, artistName, tracks, lengths);
	
	return addition;
}
//Remove CD
void removeCD(vector<CD> &lib)
{
	//check to see if library is empty -- display empty library notice if so
	if (lib.empty())
	{
		displayAlbumArtist(lib);
	}
	else {
		//initialize disk removal number variable
		int rNum;
		//display simplified list of albums and artists
		displayAlbumArtist(lib);
		//get user input
		cout << "Enter the record number you would like to remove: ";
		cin >> rNum;
		cin.ignore();
		//decrement for vector use
		rNum--;
		//create a second library
		vector<CD> newLib;
		//get first library size
		int libSize = lib.size();
		
		//loop through
		for (int i = 0; i < libSize; i++)
		{
			//if iteration matches removal number move on
			if (i == rNum)
			{
				continue;
			}
			//otherwise add CD index from library to new library
			else
			{
				newLib.push_back(lib[i]);
			}
		}
		//remove one CD from the library
		lib.pop_back();
		//swap new library to old library
		lib.swap(newLib);
		//display modified list of albums with artists
		displayAlbumArtist(lib);
	}	
}
//Update CD
void modifyCD(vector<CD> &lib)
{
	//test if library is empty and display message if so
	if (lib.empty())
	{
		displayAlbumArtist(lib);
	}
	else {
		//variable to store record number
		int rNum;
		displayAlbumArtist(lib);
		//request record number
		cout << "Enter the record number you would like to modify: ";
		cin >> rNum;
		cin.ignore();
		//validation needed
		//decrement record number for use 
		rNum--;

		cout << endl;
		cout << setw(66) << "You chose the following album: " << endl;
		for (int i = 0; i < 117; i++)
		{
			cout << '-';
		}
		cout << endl;

		//display album choice for validation
		displayCD(lib[rNum]);
		cout << endl;
		
		//variable used for modify menu choice
		int choice;
	
		string menuline = "----------------------------------";
		string spacer = "|";
		// loop to frame menu
		for (int i = 0; i < 32; i++)
		{
			spacer.append(" ");
		}
		spacer.append("|");

		cout << setw(66) << menuline << endl;
		cout << setw(66) << "| What would you like to modify? |" << endl;
		cout << setw(66) << menuline << endl;
		cout << setw(66) << spacer << endl;
		cout << setw(66) << "| 1. Artist Name                 |" << endl;
		cout << setw(66) << "| 2. Album Name                  |" << endl;
		cout << setw(66) << "| 3. Track Information           |" << endl;
		cout << setw(66) << "| 4. Back to Main Menu           |" << endl;
		cout << setw(66) << spacer << endl;
		cout << setw(66) << menuline << endl;

		cout << setw(66) << "";
		cin >> choice;
		cin.ignore();
		cout << endl;
		
		//variable declaration to cover all options in modify menu choice
		string newName;
		string newTrack;
		vector<string> newTrackList;
		vector<int> newTrackLenghtList;
		int newLength;
		int songNum;
		int counter = 1;
		
		switch (choice)
		{
		case 1: 
			//get user input for artist name
			cout << setw(66) <<""<< "Enter new artist name: ";
			getline(cin, newName);
			//set artist name with CD object function
			lib[rNum].setArtistName(newName);
			cout << endl;
			//validate change with output
			cout << setw(66) << "" << "Artist name is now: " << lib[rNum].getArtistName() << endl;
			break;
		case 2:
			//get user input for album name
			cout << setw(66) << "" << "Enter new album name: ";
			getline(cin, newName);
			//set album name with CD object function
			lib[rNum].setAlbumName(newName);
			cout << endl;
			//validate change with output
			cout << setw(66) << "" << "Album name is now: " << lib[rNum].getAlbumName() << endl;
			break;
		case 3:
			//declare new choice variable
			int modchoice;
			//display tracks
			cout << setw(66) << "" << "These are the current tracks for "<<lib[rNum].getAlbumName() <<endl;
			displayTracksLenghts(lib[rNum].getSongTitles(), lib[rNum].getSongLengths());
			cout << endl;
			
			//display track modification menu
			// loop to frame menu
		
			cout << setw(66) << menuline << endl;
			cout << setw(66) << "| How would you like to modify?  |" << endl;
			cout << setw(66) << menuline << endl;
			cout << setw(66) << spacer << endl;
			cout << setw(66) << "| 1. Add new track               |" << endl;
			cout << setw(66) << "| 2. Modify existing track name  |" << endl;
			cout << setw(66) << "| 3. Modify existing track length|" << endl;
			cout << setw(66) << "| 4. Remove track                |" << endl;
			cout << setw(66) << "| 5. Back to Main Menu           |" << endl;
			cout << setw(66) << spacer << endl;
			cout << setw(66) << menuline << endl;

			cout << setw(66) << "";
			//store user choice
			cin >> modchoice;
			cin.ignore();
			cout << endl;
			//process choice
			switch (modchoice)
			{
			case 1:
				//get user input for new track name and length
				cout << setw(66) << "" << "Enter new track name: ";
				getline(cin, newTrack);
				cout << endl;
				cout << setw(66) << "" << "Enter track length in seconds: ";
				cin >> newLength;
				cin.ignore();
				//use built in object function to add a track to an existing CD
				lib[rNum].addSong(newTrack, newLength);
				cout << endl;
				//display output for validation
				cout << setw(66) << "" << "This is the new track listing: " << endl;
				displayTracksLenghts(lib[rNum].getSongTitles(), lib[rNum].getSongLengths());
				break;
			case 2:
				//get user input for track to change
				cout << setw(66) << "" << "Enter the number of the track you want to change: ";
				cin >> songNum;
				cin.ignore();
				//decrement to use for vector
				songNum--;
				//get user input for new track name
				cout << setw(66) << "" << "Enter new track name: ";
				getline(cin, newTrack);
				cout << endl;
				//use built in CD function to modify track name
				lib[rNum].setSongName(newTrack, songNum);
				cout << endl;
				//display output for validation
				cout << setw(66) << "" << "This is the new track listing: " << endl;
				displayTracksLenghts(lib[rNum].getSongTitles(), lib[rNum].getSongLengths());
				break;
			case 3:
				//get user input for track to change
				cout << setw(66) << "" << "Enter the number of the track you want to change: ";
				cin >> songNum;
				cin.ignore();
				//decrement to use for vector
				songNum--;
				//get user input for track length
				cout << setw(66) << "" << "Enter new track length in seconds: ";
				cin >> newLength;
				cin.ignore();
				cout << endl;
				//use built in CD function to modify song length
				lib[rNum].setSongLength(newLength, songNum);
				cout << endl;
				//display output for validation
				cout << setw(66) << "" << "This is the new track listing: " << endl;
				displayTracksLenghts(lib[rNum].getSongTitles(), lib[rNum].getSongLengths());
				break;
			case 4:
				//get user input for track to remove
				cout << setw(66) << "" << "Enter the number of the track you want to remove: ";
				cin >> songNum;
				cin.ignore();
				
				//loop to fill new track list so long as counter doesn't equal songnumber for removal
				for (string title : lib[rNum].getSongTitles())
				{
					if (counter != songNum)
					{
						newTrackList.push_back(title);
					}
					counter++;
				}
				//reset counter
				counter = 1;
				//loop to fill new track length list so long as counter doesn't equal songnumber for removal
				for (int length : lib[rNum].getSongLengths())
				{
					if (counter != songNum)
					{
						newTrackLenghtList.push_back(length);
					}
					counter++;
				}
				//use CD functions to set song titles and track lengths
				lib[rNum].setSongTitles(newTrackList);
				lib[rNum].setSongLengths(newTrackLenghtList);
				
				cout << endl;
				//display output for validation
				cout << setw(66) << "" << "This is the new track listing: " << endl;
				displayTracksLenghts(lib[rNum].getSongTitles(), lib[rNum].getSongLengths());
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}
	}
}
//used to initalize data for library object
void initialCDData(vector<CD> &lib)
{
	string phsongs[12] = { "You","Creep","How Do You?", "Stop Whispering", "Thinking About You",
		"Anyone Can Play Guitar", "Ripcord", "Vegetable", "Prove Yourself", "I Can't", "Lurgee",
		"Blow Out" };

	int phSLengths[12] = { 209, 236, 132, 326, 161, 218, 190, 193, 145, 253, 188, 280 };

	string epsongs[14] = { "Blue (Da Ba Dee)", "Too Much of Heaven", "Dub in Life", "Living in a Bubble",
		"Move Your Body", "My Console", "Your Clown", "Another Race", "The Edge", "Now is Forever",
	    "Silicon World", "Europop", "Hyperlink (Deep Down)", "Blue (Da Ba Dee) extended"};

	int epLenghts[14] = { 210, 317, 237, 303, 268, 253, 249, 274, 260, 344, 271, 328, 297, 286 };

	string vssongs[12] = {"Hidden Place", "Cocoon", "It's Not Up to You", "Undo", "Pagan Poetry",
		"Frosti", "Aurora", "An Echo, a Stain", "Sun in My Mouth", "Heirloom", "Harm of Will",
	    "Unison"};

	int vslengths[12] = {328, 268, 308, 338, 314, 101, 279, 244, 160, 312, 276, 405};

	string rossongs[14] = {"Ex-Girlfriend", "Simple Kind of Life", "Bathwater", "Six Feet Under",
		"Magic's in the Makeup", "Artificial Sweetener", "Marry Me", "New", "Too Late", "Comforting Lie",
		"Suspension Without Suspense", "Starting Problem", "Home Now", "Dark Blue"};

	int roslengths[14] = { 211, 256, 243, 148, 261, 234, 279, 266, 254, 173, 250, 164, 275, 630 };

	CD PabloHoney("Pablo Honey", "Radiohead", phsongs, phSLengths, 12);
	CD Europop("Europop", "Eiffel 65", epsongs, epLenghts, 14);
	CD Vespertine("Vespertine", "Bjork", vssongs, vslengths, 12);
	CD ReturnofSaturn("Return of Saturn", "No Doubt", rossongs, roslengths, 14);

	lib.push_back(PabloHoney);
	lib.push_back(Europop);
	lib.push_back(Vespertine);
	lib.push_back(ReturnofSaturn);
}
