#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
    std::cout << "ScalarConverter constructor called.\n";
}
ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
    std::cout << "ScalarConverter copy constructor called.\n";
    // nothing to copy
}
ScalarConverter::~ScalarConverter()
{
    std::cout << "ScalarConverter detructor called.\n";
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    std::cout << "ScalarConverter assignment operator called.\n";
    // nothing to assign
    return *this;
}

void ScalarConverter::convert(std::string literal)
{
    myChar _char;
    myInt _int;
    myFloat _float;
    myDouble _double;
    char _type;

    _type = getLiteralType(literal);
    switch (_type)
    {
    case 'c':
        toChar(_char, literal);
        fromChar(_char, _int, _float, _double);
        break;
    case 'f':
        toFloat(_float, literal);
        fromFloat(_float, _char, _int, _double);
        break;
    case 'd':
        toDouble(_double, literal);
        fromDouble(_double, _char, _int, _float);
        break;
    case 'i':
        toInt(_int ,literal);
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
// Int
void ScalarConverter::toInt(myInt &_int, std::string literal)
{
    _int.value = std::atoi(literal.c_str());
}

void ScalarConverter::fromInt(myInt &_int, myChar &_char, myFloat &_float, myDouble &_double)
{
    if (_int.value >= -128 && _int.value <= 127)
    {
        if (std::isprint(_int.value))
            _char.value = static_cast<char>(_int.value);
        else
            _char.msg = "Non displayable";
    }
    else
        _char.msg = "impossible";
    _float.value = static_cast<float>(_int.value);
    _double.value = static_cast<double>(_int.value);
}
// Char
void ScalarConverter::toChar(myChar &_char, std::string literal)
{
    _char.value = literal[0];
}

void ScalarConverter::fromChar(myChar &_char, myInt &_int, myFloat &_float, myDouble &_double)
{
    _int.value = static_cast<int>(_char.value);
    _float.value = static_cast<float>(_char.value);
    _double.value = static_cast<double>(_char.value);
}
// Float
void ScalarConverter::toFloat(myFloat &_float ,std::string literal)
{
    if (literal == "-inff")
        _float.msg = "-inff";
    else if (literal == "+inff")
        _float.msg = "+inff";
    else if (literal == "nanf")
        _float.msg = "nanf";
    _float.value = std::atof(literal.c_str());
}

void ScalarConverter::fromFloat(myFloat &_float, myChar &_char, myInt &_int, myDouble &_double)
{
    // Char
    if (_float.msg != "")
        _char.msg = "impossible";
    else if (_float.value >= -128 && _float.value <= 127)
    {
        if (std::isprint(_float.value))
            _char.value = static_cast<char>(_float.value);
        else
            _char.msg = "Non displayable";
    }
    else
        _char.msg = "impossible";
    
    // Int
    if (_float.msg != "")
        _int.msg = "impossible";
    else if (_float.value >= std::numeric_limits<int>::min() 
            && _float.value <= std::numeric_limits<int>::max())
        _int.value = static_cast<int>(_float.value);
    else
        _int.msg = "impossible";

    // Double
    if (_float.msg != "")
        _double.msg = _float.msg.substr(0, _float.msg.length() - 1);
    else
        _double.value = static_cast<double>(_float.value);
}
// Double
void ScalarConverter::toDouble(myDouble &_double ,std::string literal)
{
    if (literal == "-inf")
        _double.msg = "-inf";
    else if (literal == "+inf")
        _double.msg = "+inf";
    else if (literal == "nan")
        _double.msg = "nan";
    _double.value = std::atof(literal.c_str());
}

void ScalarConverter::fromDouble(myDouble &_double, myChar &_char, myInt &_int, myFloat &_float)
{
    // Char
    if (_double.msg != "")
        _char.msg = "impossible";
    else if (_double.value >= -128 && _double.value <= 127)
    {
        if (std::isprint(_double.value))
            _char.value = static_cast<char>(_double.value);
        else
            _char.msg = "Non displayable";
    }
    else
        _char.msg = "impossible";
    
    // Int
    if (_double.msg != "")
        _int.msg = "impossible";
    else if (_double.value >= std::numeric_limits<int>::min() 
            && _double.value <= std::numeric_limits<int>::max())
        _int.value = static_cast<int>(_double.value);
    else
        _int.msg = "impossible";

    // Float
    if (_double.msg != "")
        _float.msg = _double.msg + "f";
    else if (_double.value >= -std::numeric_limits<float>::max() - 1
            && _double.value <= std::numeric_limits<float>::max())
        _float.value = static_cast<float>(_double.value);
    else
        _float.msg = "impossible";
}

void ScalarConverter::displayTypes(myInt &_int, myChar &_char, myFloat &_float, myDouble &_double)
{
    std::cout << "Char: ";
    if (_char.msg != "")
        std::cout << _char.msg << std::endl;
    else
        std::cout << "'" <<_char.value << "'" << std::endl;
    std::cout << "Int: ";
    if (_int.msg != "")
        std::cout << _int.msg << std::endl;
    else
        std::cout << _int.value << std::endl;
    std::cout << "Float: ";
    if (_float.msg != "")
        std::cout << _float.msg << std::endl;
    else
    {
        std::cout << _float.value;
        if (std::fmod(_float.value, 1.0) == 0.0)
            std::cout << ".0";
        std::cout << "f" << std::endl;
    }
    std::cout << "Double: ";
    if (_double.msg != "")
        std::cout << _double.msg << std::endl;
    else
    {
        std::cout << _double.value;
        if (std::fmod(_double.value, 1.0) == 0.0)
            std::cout << ".0";
        std::cout << std::endl;
    }
}

