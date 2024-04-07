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

static int is_pseudo_lit(std::string s)
{
	int start;

	start = 0;
	if (s.at(0) == '+' || s.at(0) == '-')
		start = 1;
	if (s.compare("nanf") == 0 || s.compare(start, 5, "inff") == 0)
		return (FLOAT);
	else if (s.compare("nan") == 0 || s.compare(start, 4, "inf") == 0)
		return (DOUBLE);
	else
		return (-1);
}

/*
1) one character input
2) no dot - int assumed
3) f at the end - float assumed
4) digit checking
 */
static int gettype(std::string s)
{
	size_t pos;
	int type;

	if (s.length() == 1)
	{
		if (s.at(0) >= 48 && s.at(0) <= 57)
			return (INT);
		if (s.at(0) >= 33 && s.at(0) <= 126)
			return (CHAR);
	}
	pos = s.find('.');
	if (pos == std::string::npos)
		type = INT;
	else
	{
		if (s.find('f') == s.length() - 1)
		{
			type = FLOAT;
			s.pop_back();
		}
		else
			type = DOUBLE;
		if (pos == s.length() - 1 || pos == 0)
			return (-1);
		else
			s.erase(pos, 1);
	}
	if (s.at(0) == '+' || s.at(0) == '-')
		s.erase(0, 1);
	for (std::string::iterator i = s.begin(); i != s.end(); i++)
	{
		if (std::isdigit(*i) == false)
		{
			type = -1;
			break;
		}
	}
	return(type);
}

void ScalarConverter::convert(const std::string s)
{
	int type;
	long temp;
	char char_val;
	int int_val;
	float float_val;
	double doub_val;
	std::stringstream ss;

	type = is_pseudo_lit(s);
	if (type == -1)
		type = gettype(s);
	switch (type)
	{
		case CHAR:
		{
			ss << s;
			ss >> char_val;
			int_val = static_cast <int> (char_val);
			float_val = static_cast <float> (char_val);
			doub_val = static_cast <double> (char_val);
		}
		break;
		case INT:
		{
			ss << s;
			ss >> temp;
			if (temp >= INT_MIN && temp <= INT_MAX)
				int_val = static_cast <int>(temp);
			else
			{
				std::cerr << "error: type undetectable\n";
				exit(0);
			}
			char_val = static_cast <char> (int_val);
			float_val = static_cast <float> (int_val);
			doub_val = static_cast <double> (int_val);
		}
		break;
		case FLOAT:
		{
			std::string str;
			ss << s;
			ss >> str;
			str.pop_back();
			ss.clear();
			ss << str;
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
		break;
		case -1:
		{
			std::cerr << "error: type undetectable\n";
			exit(0);
		}
	}
	if (int_val > CHAR_MAX || int_val < 0)
		std::cout << "char: " << "impossible" << "\n";
	else if ((char_val >= 0 && char_val < 33) || char_val == 127)
		std::cout << "char: " << "non-displayable" << "\n";
	else if (int_val > 0 && int_val <= CHAR_MAX)
		std::cout << "char: \'" << char_val << "\'\n";
	if (float_val >= INT_MIN && float_val <= INT_MAX)
		std::cout << "int: " << int_val << "\n";
	else
		std::cout << "int: " << "impossible" << "\n";
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << float_val << "f\n";
	std::cout << "double: " << doub_val << "\n";
}

/*DESTRUCTOR*/
ScalarConverter::~ScalarConverter(){}
