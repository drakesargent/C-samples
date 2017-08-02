#include <iostream>
#include <fstream>
#include <iomanip>
#include "ExamRoom.h"




// output files
ofstream testout; // test driver output file
ofstream transout; // transaction output

// constants
const int MAX_ERS = 100;

// prototype function declarations
// file operations
bool openFile(ifstream&, string);
bool openFile(ofstream&, string);
void closeFile(ifstream&);
void closeFile(ofstream&);

// test driver functions for each data structure
void testDrive(ofstream&);
void testPerson(ofstream&, ifstream&, Person&);
void testDoctor(ofstream&, ifstream&, Doctor&);
void testPatient(ofstream&, ifstream&, Patient&);
void testPQ(ofstream&, ifstream&, PQueue&);
void testER(ofstream&, ifstream&, ExamRoom&);

// data initialization
void initializeRoomNumbers(ExamRoom*);
void loadDocs(ofstream&); // loads 36 docs
void loadPats(ofstream&); // loads 200 pats

// processes the interactive checking/out choices
bool checkin(ofstream&);
// takes and processes the user entered data
void processCin(char, char, ofstream&); 

// Determines if a room is available based on
// room number and if there is a doctor in the room
bool roomAvailable(int, int&);
// Does binary search of rooms, returns index of room or -1
int searchRooms(int, int, int);
// Does sequential search of rooms by Doctors Name, returns index of room or -1
int searchRooms(string);
// Does sequential search for rooms with matching specialty
// Returns the index of the room with the smallest queue
int searchSmQueSpec(Specialty);
// If no rooms of matching specialty exist calls rooms that are
// General Practicioners, returns the index of the room with the 
// smallest queue
int searchSmQueGen(int, int&);
// If no general practitioner rooms exisit, returns index of room
// with smallest queue
int searchSmQue(int, int&);

// functions that process input for main function to checkin/out
// docs or pats
void docIn(ofstream&);
void docOut(ofstream&);
void patIn(ofstream&);
void patOut(ofstream&);

// Main apps to add or remove patients from rooms
void placeDoc(Doctor, ofstream&);
void placePat(Patient, ofstream&);
void ckoutPat(string, int, ofstream&);
void ckoutDoc(string, ofstream&);

using namespace std;

// declare ExamRooms array
ExamRoom ers[MAX_ERS];

int main()
{
	testDrive(testout);				// run object tests
	initializeRoomNumbers(ers);		// set exam rooms in the array with room numbers
	openFile(transout, "trans.out");// opens transaction file for writing 
	loadDocs(transout);				// preloads doctors
	loadPats(transout);				// preloads patients
	
	bool finished = false;			// Interactive loop
	do
	{
		finished = checkin(transout);

	} while (!finished);
	
	
	closeFile(testout);				// Closes file for writing

	return 0;
}

// file utility function definitions
bool openFile(ifstream &file, string fName)
{

	file.open(fName);


	if (file.fail() && !file.is_open()) // returns file open status
	{
		return false;
	}
	else
	{
		return true;
	}
}
bool openFile(ofstream &file, string fName)
{

	file.open(fName);


	if (file.fail() && !file.is_open()) // returns file open status
	{
		return false;
	}
	else
	{
		return true;
	}
}
void closeFile(ifstream &file)
{
	if (file.is_open()) // closes file if file is open
	{
		file.close();
	}
}
void closeFile(ofstream &file)
{
	if (file.is_open()) // closes file if file is open
	{
		file.close();
	}
}

