#include "ScalarConverter.hpp"

/*CONSTRUCTORS*/
ScalarConverter::ScalarConverter()
{
	std::cout << "class created" << std::endl;
}

//Assignment operator:
ScalarConverter &ScalarConverter::operator=(ScalarConverter const &)
{
	return(*this);
}

ScalarConverter::ScalarConverter(ScalarConverter const &original)
{
	*this = original;
}

/*FUNCTIONS*/

static bool is_pseudo_lit(std::string s)
{
	// std::string float_lit[] = {"inff", "nanf"};
	// std::string doub_lit[] = {"inf", "nan"};
	// for (int i = 0; i < 2; i++)
	// {
	// 	if s 
	// }
	if (s.compare("nan") == 0 || s.compare("nanf") == 0 )
		return (true)
	else if (s.compare("inff") == 0 || s.at(0) == '+' && s.compare(1, 4, "inff"))
		return (true)

}

static int gettype(std::string s)
{

	
	if (s.length() == 1)
	{
		if (s.at(0) >= 48 && s.at(0) <= 57)
			return (INT);
		if (s.at(0) >= 33 && s.at(0) <= 126)
			return (CHAR);
	}
	if (s.find('.') != std::string::npos)
	{
		if (s.find('f') == s.length() - 1)
			return (FLOAT);
		else
			return (DOUBLE);
	}
	return(INT);
}

void ScalarConverter::convert(const std::string s)
{
	int type;
	char char_val;
	int int_val;
	float float_val;
	std::string str;
	double doub_val;
	std::stringstream ss;
	// std::string pseudo_lit[] = {"inff", "inf", "nan", "nanf"};

	type = gettype(s);
	std::cout << "tp " << type << "\n";
	switch (type)
	{
		case CHAR:
		{
			char_val = s.at(0);
			int_val = static_cast <int> (char_val);
			float_val = static_cast <float> (char_val);
			doub_val = static_cast <double> (char_val);
		}
		break;
		case INT:
		{
			ss << s;
			ss >> int_val;
			char_val = static_cast <char> (int_val);
			float_val = static_cast <float> (int_val);
			doub_val = static_cast <double> (int_val);
		}
		break;
		case FLOAT:
		{
			str = s;
			str.pop_back();
			ss << str;
			// std::cout << "fl " << ss  << "\n";
			ss >> float_val;
			int_val = static_cast <int> (float_val);
			char_val = static_cast <char> (float_val);
			doub_val = static_cast <double> (float_val);

		}
		break;
		case DOUBLE:
		{
			ss << s;
			ss >> doub_val;
			int_val = static_cast <int> (doub_val);
			char_val = static_cast <char> (doub_val);
			float_val = static_cast <float> (doub_val);
		}
	}

	if (char_val < 33 || char_val > 126)
		std::cout << "char: " << "non-displayable" << "\n";
	else if (int_val <= CHAR_MAX && int_val > 0)
		std::cout << "char: " << char_val << "\n";
	else
		std::cout << "char: " << "impossible" << "\n";
	if (float_val <= INT_MAX && float_val >= INT_MIN)
		std::cout << "int: " << int_val << "\n";
	else
		std::cout << "int: " << "impossible" << "\n";
	std::cout << "float: " << float_val << "f\n";
	std::cout << "double: " << doub_val << "\n";

}

/*DESTRUCTOR*/
ScalarConverter::~ScalarConverter(){}
