#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <iostream>
#include <string>
#include <limits>

class ScalarConverter
{
public:
    static void convert(std::string literal);

private:
    // constructors destructors

    // ====
    static char getLiteralType(std::string literal);
    static bool checkChar(std::string literal);
    static bool checkInt(std::string literal);
    static bool checkFloat(std::string literal);
    static bool checkDouble(std::string literal);

    static int toInt(std::string literal);
    static void fromInt(int _int, char &_char, float &_float, double &_double);
    
    static void displayTypes(int _int, char _char, float _float, double _double);
};

#endif