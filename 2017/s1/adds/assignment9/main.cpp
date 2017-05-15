#include <iostream>
#include <vector>

#include <string>
#include <sstream>

#include "infix.h"

int main()
{
    std::vector<std::string> input;
    std::string line;

    // Takes in the Polish Prefix statement from user as a string to be fed to infix function.
    if ( getline(std::cin, line) )
   {
      std::istringstream str(line);

      std::string value;
      str >> value;
      input.push_back( value );
      while ( str >> value ) 
      {
        input.push_back( value );
      }
   }
    
    // Creating infix object.
    infix calc;
    infix *ptrCalc = &calc;

    std::vector<int> vec = ptrCalc->convert( input );


    /*-----OUTPUT-----*/

    // Printing out Polish Prefix input given by user.
    std::cout << "inputted statement: " << std::endl;
    for( int i = 0 ; i < input.size() ; i++ )
    {
        std::cout << input.at(i) << " ";
    }
    std::cout << "\n";

    // Print out the result of the statement.
    std::cout << vec.at(0) << std::endl;

    return 0;
}