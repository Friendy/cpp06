#include "ScalarConverter.hpp"

int main(int argc, char *argv[])
{
	// float test = 545.6f;
	std::string s;
	if (argc > 1)
		s.append(argv[1]);
	int c = s.find("nan");
	std::cout << "t " << c << "\n";
	ScalarConverter::convert(s);
}