#include "ScalarConverter.hpp"

void ScalarConverter::convert(std::string literal)
{
    char _char;
    int _int;
    float _float;
    double _double;
    char _type;

    _type = getLiteralType(literal);
    switch (_type)
    {
    case 'c':
        std::cout << "literal is of type char.\n";
        // toChar();
        // fromChar();
        break;
    case 'f':
        std::cout << "literal is of type float.\n";
        // toFloat();
        // fromFloat();
        break;
    case 'd':
        std::cout << "literal is of type double.\n";
        // toDouble();
        // fromDouble();
        break;
    case 'i':
        std::cout << "literal is of type int.\n";
        _int = toInt(literal);
        std::cout << "int = " << _int << std::endl;
        fromInt(_int, _char, _float, _double);
        break;
    }
    displayTypes(_int, _char, _float, _double);    
}

char ScalarConverter::getLiteralType(std::string literal)
{
    if (literal == "+inff" || literal == "-inff" || literal == "nanf")
        return 'f';
    if (literal == "+inf" || literal == "-inf" || literal == "nan")
        return 'd';
    if (literal.size() == 1 && !std::isdigit(literal[0]))
        return 'c';
    if (literal.find('f') != std::string::npos)
        return 'f';
    if (literal.find('.') != std::string::npos)
        return 'd';
    return  'i';
}

int ScalarConverter::toInt(std::string literal)
{
    return std::atoi(literal.c_str());
}

void ScalarConverter::fromInt(int _int, char &_char, float &_float, double &_double)
{
    _char = static_cast<char>(_int);
    _float = static_cast<float>(_int);
    _double = static_cast<double>(_int);
}

void ScalarConverter::displayTypes(int _int, char _char, float _float, double _double)
{
    std::cout << "Char: " << _char << std::endl;
    std::cout << "Int: " << _int << std::endl;
    std::cout << "Float: " << _float << std::endl;
    std::cout << "Double: " << _double << std::endl;
}

