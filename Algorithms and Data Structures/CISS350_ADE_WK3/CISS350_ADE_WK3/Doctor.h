#ifndef DOCTOR_H
#define DOCTOR_H
#include "Person.h"

/*
Doctor extends person class which stores information for room Preference.
*/

class Doctor : public Person
{
private:
	int roomPref;

public:
	Doctor();
	void setSpec(Specialty);
	void setSpec(int);
	void setRoomPref(int);

	int getRoomPref();

	void operator = (const Doctor&);
};


#endif //DOCTOR_H