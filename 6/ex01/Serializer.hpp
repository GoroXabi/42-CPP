#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include "stdint.h"

struct Data
{
	std::string	name;
	std::string	writter;
	int 		id;
};

class	Serializer
{
private:

/*--------------------CONSTRUCTORS-------------------*/

	Serializer();
	Serializer(Serializer &model);
	Serializer&operator=(const Serializer&model);

/*--------------------DESTRUCTORS--------------------*/

	~Serializer();

/*-----------------PUBLIC_FUNCTIONS------------------*/

public:

	static	uintptr_t serialize(Data* ptr);
	static	Data* deserialize(uintptr_t raw);

};

#endif
