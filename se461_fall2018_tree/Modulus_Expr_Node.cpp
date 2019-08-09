// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// rburke

#include "Modulus_Expr_Node.h"
#include "Expr_Node_Visitor.h"

//
// Initializing Constructor
//
Modulus_Expr_Node::Modulus_Expr_Node(Expr_Node * n1, Expr_Node * n2): Binary_Expr_Node(n1, n2) { }

//
// Execute
//
int Modulus_Expr_Node::execute(int num1, int num2)
{
	if (num2 == 0)
		throw Modulus_By_Zero();
	return num1 % num2;
}

//
// Get Left Child
//
Expr_Node * Modulus_Expr_Node::getLeftChild()
{
	return this->left_;
}

//
// Get Right Child
//
Expr_Node * Modulus_Expr_Node::getRightChild()
{
	return this->right_;
}

//
// Accept Visitor
//
void Modulus_Expr_Node::accept(Expr_Node_Visitor & v)
{
	v.Visit_Modulus_Expr_Node(*this);
}

//
// Get Precedence
//
int Modulus_Expr_Node::getPrecedence(void)
{
	return 2;
}

//
// Get Type
//
char Modulus_Expr_Node::getType(void)
{
	return '%';
}