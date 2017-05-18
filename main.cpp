#include <iostream>
#include <vector>

#include <string>
#include <sstream>

#include "infix.h"

// Global variables defining the operators as strings.
std::string plus = "+";
std::string times = "*";
std::string divi = "/";
std::string min = "-";

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

   /*-----CHECKING FOR ERRORS-----*/

    // if the length of the inputted statement is 2 or less, an error message is outputted.
    int inLength = input.size();
    if( inLength <= 2 )
    {
      std::cout << "Error \n";
      return 0;
    }

    // If there is not one more operand than there is operators, return an error message.
    int operatorCounter = 0;
    int operandCounter = 0;
    for( int i = inLength -1 ; i >= 0 ; i-- )
    {
        if ( input.at(i) == plus || input.at(i) == times || input.at(i) == divi || input.at(i) == min )
        {
            operatorCounter ++;
        }
        if ( input.at(i) != plus && input.at(i) != times && input.at(i) != divi && input.at(i) != min )
        {
            operandCounter ++;
        }
    }

    if ( operandCounter != operatorCounter + 1 )
    {
        std::cout << "Error \n";
        return 0;
    }

    /*----------------------------*/
    
    // Creating infix object.
    infix calc;
    infix *ptrCalc = &calc;

    // The translated prefix statement into infix notation.
    std::vector<std::string> quest = ptrCalc->ques( input );

    // Calculating the result of the entered statement.
    std::vector<int> vec = ptrCalc->convert( input );


    /*-----OUTPUT-----*/

    //std::cout << "translated to infix notation: " <<std::endl;
    int qLength = quest.size();  
    for( int i = 0 ; i < qLength ; i++ )
      std::cout << quest.at(i) << " ";

    // Print out the result of the statement.
    std::cout << vec.at(0) << std::endl;

    /*------------------------------*/

    return 0;
}