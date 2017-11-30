/*
A function to calculate N(x), the cumulative normal distribution

given in the link:
http://math60082.blogspot.com/2013/02/question-write-function-to-calculate-nx.html
*/

#include <iostream>
#include <cmath>
#include <string>
#include "../header/NormalDistribution.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

double normalDistribution(double x);

int main()
{
	cout.precision(32);
	/*
	cout << "N(0)=" << normalDistribution(0.) << endl;
	cout << "N(1)=" << normalDistribution(1.) << endl;
	cout << "N(2)=" << normalDistribution(2.) << endl;
	*/

	NormalDistribution ND = NormalDistribution(3500);
	cout << "N(0) = " << ND.normalDistribution(0.) << endl;
	cout << "N(1) = " << ND.normalDistribution(1.) << endl;
	cout << "N(2) = " << ND.normalDistribution(2.) << endl;
	cout << "N(3) = " << ND.normalDistribution(3.) << endl;
	return 0;
}

double normalDistribution(double x)
{
	if(x<-10.0) { return 0.0; }
	else if(x>10.0) { return 1.0; }
	else {
		// number of steps
		int N = 2000;
		// range of integration
		double a = 0.0;
		double b = x;
		// local variables
		double s = 0.0, h = 0.0, sum = 0.0;

		// initialise the variables
		h = (b-a)/N;
		// add in the first few terms
		sum = sum + exp(-a*a/2.0) + 4.0*exp(-(a+h)*(a+h)/2.0);
		// and the last one
		sum = sum + exp(-b*b/2.0);

		// loop over terms 2 up to N-1
		for(int i=1; i<N/2; i++)
		{
			s = a + 2*i*h;
			sum = sum + 2.0*exp(-s*s/2.0);
			s = s + h;
			sum = sum + 4.0*exp(-s*s/2.0);
		}
		// complete the integral
		sum = 0.5 + h*sum/3.0/sqrt(8.0*atan(1.0));
		// return result
		return sum;
	}
}
