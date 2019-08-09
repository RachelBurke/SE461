// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// rburke

#include "Calculator.h"

//
// Default Constructor
//
Calculator::Calculator(void) { }

//
// Destructor
//
Calculator::~Calculator(void) { }

//
// Binary Operators
//
bool Calculator::is_operator(std::string token)
{
	if (token == "+") return true;
	else if (token == "-") return true;
	else if (token == "*") return true;
	else if (token == "/") return true;
	else if (token == "%") return true;
	else return false;
}

//
// Valid Expression
//
bool Calculator::valid_expression(const std::string & infix)
{
	//No input, return false
	if (infix.size() == 0)
		return false;

	//Incorrect start of expression
	if ((infix[0] == '+') || (infix[0] == '/') || (infix[0] == '%') || (infix[0] == '*'))
		return false;


    //Count Parenthesis
    int left = 0;
    int right = 0;
	for (size_t i = 0; i < infix.size(); i++)
	{
		if (infix[i] == '(')
            left++;
        else if (infix[i] == ')')
            right++;
	}
    if (left != right)
        return false;
        
	return true;
}

//
// Parse the Expression from the User
//
bool Calculator::parse_expr(const std::string & infix, Expr_Builder & b)
{
	std::istringstream input(infix);
	std::string token;
	//Stack to keep track of operators
	std::stack<char> op_stack;
	//Operator and digit counts to keep track of unary operator
	int operator_count = 0;
	int digit_count = 0;

	b.build_expression();

	//While reading in valid
	while (input >> token)
	{
		//An open parentheses
		if (token == "(")
		{
			b.build_open_parentheses();
		}
		// A number
		else if ((isdigit(token[0])) || ((token.size() >= 2) && (atoi(token.c_str()))))
		{
			digit_count++;
			int val = atoi(token.c_str());
			b.build_number(val);
		}
		//A Valid Operator
		else if (is_operator(token))
		{
			operator_count++;

			//Condition to check for unary operator
			if (operator_count > digit_count) 
			{
				b.build_unary_operand();
				operator_count--;
				continue;
			}

			//Building the respective operator and its tree
			if (token == "+") b.build_add_operand();
			else if (token == "-") b.build_subtract_operand();
			else if (token == "*") b.build_multiply_operand();
			else if (token == "/") b.build_division_operand();
			else if (token == "%") b.build_modulus_operand();
		}
		//A Closed Parenthesis
		else if (token == ")")
		{
			//Building expression in parentheses
			b.build_close_parentheses();
		}
		else
		{
			//If something other than a number is entered
			return false;
		}
	}
	//Completed Parse
	return true;
}

//
// Evaluate the Expression
//
int Calculator::evaluate_expr(const std::string & infix)
{
	//Expression node variable
	Expr_Node * expr;

	//Visitor for postfix traversal
	Eval_Expr_Tree_Visitor eval;
	//Visit the Tree Nodes amd Evaluate
	try
	{
		if(!(valid_expression(infix)))
			throw Invalid_Input();

		//Begin to build and parse tree
		Expr_Tree_Builder tree;
		//If the expression is bad return false
		if (!(this->parse_expr(infix, tree)))
			throw Invalid_Input();

		//Getting the expression tree
		expr = tree.getExpression();

		//Empty Tree
		if (0 == expr)
			throw Invalid_Input();
		
		expr->accept(eval);
	}
	catch (std::exception)
	{
		//Delete Empty Expression if not null
		if (expr !=  0)
			delete expr;
		throw;
	}
	
	//Return the Result
	int result = eval.result();

	//Clean up memory leaks
	delete expr;

	//Result of the expression
	return result;
}