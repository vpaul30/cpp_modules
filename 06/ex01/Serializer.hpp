#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <string>
#include <cstdint>

struct Data
{
	std::string name;
	int age;
};

class Serializer
{
public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);

private:
	Serializer();
	Serializer(const Serializer &other);
	~Serializer();

	Serializer &operator=(const Serializer &other);

};

#endif