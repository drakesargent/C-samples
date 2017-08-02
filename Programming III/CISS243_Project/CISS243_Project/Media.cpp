#include "Media.h"

using namespace std;

Media::Media()
{
	title = "";
}
Media::Media(string t)
{
	title = t;
}
Media::Media(string t, int l)
{
	title = t;
	length = l;
}

int Media::getLength()
{
	return length;
}
string Media::getTitle()
{
	return title;
}
bool Media::operator ==(const Media &Right)
{
	if (Right.length == length && Right.title == title)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Media::operator !=(const Media &Right)
{
	if (Right.length != length || Right.title != title)
	{
		return true;
	}
	else
	{
		return false;
	}
}