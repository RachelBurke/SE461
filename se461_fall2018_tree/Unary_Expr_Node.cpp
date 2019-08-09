// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// rburke

#include "Unary_Expr_Node.h"
#include "Expr_Node_Visitor.h"

//
// Default Constructor
//
Unary_Expr_Node::Unary_Expr_Node(void): child_(0) { } 

//
// Initializing Constructor
//
Unary_Expr_Node::Unary_Expr_Node(Expr_Node * child): child_(child) { }

//
// Destructor
//
Unary_Expr_Node::~Unary_Expr_Node(void)
{
	if (child_ != 0)
		delete child_;
}

//
// Evaluate
//
int Unary_Expr_Node::evaluate(void)
{
	//If there is a child, evaluate the child and return
	if (this->child_)
	{
		return -this->child_->evaluate();
	}
	return 0;
}

//
// Accept Visitor
//
void Unary_Expr_Node::accept(Expr_Node_Visitor & v)
{
	v.Visit_Unary_Expr_Node(*this);
}

//
// Get Child
//
Expr_Node * Unary_Expr_Node::getChild(void)
{
	return this->child_;
}

//
// Get Precedence
//
int Unary_Expr_Node::getPrecedence(void)
{
	return 3;
}

//
// Get Type
//
char Unary_Expr_Node::getType(void)
{
	return 'u';
}