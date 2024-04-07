#include "ScalarConverter.hpp"

int main(int argc, char *argv[])
{
	std::string s;
	std::string t;
	std::stringstream ss;
	if (argc != 2)
	{
		std::cerr << "error: wrong number of arguments\n";
		exit(0);
	}
	if (argc == 2)
		s.append(argv[1]);
	ScalarConverter::convert(s);
}