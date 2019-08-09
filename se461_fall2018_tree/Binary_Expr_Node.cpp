// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// rburke

#include "Binary_Expr_Node.h"

//
// Default Constructor
//
Binary_Expr_Node::Binary_Expr_Node(void): left_(0), right_(0) { }

//
// Initializing Constructor
//
Binary_Expr_Node::Binary_Expr_Node(Expr_Node * n1, Expr_Node * n2): left_(n1), right_(n2) { }

//
// Destructor
//
Binary_Expr_Node::~Binary_Expr_Node(void)
{
	if (left_ != 0)
		delete left_;
	if (right_ != 0)
		delete right_;
}

//
// Evaluate
//
int Binary_Expr_Node::evaluate(void)
{
	int num1 = left_->evaluate();
	int num2 = right_->evaluate();
	int result = this->execute(num1, num2);
	return result;
}