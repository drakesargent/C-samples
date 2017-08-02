#ifndef INTEREST_H
#define INTEREST_H
#include <fstream>


const int MAX_CHARS = 11;
enum RelationType { LESS, GREATER, EQUAL };

class Interest{
public:
	Interest();
	RelationType comparedTo(Interest i);
	void Print(std::ofstream&) const;
	void Initialize(char*);
	static const int MAX_ITEMS = 10;

private:
	char activity[MAX_CHARS];
};

#endif // !INTEREST_H
