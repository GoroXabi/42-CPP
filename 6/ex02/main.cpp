#include <iostream>
#include <typeinfo> 
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

void identify(Base& p){

	try
	{
		(void)dynamic_cast<A &>(p);
		std::cout << "Im an A" << std::endl;
		return;
	}
	catch(const std::bad_cast){}
	try
	{
		(void)dynamic_cast<B &>(p);
		std::cout << "Im an B" << std::endl;
		return;
	}
	catch(const std::bad_cast){}
	try
	{
		(void)dynamic_cast<C &>(p);
		std::cout << "Im an C" << std::endl;
		return;
	}
	catch(const std::bad_cast){}
}

void identify(Base* p){
	if (dynamic_cast<A *>(p))
		std::cout << "Im an A" << std::endl;
	if (dynamic_cast<B *>(p))
		std::cout << "Im an B" << std::endl;
	if (dynamic_cast<C *>(p))
		std::cout << "Im an C" << std::endl;
}

Base *generate(void){

	srand (time(NULL));

	switch ((rand() % 3) + 1)
	{
	case 1:
	{
		std::cout << "Im born as an A" << std::endl;
		return(new A);
		break;
	}
	case 2:
	{
		std::cout << "Im born as an B" << std::endl;
		return(new B);
		break;
	}
	case 3:
	{
		std::cout << "Im born as an C" << std::endl;
		return(new C);
		break;
	}
	
	default:
		return(NULL);
		break;
	}
}

int main() {
	
	Base *p = generate();

	identify(p);
	identify(*p);

	return 0;
}
