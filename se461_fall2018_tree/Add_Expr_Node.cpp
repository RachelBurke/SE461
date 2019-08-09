// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// rburke

#include "Add_Expr_Node.h"
#include "Expr_Node_Visitor.h"

//
// Default Constructor
//
Add_Expr_Node::Add_Expr_Node(void) { }

//
// Initializing Constructor
//
Add_Expr_Node::Add_Expr_Node(Expr_Node * n1, Expr_Node * n2): Binary_Expr_Node(n1, n2) { }

//
// Destructor
//
Add_Expr_Node::~Add_Expr_Node(void) { }

//
// Execute
//
int Add_Expr_Node::execute(int num1, int num2)
{
	return num1 + num2;
}

//
// Get Left Child
//
Expr_Node * Add_Expr_Node::getLeftChild()
{
	return this->left_;
}

//
// Get Right Child
//
Expr_Node * Add_Expr_Node::getRightChild()
{
	return this->right_;
}

//
// Accept Visitor
//
void Add_Expr_Node::accept(Expr_Node_Visitor & v)
{
	v.Visit_Add_Expr_Node(*this);
}

//
// Get Precedence
//
int Add_Expr_Node::getPrecedence(void)
{
	return 1;
}

//
// Get Type
//
char Add_Expr_Node::getType(void)
{
	return '+';
}