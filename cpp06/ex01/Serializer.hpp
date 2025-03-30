#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h>
#include <iostream>

struct Data
{
	int x;
	char c;
	std::string str;
};

class Serializer
{
private:
	Serializer();
	Serializer(const Serializer& copy);
	Serializer& operator=(const Serializer& other);
	~Serializer();

public:

	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
	
};


#endif