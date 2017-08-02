#ifndef MEDIA_H
#define MEDIA_H
#include <string>
#include "LList.h"

using namespace std;

class Media
{
protected:
	string title;
	int length;
public:
	Media();
	Media(string);
	Media(string, int);

	int getLength();
	string getTitle();
	bool operator ==(const Media &Right);
	bool operator !=(const Media &Right);
};
#endif // !MEDIA_H
