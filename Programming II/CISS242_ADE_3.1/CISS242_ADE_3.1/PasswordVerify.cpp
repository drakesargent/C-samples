#include<iostream>
#include<cctype>
#include<string>

using namespace std;

//prototype functions
void validatePassword(char[]);

//main function for testing password validation
int main()
{
	char chars[] = {'a','b','c','d','e','f','\0'};
	validatePassword(chars);
	system("pause");
	return 0;
}

//function definitions
void validatePassword(char pass[]) 
{
	string reasons[3] = { "","","" };
	int count = 0;
	bool invalid = false;
	int len = strlen(pass);
	int upper = 0;
	int lower = 0;
	int num = 0;

	//test length
	if (len < 6 )
	{
		invalid = true;
		reasons[count] = "Password must be at least 6 characters.";
		count++;
	}

	//evaluate and increment password character types
	for (int i = 0; i < len; i++)
	{
		if (isupper(pass[i])) 
		{
			upper++;
		}
		else if (islower(pass[i]))
		{
			lower++;
		}
		else if (isdigit(pass[i]))
		{
			num++;
		}
	}

	//test character case
	if (upper <= 0 || lower <= 0) //upper & lower test
	{
		invalid = true;
		reasons[count] = "Password must have at least one upper case letter and one lowercase letter.";
		count++;
	}

	//digit test case
	if (num <= 0)
	{
		invalid = true;
		reasons[count] = "Password must have at least one numeric digit.";
		count++;
	}

	//if Password is invalid display and cycle through reasons to print
	if (invalid)
	{
		cout << "Password entered is invalid." << endl;
		for (int i = 0; i < count; i++)
		{
			cout << reasons[i] << endl;
		}
	}
}