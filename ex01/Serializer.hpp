#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP
# include <string>
# include <iostream>

struct Data;

class Serializer {

private:
	Serializer();
	Serializer(Serializer const &original);

public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);

	Serializer &operator=(Serializer const &original);
	~Serializer();
};

#endif
