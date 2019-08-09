// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// rburke

#ifndef EXPR_TREE_BUILDER_H_
#define EXPR_TREE_BUILDER_H_

#include "Expr_Node.h"
#include "Expr_Builder.h"
#include "Calculator_Node_Factory.h"
#include "Num_Expr_Node.h"
#include "Unary_Expr_Node.h"
#include "Add_Expr_Node.h"
#include "Subtract_Expr_Node.h"
#include "Multiply_Expr_Node.h"
#include "Divide_Expr_Node.h"
#include "Modulus_Expr_Node.h"
#include "Open_Parentheses_Node.h"
#include "Close_Parentheses_Node.h"

/**
* @class Expr_Tree_Builder
*
* Implementation of Concrete Builder for Expresion Trees
*/
class Expr_Tree_Builder : public Expr_Builder
{
public:
	/**
	 * Default constructor
	 */
	Expr_Tree_Builder(void) = default;

	/**
	 * Destructor
	 */
	virtual ~Expr_Tree_Builder(void) = default;

	/**
	* Build the initial expression
	*/
	virtual void build_expression(void)
	{
		this->tree_ = 0;
	}

	/**
	 * Build Method
	 */
	virtual void build_binary(void);

	/**
	* Build the number node
	*/
	virtual void build_number(int n);

	/**
	* Build the unary node
	*/
	virtual void build_unary_operand(void);

	/**
	* Build the add node
	*/
	virtual void build_add_operand(void);

	/**
	* Build the subtract node
	*/
	virtual void build_subtract_operand(void);

	/**
	* Build the multiply node
	*/
	virtual void build_multiply_operand(void);

	/**
	* Build the division node
	*/
	virtual void build_division_operand(void);

	/**
	* Build the modulus node
	*/
	virtual void build_modulus_operand(void);

	/**
	* Build the open parentheses node
	*/
	virtual void build_open_parentheses(void);

	/**
	* Build the close parentheses node
	*/
	virtual void build_close_parentheses(void);

	/**
	* Build the empty unary node
	*/
	virtual void build_empty_unary_operand(void);

	/**
	* Build the empty add node
	*/
	virtual void build_empty_add_operand(void);

	/**
	* Build the empty subtract node
	*/
	virtual void build_empty_subtract_operand(void);

	/**
	* Build the empty multiply node
	*/
	virtual void build_empty_multiply_operand(void);

	/**
	* Build the empty divide node
	*/
	virtual void build_empty_divide_operand(void);

	/**
	* Build the empty modulus node
	*/
	virtual void build_empty_modulus_operand(void);

	/**
	* Build the empty parentheses node
	*/
	virtual void build_empty_parentheses(void);

	/**
	* Build the operator tree
	*
	* @param[in]		token		token to be built into a tree
	*/
	virtual void build_op(char token);

	/**
	* Get Expression Tree
	*
	* @return						the expression tree
	*/
	virtual Expr_Node * getExpression(void);
	
private:
	// Variables to help with tree building
	Expr_Node * tree_;
	Calculator_Node_Factory factory;
	Expr_Node * empty_node;
};

#endif