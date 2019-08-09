// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// rburke

#include "Expr_Tree_Builder.h"

//
// Build Method
//
void Expr_Tree_Builder::build_binary(void)
{
		if (op_stack.empty())
	{
		op_stack.push(empty_node);
	}
	else if (op_stack.top()->getType() == '(')
	{
		op_stack.push(empty_node);
	}
	//If stack top's precedence is higher then building operator tree
	else if (op_stack.top()->getPrecedence() >= empty_node->getPrecedence())
	{
		while (op_stack.top()->getPrecedence() >= empty_node->getPrecedence())
		{
			build_op(op_stack.top()->getType());
			delete op_stack.top();
			op_stack.pop();
			if ((op_stack.empty()) || (op_stack.top()->getType() == '('))
			{
				op_stack.push(empty_node);
				break;
			}
		}
		if (op_stack.top()->getPrecedence() < empty_node->getPrecedence())
		{
			op_stack.push(empty_node);
		}
	}
	//Push node on stack if the top's precedence is lower
	else if (op_stack.top()->getPrecedence() < empty_node->getPrecedence())
	{
		op_stack.push(empty_node);
	}
}

//
// Build Number
//
void Expr_Tree_Builder::build_number(int n)
{
	Expr_Node * tree_ = factory.create_num_node(n);
	expr_stack.push(tree_);
}

//
// Build Unary Operand
//
void Expr_Tree_Builder::build_unary_operand(void)
{
	build_empty_unary_operand();
	if (!(op_stack.empty()))
	{
		//If there is already a unary present on stack top, build it
		while (op_stack.top()->getType() == 'u')
		{
			build_op(op_stack.top()->getType());
			delete op_stack.top();
			op_stack.pop();
		}
	}
	op_stack.push(empty_node);
}

//
// Build Open Parenthesis
//
void Expr_Tree_Builder::build_open_parentheses(void)
{
	build_empty_parentheses();
	op_stack.push(empty_node);
}

//
// Build Closed Parentheses
//
void Expr_Tree_Builder::build_close_parentheses(void)
{
	while (!(op_stack.top()->getType() == '('))
	{
		build_op(op_stack.top()->getType());
		delete op_stack.top();
		op_stack.pop();
		if (op_stack.empty()) break;
	}
	if (!(op_stack.empty()))
	{
		//Popping '(' open parentheses
		delete op_stack.top();
		op_stack.pop();
	}
}

//
// Build Addition
//
void Expr_Tree_Builder::build_add_operand(void)
{
	build_empty_add_operand();

	build_binary();
}

//
// Build Subtraction
//
void Expr_Tree_Builder::build_subtract_operand(void)
{

	build_empty_subtract_operand();

	build_binary();
}

//
// Build Multiplication
//
void Expr_Tree_Builder::build_multiply_operand(void)
{
	build_empty_multiply_operand();

	build_binary();
}

//
// Build Division
//
void Expr_Tree_Builder::build_division_operand(void)
{
	build_empty_divide_operand();

	build_binary();
}

//
// Build Modulus
//
void Expr_Tree_Builder::build_modulus_operand(void)
{
	build_empty_modulus_operand();

	build_binary();
}

//
// Build Empty Unary Node
//
void Expr_Tree_Builder::build_empty_unary_operand(void)
{
	empty_node = factory.create_empty_unary_node();
}

//
// Build Empty Add Node
//
void Expr_Tree_Builder::build_empty_add_operand(void)
{
	empty_node = factory.create_empty_add_node();
}

//
// Build Empty Subtract Node
//
void Expr_Tree_Builder::build_empty_subtract_operand(void)
{
	empty_node = factory.create_empty_subtract_node();
}

//
// Build Empty Multiply Node
//
void Expr_Tree_Builder::build_empty_multiply_operand(void)
{
	empty_node = factory.create_empty_multiply_node();
}

//
// Build Empty Divide Node
//
void Expr_Tree_Builder::build_empty_divide_operand(void)
{
	empty_node = factory.create_empty_divide_node();
}

//
// Build Empty Modulus Node
//
void Expr_Tree_Builder::build_empty_modulus_operand(void)
{
	empty_node = factory.create_empty_modulus_node();
}

//
// Build Empty Parenthesis Node
//
void Expr_Tree_Builder::build_empty_parentheses(void)
{
	empty_node = factory.create_parentheses_node();
}

//
// Comment: Moved from a series of if-else statements to a 
//          switch statement in an attempt to reuse some code
//

//
// Build Operation
//
void Expr_Tree_Builder::build_op(char token)
{
	//If we have a binary node
	if(token != 'u')
	{
		//Get two elements off the top of stack
		Expr_Node * n2 = expr_stack.top();
		expr_stack.pop();
		Expr_Node * n1 = expr_stack.top();
		expr_stack.pop();
		switch (token)
		{
			//Creating add node with the first two elements on stack
			case '+': 
			{
				Expr_Node * tree_ = factory.create_add_node(n1, n2);
				expr_stack.push(tree_);
				break;
			}
			//Creating subtract node with the first two elements on stack
			case '-':
			{
				Expr_Node * tree_ = factory.create_sub_node(n1, n2);
				expr_stack.push(tree_);
				break;
			}
			//Creating multiply node with the first two elements on stack
			case '*':
			{
				Expr_Node * tree_ = factory.create_mul_node(n1, n2);
			    expr_stack.push(tree_);
				break;
			}
			//Creating division node with the first two elements on stack
			case '/':
			{
				Expr_Node * tree_ = factory.create_div_node(n1, n2);
				expr_stack.push(tree_);
				break;
			}
			//Creating modulus node with the first two elements on stack
			case '%':
			{
				Expr_Node * tree_ = factory.create_mod_node(n1, n2);
				expr_stack.push(tree_);
				break;
			}
			default: throw Unknown_Operator();
		}
		
	}
	//We have a unary node
	else
	{
		//Creating unary node with the first two elements on stack
		Expr_Node * n1 = expr_stack.top();
		Expr_Node * tree_ = factory.create_unary_node(n1);
		expr_stack.pop();
		expr_stack.push(tree_);
	}
}

/**
 * Get Expression Tree
 */
Expr_Node * Expr_Tree_Builder::getExpression(void)
{
	//Storing the remaining operators from stack
	while (!(op_stack.empty()))
	{
		build_op(op_stack.top()->getType());
		delete op_stack.top();
		op_stack.pop();
	}
	//Deleting leftover elements
	if (!(op_stack.empty()))
	{
		for (size_t i = 0; i < op_stack.size(); i++)
		{
			delete op_stack.top();
			op_stack.pop();
		}
	}

	this->tree_ = expr_stack.top();
	return this->tree_;
}