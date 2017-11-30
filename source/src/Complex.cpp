/*
Complex.cpp

Source file for Complex number class
*/

#include <cmath>
#include <string>
#include "../../header/Complex.hpp"
#include "../../header/StringConversion.hpp"

using std::string;

// Default constructor
Complex::Complex()
{
	real_x = 0.0;
	imag_y = 0.0;
}

Complex::Complex(double real, double imag)
{
	real_x = real;
	imag_y = imag;
}

// Copy constructor
Complex::Complex(const Complex& cpx2)
{
	copy(cpx2);
}

// Destructor
Complex::~Complex()
{}

// Public Modifiers
void Complex::setReal(const double real)
{ real_x = real; }

void Complex::setImaginary(const double imag)
{ imag_y = imag; }

// Public Selectors
double Complex::getReal() const
{ return real_x; }

double Complex::getImaginary() const
{ return imag_y; }

string Complex::toString() const
{
	StringConversion<double> sc;
	if (imag_y > 0) {
		return sc.getString(real_x) + " + " + sc.getString(imag_y) + "i";
	}
	else {
		return sc.getString(real_x) + " - " + sc.getString(fabs(imag_y)) + "i";
	}
}

// Assignment operator overloading
Complex& Complex::operator = (const Complex& cpx2)
{	// deep copy
	if (this == &cpx2) { return *this; }
	else {
		copy(cpx2);
		return *this;
	}
}

Complex Complex::operator + (const Complex& cpx2) const
{
	return Complex(real_x+cpx2.getReal(), imag_y+cpx2.getImaginary());
}

Complex Complex::operator - (const Complex& cpx2) const
{
	return Complex(real_x-cpx2.getReal(), imag_y-cpx2.getImaginary());
}

Complex Complex::operator * (const Complex& cpx2) const
{
	double x1 = real_x, y1 = imag_y;
	double x2 = cpx2.getReal(), y2 = cpx2.getImaginary();

	return Complex(x1*x2 - y1*y2, x1*y2 + x2*y1);
}

Complex Complex::operator / (const Complex& cpx2) const
{
	double x1 = real_x, y1 = imag_y;
	double x2 = cpx2.getReal(), y2 = cpx2.getImaginary();

	double x2_2 = x2*x2;
	double y2_2 = y2*y2;

	return Complex((x1*x2 + y1*y2)/(x2_2 + y2_2), (x2*y1 - x1*y2)/(x2_2 + y2_2));
}

// friend operators
Complex operator * (const Complex& cpx, double d)
{
	return Complex(cpx.real_x * d, cpx.imag_y * d);
}

Complex operator * (double d, const Complex& cpx)
{
	return cpx * d;
}

// friend functions
Complex exp(const Complex& cpx)
{ // Exponential function
	double ex = exp(cpx.real_x);
	return Complex(ex * cos(cpx.imag_y), ex * sin(cpx.imag_y));
}

Complex cos(const Complex& cpx)
{ // Consine function
	return Complex(cos(cpx.real_x) * cosh(cpx.imag_y), -sin(cpx.real_x) * sinh(cpx.imag_y));
}

Complex sin(const Complex& cpx)
{ // Sine function
	return Complex(sin(cpx.real_x) * cosh(cpx.imag_y), cos(cpx.real_x) * sinh(cpx.imag_y));
}

Complex tan(const Complex& cpx)
{ // Tangent function
	double x = cpx.real_x, y = cpx.imag_y;
	double res_real = (tan(x) - tan(x) * (tanh(y)*tanh(y))) / (1 + tan(x)*tan(x) * (tanh(y)*tanh(y)));
	double res_imag = (tanh(y) + (tan(x)*tan(x)) * tanh(y)) / (1 + tan(x)*tan(x) * (tanh(y)*tanh(y)));
	return Complex(res_real, res_imag);
}

Complex cosh(const Complex& cpx)
{ // Hyperbolic Cosine function
	return Complex(cosh(cpx.real_x)*cos(cpx.imag_y), sinh(cpx.real_x)*sin(cpx.imag_y));
}

Complex sinh(const Complex& cpx)
{ // Hyperbolic Sine function
	return Complex(sinh(cpx.real_x)*cos(cpx.imag_y), cosh(cpx.real_x)*sin(cpx.imag_y));
}

Complex tanh(const Complex& cpx)
{ // Hyperbolic Tangent function
	return sinh(cpx)/cosh(cpx);
}


// Private member function
void Complex::copy(const Complex& cpx2)
{
	real_x = cpx2.getReal();
	imag_y = cpx2.getImaginary();
}

