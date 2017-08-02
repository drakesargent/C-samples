
#include <iostream>
#include <conio.h>
#include <cstring>
using namespace std;

int main()
{
	bool found = false;
	const int num = 11;
	const int size = 100;

	// Holds the contacts for user to search for.
	char numbers[num][size] = { "Renee Javens, 678-1223", "Joe Looney, 586-0097",
								"Geri Palmer, 223-8787", "Lynn Presnell, 887-1212",
								"Bill Wolfe, 223-8878", "Sam Wiggins, 486-0998",
								"Bob Kain, 586-8712", "Tim Haynes, 586-7676",
								"John Johnson, 223-9037", "Jean James, 678-4939",
								"Ron Palmer, 486-2787" };
	// Holds the user's input
	char search[size];
	char *Contact = NULL;
	int count;

	// Prompts the user to enter in the contact they are searching for
	cout << "Welcome to contact search." << endl;
	cout << endl;
	cout << "Enter in the name of the person you are searching for." << endl;
	cin.getline(search, size);

	// For Loop to walk through the array and search for the contact or part of it
	for (count = 0; count < num; count++)
	{
		Contact = strstr(numbers[count], search);

		if (Contact != NULL)
		{
			cout << numbers[count] << endl;
			found = true;
		}
	}

	// Informs user that the contact they are searching for does not exist in the list
	if (!found)
	{
		cout << "The person is not in our contact list." << endl;
	}

	
	system("pause");
	return 0;

}