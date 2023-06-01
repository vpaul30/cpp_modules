#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <iostream>
#include <string>
#include <limits>

class ScalarConverter
{
public:
    ScalarConverter();
    ScalarConverter(std::string literal);
    ScalarConverter(ScalarConverter &other);
    ~ScalarConverter();

    ScalarConverter &operator=(ScalarConverter &other);

    void convert();

private:
    std::string _literal;
    char _char;
    int _int;
    float _float;
    double _double;
    int _type;

    char getChar() const;
    int getInt() const;
    float getFloat() const;
    double getDouble() const;

    char getLiteralType() const;
    bool checkChar() const;
    bool checkInt() const;
    bool checkFloat() const;
    bool checkDouble() const;

};

#endif