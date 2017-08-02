#ifndef CASHREGISTER_H
#define CASHREGISTER_H


class CashRegister
{
public:
	//constructor
	CashRegister();
	//~CashRegister();

	//mutator function declarations
	void calcUnitPrice(double uc, double pm);
	void calcSubTotal(double up, int qty);
	void calcTax(double subt, double salest);
	void calcTotal(double subt, double t);

	//accessor function declarations
	double getUnitPrice();
	double getSubTotal();
	double getTax();
	double getTotal();
	double getSalesTax();
	double getProfitMargin();

private:
	//set on initialization w/ constructor
	double salesTax;
	double profitMargin;

	//calculated fields
	double unitPrice;
	double subtotal;
	double tax;
	double total;

	//private functions
	void setSalesTax(double st);
	void setProfitMargin(double pm);

};

#endif // !CASHREGISTER_H

