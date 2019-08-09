// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// rburke

#ifndef CLOSE_PARENTHESES_NODE_H_
#define CLOSE_PARENTHESES_NODE_H_

#include "Expr_Node.h"

/**
* @class Num_Expr_Node
*
* Implementation of a close parentheses node
*/
class Close_Parentheses_Node : public Expr_Node
{
public:
	/**
	 * Default constructor
	 */
	Close_Parentheses_Node(void);

	/**
	 * Destructor
	 */
	virtual ~Close_Parentheses_Node(void);

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

#endif		// !defined CLOSE_PARENTHESES_NODE_H_