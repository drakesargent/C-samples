#include <iostream>
#include <iomanip>
#include "CD.h"
#include "DVD.h"


using namespace std;

LList<CD> CDLib;
LList<DVD> DVDLib;

void initialCDData(LList<CD> &lib);
void initialDVDData(LList<DVD> &lib);
void displayMenu();
void runMenuChoice(LList<CD> &cd, LList<DVD>&dvd, bool &cont);
void displayLibrary(LList<CD> &cd, LList<DVD>&dvd);
void displayCDs(LList<CD>&);
void displayDVDs(LList<DVD>&);
void removeCD(int, LList<CD>&);
void removeDVD(int, LList<DVD>&);
CD addCD();
DVD addDVD();

int main()
{
	

	initialCDData(CDLib);
	initialDVDData(DVDLib);
	
	//loop for menu -- menu choice stops loop
	bool proceed = true;
	do
	{
		displayMenu();
		runMenuChoice(CDLib, DVDLib, proceed);

	} while (proceed);


	return 0;
}

//used to initalize data for library object
void initialCDData(LList<CD> &lib)
{
	string phsongs[12] = { "You","Creep","How Do You?", "Stop Whispering", "Thinking About You",
		"Anyone Can Play Guitar", "Ripcord", "Vegetable", "Prove Yourself", "I Can't", "Lurgee",
		"Blow Out" };

	int phSLengths[12] = { 209, 236, 132, 326, 161, 218, 190, 193, 145, 253, 188, 280 };

	string epsongs[14] = { "Blue (Da Ba Dee)", "Too Much of Heaven", "Dub in Life", "Living in a Bubble",
		"Move Your Body", "My Console", "Your Clown", "Another Race", "The Edge", "Now is Forever",
		"Silicon World", "Europop", "Hyperlink (Deep Down)", "Blue (Da Ba Dee) extended" };

	int epLenghts[14] = { 210, 317, 237, 303, 268, 253, 249, 274, 260, 344, 271, 328, 297, 286 };

	string vssongs[12] = { "Hidden Place", "Cocoon", "It's Not Up to You", "Undo", "Pagan Poetry",
		"Frosti", "Aurora", "An Echo, a Stain", "Sun in My Mouth", "Heirloom", "Harm of Will",
		"Unison" };

	int vslengths[12] = { 328, 268, 308, 338, 314, 101, 279, 244, 160, 312, 276, 405 };

	string rossongs[14] = { "Ex-Girlfriend", "Simple Kind of Life", "Bathwater", "Six Feet Under",
		"Magic's in the Makeup", "Artificial Sweetener", "Marry Me", "New", "Too Late", "Comforting Lie",
		"Suspension Without Suspense", "Starting Problem", "Home Now", "Dark Blue" };

	int roslengths[14] = { 211, 256, 243, 148, 261, 234, 279, 266, 254, 173, 250, 164, 275, 630 };

	CD PabloHoney("Pablo Honey", "Radiohead", phsongs, phSLengths, 12);
	CD Europop("Europop", "Eiffel 65", epsongs, epLenghts, 14);
	CD Vespertine("Vespertine", "Bjork", vssongs, vslengths, 12);
	CD ReturnofSaturn("Return of Saturn", "No Doubt", rossongs, roslengths, 14);

	lib.appendNode(PabloHoney);
	lib.appendNode(Europop);
	lib.appendNode(Vespertine);
	lib.appendNode(ReturnofSaturn);
}

void initialDVDData(LList<DVD> &lib)
{
	string psychoN[] = {"Anthony Perkens","Vera Miles", "John Gavin", "Janet Leigh", "Martin Balsam", "John McIntire",
		"Simon Oakland", "Frank Albertson", "Patricia Hitchcock", "Vaughn Taylor", "Laurine Tuttle", "John Anderson",
		"Mort Mills"};
	string psychoC[] = {"Norman Bates", "Lila Crane", "Sam Loomis", "Marion Crane", "Det. Milton Arbogast", "Sheriff Al Chambers",
		"Dr. Fred Richman", "Tom Cassidy", "Caroline", "George Lowery", "Mrs. Chambers", "California Charlie", "Highway Patrol Officer"
	};
	DVD psycho("Psycho", 1960, 6540, psychoN, psychoC, 13);

	string birdsN[] = { "Tippi Hedren", "Suzanne Pleshette", "Rod Taylor", "Jessica Tandy", "Veronica Cartwright", "Ethel Griffles",
		"Charles McGraw"
	};
	string birdsC[] = { "Melanie Daniels", "Annie Hayworth", "Mitch Brenner", "Lydia Brenner", "Cathy Brenner", "Mrs. Bundy", "Sebastian Sholes"
	};
	DVD birds("The Birds", 1963, 7140, birdsN, birdsC, 7);
	

	string darkN[] = {"Audrey Hepburn", "Alan Arkin", "Richard Crenna", "Efrem Zimbalist Jr.", "Jack Weston", "Samantha Jones", "Julie Herrod"
	};
	string darkC[] = {"Susy Hendrix", "Roat, Roat Jr., Roat Sr.", "Mike Talman", "Sam Hendrix", "Carlino", "Lisa", "Gloria"
	};
	DVD dark("Wait Until Dark", 1967, 6480, birdsN, birdsC, 7);

	lib.appendNode(psycho);
	lib.appendNode(birds);
	lib.appendNode(dark);
}

