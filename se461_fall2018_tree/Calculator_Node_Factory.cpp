// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// rburke

#include "Calculator_Node_Factory.h"

//
// Default Constructor
//
Calculator_Node_Factory::Calculator_Node_Factory(void) { }

//
// Destructor
//
Calculator_Node_Factory::~Calculator_Node_Factory(void) { }

//
// Creaet Number Node
//
Num_Expr_Node * Calculator_Node_Factory::create_num_node(int n)
{
	return new Num_Expr_Node(n);
}

//
// Create Unary Node
//
Unary_Expr_Node * Calculator_Node_Factory::create_unary_node(Expr_Node * n1)
{
	return new Unary_Expr_Node(n1);
}

//
// Create Addition Node
//
Add_Expr_Node * Calculator_Node_Factory::create_add_node(Expr_Node * n1, Expr_Node * n2)
{
	return new Add_Expr_Node(n1, n2);
}

//
// Create Subtraction Node
//
Subtract_Expr_Node * Calculator_Node_Factory::create_sub_node(Expr_Node * n1, Expr_Node * n2)
{
	return new Subtract_Expr_Node(n1, n2);
}

//
// Create Multiplication Node
//
Multiply_Expr_Node * Calculator_Node_Factory::create_mul_node(Expr_Node * n1, Expr_Node * n2)
{
	return new Multiply_Expr_Node(n1, n2);
}

//
// Create Division Node
//
Divide_Expr_Node * Calculator_Node_Factory::create_div_node(Expr_Node * n1, Expr_Node * n2)
{
	return new Divide_Expr_Node(n1, n2);
}

//
// Create Modulus Node
//
Modulus_Expr_Node * Calculator_Node_Factory::create_mod_node(Expr_Node * n1, Expr_Node * n2)
{
	return new Modulus_Expr_Node(n1, n2);
}

//
// Create Parenthesis Node
//
Open_Parentheses_Node * Calculator_Node_Factory::create_parentheses_node(void)
{
	return new Open_Parentheses_Node();
}

//
// Create Empty Unary Node
//
Unary_Expr_Node * Calculator_Node_Factory::create_empty_unary_node(void)
{
	return new Unary_Expr_Node();
}

//
// Create Empty Addition Node
//
Add_Expr_Node * Calculator_Node_Factory::create_empty_add_node(void)
{
	return new Add_Expr_Node();
}

//
// Creae Empty Subtraction Node
//
Subtract_Expr_Node * Calculator_Node_Factory::create_empty_subtract_node(void)
{
	return new Subtract_Expr_Node();
}

//
// Create Empty Multiplication Node
//
Multiply_Expr_Node * Calculator_Node_Factory::create_empty_multiply_node(void)
{
	return new Multiply_Expr_Node();
}

//
// Create Empty Division Node
//
Divide_Expr_Node * Calculator_Node_Factory::create_empty_divide_node(void)
{
	return new Divide_Expr_Node();
}

//
// Create Empty Modulus Node
//
Modulus_Expr_Node * Calculator_Node_Factory::create_empty_modulus_node(void)
{
	return new Modulus_Expr_Node();
}