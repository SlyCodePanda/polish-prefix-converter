#include <iostream>
#include <vector>
#include <string>
#include <string.h>

#include <typeinfo>
#include <stdio.h>
#include <stdlib.h>

#include "infix.h"

// infix class constructor.
infix::infix()
{

}

// Displays the infix interpretation of the inputted polish prefix.
std::vector <std::string> infix::ques( std::vector<std::string> input )
{
	int length = input.size();
	std::vector<std::string> vec;
	// j is used as a counter for the operators.
	int j = 0;
	int k = 0; // <= counter for adding parenthesis?

	// Scans the given prefix expression from right to left.
	for( int i = length-1 ; i >= 0 ; i-- )
	{
		// If element is an operand.
		if( input.at(i) != plus && input.at(i) != times && input.at(i) != divi && input.at(i) != min )
		{
			vec.insert( vec.begin(), input.at(i) );
		}

		// If element is an operator...
		if( input.at(i) == plus || input.at(i) == times || input.at(i) == divi || input.at(i) == min )
		{
			j++;
			std::string operand1 = input.at(i);

			vec.insert (vec.begin()+j,operand1 );
			j++;
		}
	}

	vec.insert( vec.end(), " = " );
	return vec;
}

// Function that does the calculation of the entered prefix statement.
std::vector<int> infix::convert( std::vector<std::string> input )
{
	int length = input.size();
	std::vector<int> vec;

	// Scans the given prefix expression from right to left.
	for( int i = length-1 ; i >= 0 ; i-- )
	{
		// If 'operand' (i.e nonnegative number between 0 - 99) ...
		// If element is not an operator.
		if( input.at(i) != plus && input.at(i) != times && input.at(i) != divi && input.at(i) != min )
		{
			// Convert the found element 'x' into an integer 'newX' and push it into vector.
			std::string x = input.at(i);
			int newX = std::stoi(x);

			//vec.push_back( newX );
			vec.insert(vec.begin(), newX);
		}
		//  If 'operator' (i.e +, -, *, /) ...
		// If operator is a '+'.
		if( input.at(i) == plus )
		{
			// In the case of a '+' being found, use said operator on the two operands in vector.
			// Then push result onto stack.
			int opperand1 = (vec.at(0));
			int opperand2 = (vec.at(1));

			vec.erase (vec.begin(),vec.begin()+2);

			// Computing 'operand1' 'operator' 'operand2'.
			int operation = opperand1 + opperand2;
			vec.push_back( operation );
		}
		// If operator is a '*'.
		if( input.at(i) == times )
		{
			int opperand1 = (vec.at(0));
			int opperand2 = (vec.at(1));

			vec.erase (vec.begin(),vec.begin()+2);

			// Computing 'operand1' 'operator' 'operand2'.
			int operation = opperand1 * opperand2;
			vec.push_back( operation );
		}
		// If operator is a '/'.
		if( input.at(i) == divi )
		{
			int opperand1 = (vec.at(0));
			int opperand2 = (vec.at(1));

			vec.erase (vec.begin(),vec.begin()+2);

			// Computing 'operand1' 'operator' 'operand2'.
			int operation = opperand1 / opperand2;
			vec.push_back( operation );
		}
		// If operator is a '-'.
		if( input.at(i) == min )
		{
			int opperand1 = (vec.at(0));
			int opperand2 = (vec.at(1));

			vec.erase (vec.begin(),vec.begin()+2);

			// Computing 'operand1' 'operator' 'operand2'.
			int operation = opperand1 - opperand2;
			vec.push_back( operation );
		}
	}

	return vec;
}

// infix class destructor.
infix::~infix()
{

}