// object testing function
void testDrive(ofstream &tout)
{
	if (openFile(tout, "Test.out"))
	{
		tout << "INITIALIZING TEST STREAMS" << endl;
		ifstream tper, tdoc, tpat, tpq, ter;
		tout << "ATTEMPTING PERSON TEST: " << endl;
		if (openFile(tper, "tper.txt"))
		{
			tout << "-------------------------\n" << endl;
			Person per;
			testPerson(tout, tper, per);
			closeFile(tper);
		}
		tout << "ATTEMPTING DOCTOR TEST: " << endl;
		if (openFile(tdoc, "tdoc.txt"))
		{
			tout << "-------------------------\n" << endl;
			Doctor doc;
			testDoctor(tout, tdoc, doc);
			closeFile(tdoc);
		}
		tout << "ATTEMPTING PATIENT TEST: " << endl;
		if (openFile(tpat, "tpat.txt"))
		{
			tout << "-------------------------\n" << endl;
			Patient pat;
			testPatient(tout, tpat, pat);
			closeFile(tpat);
		}
		tout << "ATTEMPTING PQUEUE TEST: " << endl;
		if (openFile(tpq, "tpq.txt"))
		{
			tout << "-------------------------\n" << endl;
			PQueue que;
			testPQ(tout, tpq, que);
			closeFile(tpq);
		}
		tout << "ATTEMPTING EXAMROOM TEST: " << endl;
		if (openFile(ter, "ter.txt"))
		{
			tout << "-------------------------\n" << endl;
			ExamRoom exr;
			testER(tout, ter, exr);
			closeFile(ter);
		}

		tout << "---END OF TESTING---" << endl;
		closeFile(tout);
	}
}
// calls for each object test with unique input
void testPerson(ofstream &tout, ifstream &tper, Person &per)
{
	string line;
	
	while (line != "Quit")
	{
		getline(tper, line);
		if (line == "Initialize")
		{
			tout << "Getting next line." << endl;
		}
		else if (line == "SetName")
		{
			string Name;
			getline(tper, Name, '\n');
			tout << "Setting name to "<< Name << endl;
			per.setName(Name);
			tout << "Name Set" << endl;
		}
		else if (line == "GetSpec")
		{
			tout << "Getting Specialty" << endl;
			tout << per.getSpec() << endl;
		}
	}
	tout << "---Exiting Person Test---\n" << endl;
}
void testDoctor(ofstream &tout, ifstream &tdoc, Doctor &doc)
{
	string line;
	Doctor NewDoc;

	while (line != "Quit")
	{
		getline(tdoc, line);
		if (line == "Initialize")
		{
			tout << "Getting next line." << endl;
		}
		else if (line == "GetSpec")
		{
			tout << "Getting doctor specialty." << endl;
			tout << doc.getSpec() << endl;
		}
		else if (line == "SetSpec")
		{
			tout << "Setting doctor specialty." << endl;
			int spex;
			tdoc >>spex;
			Specialty deet;
			deet = static_cast<Specialty>(spex);
			doc.setSpec(deet);
		}
		else if (line == "GetRoomPref")
		{
			tout << "Getting doctor room preference." << endl;
			tout << doc.getRoomPref() << endl;
		}
		else if (line == "SetRoomPref")
		{
			tout << "Setting doctor room preference." << endl;
			int room;
			tdoc >> room;
			doc.setRoomPref(room);
		}
		else if (line == "NewDoc")
		{
			tout << "New Doctor Here" << endl;
		}
		else if (line == "Equal")
		{
			tout << "Test Doctor will be new doctor" << endl;
			doc = NewDoc;
		}
		
	}
	tout << "---Exiting Doctor Test---\n" << endl;
}
void testPatient(ofstream &tout, ifstream &tpat, Patient &pat)
{
	string line;
	Patient NewPat;

	while (line != "Quit")
	{
		getline(tpat, line);
		if (line == "Initialize")
		{
			tout << "Getting next line." << endl;
		}
		else if (line == "SetSpec")
		{
			tout << "Setting patient desired doctor specialty." << endl;
			int spex;
			tpat >> spex;
			Specialty deet;
			deet = static_cast<Specialty>(spex);
			try
			{
				pat.setSpec(deet);
			}
			catch (Patient::err_age e)
			{
				tout << e.getMessage() << endl;
			}
		}
		else if (line == "getAge")
		{
			tout << "Getting patient Age." << endl;
			tout << pat.getAge() << endl;
		}
		else if (line == "setAge")
		{
			tout << "Setting patient Age." << endl;
			int age;
			tpat >> age;
			pat.setAge(age);
		}
		else if (line == "GetSpec")
		{
			tout << "Getting patient desired doctor specialty." << endl;
			tout << pat.getSpec() << endl;
		}
		else if (line == "NewPat")
		{
			tout << "New Patient Here" << endl;
		}
		else if (line == "Equal")
		{
			tout << "Test Patient will be new Patient" << endl;
			pat = NewPat;
		}

	}
	tout << "---Exiting Patient Test---\n" << endl;
}
void testPQ(ofstream &tout, ifstream &tpq, PQueue &pq)
{
	string line;

	while (line != "Quit")
	{
		getline(tpq, line);
		if (line == "Initialize")
		{
			tout << "Getting next line." << endl;
		}
		else if (line == "GetLen")
		{
			tout << "Getting Queue Length" << endl;
			tout << pq.getLen() << endl;
		}
		else if (line == "Enqueue")
		{
			tout << "Adding to the queue" << endl;
			string name;
			tpq >> name;
			Patient goin;
			goin.setName(name);
			try
			{
				pq.enqueue(goin);
				tout << "Added " << name << " to the queue." << endl;
			}
			catch (FullQueue)
			{
				tout << "Reached peak queue." << endl;
			}
		}
		else if (line == "Dequeue")
		{
			tout << "Removing person from queue." << endl;
			Patient remove;
			try 
			{
				pq.dequeue(remove);
				tout << remove.getName() << " removed from the queue." << endl;
			}
			catch (EmptyQueue)
			{
				tout << "There wasn't anyone in the queue to remove." << endl;
			}
		}
		else if (line == "Flood")
		{
			tout << "Bound checking queue add" << endl;
			bool flood = true;
			int maxcount;
			tpq >> maxcount;
			int count = 0;
			while (flood)
			{
				Patient drip;
				try
				{
					pq.enqueue(drip);
				}
				catch (FullQueue)
				{
					flood = false;
					tout << "boundary at " << count << endl;
				}
				count++;
				if (count == maxcount)
				{
					flood = false;
					tout << "boundary beyond " << count <<endl;
				}
			}
		}
		else if (line == "IsFull")
		{
			tout << "Is the list full" << endl;
			if (pq.isFull())
			{
				tout << "Yes." << endl;
			}
			else
			{
				tout << "No." << endl;
			}
		}
		else if (line == "IsEmpty")
		{
			tout << "Is the list empty" << endl;
			if (pq.isEmpty())
			{
				tout << "Yes." << endl;
			}
			else
			{
				tout << "No." << endl;
			}
		}
		else if (line == "MakeEmpty")
		{
			tout << "Emptying list" << endl;
			pq.makeEmpty();
		}

	}
	tout << "---Exiting Patient Queue Test---\n" << endl;
}
void testER(ofstream &tout, ifstream &ter, ExamRoom &er)
{
	string line;
	int rm;

	while (line != "Quit")
	{
		getline(ter, line);
		if (line == "Initialize")
		{
			tout << "Getting next line." << endl;
		}
		else if (line == "HasDoc")
		{
			tout << "Displaying if Exam Room has a Doctor." << endl;
			if (er.hasDoc())
			{
				tout << "Yes." << endl;
			}
			else
			{
				tout << "No." << endl;
			}
		}
		else if (line == "HasPat")
		{
			tout << "Displaying if Exam Room has a Patient." << endl;
			if (er.hasPat())
			{
				tout << "Yes." << endl;
			}
			else
			{
				tout << "No." << endl;
			}
		}
		else if (line == "PatsInQ")
		{
			tout << "Displaying if patients are in Exam Room queue." << endl;
			if (er.patsInQ())
			{
				tout << "Yes." << endl;
			}
			else
			{
				tout << "No." << endl;
			}
		}
		else if (line == "GetRoomNum")
		{
			tout << "Displaying Exam Room Number." << endl;
			tout << er.getRoomNum() << endl;
		}
		else if (line == "SetRoomNum")
		{
			tout << "Setting Exam Room Number." << endl;
			ter >> rm;
			er.setRoomNum(rm);
		}
		else if (line == "GetSpec")
		{
			tout << "Getting Exam Room Specialization." << endl;
			tout << er.getSpec() << endl;
		}
		else if (line == "SetDoc")
		{
			tout << "Setting Doctor for Exam Room." << endl;
			Doctor d;
			d.setName("Gerald");
			d.setRoomPref(101);
			d.setSpec(7);
			er.setDoc(d);
		}
		else if (line == "Qlen")
		{
			tout << "Displaying number of patients in Exam Room queue." << endl;
			tout << er.queueLen() << endl;
		}
		else if (line == "AddToQ")
		{
			tout << "Adding Patient to exam Room Queue." << endl;
			Patient p;
			string name;
			getline(ter, name);
			p.setName(name);
			p.setAge(19);
			er.enquePat(p);
			tout << "Patient " << p.getName() << " is enqueued." << endl;
		}
		else if (line == "SetPat")
		{
			tout << "Setting next Patient in the Exam Room." << endl;
			er.setPat();

		}
		else if (line == "CurrentPat")
		{
			tout << "Displaying current Patient in Exam Room." << endl;
			tout << er.currentPat() << endl;
		}
		else if (line == "ClearPat")
		{
			tout << "Clearing current Patient from Exam Room." << endl;
			er.clearPat();
		}
		else if (line == "ClearDoc")
		{
			tout << "Clearing current Doctor from Exam Room." << endl;
			er.clearDoc();
		}

	}
	tout << "---Exiting Exam Room Test---\n" << endl;
}

