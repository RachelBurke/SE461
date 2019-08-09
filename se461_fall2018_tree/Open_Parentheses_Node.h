// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// rburke

#ifndef OPEN_PARENTHESES_NODE_H_
#define OPEN_PARENTHESES_NODE_H_

#include "Expr_Node.h"

/**
* @class Num_Expr_Node
*
* Implementation of an open parentheses node
*/
class Open_Parentheses_Node : public Expr_Node
{
public:
	/**
	 * Default constructor
	 */
	Open_Parentheses_Node(void) = default;

	/**
	 * Destructor
	 */
	virtual ~Open_Parentheses_Node(void) = default;

	/**
	* Evaluate
	*
	* @return						the result
	*/
	virtual int evaluate(void);

	/**
	* Accept Visitor
	*
	* @param[in]		v		the visitor type
	*/
	virtual void accept(Expr_Node_Visitor & v);

	/**
	* Get Precedence
	*
	* @return						the precendence
	*/
	virtual int getPrecedence(void);

	/**
	* Get Type
	*
	* @return						the operator
	*/
	virtual char getType(void);
};

#endif