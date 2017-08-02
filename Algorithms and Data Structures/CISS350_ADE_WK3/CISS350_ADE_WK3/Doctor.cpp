#include "Doctor.h"

Doctor::Doctor()
{
	roomPref = 0;
}

void Doctor::setSpec(Specialty s)
{
	spec = s;
}

void Doctor::setSpec(int s)
{
	Specialty spe = static_cast<Specialty>(s);
	spec = spe;
}

void Doctor::setRoomPref(int r)
{
	roomPref = r;
}

int Doctor::getRoomPref()
{
	return roomPref;
}

void Doctor::operator = (const Doctor &right)
{
	name = right.name;
	spec = right.spec;
	roomPref = right.roomPref;
}