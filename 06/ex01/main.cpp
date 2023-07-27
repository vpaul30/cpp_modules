#include "Serializer.hpp"

int main()
{
	Data *myData = new Data();

	myData->name = "John";
	myData->age = 35;

	std::cout << "===myData===\n";
	std::cout << "name: " << myData->name << std::endl;
	std::cout << "age: " << myData->age << std::endl;

	std::cout << std::endl;

	uintptr_t serialize_res = Serializer::serialize(myData);
	std::cout << serialize_res << " - serialize_res" << std::endl; 

	std::cout << std::endl;

	Data *deserialize_res = Serializer::deserialize(serialize_res);
	std::cout << myData << " - myData" << std::endl;
	std::cout << deserialize_res << " - deserialize_res" << std::endl;

	std::cout << "\n===myData===\n";
	std::cout << "name: " << myData->name << std::endl;
	std::cout << "age: " << myData->age << std::endl;

	std::cout << "\n===deserialize_res===\n";
	std::cout << "name: " << deserialize_res->name << std::endl;
	std::cout << "age: " << deserialize_res->age << std::endl;

	delete myData;
	return 0;
}