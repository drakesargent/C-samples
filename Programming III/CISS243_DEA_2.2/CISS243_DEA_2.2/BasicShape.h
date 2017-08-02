//Abstract Class header for BasicShape Class
#ifndef BASICSHAPE_H
#define BASICSHAPE_H

// The BasicShape Class holds the calculated value of
// area as defined by derrived classes
class BasicShape
{
protected:
	double area; // to hold calculated area
public:
	// default constructor
	BasicShape()
	{
		area = 0.0;
	}
	// accessor function to access area
	double getArea()
	{
		return area;
	}
	// virtual area calculation function to be overridden
	// by derrived classes
	virtual void calcArea() = 0;
};

#endif // !BASICSHAPE_H

