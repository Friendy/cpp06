#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# include <string>
# include <iostream>
# include <sstream>
# include <climits>
# include <iomanip>

# define INT 0
# define CHAR 1
# define FLOAT 2
# define DOUBLE 3

class ScalarConverter {

private:
	ScalarConverter();
	ScalarConverter(ScalarConverter const &original);

public:
	static void convert(const std::string s);

	ScalarConverter &operator=(ScalarConverter const &original);
	~ScalarConverter();
};

#endif
