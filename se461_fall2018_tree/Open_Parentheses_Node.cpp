// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// rburke

#include "Open_Parentheses_Node.h"

//
// Evaluate
//
int Open_Parentheses_Node::evaluate(void)
{
	return 1;
}

//
// Accept Visitor
//
void Open_Parentheses_Node::accept(Expr_Node_Visitor & v) { }

//
// Get Precedence
//
int Open_Parentheses_Node::getPrecedence(void)
{
	return 0;
}

//
// Get Type
//
char Open_Parentheses_Node::getType(void)
{
	return '(';
}

