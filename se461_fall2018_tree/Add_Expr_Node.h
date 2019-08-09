// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// rburke

#ifndef ADD_EXPR_NODE_H_
#define ADD_EXPR_NODE_H_

#include "Expr_Node.h"
#include "Binary_Expr_Node.h"

/**
* @class Add_Expr_Node
*
* Implementation of an addition node
*/
class Add_Expr_Node : public Binary_Expr_Node
{
public:
	/**
	 * Default constructor
	 */
	Add_Expr_Node(void);

	/**
	* Initializing constructor
	*
	* @param[in]		n1		child node
	* @param[in]		n2		child node
	*/
	Add_Expr_Node(Expr_Node * n1, Expr_Node * n2);

	/**
	 * Destructor
	 */
	virtual ~Add_Expr_Node(void);

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
	* Get the operator
	*
	* @return						the operator
	*/
	virtual char getType(void);

};

#endif