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

    // The translated prefix statement into infix notation.
    std::vector<std::string> quest = ptrCalc->ques( input );

    // Calculating the result of the entered statement.
    std::vector<int> vec = ptrCalc->convert( input );


    /*-----OUTPUT-----*/
/*
    // Printing out Polish Prefix input given by user.
    std::cout << "inputted statement: " << std::endl;
    for( int i = 0 ; i < input.size() ; i++ )
    {
        std::cout << input.at(i) << " ";
    }
    std::cout << "\n";
*/
    //std::cout << "translated to infix notation: " <<std::endl;
    for( int i = 0 ; i < quest.size() ; i++ )
      std::cout << quest.at(i) << " ";

    // Print out the result of the statement.
    std::cout << vec.at(0) << std::endl;

    return 0;
}