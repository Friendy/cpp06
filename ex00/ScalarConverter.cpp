#include "ScalarConverter.hpp"

/*CONSTRUCTORS*/
ScalarConverter::ScalarConverter()
{
	std::cout << "class created" << std::endl;
}

//Assignment operator:
ScalarConverter &ScalarConverter::operator=(ScalarConverter const &original)
{
	return(*this);
}

ScalarConverter::ScalarConverter(ScalarConverter const &original)
{
	*this = original;
}

/*FUNCTIONS*/
static int gettype(const std::string s)
{
	if (s.find('f')!= std::string::npos && s.length() != 1)
		return (FLOAT);
	if (s.find('.')!= std::string::npos)
		return (DOUBLE);
	if (s.length() == 1 && s.at(0) >= 32 && s.at(0) <= 126)
		return (CHAR);
	return(INT);
}

void ScalarConverter::convert(const std::string s)
{
	int type;
	char char_val;
	int int_val;
	float float_val;
	double doub_val;
	std::stringstream ss;

	type = gettype(s);
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
			ss << s;
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


	
	std::cout << "char: " << char_val << "\n";
	std::cout << "int: " << int_val << "\n";
	std::cout << "float: " << float_val << "f \n";
	std::cout << "double: " << doub_val << "\n";

}

/*DESTRUCTOR*/
ScalarConverter::~ScalarConverter(){}
