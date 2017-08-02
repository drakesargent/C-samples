#include "WeatherStats.h"
using namespace std;

WeatherStats::WeatherStats()
{
	rain = 0.0;
	snow = 0.0;
	numSunny = 0;
}

WeatherStats::WeatherStats(double r, double s, int ns)
{
	rain = r;
	snow = s;
	numSunny = ns;
}

void WeatherStats::setRain(double r)
{
	rain = r;
}

void WeatherStats::setSnow(double s)
{
	snow = s;
}

void WeatherStats::setNumSunny(int ns)
{
	numSunny = ns;
}

double WeatherStats::getRain()
{
	return rain;
}

double WeatherStats::getSnow()
{
	return snow;
}

int WeatherStats::getNumSunny()
{
	return numSunny;
}

ostream &operator << (ostream &strm, const WeatherStats &obj)
{
	strm << "Rain: " << obj.rain << " inches";
	strm << "\nSnow: " << obj.snow << " inches";
	strm << "\nSunny Days: " << obj.numSunny;
	strm << "\n";
	return strm;
}

void WeatherStats::operator= (const WeatherStats &right)
{
	rain = right.rain;
	snow = right.snow;
	numSunny = right.numSunny;
}

bool WeatherStats::operator==(const WeatherStats &right)
{
	bool even;
	if (rain == right.rain && snow == right.snow && numSunny == right.numSunny)
	{
		even = true;
	}
	else
	{
		even = false;
	}
	return even;
}