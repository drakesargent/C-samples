#include "Interest.h"
#include <cstring>

Interest::Interest()
{
	activity[0]='\0';
}

RelationType Interest::comparedTo(Interest i)
{
	int result = strcmp(activity, i.activity);

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

void Interest::Print(std::ofstream &file) const
{
	file << activity << " ";
}

void Interest::Initialize(char *act)
{
	strcpy(activity, act);
}