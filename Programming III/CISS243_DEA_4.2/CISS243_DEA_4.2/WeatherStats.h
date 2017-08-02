#ifndef WEATHERSTATS_H
#define WEATHERSTATS_H

#include <iostream>
using namespace std;

class WeatherStats;
ostream &operator << (ostream &strm, const WeatherStats &obj);

class WeatherStats
{
private:
	double rain, snow;
	int numSunny;
public:
	// Constructor declarations defined in WeatherStats.cpp
	WeatherStats(double, double, int);
	WeatherStats();

	// Class function declarations defined in WeatherStats.cpp
	void setRain(double);
	void setSnow(double);
	void setNumSunny(int);

	double getRain();
	double getSnow();
	int getNumSunny();

	void operator= (const WeatherStats &right);
	bool operator==(const WeatherStats &right);
	friend ostream &operator << (ostream &strm, const WeatherStats &obj);
};
#endif // !1



