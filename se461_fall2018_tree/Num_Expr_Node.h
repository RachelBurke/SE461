// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// rburke

#ifndef NUM_EXPR_NODE_H_
#define NUM_EXPR_NODE_H_

#include "Expr_Node.h"

/**
* @class Num_Expr_Node
*
* Implementation of a number node
*/
class Num_Expr_Node : public Expr_Node
{
public:
	/**
	 * Default constructor
	 */
	Num_Expr_Node(void);

	/**
	* Initializing constructor.
	*
	* @param[in]      num        value to be initialized
	*/
	Num_Expr_Node(int num);

	/**
	 * Destructor
	 */
	virtual ~Num_Expr_Node(void);

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

	/**
	* Get Value
	*
	* @return						the number
	*/
	virtual int getValue(void);

private:
	// Number Variable
	int n_;
};

#endif