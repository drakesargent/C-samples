// Class header and definition for MinMax Template Class
#ifndef MINMAX_H
#define MINMAX_H

// MinMax Template Class accepts two values of a user defined
// data-type. These values are compared and returned via class
// functions.

template <class T>
class MinMax
{
private:
	T alpha; // to store first user defined data type value
	T beta; // to store second user defined data type value
public:
	
	// constructor declaration, defined below, accepts two
	// user defined data type values as arguments
	MinMax(T a, T b);
	
	// evaluated accessor function declarations
	T minimum();
	T maximum();
	
};

// Class constructor definition
template <class T>
MinMax<T>::MinMax(T a, T b)
{
	alpha = a;
	beta = b;
}

// accessor function evaluates the class fields and returns
// the lesser of the two
template <class T>
T MinMax<T>::minimum()
{
	if (alpha < beta)
	{
		return alpha;
	}
	else
	{
		return beta;
	}
}

// accessor function evaluats the class fields and returns
// the greater of the two
template <class T>
T MinMax<T>::maximum()
{
	if (alpha > beta)
	{
		return alpha;
	}
	else
	{
		return beta;
	}
}

#endif // !MINMAX_H

