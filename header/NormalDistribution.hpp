/*
NormalDistribution.hpp

Header file
A class to calculate N(x), the cumulative normal distribution

given in the link:
http://math60082.blogspot.com/2013/02/question-write-function-to-calculate-nx.html
*/

#ifndef NormalDistribution_HPP
#define NormalDistribution_HPP

class NormalDistribution
{
public:
	// constructors
	NormalDistribution();
	NormalDistribution(const int step_num);
	virtual ~NormalDistribution();

	// public selector and mutator
	void setStepNum(int step_num);
	int getStepNum() const;

	// public member function
	double normalDistribution(const double x) const;

private:
	int stpNum;
};

#endif

