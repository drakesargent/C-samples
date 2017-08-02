/*Kenneth Drake-Sargent
*CISS241_DEA
*Chapter 2
*Stock Market
*/
/*
Using known values calculate and display amount paid for stock, the commission, the total amount paid, and the minimal price for the stock to make a profit

Declare variables for known values number of shares, stock price, and broker fee percentage
Declare variables for calculations of ammount paid for stock, commission amount, total amount paid, and minimum profitable price.
Initialize variables with known values
Perform calculations for ammount paid for stock, commission, total, and minimum profit price
Store results in appropriate variables.
Display results for each calculation.
*/
#include <iostream>
using namespace std;

int main()
{
	//variables for known values
	double numShares, stockPrice, brokerPct;

	//variables for calculated values
	double totalStockPrice, totalBrokerFee, transactionTotal, minProfitValue;

	//initialize known values
	numShares = 600;
	stockPrice = 21.77;
	brokerPct = .02;

	//store calculated values
	totalStockPrice = stockPrice * numShares;
	totalBrokerFee = totalStockPrice * brokerPct;
	transactionTotal = totalStockPrice + totalBrokerFee;
	minProfitValue = (transactionTotal / numShares) + .01;

	//Display calculation results
	cout << "The total amount paid for the stocks is $" << totalStockPrice << "." << endl;
	cout << "The total amount paid for the broker fee is $" << totalBrokerFee << "." << endl;
	cout << "The total cost of the transaction is $" << transactionTotal << "." << endl;
	cout << "The minimum stock value to return a profit assuming no selling fee is $" << minProfitValue << "." << endl;

	return 0;
}