#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <limits>

struct myChar
{
    char value;
    std::string msg;
};

struct myInt
{
    int value;
    std::string msg;
};

struct myFloat
{
    float value;
    std::string msg;
};

struct myDouble
{
    double value;
    std::string msg;
};

class ScalarConverter
{
public:
    static void convert(std::string literal);

private:
    // constructors destructors
    ScalarConverter();
    ScalarConverter(const ScalarConverter &other);
    ~ScalarConverter();

    ScalarConverter &operator=(const ScalarConverter &other);
    // ====
    static char getLiteralType(std::string literal);
    static bool checkChar(std::string literal);
    static bool checkInt(std::string literal);
    static bool checkFloat(std::string literal);
    static bool checkDouble(std::string literal);
    // Int
    static void toInt(myInt &_int ,std::string literal);
    static void fromInt(myInt &_int, myChar &_char, myFloat &_float, myDouble &_double);
    // Char
    static void toChar(myChar &_char ,std::string literal);
    static void fromChar(myChar &_char, myInt &_int, myFloat &_float, myDouble &_double);
    // Float
    static void toFloat(myFloat &_float ,std::string literal);
    static void fromFloat(myFloat &_float, myChar &_char, myInt &_int, myDouble &_double);
    // Double
    static void toDouble(myDouble &_double ,std::string literal);
    static void fromDouble(myDouble &_double, myChar &_char, myInt &_int, myFloat &_float);

    static void displayTypes(myInt &_int, myChar &_char, myFloat &_float, myDouble &_double);
};

#endif