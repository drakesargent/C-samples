#ifndef CIRCLE_H
#define CIRCLE_H

using namespace std;

const double PI = 3.14159;

class Circle
{
private:
	double radius;
	double pi;
public:
	//constructors
	Circle()
	{
		radius = 0.0;
		pi = PI;
	}
	Circle(double r)
	{
		radius = r;
		pi = PI;
	}
	//mutators
	void setRadius(double r)
	{
		radius = r;
	}
	//accessors
	double getRadius()
	{
		return radius;
	}
	double getArea()
	{
		double area = pi*radius*radius;
		return area;
	}
	double getDiameter()
	{
		double diam = radius * 2;
		return diam;
	}
	double getCircumfrence()
	{
		double circum = 2 * pi * radius;
		return circum;
	}
};

#endif // CIRCLE_H
