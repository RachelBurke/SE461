// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// rburke

#include "Multiply_Expr_Node.h"
#include "Expr_Node_Visitor.h"

//
// Initializing Constructor
//
Multiply_Expr_Node::Multiply_Expr_Node(Expr_Node * n1, Expr_Node * n2): Binary_Expr_Node(n1, n2) { }

//
// Execute
//
int Multiply_Expr_Node::execute(int num1, int num2)
{
	return num1 * num2;
}

//
// Get Left Child
//
Expr_Node * Multiply_Expr_Node::getLeftChild()
{
	return this->left_;
}

//
// Get Right Child
//
Expr_Node * Multiply_Expr_Node::getRightChild()
{
	return this->right_;
}

//
// Accept Visitor
//
void Multiply_Expr_Node::accept(Expr_Node_Visitor & v)
{
	v.Visit_Multiply_Expr_Node(*this);
}

//
// Get Precedence
//
int Multiply_Expr_Node::getPrecedence(void)
{
	return 2;
}

//
//my_type
//
char Multiply_Expr_Node::getType(void)
{
	return '*';
}