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

int RPN::calculate(std::string line)
{
	if (!isdigit(*line.begin()))
		throw std::runtime_error("Error");
	
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
				throw std::runtime_error("Error");
			rigth = stack.top();
			stack.pop();
			left = stack.top();
			stack.pop();
			stack.push(choose(left, rigth, *it));
		}
		else if (!isdigit(*it))
			throw std::runtime_error("Error");
		else
			stack.push(*it - '0');
	}
	if (stack.size() != 1)
		throw std::runtime_error("Error");
	std::cout << stack.top() << std::endl;
	
	return(stack.top());
}