//Menu
void displayMenu()
{
	// display string variables
	string menuline = "----------------------------------";
	string spacer = "|";
	string display = "|  1. Display Media Library      |";
	string add = "|  2. Add a CD/DVD               |";
	string deleteA = "|  3. Delete a CD/DVD            |";
	string modify = "|  4. Modify a CD/DVD            |";
	string exitPro = "|  5. Exit Media Track           |";

	// loop to frame menu
	for (int i = 0; i < 32; i++)
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
	cout << "WELCOME TO MEDIA TRACK";
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

void runMenuChoice(LList<CD> &cd, LList<DVD>&dvd, bool &cont)
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
		displayLibrary(cd, dvd);
		break;
	case 2:
		cout << "Type 1 for CD or 2 for DVD: ";
		int type;
		cin >> type;
		cin.ignore();
		switch (type) 
		{
		case 1:
			cd.appendNode(addCD());
			break;
		case 2:
			dvd.appendNode(addDVD());
			break;
		default:
			break;
		}
		break;
	case 3:
		cout << "Type 1 for CD or 2 for DVD: ";
		int x;
		cin >> x;
		cin.ignore();
		switch (x)
		{
		case 1:
			displayCDs(CDLib);
			cout << "Enter the # you would like to delete: ";
			int del1;
			cin >> del1;
			cin.ignore();
			removeCD(del1, CDLib);
			displayCDs(CDLib);
			break;
		case 2:
			displayDVDs(DVDLib);
			cout << "Enter the # you would like to delete: ";
			int del2;
			cin >> del2;
			cin.ignore();
			removeDVD(del2, DVDLib);
			displayDVDs(DVDLib);
			break;
		default:
			break;
		}
		break;
	case 4:
		//function to modify cd
		//modifyCD(lib); not implemented
		break;
	case 5:
		cont = false;
		break;
	default:
		cont = false;
		break;
	}

}
void displayLibrary(LList<CD> &cd, LList<DVD>&dvd)
{
	//table header
	cout << setw(3) << left << "#";
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
	cd.displayList();

	//table header
	cout << setw(3) << left << "#";
	cout << setw(20) << left;
	cout << "MOVIE TITLE";
	cout << setw(15) << left;
	cout << "PLAY TIME";
	cout << setw(15) << left;
	cout << "YEAR RELEASED";
	cout << setw(30) << left;
	cout << "ACTORS/ACTRESSES";
	cout << setw(10) << left;
	cout << "CHARACTERS" << endl;
	//line break
	for (int i = 0; i < 117; i++)
	{
		cout << '-';
	}
	cout << endl;
	dvd.displayList();
}
void displayCDs(LList<CD>&cd)
{
	//table header
	cout << setw(3) << left << "#";
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
	cd.displayList();
}
void displayDVDs(LList<DVD>&dvd)
{
	//table header
	cout << setw(3) << left << "#";
	cout << setw(20) << left;
	cout << "MOVIE TITLE";
	cout << setw(15) << left;
	cout << "PLAY TIME";
	cout << setw(15) << left;
	cout << "YEAR RELEASED";
	cout << setw(30) << left;
	cout << "ACTORS/ACTRESSES";
	cout << setw(10) << left;
	cout << "CHARACTERS" << endl;
	//line break
	for (int i = 0; i < 117; i++)
	{
		cout << '-';
	}
	cout << endl;
	dvd.displayList();
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
DVD addDVD()
{
	//declare variables required to instanciate a new CD
	string title;
	int year;
	int runTime;
		
	//line break
	for (int i = 0; i < 117; i++)
	{
		cout << '-';
	}
	cout << endl;
	//get album name and artist name
	cout << setw(66) << "Enter Movie Title: ";
	getline(cin, title);
	cout << setw(66) << "Enter Year Produced: ";
	cin >> year;
	cin.ignore();
	cout << setw(66) << "Enter Run Time in Seconds: ";
	cin >> runTime;
	cin.ignore();
	//line break
	for (int i = 0; i < 117; i++)
	{
		cout << '-';
	}
	cout << endl;
	//loop variables to get track information
	bool nextActor = true;
	int ActorNum = 0;
	string names[50];
	string characters[50];
	do
	{
		//track name and length variables
		string name;
		string character;
		//request user input
		cout << setw(66);
		cout << "Enter the Name of the first actor: ";
		getline(cin, name);

		cout << setw(66);
		cout << "Enter the Character"<< name <<" played:";
		getline(cin, character);
		

		names[ActorNum] = name;
		characters[ActorNum] = character;
		
		
		//check to see if user is finished track input
		char proceed;
		cout << setw(66);
		cout << "Is there another actor to enter? (y or n)";
		cin >> proceed;
		cin.ignore();
		switch (proceed)
		{
		case 'Y':
		case 'y':
			ActorNum++;
			break;
		case 'N':
		case 'n':
		default:
			nextActor = false;
			break;
		}

	} while (nextActor);
	
	//create and return CD object
	DVD addition( title, year, runTime, names, characters, ActorNum);

	return addition;
}

void removeCD(int num, LList<CD> &cd)
{
	cd.deleteNode(num - 1);
}
void removeDVD(int num, LList<DVD> &dvd)
{
	dvd.deleteNode(num - 1);
}

