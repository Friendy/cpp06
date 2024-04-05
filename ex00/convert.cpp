#include "ScalarConverter.hpp"

int main(int argc, char *argv[])
{
    std::string s;
    s.append(argv[1]);
    // std::cout << s << "\n";
    ScalarConverter::convert(s);
}