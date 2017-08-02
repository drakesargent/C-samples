#include "Person.h"

// definition of person
// default constructor creates empty record
// sets specialty to PED.
Person::Person()
{
	name = "";
	spec = PED;
}

void Person::setName(std::string n)
{
	name = n;
}

Specialty Person::getSpec()
{
	return spec;
}

std::string Person::getName()
{
	return name;
}