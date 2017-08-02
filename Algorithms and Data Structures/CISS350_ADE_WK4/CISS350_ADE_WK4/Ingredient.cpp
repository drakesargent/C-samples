#include "Ingredient.h"
#include <sstream>
#include <iomanip>

//constructor
Ingredient::Ingredient()
{
	name = "";
	scale = OUNCE;
	amount = 0.0;
}
//copy
void Ingredient::operator=(Ingredient &i)
{
	name = i.name;
	scale = i.scale;
	amount = i.amount;
}

//accessor functions
string Ingredient::getName()
{
	return name;
}

weight Ingredient::getScale()
{
	return scale;
}

double Ingredient::getAmount()
{
	return amount;
}

//mutator functions
void Ingredient::setName(string n)
{
	name = n;
}
void Ingredient::setScale(int sc)
{
	scale = static_cast<weight>(sc);
}
void Ingredient::setAmount(double amt)
{
	amount = amt;
}

//evaluation operator overloads
bool Ingredient::operator==(const Ingredient &i)
{
	if (name == i.name)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Ingredient::operator!=(const Ingredient &i)
{
	if (name != i.name)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//manipulator functions
string Ingredient::print()
{
	string output = "";
	string scl = weightScale(scale);
	if (amount > 1)
	{
		scl.append("s");
	}
	output.append(to_string_pre<double>(amount,2));
	output.append(" ");
	output.append(scl);
	output.append(" of ");
	output.append(name);
	return output;
}
string Ingredient::weightScale(weight sc)
{
	switch (sc)
	{
	case OUNCE:
		return "Ounce";
		break;
	case GRAM:
		return "Gram";
		break;
	case FL_OUNCE:
		return "Fluid Ounce";
		break;
	case LITRE:
		return "Litre";
		break;
	case POUND:
		return "Pound";
		break;
	case COUNT:
		return "Count";
		break;
	case CUP:
		return "Cup";
		break;
	case TABLESPOON:
		return "TableSpoon";
		break;
	case TEASPOON:
		return "TeaSpoon";
		break;
	default:
		return "";
		break;
	}
}

/*
found on stackoverflow
https://stackoverflow.com/questions/16605967/set-precision-of-stdto-string-when-converting-floating-point-values
*/
template <typename T>
string Ingredient::to_string_pre(const T a_value, const int n)
{
	std::ostringstream out;
	out << std::setprecision(n) << a_value;
	return out.str();
}