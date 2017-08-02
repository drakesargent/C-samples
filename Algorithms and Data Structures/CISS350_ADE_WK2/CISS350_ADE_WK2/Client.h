#ifndef CLIENT_H
#define CLIENT_H
#include <fstream>
#include <cstring>

enum RelationType { LESS, GREATER, EQUAL };

const int NAME_MAX = 21;
const int MAX_PHONE = 9;
const int MAX_INTR = 10;
const int MAX_ITEMS = 25;
const int MAX_INTR_CHARS = 11;

/*Client holds the information for a person enrolled
in the dating service. It possesses functions to 
set member items and compare one client to another.
*/

class Client
{
public:
	// structure to hold the number of interests
	struct Interest
	{
		char activity[MAX_INTR] = { '\0' };
	};
	
	//constructor
	Client();
	RelationType comparedTo(Client c);
	// treat as output overload
	void PrintFree(std::ofstream&,bool) const;
	// print interests
	void PrintInterests(std::ofstream&) const;
	
	// use mutator classes to add information
	void setSex(char);
	void setfName(char*);
	void setPhone(char*);
	void setNumInterests(int);
	void setInterest(Interest*);
	void setInterest(char*);
	void setMatch(char*);
	void voidMatch(); // sets the match variable to '\0'

	// accessor classes to retrive data
	char getSex();
	char* getfName();
	int getNumInterests();
	char* getInterest(int);
	char* getMatch();

	// evaluates if the match variable is empty
	bool matchEmpty();
	
	// evaluates if a given interest exists for this client
	bool searchInterest(char*);

	//overloads
	void operator = (const Client&);
	bool operator == (const Client&);
	bool operator != (const Client&);

	//output overload for pointer and for reference
	friend std::ostream &operator << (std::ostream&, const Client&);
	friend std::ostream &operator << (std::ostream&, const Client*);

private:
	//private variables
	char sex;
	char fName[NAME_MAX];
	char phone[MAX_PHONE];
	int numInterests;
	Interest interests[MAX_INTR];
	char match[NAME_MAX];
};

#endif