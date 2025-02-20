#include <iostream>
#include "Serializer.hpp"


int main() {
	
	Data		data;
	Data		*ptr = &data;
	uintptr_t	uptr = Serializer::serialize(&data);

	data.id = 1;
	data.name = "aaaa";
	data.writter = "me";

	std::cout << data.id << std::endl;
	std::cout << data.name << std::endl;
	std::cout << data.writter << std::endl;

	std::cout << ptr->id << std::endl;
	std::cout << ptr->name << std::endl;
	std::cout << ptr->writter << std::endl;

	ptr = Serializer::deserialize(uptr);

	std::cout << ptr->id << std::endl;
	std::cout << ptr->name << std::endl;
	std::cout << ptr->writter << std::endl;


	return 0;
}
