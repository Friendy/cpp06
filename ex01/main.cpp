#include "Serializer.hpp"
#include "Data.hpp"

int main()
{
	Data data;
	Data *data1;

	data.data_int = 123;
	data.data_float = 42.42;
	data.data_str = "my string";
	data.printme();
	uintptr_t ptr;
	ptr = Serializer::serialize(&data);
	std::cout << "converted: " << ptr << "\n";
	data1 = Serializer::deserialize(ptr);
	data1->printme();
}