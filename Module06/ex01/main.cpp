#include "Serializer.hpp"

int main()
{
    Data        dataObj;
    Data        *tmp;
    uintptr_t   serialized = 0;

    dataObj.index = 42;

    std::cout << "BEFORE SERIALIZATION" << std::endl;
    std::cout << "Original pointer's Adress :" << &dataObj << std::endl;
	std::cout << "Original pointer's Index  :" << dataObj.index << std::endl;

	serialized = Serializer::serialize(&dataObj);
	tmp = Serializer::deserialize(serialized);

    std::cout << "\nAFTER SERIALIZATION" << std::endl;
	std::cout << "Return value's Adress     :" << &dataObj << std::endl;
	std::cout << "Return value's Index      :" << tmp->index << std::endl;
    return 0;
}