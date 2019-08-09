// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// rburke

#ifndef EXPR_NODE_H_
#define EXPR_NODE_H_

#include <cstring>

//Forward declaration
class Expr_Node_Visitor;

/**
* @class Expr_Node
*
* Implementation of the expression node
*/
class Expr_Node
{
public:
	/**
	 * Default constructor
	 */
	Expr_Node(void) = default;

	/**
	 * Destructor
	 */
	virtual ~Expr_Node(void) = default;

	/**
	* Evaluate
	*
	* @return						the result
	*/
	virtual int evaluate(void) = 0;
	
	/**
	* Accept Visitor
	*
	* @param[in]		v		the visitor type
	*/
	virtual void accept(Expr_Node_Visitor & v) = 0;

	/**
	* Get Precedence
	*
	* @return						the precendence
	*/
	virtual int getPrecedence(void) = 0;

	/**
	* Get Type
	*
	* @return						the operator
	*/
	virtual char getType(void) = 0;
};

#endif