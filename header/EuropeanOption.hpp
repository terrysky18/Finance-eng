/*
EuropeanOption.hpp

Header file

A class for model an European option
These attributes are modelled
+ Strike price
+ Volatility
+ Risk-free interest rate
+ Expiry date
*/

#ifndef EuropeanOption_HPP
#define EuropeanOption_HPP

#include <string>
using std::string;

class EuropeanOption
{
public:
	// constructors
	EuropeanOption();  // Default call option
	EuropeanOption(const EuropeanOption& option2);  // copy constructor
	EuropeanOption(const string& option_type);  // create option type
	// destructor
	virtual ~EuropeanOption();

	// Assignment operator
	EuropeanOption& operator = (const EuropeanOption& option2);

	// Functions that calculate option price and some sensitivities
	double Price() const;
	double Delta() const;

	// Modifier functions
	void toggle();	// change option type (C/P, P/C)

	// Public modifier and selector
	void setInterestRate(double int_rate);
	double getInterestRate() const;
	void setVolatility(double volatility);
	double getVolatility() const;
	void setStrikePrice(double strk_prc);
	double getStrikePrice() const;
	void setExpiryDate(double exp_date);
	double getExpiryDate() const;
	void setCurrentPrice(double und_prc);
	double getCurrentPrice() const;
	void setCostCarry(double cost);
	double getCostCarry() const;
	void setOptType(string option_type);
	string getOptType() const;

private:
	// Private member variables
	double r;	// Interest rate
	double sig;	// Volatility
	double K;	// Strike price
	double T;	// Expiry date
	double U;	// Current underlying price
	double b;	// Cost of carry
	string optType;	// Option name (call, put)

	// Private member functions
	void init();	// Initialise all default values
	void copy(const EuropeanOption& o2);
	// Kernel functions for option calculation
	double CallPrice() const;
	double PutPrice() const;
	double CallDelta() const;
	double PutDelta() const;
};

#endif

