#include "RPN.hpp"

/*--------------------------------------------------------------*/
/*							CONSTRUCTORS						*/
/*--------------------------------------------------------------*/

RPN::RPN() {

}

RPN::RPN(const RPN &model) {
	(void)model;
}

RPN &RPN::operator=(const RPN &model) {
	(void)model;
	return (*this);
}

/*--------------------------------------------------------------*/
/*							DESTRUCTORS							*/
/*--------------------------------------------------------------*/

RPN::~RPN() {

}

/*--------------------------------------------------------------*/
/*						PUBLIC_FUNCTIONS						*/
/*--------------------------------------------------------------*/

// "8 9 * 9 - 9 - 9 - 4 - 1 +"

int	choose(int left, int rigth, char op)
{
	if (op == '+')
		return(left + rigth);
	if (op == '-')
		return(left - rigth);
	if (op == '*')
		return(left * rigth);
	if (op == '/')
		return(left / rigth);
	return(0);
}

bool RPN::calculate(std::string line)
{
	if (!isdigit(*line.begin()))
		return (false);
	
	std::stack<int> stack;
	
	for(std::string::iterator it = line.begin(); it != line.end(); it++)
	{
		int left;
		int rigth;
		if (*it == ' ')
			continue;
		if (*it == '+' || *it == '-'
		|| *it == '*' || *it == '/')
		{
			if (stack.size() < 2)
				return (false);
			rigth = stack.top();
			stack.pop();
			left = stack.top();
			stack.pop();
			stack.push(choose(left, rigth, *it));
		}
		else if (!isdigit(*it))
			return(false);
		else
			stack.push(*it - '0');
		
	}
	if (stack.size() != 1)
		return(false);
	std::cout << stack.top() << std::endl;
	
	return(true);
}