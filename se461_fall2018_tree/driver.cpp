// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// rburke

#include <iostream>
#include <string>
#include "Calculator.h"


int main (int argc, char * argv [])
{
	Calculator c;
	std::string infix;

	while (1)
	{
		std::cout << "Enter an expression:" << std::endl;
		std::getline(std::cin, infix);
		if (infix == "QUIT") break;

		try
		{
			//Evaluate expression and print result
			int res = c.evaluate_expr(infix);
			std::cout << res << std::endl;
		}
		//Catching invalid input or division and modulus errors
		catch (std::exception & exp)
		{
			std::cout << exp.what() << std::endl;
		}
	}
	return 0;
}