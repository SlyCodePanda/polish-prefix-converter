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

std::vector<int> infix::convert( std::vector<std::string> input )
{
	int length = input.size();
	std::vector<int> vec;

	// testing input vector...
	std::cout << "input length: " << length << "\n";

	// Scans the given prefix expression from right to left.
	for( int i = length-1 ; i >= 0 ; i-- )
	{
		// For test, checking input vector.
		std::cout << input.at(i) << std::endl;

		// If 'operand' (i.e nonnegative number between 0 - 99) ...
		// If element is not an operator.
		if( input.at(i) != plus && input.at(i) != times && input.at(i) != divi && input.at(i) != min )
		{
			// Convert the found element into an integer 'x' and push it into vector.
			std::string x = input.at(i);
			int newX = std::stoi(x);

			//vec.push_back( newX );
			vec.insert(vec.begin(), newX);

			// Testing to see if all elements are being added correctly.
			std::cout << "Operand deteceted: \n";
			for( int i = 0 ; i < vec.size() ; i++ )
			{
				std::cout << vec.at(i) << " ";
			}
			std::cout << "\n";
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

			// Showing output of the computation being performed.
			std::cout << opperand1 << " + " << opperand2 << "\n";
			int operation = opperand1 + opperand2;
			vec.push_back( operation );
		}
		// If operator is a '*'.
		if( input.at(i) == times )
		{
			int opperand1 = (vec.at(0));
			int opperand2 = (vec.at(1));

			vec.erase (vec.begin(),vec.begin()+2);

			// Showing output of the computation being performed.
			std::cout << opperand1 << " * " << opperand2 << "\n";
			int operation = opperand1 * opperand2;
			vec.push_back( operation );
		}
		// If operator is a '/'.
		if( input.at(i) == divi )
		{
			int opperand1 = (vec.at(0));
			int opperand2 = (vec.at(1));

			vec.erase (vec.begin(),vec.begin()+2);

			// Showing output of the computation being performed.
			std::cout << opperand1 << " / " << opperand2 << "\n";
			int operation = opperand1 / opperand2;
			vec.push_back( operation );
		}
		// If operator is a '-'.
		if( input.at(i) == min )
		{
			int opperand1 = (vec.at(0));
			int opperand2 = (vec.at(1));

			vec.erase (vec.begin(),vec.begin()+2);

			// Showing output of the computation being performed.
			std::cout << opperand1 << " - " << opperand2 << "\n";
			int operation = opperand1 - opperand2;
			vec.push_back( operation );
		}
	}

	// Testing to see vec contents.
	std::cout << "vec: \n";
	for( int i = 0 ; i < vec.size() ; i++ )
	{
		std::cout << vec.at(i) << " ";
	}
	std::cout << "\n";

	return vec;
}

// infix class destructor.
infix::~infix()
{

}