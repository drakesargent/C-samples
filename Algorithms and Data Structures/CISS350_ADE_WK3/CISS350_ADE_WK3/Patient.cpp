#include "Patient.h"

Patient::Patient()
{
	age = 0;
	emerg = "";
}

void Patient::setAge(int a)
{
	age = a;
}
void Patient::setSpec(Specialty s)
{
	if (age == 0)
	{
		throw err_age();
	}
	else if (age < 16)
	{
		spec = PED;
	}
	else
	{
		spec = s;
	}
}
// age must be set first or error is thrown
void Patient::setSpec(int s)
{
	if (age == 0)
	{
		throw err_age();
	}
	else if (age < 16)
	{
		spec = PED;
	}
	else
	{
		spec = static_cast<Specialty>(s);
	}
}
void Patient::setEmerg(string e)
{
	emerg = e;
}

int Patient::getAge()
{
	return age;
}

void Patient::operator = (const Patient &right)
{
	name = right.name;
	spec = right.spec;
	age = right.age;
	emerg = right.emerg;
}