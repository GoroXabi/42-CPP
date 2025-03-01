#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>

class	RPN
{
private:
	
/*--------------------CONSTRUCTORS-------------------*/
	
	RPN();
	RPN(const RPN &model);
	RPN &operator=(const RPN &model);
	
/*--------------------DESTRUCTORS--------------------*/
	
	~RPN();

public:

/*-----------------PUBLIC_FUNCTIONS------------------*/

	static int calculate(std::string line);

};

#endif
