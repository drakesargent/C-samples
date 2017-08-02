#include "UnsortedType.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// global file variables
ifstream clients;
ifstream clDriver;
ofstream clDrOutput;
ofstream datesout;

// global client lists
UnsortedType M;
UnsortedType F;


// prototype function declarations
// file operations
bool openFile(ifstream&, string);
bool openFile(ofstream&, string);
void closeFile(ifstream&);
void closeFile(ofstream&);

// performs the datastructure testing for
// client and unsorted type
void clDrive(ifstream&, ofstream&);

// utility function that resets a cstring
void emptyCString(char*);

// opens the client datafile reads in and sorts
// the clients into the proper lists
void loadClients(ifstream&);
// parses the client information from datastream and 
// assigns them to the given client
void readinClient(ifstream&, Client&);

// input stream parsing for
void parseSex(ifstream&, char&);
void parseName(ifstream&, char*);
void parsePhone(ifstream&, char*);
void parseNumInt(ifstream&, int&);
void parseInterests(ifstream&, Client&);
// assigns the clients to a list based on sex
void sortClients(UnsortedType&, UnsortedType&, Client&);

// get the command from the user entry
void parseCmd(string&, char*);
void parseUMName(string, char*); 

// evaluate command and take action
void processCMD(char*, bool&, string&, ofstream&);

// utility to change a string to a cstring
void strChar(string, char*);
// utility to change a cstring to all upper case
void allUpper(char*);

// accepts the two lists and evaluates matches based off of interests
void match(UnsortedType&, UnsortedType&);

// compares the interests, if >=3 return true
bool compInterest(Client&, Client&);
// removes the match state for the name given and the match
void unmatch(UnsortedType&, UnsortedType&, char*);
// prints those who are available
void printFree(UnsortedType&, UnsortedType&, ofstream&);
// prints a list of those who are matched
void printMatch(UnsortedType&, ofstream&);
// parses user input to add to list and find a match
void newClient(UnsortedType&, UnsortedType&, string&, ofstream&);
// utility to parse data from a string for a client object
void parseSex(string &line, char &s);
void parseName(string &line, char *n);
void parsePhone(string &line, char *p);
void parseNumInt(string &line, int &ni);
void parseInterests(string &line, int, Client::Interest *intr);
// displays menu
void menu(ofstream&);

int main()
{
	clDrive(clDriver, clDrOutput);
	loadClients(clients);
	match(M, F);
	openFile(datesout, "dates.out");

	bool finished = false;

	do
	{
		menu(datesout);
		string line;
		getline(cin, line);
		datesout << line << endl;
		datesout << endl;
		char *cmd = new char[11];
		parseCmd(line, cmd);
		processCMD(cmd, finished, line, datesout);
		delete[] cmd;
		
	} while (!finished);
	closeFile(datesout);
	return 0;
}