// function to initialize room numbers
void initializeRoomNumbers(ExamRoom *ers)
{
	int room = 100;							//starts at 100
	for (int i = 0; i < MAX_ERS / 10; i++)
	{
		for (int j = 0; j < 10; j++)		//increments from 100 - 109
		{
			int index = j + (i * 10);
			ers[index].setRoomNum(room);
			room += 1;
		}									//resets tens each loop
		room -= 10;							//adds floors from 100-1000
		room += 100;						//rooms from 0-9 on each floor 
	}										//ie 904, 702, 101, 500, 408
}

// preloads Doctors and patients for examrooms
void loadDocs(ofstream &tout)
{
	ifstream docs;
	if (openFile(docs, "docs.dat"))
	{
		string name = "";
		int spec;
		int room;
		Doctor d;
		while (!docs.eof())
		{
			docs >> name;
			docs >> room;
			docs >> spec;
			
			d.setName(name);
			d.setSpec(spec);
			d.setRoomPref(room);

			placeDoc(d, tout);
		}
	}
	closeFile(docs);
}
void loadPats(ofstream &tout)
{
	ifstream pats;
	if (openFile(pats, "pats.dat"))
	{
		string name = "";
		int spec;
		int age;
		string emerg = "";
		Patient p;
		while (!pats.eof())
		{
			pats >> name;
			pats >> spec;
			pats >> age;
			pats >> emerg;

			p.setName(name);
			p.setAge(age);
			p.setSpec(spec);
			p.setEmerg(emerg);

			placePat(p, tout);
		}
	}
	closeFile(pats);
}

