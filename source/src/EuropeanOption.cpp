/*
EuropeanOption.cpp

Source file for European option class:
*/

#include <string>
#include <cmath>
#include "../../header/EuropeanOption.hpp"
#include "../../header/NormalDistribution.hpp"

// Default constructor
EuropeanOption::EuropeanOption()
{
	init();		// default call option
}

// Copy constructor
EuropeanOption::EuropeanOption(const EuropeanOption& option2)
{
	copy(option2);
}

// Create option constructor
EuropeanOption::EuropeanOption(const string& option_type)
{
	init();
	optType = option_type;
	if (optType == "c") { optType = "C"; }
}

// Destructor
EuropeanOption::~EuropeanOption()
{}

// Assignment operator
EuropeanOption& EuropeanOption::operator = (const EuropeanOption& option2)
{	// Assignment operator (deep copy)
	if (this == &option2) { return *this; }
	else {
		copy(option2);
		return *this;
	}
}

// Public functions
double EuropeanOption::Price() const
{	// function to calculate the option price
	if (optType == "C")
	{ return CallPrice(); }
	else
	{ return PutPrice(); }
}

double EuropeanOption::Delta() const
{	// function to calculate the sensitivities
	if (optType == "C")
	{ return CallDelta(); }
	else
	{ return PutDelta(); }
}

void EuropeanOption::toggle()
{	// switch the option type (C/P, P/C)
	if (optType == "C")
	{ optType = "P"; }
	else
	{ optType = "C"; }
}

// Public mutator and accessor
void EuropeanOption::setInterestRate(double int_rate)
{ r = int_rate; }

double EuropeanOption::getInterestRate() const
{ return r; }

void EuropeanOption::setVolatility(double volatility)
{ sig = volatility; }

double EuropeanOption::getVolatility() const
{ return sig; }

void EuropeanOption::setStrikePrice(double strk_prc)
{ K = strk_prc; }

double EuropeanOption::getStrikePrice() const
{ return K; }

void EuropeanOption::setExpiryDate(double exp_date)
{ T = exp_date; }

double EuropeanOption::getExpiryDate() const
{ return T; }

void EuropeanOption::setCurrentPrice(double und_prc)
{ U = und_prc; }

double EuropeanOption::getCurrentPrice() const
{ return U; }

void EuropeanOption::setCostCarry(double cost)
{ b = cost; }

double EuropeanOption::getCostCarry() const
{ return b; }

void EuropeanOption::setOptType(string option_type)
{ optType = option_type; }

string EuropeanOption::getOptType() const
{ return optType; }


// Private member functions
void EuropeanOption::init()
{	// Initialise all default values

	// Default values
	r = 0.08;	// interest rate
	sig = 0.30;	// volatility
	K = 65.0;	// strike price
	T = 0.25;	// expiry date
	U = 60.0;	// current underlying price, stock in the case
	b = r;		// Black and Scholes stock option model (1973)
	optType = "C";	// European Call Option (default type)
}

void EuropeanOption::copy(const EuropeanOption& o2)
{
	r = o2.getInterestRate();
	sig = o2.getVolatility();
	K = o2.getStrikePrice();
	T = o2.getExpiryDate();
	U = o2.getCurrentPrice();
	b = o2.getCostCarry();

	optType = o2.getOptType();
}

// Kernel Functions
double EuropeanOption::CallPrice() const
{
	NormalDistribution N = NormalDistribution(4000);
	double tmp = sig * sqrt(T);
	double d1 = (log(U/K) + (b + (sig*sig)*0.5) * T) / tmp;
	double d2 = d1 - tmp;
	double normDis1 = N.normalDistribution(d1);
	double normDis2 = N.normalDistribution(d2);

	return (U * exp((b-r)*T) * normDis1) - (K * exp(-r*T) * normDis2);
}

double EuropeanOption::PutPrice() const
{
	NormalDistribution N = NormalDistribution(4000);
	double tmp = sig * sqrt(T);
	double d1 = (log(U/K) + (b + (sig*sig)*0.5) * T) / tmp;
	double d2 = d1 - tmp;
	double normDis1 = N.normalDistribution(-d2);
	double normDis2 = N.normalDistribution(-d1);

	return (K * exp(-r*T) * normDis1) - (U * exp((b-r)*T) * normDis2);
}

double EuropeanOption::CallDelta() const
{
	NormalDistribution N = NormalDistribution(4000);
	double tmp = sig * sqrt(T);
	double d1 = (log(U/K) + (b + (sig*sig)*0.5) * T) / tmp;
	double normDis = N.normalDistribution(d1);

	return exp((b-r)*T) * normDis;
}

double EuropeanOption::PutDelta() const
{
	NormalDistribution N = NormalDistribution(4000);
	double tmp = sig * sqrt(T);
	double d1 = (log(U/K) + (b + (sig*sig)*0.5) * T) / tmp;
	double normDis = N.normalDistribution(d1);

	return exp((b-r)*T) * (normDis - 1.0);
}

