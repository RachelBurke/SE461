// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// rburke

#ifndef UNARY_EXPR_NODE_H_
#define UNARY_EXPR_NODE_H_

#include "Expr_Node.h"

/**
* @class Unary_Expr_Node
*
* Implementation of a unary expression node
*/
class Unary_Expr_Node : public Expr_Node
{
public:
	/**
	 * Default constructor
	 */
	Unary_Expr_Node(void);

	/**
	* Initializing constructor.
	*
	* @param[in]      child        node to be initialized
	*/
	Unary_Expr_Node(Expr_Node * child);

	/**
	 * Destructor
	 */
	virtual ~Unary_Expr_Node(void);

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
	* Get Child
	*
	* @return						the child node
	*/
	virtual Expr_Node * getChild(void);

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

private:
	// Child node variable
	Expr_Node * child_;
};

#endif