// interactive prompt logic
bool checkin(ofstream &tout)
{
	string welcome = "Welcome to Medi-Scheduler\n--------------------------\n";
	string personType = "Type D for Doctor or P for Patient: ";
	string checkType = "Type I for check-in or O for checkout: ";
	char pt, ct;
	cout << welcome << personType;
	tout << welcome << personType;
	cin >> pt;
	tout << pt << endl;
	cout << checkType;
	tout << checkType;
	cin >> ct;
	tout << ct;

	processCin(pt, ct, tout); // processes input

	string msg = "Woud you like to continue (Y|N): ";
	cout << msg;
	tout << msg;
	char quit;
	cin >> quit;
	tout << quit;
	string border = "\n--------------------------------\n";
	
	switch (quit)
	{
	case'Y':
	case'y':
		cout << border << endl;
		tout << border << endl;
		return false;
		break;
	case'N':
	case'n':
		cout << border << endl;
		tout << border << endl;
		return true;
		break;
	default:
		cout << border << endl;
		tout << border << endl;
		return false;
	}
	return false;
}
void processCin(char p, char c, ofstream &tout)
{
	switch (p)
	{
	case 'D':
		switch (c)
		{
		case 'I':
			docIn(tout);
			break;
		case 'O':
			docOut(tout);
			break;
		default:
			cout << "Invalid Entry. Try again." << endl;
			tout << "Invalid Entry. Try again." << endl;
			break;
		}
		break;
	case 'P':
		switch (c)
		{
		case 'I':
			patIn(tout);
			break;
		case 'O':
			patOut(tout);
			break;
		default:
			cout << "Invalid Entry. Try again." << endl;
			tout << "Invalid Entry. Try again." << endl;
			break;
		}
		break;
	default:
		cout << "Invalid Entry. Try again." << endl;
		tout << "Invalid Entry. Try again." << endl;
		break;
	}
}



