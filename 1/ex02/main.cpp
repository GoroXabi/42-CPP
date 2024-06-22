#include <iostream>
#include <string>


int main() {
    
	std::string string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string &stringREF = string;

	std::cout << "string addres = \t" << &string << std::endl;
	std::cout << "stringPTR addres = \t" << &stringPTR << std::endl;
	std::cout << "stringREF addres = \t" << &stringREF << std::endl;

	std::cout << "string content = \t" << string << std::endl;
	std::cout << "stringPTR content = \t" << *stringPTR << std::endl;
	std::cout << "stringREF content = \t" << stringREF << std::endl;

    return 0;
}
