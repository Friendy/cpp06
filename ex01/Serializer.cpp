#include "Serializer.hpp"

/*CONSTRUCTORS*/
Serializer::Serializer()
{
	std::cout << "class created" << std::endl;
}

//Assignment operator:
Serializer &Serializer::operator=(Serializer const &)
{
	return(*this);
}

Serializer::Serializer(Serializer const &original)
{
	*this = original;
}

/*FUNCTIONS*/
uintptr_t Serializer::serialize(Data *ptr)
{
	return(reinterpret_cast <uintptr_t> (ptr));
}

Data *Serializer::deserialize(uintptr_t raw)
{
	return(reinterpret_cast <Data *> (raw));
}

/*DESTRUCTOR*/
Serializer::~Serializer(){}