bool openFile(ifstream &file, string fName)
{
	
		file.open(fName);
		

	if (file.fail()&&!file.is_open()) // returns file open status
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

void clDrive(ifstream &drive, ofstream &fileout)
{
	// opens file objects
	if (openFile(drive, "ClientDriver.txt") && openFile(fileout, "test_out.log"))
	{
		string line;
		Client *client = nullptr;
		UnsortedType test;

		// argument variables
		char s;
		char fN[NAME_MAX];
		char ph[MAX_PHONE];
		char intr[MAX_INTR_CHARS];
		int nI;
		Client::Interest iArry[MAX_INTR];
		
		while (line != "Quit")
		{
			drive >> line;
			if (line == "Initialize")
			{
				fileout << "Input client's sex" << endl;
				drive >> s;
				drive.get();
				fileout << "Input client's full name" << endl;
				drive.getline(fN, 21, ',');
				drive.get();
				fileout << "Input client's phone number" << endl;
				drive >> ph;
				drive.get();
				fileout << "Input number of interests" << endl;
				drive >> nI;
				drive.get();
				fileout << "Creating array of interests" << endl;
				
				for (int i = 0; i < nI; i++)
				{
					if (i < nI - 1) 
					{
						drive.getline(intr, 11, ',');
						strcpy(iArry[i].activity,intr);
						drive.get();
					}
					else
					{
						drive.getline(intr, 11);
						strcpy(iArry[i].activity, intr);
					}
				}
				fileout << endl;
			}
			else if (line == "Verify")
			{
				fileout << "Sex: " << s << endl;
				fileout << "Full Name: " << fN << endl;
				fileout << "Phone: " << ph << endl;
				fileout << "Number of Interests: " << nI << endl;
				fileout << "Interests: ";
				for (int i = 0; i < nI - 1; i++)
				{
					fileout << iArry[i].activity << ", ";
				}
				fileout << iArry[nI - 1].activity << "\n";
				fileout << endl;
			}
			else if (line == "Client")
			{
				fileout << "Initializing Client's values" << endl;
				client = new Client;
				fileout << "sex" << endl;
				client->setSex(s);
				fileout << "full name" << endl;
				client->setfName(fN);
				fileout << "phone" << endl;
				client->setPhone(ph);
				fileout << "numinterests" << endl;
				client->setNumInterests(nI);
				fileout << "interests" << endl;
				client->setInterest(iArry);
				fileout << endl;
			}
			else if (line == "Print")
			{
				fileout << client;
				fileout << endl;
			}
			else if (line == "PrintM")
			{
				client->PrintFree(fileout, false);
				fileout << endl;
			}
			else if (line == "SearchInt")
			{
				char search[11];
				drive >> search;
				fileout << "Searching for: " << search << endl;
				if (client->searchInterest(search))
				{
					fileout << search << " found in interests" << endl;
				}
				else
				{
					fileout << search << " not found in interests" << endl;
				}
				fileout << endl;
			}
			else if (line == "Add")
			{				
				Client trudy;
				
				trudy.setSex(s);
				trudy.setfName(fN);
				trudy.setPhone(ph);
				trudy.setNumInterests(nI);
				trudy.setInterest(iArry);

				fileout << "Adding Client to UnsortedList" << endl;
				test.putItem(trudy);
				fileout <<"Success\n"<<endl;
			}
			else if (line == "Clear")
			{
				s = '\0';
				emptyCString(fN);
				emptyCString(ph);
				emptyCString(intr);
				delete client;
				client = nullptr;
			}
			else if (line == "Search")
			{
				fileout << "Searching for Client." << endl;
				Client find;
				bool found;
				find.setfName(fN);
				find.setPhone(ph);
				find = test.getItem(find,found);
				if (found)
				{
					fileout << fN <<" is in list." << endl;
				}
				else
				{
					fileout << fN <<" is not in list. " << endl;
				}
				fileout << endl;
			}
			else if (line == "Remove")
			{
				fileout << "Removing " << fN << " from list." << endl;
				Client remove;
				remove.setfName(fN);
				remove.setPhone(ph);
				test.deleteItem(remove);
				fileout << "Deleted Client.\n" << endl;
			}
			else if (line == "Length")
			{
				fileout << "Length of storage list for Clients: ";
				fileout << test.getLength() << endl;
				fileout << endl;
			}
			else if (line == "Full")
			{
				fileout << "Is the list full?" << endl;
				if (test.isFull())
				{
					fileout << "Yes.\n" << endl;
				}
				else
				{
					fileout << "No.\n" << endl;
				}
			}
			else if (line == "GetNext")
			{
				fileout << "Displaying next item in list: " << endl;
				fileout << test.getNextItem();
				fileout << endl;
			}
			else if (line == "Reset")
			{
				fileout << "Resetting List Index." << endl;
				test.resetList();
			}
			else if (line == "MakeEmpty")
			{
				fileout << "Emptying List" << endl;
					test.makeEmpty();
			}
			else if (line == "FillList")
			{
				fileout << "Filling Array" << endl;
				
				Client trudy;

				trudy.setSex(s);
				trudy.setfName(fN);
				trudy.setPhone(ph);
				trudy.setNumInterests(nI);
				trudy.setInterest(iArry);

				for (int i = test.getLength(); i < MAX_ITEMS; i++)
				{
					test.putItem(trudy);
				}
			}
		}
		closeFile(clDriver);
		closeFile(clDrOutput);
	}
	else
	{
		cout << "File opening error." << endl;
	}
}

void emptyCString(char *ary)
{
	int aryLen = strlen(ary);
	for (int i = 0; i < aryLen; i++)
	{
		ary[i] = '\0';
	}
}

void loadClients(ifstream &strm)
{
	openFile(strm, "clients.mf");
	Client testClient;
	while ((strm.rdstate()&ifstream::eofbit) == 0)
	{
		readinClient(strm, testClient);
		sortClients(M, F, testClient);
	}
	closeFile(strm);
}
void readinClient(ifstream &strm, Client &clnt)
{
	char sex;
	char name[NAME_MAX];
	char phone[MAX_PHONE];
	int num;

	parseSex(strm, sex);
	parseName(strm, name);
	parsePhone(strm, phone);
	parseNumInt(strm, num);

	clnt.setSex(sex);
	clnt.setfName(name);
	clnt.setPhone(phone);
	clnt.setNumInterests(num);

	parseInterests(strm, clnt);
}

void parseSex(ifstream &strm, char &sex)
{
	strm >> sex;
	strm.get();
}
void parseName(ifstream &strm, char *name)
{
	strm.getline(name, 21, ',');
	strm.get();
}
void parsePhone(ifstream &strm, char *phone)
{
	strm >> phone;
	strm.get();
}
void parseNumInt(ifstream &strm, int &num)
{
	strm >> num;
	strm.get();
}
void parseInterests(ifstream &strm, Client &clnt)
{
	Client::Interest iArry[MAX_INTR];
	int nI = clnt.getNumInterests();
	char intr[11];
	for (int i = 0; i < nI; i++)
	{
		if (i < nI - 1)
		{
			strm.getline(intr, 11, ',');
			strcpy(iArry[i].activity, intr);
			strm.get();
		}
		else
		{
			strm.getline(intr, 11);
			strcpy(iArry[i].activity, intr);
		}
	}
	clnt.setInterest(iArry);
}

void sortClients(UnsortedType &male, UnsortedType &female, Client &sort)
{
	if (sort.getSex() == 'M' && !male.isFull())
	{
		male.putItem(sort);
	}
	else if (!female.isFull())
	{
		female.putItem(sort);
	}
}

void parseCmd(string &line, char *cmd)
{
	int space = line.find(' ');
	if (space < 0)
	{
		strChar(line, cmd);
		line.erase(0, line.length());
	}
	else
	{
		string command = line.substr(0, space);
		line.erase(0, space + 1);
		strChar(command, cmd);
	}
}
void parseUMName(string line, char *matchName)
{
	if (line.length() < 21)
	{
		strChar(line, matchName);
	}
	else
	{
		throw "Name too long.";
	}
}

void processCMD(char *cmd, bool &quit, string &line, ofstream &dout)
{
	allUpper(cmd);
	if (strcmp(cmd, "QUIT") == 0)
	{
		quit = true;
	}
	else if (strcmp(cmd, "UNMATCH")==0)
	{
		char mName[21];
		try
		{
			parseUMName(line, mName);
		}
		catch (string e)
		{
			cout << e << endl;
		}
		unmatch(M, F, mName);
		quit = false;
	}
	else if (strcmp(cmd, "PRINTFREE")==0)
	{
		printFree(M, F, dout);
		quit = false;
	}
	else if (strcmp(cmd, "PRINTMATCH")==0)
	{
		printMatch(M, dout);
		quit = false;
	}
	else if (strcmp(cmd, "NEWCLIENT")==0)
	{
		newClient(M, F, line, dout);
		match(M, F);
		quit = false;
	}
	else
	{
		quit = false;
	}
	line = "";
}

void strChar(string line, char *cmd)
{
	int len = line.length();
	int chLen = strlen(cmd);
	if (len < chLen)
	{
		for (int i = 0; i < len; i++)
		{
			cmd[i] = line[i];
		}
		cmd[len] = '\0';
	}
}
void allUpper(char *cmd)
{
	int len = strlen(cmd);
	for (int i = 0; i < len; i++)
	{
		cmd[i]=toupper(cmd[i]);
	}
}

void match(UnsortedType &Men, UnsortedType &Women)
{
	int menlen = Men.getLength();
	int womlen = Women.getLength();
	int numMatched = 0;
	Client male;
	Client female;
	for (int i = 0; i < menlen; i++)
	{
		male = Men.getNextItem();
		if (male.matchEmpty())
		{
			Women.resetList();
			for (int j = 0; j < womlen; j++)
			{
					female = Women.getNextItem();
					if (female.matchEmpty()) {
					if (compInterest(male, female))
					{
						male.setMatch(female.getfName());
						female.setMatch(male.getfName());
						numMatched++;
						Men.deleteItem(male);
						Men.putItem(male);
						Women.deleteItem(female);
						Women.putItem(female);
						break;
					}
				}
			}
		}
	}
}

bool compInterest(Client &male, Client &female)
{
	int matches = 0;
	for (int k = 0; k < male.getNumInterests(); k++)
	{
		if (female.searchInterest(male.getInterest(k)))
		{
			matches++;
		}
	}
	if (matches >= 3)
	{
		return true;
	}
	else
	{
		return false;
	}

}

void unmatch(UnsortedType &men, UnsortedType &women, char *matchName)
{
	Client p1;
	Client p2;

	p1.setfName(matchName);

	bool mfound;
	bool wfound;

	//search lists for name
	p1 = men.getItem(p1, mfound);
	p1 = women.getItem(p1, wfound);
	
	char partner[21];
	strcpy(partner, p1.getMatch());
	p2.setfName(partner);

	if (mfound)
	{
		p2 = women.getItem(p2, wfound);
		p1.voidMatch();
		p2.voidMatch();
		men.deleteItem(p1);
		men.putItem(p1);
		women.deleteItem(p2);
		women.putItem(p2);
	}
	else
	{
		p2 = men.getItem(p2, mfound);
		p1.voidMatch();
		p2.voidMatch();
		women.deleteItem(p1);
		women.putItem(p1);
		men.deleteItem(p2);
		men.putItem(p2);
	}
	
}

void printFree(UnsortedType &men, UnsortedType &women, ofstream &dout)
{
	int menlen = men.getLength();
	int womlen = women.getLength();

	string fmen = "Listing of available Men";
	string fwom = "Listing of available Women";
	string subd = "--------------------------";

	cout << fmen << endl;
	cout << subd << endl;
	dout << fmen << endl;
	dout << subd << endl;

	Client holder;

	men.resetList();

	for (int i = 0; i < menlen; i++)
	{
		holder = men.getNextItem();;
		holder.PrintFree(dout, true);
	}
	cout << endl;
	dout << endl;
	cout << fwom << endl;
	cout << subd << endl;
	dout << fwom << endl;
	dout << subd << endl;

	women.resetList();

	for (int i = 0; i < womlen; i++)
	{
		holder = women.getNextItem();
		holder.PrintFree(dout, true);
	}
	cout << endl;
	dout << endl;
}

void printMatch(UnsortedType &list, ofstream &dout)
{
	Client holder;
	list.resetList();
	int listLen = list.getLength();
	string head = "Current Matches";
	string line = "---------------";

	cout << head << endl;
	cout << line << endl;
	dout << head << endl;
	dout << line << endl;

	for (int i = 0; i < listLen; i++)
	{
		holder = list.getNextItem();
		if (!holder.matchEmpty())
		{
			cout << setw(25) << left << holder.getfName();
			cout << setw(17) << left << "-matched to-";
			cout << setw(25) << left << holder.getMatch() << endl;
			dout << setw(25) << left << holder.getfName();
			dout << setw(17) << left << "-matched to-";
			dout << setw(25) << left << holder.getMatch() << endl;
		}
	}
}

void newClient(UnsortedType &men, UnsortedType &women, string &line, ofstream &dout)
{
	char s = ' ';
	char n[NAME_MAX];
	char p[MAX_PHONE];
	int ni;
	Client::Interest intr[MAX_INTR];
	
	parseSex(line, s);
	parseName(line, n);
	parsePhone(line, p);
	parseNumInt(line, ni);
	parseInterests(line, ni, intr);

	s = toupper(s);

	Client holder;

	holder.setfName(n);
	holder.setSex(s);
	holder.setPhone(p);
	holder.setNumInterests(ni);
	holder.setInterest(intr);

	switch (s)
	{
	case 'M':
		men.putItem(holder);
	case 'F':
		women.putItem(holder);
	}
}

void parseSex(string &line, char &s)
{
	s = line[0];
	line.erase(0, 2);
}
void parseName(string &line, char *n)
{
	int spaces = 0;
	int commas = 0;
	char space = ' ';
	char comma = ',';
	for (int i = 0; i < NAME_MAX; i++)
	{
		if (line[i] == space)
		{
			spaces++;
		}
		if (line[i] == comma)
		{
			n[i] = '\0';
			line.erase(0, i + 2);
			cout << line << endl;
			cout << n << endl;
			break;
		}
		if (spaces > 1) {
			n[i] = '\0';
			line.erase(0, i + 1);
			cout << line << endl;
			cout << n << endl;
			break;
		}
		n[i] = line[i];
	}
}
void parsePhone(string &line, char *p)
{
	for (int i = 0; i < MAX_PHONE; i++)
	{
		p[i] = line[i];
	}
	line.erase(0, MAX_PHONE);
	p[MAX_PHONE - 1] = '\0';
}
void parseNumInt(string &line, int &ni)
{
	if (line.find("10", 0) > line.length())
	{
		char h[] = { line[0] };
		ni = atoi(h);
		line.erase(0, 2);
	}
	else
	{
		char h[] = {line[0],line[1]};
		ni = atoi(h);
		line.erase(0, 3);
	}
}
void parseInterests(string &line, int ni, Client::Interest *intr)
{
	char comma = ',';
	char intrs[MAX_INTR_CHARS];
	for (int i = 0; i < ni; i++)
	{
		if (i == ni - 1) 
		{
			for (int j = 0; j < line.length(); j++)
			{
				intrs[j] = line[j];
			}
			intrs[line.length()] = '\0';
		}
		else 
		{
			for (int j = 0; j < MAX_INTR_CHARS; j++)
			{
				if (line[j] == comma)
				{
					intrs[j] = '\0';
					line.erase(0, j + 2);
					break;
				}
				intrs[j] = line[j];
			}
		}
		strcpy(intr[i].activity, intrs);
		intrs[0] = '\0';
	}
}

void menu(ofstream &dout)
{
	string header = "WELCOME TO SAM'S COMPUTER DATING SERVICE";
	string under1 = "----------------------------------------";
	string subh1 = "Enter one of the following options:";
	string opt1 = "NEWCLIENT <sex> <name>, <phone number> <number of interests> <interests>";
	string opt2 = "UNMATCH <name>";
	string opt3 = "PRINTMATCH";
	string opt4 = "PRINTFREE";
	string opt5 = "QUIT";

	cout << header << endl;
	cout << under1 << endl;
	cout << subh1 << endl;
	cout << opt1 << endl;
	cout << opt2 << endl;
	cout << opt3 << endl;
	cout << opt4 << endl;
	cout << opt5 << endl;

	dout << header << endl;
	dout << under1 << endl;
	dout << subh1 << endl;
	dout << opt1 << endl;
	dout << opt2 << endl;
	dout << opt3 << endl;
	dout << opt4 << endl;
	dout << opt5 << endl;
}