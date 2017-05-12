#include <iostream>
#include <vector>
#include <string>
#include <string.h>

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
/*
	std::vector<int> value1;

	std::cout << length << std::endl;
	for ( int i = 0 ; i < length ; i++ )
	{
		if ( input.at(i) != plus )
			std::cout << "These aren't plus signs! " << input.at(i) << "\n";
			value1.push_back( atoi( input.at(i)) );
	}
	std::cout << "\n";
*/
	// Scans the given prefix expression from right to left.
	for( int i = length ; i >= 0 ; i-- )
	{
		std::cout << input.at(i) << std::endl;
		if( input.at(i) != plus )
		{
			//std::cout << "found a number! Adding to vector. \n";
			std::string x = input.at(i);
			std::stoi(x);
			vec.push_back( x );
		}
		if( input.at(i) == plus )
		{
			int opperand1 = (vec.at(0)) - '0';
			int opperand2 = (vec.at(1)) - '0';
			vec.pop_back();
			vec.pop_back();

			int operation = opperand1 + opperand2;
			vec.push_back( operation );
		}
	}

	return vec;
}

// infix class destructor.
infix::~infix()
{

}