// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// rburke

#ifndef CALCULATOR_H_
#define CALCULATOR_H_

#include"Expr_Builder.h"
#include "Expr_Tree_Builder.h"
#include "Eval_Expr_Tree_Visitor.h"
#include <stack>
#include <string>
#include <sstream>
#include <exception>

/**
* @class Calculator
*
* Implementation of a simple calculator
*/
class Calculator
{
public:
	/**
	 * Default constructor
	 */
	Calculator(void);

	/**
	 * Destructor
	 */
	virtual ~Calculator(void);

	/**
	 * Check if expression is valid
	 * 
	 * @param[in]		infix			infix string
	 * @return							boolean value to indicate success
	 */
	bool valid_expression(const std::string & infix);

	/**
	* Check if token is an operator
	*
	* @param[in]		token			token to be tested
	* @return							boolean value to indicate token
	*/
	bool is_operator(std::string token);

	/**
	* Parse Expression
	*
	* @param[in]		infix			infix string
	* @param[in]		b				the desired builder
	* @return							boolean value to indicate success
	*/
	bool parse_expr(const std::string & infix, Expr_Builder & b);

	/**
	* Evaluate
	*
	* @param[in]		infix			infix string
	* @return							the result
	*/
	int evaluate_expr(const std::string & infix);

	/**
 	* Exception class for invalid input
	*/
	class Invalid_Input : public std::exception {
	public:
  		/// Default constructor.
    	Invalid_Input(void): std::exception() { }
	};

};

#endif