void docIn(ofstream &tout)
{
	cin.ignore();

	Doctor d;

	string dname = "";
	int spec;
	int roompref;

	string welcome = "\nWelcome Doctor!\nPlease enter name: ";
	string entRoom = "Enter Room # Preference: ";
	string entSpec = "Enter Specialty code #: ";
	string specialt = "1 - PED, 2 - GEN, 3 - INT, 4 - CAR, 5 - SUR, 6 - OBS, ";
	specialt.append("7 - PSY, 8 - NEU, 9 - ORT, 10 - DET, 11 - OPT, 12 - ENT");

	cout << welcome;
	tout << welcome;
	getline(cin, dname);
	tout << dname << endl;

	cout << entRoom;
	tout << entRoom;
	cin >> roompref;
	cin.ignore();
	tout << roompref << endl;

	cout << specialt << endl;
	tout << specialt << endl;
	cout << entSpec;
	tout << entSpec;
	cin >> spec;
	cin.ignore();
	tout << spec << endl;

	cout << endl;
	tout << endl;

	d.setName(dname);
	d.setRoomPref(roompref);
	spec = spec - 1;
	d.setSpec(spec);

	placeDoc(d, tout);
}
void docOut(ofstream &tout)
{
	cin.ignore();

	string dname = "";
	string welcome = "\nThank You, Doctor!\nPlease enter name to check-out: ";

	cout << welcome;
	tout << welcome;
	getline(cin, dname);
	tout << dname << endl;

	ckoutDoc(dname, tout);
}

void patIn(ofstream &tout)
{
	cin.ignore();

	Patient p;

	string dname = "";
	int spec, age;
	string eme = "";

	string welcome = "\nWelcome Patient!\nPlease enter name: ";
	string entAge = "Enter Age: ";
	string entSpec = "Enter Desired Specialty code #: ";
	string emerg = "Enter reason for visit: ";
	string specialt = "1 - PED, 2 - GEN, 3 - INT, 4 - CAR, 5 - SUR, 6 - OBS, ";
	specialt.append("7 - PSY, 8 - NEU, 9 - ORT, 10 - DET, 11 - OPT, 12 - ENT");

	// need number error checking
	cout << welcome;
	tout << welcome;
	getline(cin, dname);
	tout << dname << endl;

	cout << entAge;
	tout << entAge;
	cin >> age;
	cin.ignore();
	tout << age << endl;

	cout << emerg;
	tout << emerg;
	getline(cin, eme);
	tout << emerg << endl;

	cout << specialt << endl;
	tout << specialt << endl;
	cout << entSpec;
	tout << entSpec;
	cin >> spec;
	tout << spec << endl;

	p.setName(dname);
	p.setAge(age);
	try
	{
		spec -= 1;
		p.setSpec(spec);
	}
	catch (Patient::err_age)
	{

	}
	p.setEmerg(eme);

	placePat(p, tout);
}
void patOut(ofstream &tout)
{
	cin.ignore();

	string welcome = "\nThank you for visiting!\nPlease enter name: ";
	string entRoom = "Enter Room #: ";

	string dname = "";
	int roompref;

	cout << welcome;
	tout << welcome;
	getline(cin, dname);
	tout << dname << endl;

	cout << entRoom;
	tout << entRoom;
	cin >> roompref;
	tout << roompref << endl;

	ckoutPat(dname, roompref, tout);
}

