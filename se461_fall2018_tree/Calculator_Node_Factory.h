// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// rburke

#ifndef CALC_NODE_FACTORY_H_
#define CALC_NODE_FACTORY_H_

#include "Node_Factory.h"
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
* @class Calculator_Node_Factory
*
* Implementation of a concrete factory for creating nodes
*/
class Calculator_Node_Factory : public Node_Factory
{
public:
	/**
	 * Default constructor
	 */
	Calculator_Node_Factory(void);

	/**
	 * Destructor
	 */
	~Calculator_Node_Factory(void);

	/**
	* Create the node
	*
	* @param[in]		n			number to be inserted in the node
	* @return						the created node
	*/
	virtual Num_Expr_Node * create_num_node(int n);

	/**
	* Create the node
	*
	* @param[in]		n1			number to be inserted in child node
	* @return						the created node
	*/
	virtual Unary_Expr_Node * create_unary_node(Expr_Node * n1);

	/**
	* Create the node
	*
	* @param[in]		n1			number to be inserted in left child node
	* @param[in]		n2			number to be inserted in right child node
	* @return						the created node
	*/
	virtual Add_Expr_Node * create_add_node(Expr_Node * n1, Expr_Node * n2);

	/**
	* Create the node
	*
	* @param[in]		n1			number to be inserted in left child node
	* @param[in]		n2			number to be inserted in right child node
	* @return						the created node
	*/
	virtual Subtract_Expr_Node * create_sub_node(Expr_Node * n1, Expr_Node * n2);

	/**
	* Create the node
	*
	* @param[in]		n1			number to be inserted in left child node
	* @param[in]		n2			number to be inserted in right child node
	* @return						the created node
	*/
	virtual Multiply_Expr_Node * create_mul_node(Expr_Node * n1, Expr_Node * n2);

	/**
	* Create the node
	*
	* @param[in]		n1			number to be inserted in left child node
	* @param[in]		n2			number to be inserted in right child node
	* @return						the created node
	*/
	virtual Divide_Expr_Node * create_div_node(Expr_Node * n1, Expr_Node * n2);

	/**
	* Create the node
	*
	* @param[in]		n1			number to be inserted in left child node
	* @param[in]		n2			number to be inserted in right child node
	* @return						the created node
	*/
	virtual Modulus_Expr_Node * create_mod_node(Expr_Node * n1, Expr_Node * n2);

	/**
	* Create the node
	*
	* @return						the created node
	*/
	virtual Open_Parentheses_Node * create_parentheses_node(void);

	/**
	* Create the empty node
	*
	* @return						the created node
	*/
	virtual Unary_Expr_Node * create_empty_unary_node(void);

	/**
	* Create the empty node
	*
	* @return						the created node
	*/
	virtual Add_Expr_Node * create_empty_add_node(void);

	/**
	* Create the empty node
	*
	* @return						the created node
	*/
	virtual Subtract_Expr_Node * create_empty_subtract_node(void);

	/**
	* Create the empty node
	*
	* @return						the created node
	*/
	virtual Multiply_Expr_Node * create_empty_multiply_node(void);

	/**
	* Create the empty node
	*
	* @return						the created node
	*/
	virtual Divide_Expr_Node * create_empty_divide_node(void);

	/**
	* Create the empty node
	*
	* @return						the created node
	*/
	virtual Modulus_Expr_Node * create_empty_modulus_node(void);


};

#endif