#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <string>
# include <stdint.h>

struct Data {
	int	index;
};

class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer& copy);
		~Serializer();
		Serializer& operator=(const Serializer& copy);
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif