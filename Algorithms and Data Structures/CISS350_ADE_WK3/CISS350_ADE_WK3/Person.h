#ifndef PERSON_H
#define PERSON_H
#include <string>

enum Specialty { PED, GEN, INT, CAR, SUR, OBS, PSY, NEU,
				 ORT, DET, OPT, ENT };

/*
Root class that is parent to Patient and Doctor Class.
Stores Name and specialty. Further definition of how
these fields are used will be in the Child Classes.
*/
class Person
{
protected:
	std::string name;
	Specialty spec;

public:
	Person();
	void setName(std::string);
	Specialty getSpec();
	std::string getName();

};
#endif // !PERSON_H
