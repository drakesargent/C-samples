#include <iomanip>
#include <iostream>
#include <memory>
#include "CashRegister.h"

using namespace std;

//private function definitions
void CashRegister::setSalesTax(double st)
{
	salesTax = st;
}

void CashRegister::setProfitMargin(double pm)
{
	profitMargin = pm;
}



//constructor and destructor
CashRegister::CashRegister()
{
	setSalesTax(.06);
	setProfitMargin(1.3);
	unitPrice = 0.0;
	subtotal = 0.0;
	tax = 0.0;
	total = 0.0;
}

/*CashRegister::~CashRegister()
{

}*/

//mutator calculated function definitions
void CashRegister::calcUnitPrice(double uc, double pm)
{
	unitPrice = uc * pm;
}
void CashRegister::calcSubTotal(double up, int qty)
{
	subtotal = up * qty;
}
void CashRegister::calcTax(double subt, double salest)
{
	tax = subt * salest;
}
void CashRegister::calcTotal(double subt, double t)
{
	total = subt + t;
}
//accessor function definitions
double CashRegister::getUnitPrice()
{
	return unitPrice;
}
double CashRegister::getSubTotal()
{
	return subtotal;
}
double CashRegister::getTax()
{
	return tax;
}
double CashRegister::getTotal()
{
	return total;
}
double CashRegister::getSalesTax()
{
	return salesTax;
}
double CashRegister::getProfitMargin()
{
	return profitMargin;
}


