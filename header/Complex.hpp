/*
Complex.hpp

Header file

A class to model mathematical complex numbers
*/

#ifndef Complex_HPP
#define Complex_HPP

#include <string>
using std::string;

class Complex
{
public:
	// Constructors
	Complex();		// default
	Complex(double real, double imag);
	Complex(const Complex& cpx2);	// copy constructor
	// Destructor
	virtual ~Complex();

	// Selector and modifier
	void setReal(const double real);
	double getReal() const;
	void setImaginary(const double imag);
	double getImaginary() const;

	string toString() const;

	// Operator overloading
	Complex& operator = (const Complex& cpx2);
	Complex operator + (const Complex& cpx2) const;
	Complex operator - (const Complex& cpx2) const;
	Complex operator * (const Complex& cpx2) const;
	Complex operator / (const Complex& cpx2) const;

	// friend operators
	friend Complex operator * (const Complex& cpx, double d);
	friend Complex operator * (double d, const Complex& cpx);

	// friend functions
	friend Complex exp(const Complex& cpx);
	friend Complex cos(const Complex& cpx);
	friend Complex sin(const Complex& cpx);
	friend Complex tan(const Complex& cpx);
	friend Complex cosh(const Complex& cpx);
	friend Complex sinh(const Complex& cpx);
	friend Complex tanh(const Complex& cpx);

private:
	// Member variables
	double real_x;	// real component
	double imag_y;	// imaginary component

	// Member functions
	void copy(const Complex& cpx2);
};

#endif

