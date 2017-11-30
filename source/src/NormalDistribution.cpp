/*
NormalDistribution.cpp

Source file for normal distribution class
*/

#include <cmath>
#include "../header/NormalDistribution.hpp"

// Default constructor, 2000 as default step number
NormalDistribution::NormalDistribution()
{// default value as 2000
	stpNum = 2000;
}

NormalDistribution::NormalDistribution(const int step_num) 
{ stpNum = step_num; }

NormalDistribution::~NormalDistribution()
{}

// public selector and mutator
void NormalDistribution::setStepNum(int step_num)
{ stpNum = step_num; }

int NormalDistribution::getStepNum() const
{ return stpNum; }

// public member function
double NormalDistribution::normalDistribution(const double x) const
{
	if(x<-10.0) { return 0.0; }
	else if(x>10.0) { return 1.0; }
	else {
		// number of steps
		int N = stpNum;
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

