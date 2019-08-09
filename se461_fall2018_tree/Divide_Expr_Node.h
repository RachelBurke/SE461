// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// rburke

#ifndef DIVIDE_EXPR_NODE_H_
#define DIVIDE_EXPR_NODE_H_

#include "Binary_Expr_Node.h"
#include "My_Exceptions.h"


/**
* @class Divide_Expr_Node
*
* Implementation of a division node
*/
class Divide_Expr_Node : public Binary_Expr_Node
{
public:
	/**
	 * Default constructor
	 */
	Divide_Expr_Node(void);

	/**
	* Initializing constructor
	*
	* @param[in]		n1		child node
	* @param[in]		n2		child node
	*/
	Divide_Expr_Node(Expr_Node * n1, Expr_Node * n2);

	/**
	 * Destructor
	 */
	virtual ~Divide_Expr_Node(void);

	/**
	* Execute
	*
	* @param[in]		num1		number in child node
	* @param[in]		num2		number in child node
	* @return						the result
	*/
	virtual int execute(int num1, int num2);

	/**
	* Get Left Child
	*
	* @return						the left child node
	*/
	virtual Expr_Node * getLeftChild();

	/**
	* Get Right Child
	*
	* @return						the right child node
	*/
	virtual Expr_Node * getRightChild();

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