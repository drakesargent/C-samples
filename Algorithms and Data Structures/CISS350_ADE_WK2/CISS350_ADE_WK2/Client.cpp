#include "Client.h"
#include <iomanip>
#include <ostream>
#include <string>
#include <iostream>

using namespace std;

// constructor definition
Client::Client()
{
	sex = '\0';
	fName[0] ='\0';
	phone[0] = '\0';
	numInterests = 0;
	match[0] = '\0';
}

// class comparison
RelationType Client::comparedTo(Client c)
{
	int result = strcmp(fName, c.fName);


	if (result < 0)
	{
		return LESS;
	}
	else if (result == 0)
	{
		return EQUAL;
	}
	else return GREATER;
}

// prints if this person is available
void Client::PrintFree(std::ofstream &file, bool T) const
{
	if (match[0] == '\0')
	{
		file << std::setw(25) << std::left << fName << ' ';
		file << std::setw(10) << std::right << phone << std::endl;
		if (T)
		{
			cout << std::setw(25) << std::left << fName << ' ';
			cout << std::setw(10) << std::right << phone << std::endl;
		}
	}
}

// prints the client's interests
void Client::PrintInterests(std::ofstream &file) const
{
	for (int i = 0; i < numInterests - 1; i++)
	{
		file << interests[i].activity << ", ";
	}
	file << interests[numInterests - 1].activity << "\n";
}

// mutator function definitions
void Client::setSex(char s)
{
	sex = s;
}
void Client::setfName(char *fn)
{
	strcpy(fName, fn);
}
void Client::setPhone(char *ph)
{
	strcpy(phone, ph);
}
void Client::setNumInterests(int num)
{
	numInterests = num;
}
void Client::setInterest(Interest *activitys)
{
	for (int i = 0; i <= numInterests; i++)
	{
		strcpy(interests[i].activity, activitys[i].activity);
	}
}
void Client::setInterest(char *activity)
{
	if (!searchInterest(activity))
	{
		for (int i = 0; i <= numInterests; i++)
		{
			if (interests[i].activity[0]=='\0')
			{
				strcat(interests[i].activity, activity);
			}
		}
	}
}
bool Client::searchInterest(char *activity)
{
	for (int i = 0; i < numInterests; i++)
	{
		char right[MAX_INTR_CHARS];
		strcpy(right, activity);
		char left[MAX_INTR_CHARS];
		strcpy(left, interests[i].activity);

		int num = strcmp(left, right);
		if (num == 0)
		{
			return true;
		}
	}
	return false;
}
void Client::setMatch(char *mName)
{
	strcpy(match, mName);
}
void Client::voidMatch()
{
	match[0] = '\0';
}

// accessor functions
char Client::getSex()
{
	return sex;
}
char* Client::getfName()
{
	return fName;
}
int Client::getNumInterests()
{
	return numInterests;
}
char* Client::getMatch()
{
	return match;
}
bool Client::matchEmpty()
{
	if (match[0] == '\0')
	{
		return true;
	}
	else
	{
		return false;
	}
}
char* Client::getInterest(int num)
{
	return interests[num].activity;
}

// operator overloads
void Client::operator = (const Client &right)
{
	
	sex = right.sex;
	strcpy(fName, right.fName);
	strcpy(phone, right.phone);
	this->setNumInterests(right.numInterests);
	
	for (int i = 0; i<numInterests; i++)
	{
		strcpy(interests[i].activity, right.interests[i].activity);
	}
	strcpy(match, right.match);
}
bool Client::operator == (const Client &right)
{
	int result = 0;
	result += strcmp(fName, right.fName);

	if (result == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Client::operator != (const Client &right)
{
	int result = 0;
	result += strcmp(fName, right.fName);

	if (result != 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
// stream overloads
ostream &operator << (ostream &strm, const Client &rec)
{
	strm << rec.sex << ' ';
	strm << rec.fName << ", ";
	strm << rec.phone << ' ';
	strm << rec.numInterests << ' ';
	for (int i = 0; i < rec.numInterests-1; i++)
	{
		strm << rec.interests[i].activity << ", ";
	}
	strm << rec.interests[rec.numInterests - 1].activity << "\n";
	
	return strm;
}
ostream &operator << (ostream &strm, const Client *rec)
{
	strm << rec->sex << ' ';
	strm << rec->fName << ", ";
	strm << rec->phone << ' ';
	strm << rec->numInterests << ' ';
	for (int i = 0; i < rec->numInterests - 1; i++)
	{
		strm << rec->interests[i].activity << ", ";
	}
	strm << rec->interests[rec->numInterests - 1].activity << "\n";

	return strm;
}