void placeDoc(Doctor d, ofstream &tout)
{
	string greetings = "\nHello Dr. ";
	greetings.append(d.getName());
	greetings.append("\nFinding Room for you.\n");

	cout << greetings;
	tout << greetings;

	int loc = -1;
	if (roomAvailable(d.getRoomPref(), loc))
	{
		ers[loc].setDoc(d);
		string assigned = d.getName();
		assigned.append(" assigned to Room ");
		assigned.append(to_string(ers[loc].getRoomNum()));
		assigned.append("\n");

		cout << assigned << endl;
		tout << assigned << endl;
	}
	else
	{
		string sorry = "Apologies Room ";
		sorry.append(to_string(d.getRoomPref()));
		sorry.append(" either is in use or doesn't exist.\nPlease try again.\n");

		cout << sorry << endl;
		tout << sorry << endl;
	}
}
void placePat(Patient p, ofstream &tout)
{
	string greetings = "\nHello ";
	greetings.append(p.getName());
	greetings.append("\nFinding a doctor and exam room for you.\n");

	cout << greetings;
	tout << greetings;

	int pos = -1;
	try
	{
		pos = searchSmQueSpec(p.getSpec());
	}
	catch (NoDoctors)
	{
		string sorry = "\n---Apologies the doctors have not arrived yet.---\n";
		cout << sorry << endl;
		tout << sorry << endl;
		return;
	}
	if (pos >= 0)
	{
		ers[pos].enquePat(p);
		string instructions = "Please go to Room ";
		instructions.append(to_string(ers[pos].getRoomNum()));
		instructions.append(".\nYou will be seen by Dr. ");
		instructions.append(ers[pos].currentDoc());
		cout << instructions;
		tout << instructions;

		if (ers[pos].hasPat())
		{
			int numque = ers[pos].queueLen();
			cout << "\nThere are/is " << numque << " patient(s) ahead of you.\n" << endl;
			tout << "\nThere are/is " << numque << " patient(s) ahead of you.\n" << endl;
		}
		else
		{
			cout << '\n' << endl;
			tout << '\n' << endl;
			try
			{
				ers[pos].setPat();
			}
			catch (EmptyLine m)
			{
				cout << m.getMsg() << endl;
				tout << m.getMsg() << endl;
			}
			catch (RoomInUse)
			{

			}
		}
	}
}
void ckoutPat(string n, int roompref, ofstream &tout)
{
	string entRoom = "Enter Room #: ";
	bool cont = true;
	while (cont)
	{
		int loc = searchRooms(roompref, 0, 99);
		if (loc > -1)
		{
			if (ers[loc].currentPat() == n)
			{
				ers[loc].clearPat();
				cont = false;
				try
				{
					ers[loc].setPat();
				}
				catch (EmptyLine e)
				{
					cout << e.getMsg() << endl;
					tout << e.getMsg() << endl;
				}
				catch (RoomInUse)
				{

				}
				catch (NoDoctors)
				{

				}
				cout << "Thank you " << n << ".\n" << endl;
				tout << "Thank you " << n << ".\n" << endl;
			}
			else
			{
				cout << "Wrong room information " << entRoom << endl;
				tout << "Wrong room information " << entRoom << endl;
				cin >> roompref;
				cin.ignore();
				tout << roompref << endl;
			}
		}
		
	}
}
void ckoutDoc(string n, ofstream &tout)
{
	int loc = searchRooms(n);

	if (loc >= 0)
	{
		ers[loc].clearDoc();
		cout << "Thank you Dr. " << n << "!\n" << endl;
		tout << "Thank you Dr. " << n << "!\n" << endl;
		if (ers[loc].hasPat())
		{
			ckoutPat(ers[loc].currentPat(), ers[loc].getRoomNum(), tout);
		}
		if (ers[loc].patsInQ())
		{
			int len = ers[loc].queueLen();
			for (int i = 0; i < len; i++)
			{
				string msg = "*****RE-ASSIGNMENT*****\n------------------------";
				cout << msg;
				tout << msg;
				placePat(ers[loc].nextPat(), tout);
			}
		}
	}
}


