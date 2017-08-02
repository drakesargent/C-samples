#ifndef PATIENT_H
#define PATIENT_H
#include "Person.h"

using namespace std;
/*
Patient extends person class which stores information for age
and emergency. It also has an error class associated thrown if
a specialty is set when the age has not yet been.
*/
class Patient : public Person
{
private:
	int age;
	string emerg;

public:
	Patient();

	// age must be set before 
	// specialty due to specialty
	// constraint
	class err_age
	{
	private:
		string msg;
	public:
		err_age()
		{
			msg = "Age is not yet set. Cannot assign Specialty without valid age";
		}
		string getMessage()
		{
			return msg;
		}
	};

	void setAge(int);
	void setSpec(Specialty);
	void setSpec(int);
	void setEmerg(string);

	int getAge();

	void operator = (const Patient&);
};
#endif // !PATIENT_H
