// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// rburke

#include "Num_Expr_Node.h"
#include "Expr_Node_Visitor.h"

//
// Default Constructor
//
Num_Expr_Node::Num_Expr_Node(void) { }

//
// Initializing Constructor
//
Num_Expr_Node::Num_Expr_Node(int num): n_(num) { }

//
// Destructor
//
Num_Expr_Node::~Num_Expr_Node(void) { }

//
// Evaluate
//
int Num_Expr_Node::evaluate()
{
	return n_;
}

//
// Accept Visitor
//
void Num_Expr_Node::accept(Expr_Node_Visitor & v)
{
	v.Visit_Num_Expr_Node(*this);
}

//
// Get Precedence
//
int Num_Expr_Node::getPrecedence(void)
{
	return 4;
}

//
// Get Type
//
char Num_Expr_Node::getType(void)
{
	return 'n';
}

//
// Get Value
//
int Num_Expr_Node::getValue(void)
{
	return n_;
}