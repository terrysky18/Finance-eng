/*
TestComplex.cpp

To test the Complex number class
*/

#include <iostream>
#include <string>
#include <cstdlib>	// to use random number generator
#include <ctime>	// to use clock

#include "../header/StringConversion.hpp"
#include "../header/Complex.hpp"

using std::string;
using std::cout;
using std::cin;
using std::endl;

Complex genComplex();

int main()
{
	srand(time(NULL));	// seed the random generator
	Complex complex1 = genComplex();
	Complex complex2 = genComplex();

	cout << "Complex number 1 = " << complex1.toString() << endl;
	cout << "complex number 2 = " << complex2.toString() << endl;

	Complex complex3 = complex1 + complex2;
	cout << complex1.toString() << " + " << complex2.toString();
	cout << " = " << complex3.toString() << endl;

	complex3 = complex1 - complex2;
	cout << complex1.toString() << " - " << complex2.toString();
	cout << " = " << complex3.toString() << endl;

	complex3 = complex1 * complex2;
	cout << complex1.toString() << " * " << complex2.toString();
	cout << " = " << complex3.toString() << endl;

	complex3 = complex1 / complex2;
	cout << complex1.toString() << " / " << complex2.toString();
	cout << " = " << complex3.toString() << endl;

	complex3 = exp(complex1);
	cout << "exp(" << complex1.toString() << ") = ";
	cout << complex3.toString() << endl;

	complex3 = exp(complex2);
	cout << "exp(" << complex2.toString() << ") = ";
	cout << complex3.toString() << endl;

	complex3 = cos(complex1);
	cout << "cos(" << complex1.toString() << ") = ";
	cout << complex3.toString() << endl;

	complex3 = cos(complex2);
	cout << "cos(" << complex2.toString() << ") = ";
	cout << complex3.toString() << endl;

	complex3 = sin(complex1);
	cout << "sin(" << complex1.toString() << ") = ";
	cout << complex3.toString() << endl;

	complex3 = sin(complex2);
	cout << "sin(" << complex2.toString() << ") = ";
	cout << complex3.toString() << endl;

	complex3 = tan(complex1);
	cout << "tan(" << complex1.toString() << ") = ";
	cout << complex3.toString() << endl;

	complex3 = tan(complex2);
	cout << "tan(" << complex2.toString() << ") = ";
	cout << complex3.toString() << endl;

	complex3 = cosh(complex1);
	cout << "cosh(" << complex1.toString() << ") = ";
	cout << complex3.toString() << endl;

	complex3 = cosh(complex2);
	cout << "cosh(" << complex2.toString() << ") = ";
	cout << complex3.toString() << endl;

	complex3 = sinh(complex1);
	cout << "sinh(" << complex1.toString() << ") = ";
	cout << complex3.toString() << endl;

	complex3 = sinh(complex2);
	cout << "sinh(" << complex2.toString() << ") = ";
	cout << complex3.toString() << endl;

	complex3 = tanh(complex1);
	cout << "tanh(" << complex1.toString() << ") = ";
	cout << complex3.toString() << endl;

	complex3 = tanh(complex2);
	cout << "tanh(" << complex2.toString() << ") = ";
	cout << complex3.toString() << endl;

	return 0;
}

// Generate and return a Complex number
Complex genComplex()
{
	// produce a number between 0 and 10
	int tmp1 = rand() % 20 - 10;
	int tmp2 = rand() % 20 - 10;

	double a = static_cast<double>(tmp1);
	double b = static_cast<double>(tmp2);

	return Complex(a, b);
}

