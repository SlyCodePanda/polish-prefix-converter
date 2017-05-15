#include <iostream>
#include <string>
#include <vector>

class infix
{
public:
	// Characters that represent the operators of a statement.
	std::string plus = "+";
	std::string times = "*";
	std::string divi = "/";
	std::string min = "-";

	// The function that converts the prefix statement to infix.
	std::vector<int> convert( std::vector<std::string> input );

	infix();
	~infix();
};