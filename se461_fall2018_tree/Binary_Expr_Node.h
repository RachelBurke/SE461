// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// rburke

#ifndef BINARY_EXPR_NODE_H_
#define BINARY_EXPR_NODE_H_

#include "Expr_Node.h"

/**
* @class Binary_Expr_Node
*
* Implementation of a binary expression node
*/
class Binary_Expr_Node : public Expr_Node
{
public:
	/**
	 * Default constructor
	 */
	Binary_Expr_Node(void);

	/**
	* Initializing constructor.
	*
	* @param[in]      n1        child node
	* @param[in]      n2        child node
	*/
	Binary_Expr_Node(Expr_Node * n1, Expr_Node * n2);

	/**
	 * Destructor
	 */
	virtual ~Binary_Expr_Node(void);

	/**
	* Execute
	*
	* @param[in]		num1		number in child node
	* @param[in]		num2		number in child node
	* @return						the result
	*/
	virtual int execute(int n1, int n2) = 0;

	/**
	* Evaluate
	*
	* @return						the result
	*/
	virtual int evaluate(void);

	/**
	* Get Left Child
	*
	* @return						the left child node
	*/
	virtual Expr_Node * getLeftChild() = 0;

	/**
	* Get Right Child
	*
	* @return						the right child node
	*/
	virtual Expr_Node * getRightChild() = 0;

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

protected:
	//Child nodes
	Expr_Node * left_;
	Expr_Node * right_;
};


#endif