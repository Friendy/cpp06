#include "Data.hpp"

void Data::printme()
{
	std::cout << "printing structure:" << "\n";
	std::cout << "\tdata_int " << this->data_int << "\n";
	std::cout << "\tdata_str " << this->data_str << "\n";
	std::cout << "\tdata_float " << this->data_float << "\n";
	std::cout << "\taddress " << this << "\n";
}