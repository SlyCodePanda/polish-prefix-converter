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

	// The function that rearranges the prefix notation and prints out it's infix interpretation.
	std::vector<std::string> ques( std::vector<std::string> input );

	// The function that converts the prefix statement to infix.
	std::vector<int> convert( std::vector<std::string> input );

	infix();
	~infix();
};