bool roomAvailable(int room, int &loc)
{
	int roomLoc = searchRooms(room, 0, 99);
	if (roomLoc < 0 || ers[roomLoc].hasDoc())
	{
		return false;
	}
	else
	{
		loc = roomLoc;
		return true;
	}

}
// returns room array location
int searchRooms(int roomnum, int first, int last)			// binary search returns array location or -1
{
	int middle;
	if (first > last)
	{
		return -1;
	}
	middle = (first + last) / 2;
	if (ers[middle].getRoomNum() == roomnum)
	{
		return middle;
	}
	if (ers[middle].getRoomNum() < roomnum)
	{
		return searchRooms(roomnum, middle + 1, last);
	}
	if (ers[middle].getRoomNum() > roomnum)
	{
		return searchRooms(roomnum, first, middle - 1);
	}
} 
int searchRooms(string n)									// sequential search returns array location based on doc's name
{
	for (int i = 0; i < MAX_ERS; i++)
	{
		if (ers[i].currentDoc() == n)
		{
			return i;
		}
	}
	return -1;
}
int searchSmQueSpec(Specialty spec)							// sequential search returns room with specialist who has the smallest queue
{
	int lowest = 100;
	int count = -1;
	for (int i = 0; i < MAX_ERS; i++)
	{
		if (ers[i].hasDoc() && ers[i].getSpec() == spec)
		{
			if (ers[i].queueLen() < lowest)
			{
				lowest = ers[i].queueLen();
				count = i;
			}

		}
	}
	if (lowest == 100)										// lowest will remain 100 if no specialist was found, calls next search which returns
	{														// room location with a generalist who has the smallest queue
		count = searchSmQueGen(count, lowest);
		if (lowest == 100)
		{
			count = searchSmQue(count, lowest);				// if no rooms exist for generalists, this returns location for the room with a doctor that 
			if (lowest == 100)								// has the smallest queue, or throws an error that means there are no doctors.
			{
				throw NoDoctors();
			}
		}
	}

	return count;
}// throws NoDoctors
int searchSmQueGen(int count, int &l)						//  returns room location with a generalist who has the smallest queue
{
	int c = count;
	int lowest = 100;
	for (int i = 0; i < MAX_ERS; i++)
	{
		if (ers[i].hasDoc() && ers[i].getSpec() == GEN)
		{
			if (ers[i].queueLen() < lowest)
			{
				lowest = ers[i].queueLen();
				c = i;
			}

		}
	}
	l = lowest;
	return c;
}
int searchSmQue(int count, int &l)							// returns location for the room with a doctor that has the smallest queue
{
	int c = count;
	int lowest = 100;
	for (int i = 0; i < MAX_ERS; i++)
	{
		if (ers[i].hasDoc())
		{
			if (ers[i].queueLen() < lowest)
			{
				lowest = ers[i].queueLen();
				c = i;
			}

		}
	}
	l = lowest;
	return c;
}
