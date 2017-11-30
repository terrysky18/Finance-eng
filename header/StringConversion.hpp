/**
StringConversion.hpp

Inline header file
Using stringstream to conversion any value into a string
*/

#ifndef StringConversion_HPP
#define StringConversion_HPP

#include <string>
#include <sstream>

using std::string;
using std::stringstream;

template<typename T>
class StringConversion
{
public:
	StringConversion()
	{}

	string getString(const T& value)
	{
		my_value = value;
		stringstream ss;
		ss << my_value;
		return ss.str();
	}

	~StringConversion()
	{}

private:
	T my_value;
};

#endif

