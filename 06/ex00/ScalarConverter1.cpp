#include "ScalarConverter1.hpp"

ScalarConverter::ScalarConverter() : _literal("0")
{
    std::cout << "Default constructer.\n";
}

ScalarConverter::ScalarConverter(std::string literal) : _literal(literal)
{
    std::cout << "Constructor.\n";
}

ScalarConverter::ScalarConverter(ScalarConverter &other)
{
    std::cout << "Copy constructor.\n";
    // copy
}

ScalarConverter::~ScalarConverter()
{
    std::cout << "Destructor called.\n";
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter &other)
{
    std::cout << "Copy assignment operator.\n";
    // copy
}

void ScalarConverter::convert()
{
    //check input and find input type
    std::cout << "check if literal - " << _literal << " is char:\n";
    if (checkChar())
        std::cout << "TRUE\n";
    else
        std::cout << "FALSE\n";

    std::cout << "check if literal - " << _literal << " is int:\n";
    if (checkInt())
        std::cout << "TRUE\n";
    else
        std::cout << "FALSE\n";

    std::cout << "check if literal - " << _literal << " is float:\n";
    if (checkFloat())
        std::cout << "TRUE\n";
    else
        std::cout << "FALSE\n";
}

char ScalarConverter::getLiteralType() const
{

}

bool ScalarConverter::checkChar() const
{
    if (_literal.size() != 1)
        return false;
    if (_literal[0] >= '0' && _literal[0] <= '9')
        return false;
    return true;
}

bool ScalarConverter::checkInt() const
{
    int sign = 0;
    if (_literal[0] == '+' || _literal[0] == '-')
        sign = 1;
    for (int i = 0; i + sign < _literal.size(); i++)
        if (_literal[i + sign] < '0' || _literal[i + sign] > '9')
            return false;
    return true;
}

bool ScalarConverter::checkFloat() const
{
    int dot_counter = 0;
    int f_counter = 0; 
    int sign = 0;

    if (_literal[0] == '+' || _literal[0] == '-')
        sign = 1;
    for (int i = 0; i + sign < _literal.size(); i++)
    {
        if (_literal[i + sign] == '.')
            dot_counter++;
        else if (_literal[i + sign] == 'f')
            f_counter++;
        else if (_literal[i + sign] < '0' || _literal[i] > '9')
            return false;
    }
    if (dot_counter != 1 || f_counter != 1)
        return false;
    if (_literal[_literal.size() - 1] != 'f')
        return false;
    if (_literal[0 + sign] == '.' || _literal[_literal.size() - 2] == '.')
        return false;
    return true;
}

bool ScalarConverter::checkDouble() const
{
    int dot_counter = 0;
    int sign = 0;

    if (_literal[0] == '+' || _literal[0] == '-')
        sign = 1;
    for (int i = 0; i + sign < _literal.size(); i++)
    {
        if (_literal[i + sign] == '.')
            dot_counter++;
        else if (_literal[i + sign] < '0' || _literal[i] > '9')
            return false;
    }
    if (dot_counter != 1)
        return false;
    if (_literal[0 + sign] == '.' || _literal[_literal.size() - 1] == '.')
        return false;
    return true;
}
