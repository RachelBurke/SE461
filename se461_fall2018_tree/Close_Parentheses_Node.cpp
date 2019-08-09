// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// rburke

#include "Close_Parentheses_Node.h"

//
// Default Constructor
//
Close_Parentheses_Node::Close_Parentheses_Node(void) { }

//
// Destructor
//
Close_Parentheses_Node::~Close_Parentheses_Node(void) { }

//
// Evaluate
//
int Close_Parentheses_Node::evaluate(void)
{
	return 1;
}

//
// Accept Visitor
//
void Close_Parentheses_Node::accept(Expr_Node_Visitor & v) { }

//
// Get Precedence
//
int Close_Parentheses_Node::getPrecedence(void)
{
	return 0;
}

//
// Get Type
//
char Close_Parentheses_Node::getType(void)
{
	return ')';
}

