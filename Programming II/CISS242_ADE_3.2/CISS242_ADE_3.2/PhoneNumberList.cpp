#include<iostream>
#include<string>
using namespace std;
//starting array of string names and numbers
string numList[]{
	"Renee Javins, 678-1223",
	"Joe Looney, 586-0097",
	"Geri Palmer, 223-8787",
	"Lynn Presnell, 887-1212",
	"Bill Wolfe, 223-8878",
	"Sam Wiggins, 486-0998",
	"Bob Kain, 586-8712",
	"Tim Haynes, 586-7676",
	"John Johnson, 223-9037",
	"Jean James, 678-4939",
	"Ron Palmer, 486-2783"
};
//holder string for user input
string name;

int main()
{
	//request user input for search value
	cout << "Enter a name or partial name to search for a phone number: ";
	cin >> name;

	//use loop to compair given name versus array & print each match
	for (int i = 0; i < 11; i++)
	{
		//variable to store result from find function
		int result;
		
		result = numList[i].find(name, 0);
		
		//test result if > -1 print result
		if (result >= 0)
		{
			cout << numList[i] << endl;
		}
		
	}

	system("pause");
	return 0;
}