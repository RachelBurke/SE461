// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// rburke

#include "Divide_Expr_Node.h"
#include "Expr_Node_Visitor.h"

//
// Default Constructor
//
Divide_Expr_Node::Divide_Expr_Node(void) { }

//
// Initializing Constructor
//
Divide_Expr_Node::Divide_Expr_Node(Expr_Node * n1, Expr_Node * n2): Binary_Expr_Node(n1, n2) { }

//
// Destructor
//
Divide_Expr_Node::~Divide_Expr_Node(void) { }

//
// Excecute
//
int Divide_Expr_Node::execute(int num1, int num2)
{
	if (num2 == 0)
		throw Divide_By_Zero();
	return num1 / num2;
}

//
// Get Left Child
//
Expr_Node * Divide_Expr_Node::getLeftChild()
{
	return this->left_;
}

//
// Get Right Child
//
Expr_Node * Divide_Expr_Node::getRightChild()
{
	return this->right_;
}

//
// Accept Visitor
//
void Divide_Expr_Node::accept(Expr_Node_Visitor & v)
{
	v.Visit_Divide_Expr_Node(*this);
}

//
// Get Precedence
//
int Divide_Expr_Node::getPrecedence(void)
{
	return 2;
}

//
// Get Type
//
char Divide_Expr_Node::getType(void)
{
	return '/';
}