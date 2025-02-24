#include "Serializer.hpp"

/*--------------------------------------------------------------*/
/*							CONSTRUCTORS						*/
/*--------------------------------------------------------------*/

Serializer::Serializer() {

}

Serializer::Serializer(Serializer &model) {

	(void)model;
}

Serializer &Serializer::operator=(const Serializer &model) {

	(void)model;
	return (*this);
}

/*--------------------------------------------------------------*/
/*							DESTRUCTORS							*/
/*--------------------------------------------------------------*/

Serializer::~Serializer() {

}

/*--------------------------------------------------------------*/
/*						PUBLIC_FUNCTIONS						*/
/*--------------------------------------------------------------*/

uintptr_t Serializer::serialize(Data* ptr){
	return(reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw){
	return(reinterpret_cast<Data *>(raw));
}