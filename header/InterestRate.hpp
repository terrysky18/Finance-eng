/*
InterestRate.hpp

Header file

A class for interest rate modelling
*/

#ifndef InterestRate_HPP
#define InterestRate_HPP

class InterestRate
{
public:
	// constructors
	InterestRate();

	// mutators and accessors
	void setNumPeriods(double num_period);
	double getNumPeriods();
	void setInterestRate(double int_rate);
	double getInterestRate();

	// destructor
	virtual ~InterestRate();

private:
	double n;	// number of periods
	double r;	// interest rate per period
	double P0;	// original principal
	double Pn;	// future principal value after n periods
	double A;	// annuity amount
	double PV;	// present value
};

#endif

