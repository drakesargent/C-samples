#ifndef INGREDIENT_H
#define INGREDIENT_H
#include <string>
#include <iostream>
using namespace std;
/*
Ingredient class holds fields for ingredient name,
Weight type enum, and amount. To be used for Recipes.
*/

enum weight {OUNCE, GRAM, FL_OUNCE, LITRE, POUND, COUNT, CUP,
				TABLESPOON, TEASPOON};

class Ingredient
{
private:
	string name;
	weight scale;
	double amount;

public:
	//constructor
	Ingredient();
	//copy
	void operator=(Ingredient&);
	
	//accessor functions
	string getName();
	weight getScale();
	double getAmount();

	//mutator functions
	void setName(string);
	void setScale(int);
	void setAmount(double);

	//evaluation operator overloads
	bool operator==(const Ingredient&);
	bool operator!=(const Ingredient&);

	//manipulator functions
	string print();
	string weightScale(weight);

	template <typename T>
	string to_string_pre(const T a_value, const int n);
};

#endif // !1

