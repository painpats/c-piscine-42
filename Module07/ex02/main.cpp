#include "Array.hpp"

#define MAX_VAL 750

int main(int, char**)
{
    std::cout << ".------------.\n| INTRA MAIN |\n.------------." << std::endl;

    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;


    std::cout << "\n.---------.\n| MY TEST |\n.---------." << std::endl;
	
    Array<std::string> str(3);
	try
	{
		for (size_t i = 0; i < 3; i++)
			str[i] = "The end";
		std::cout << "Test with a string :" << std::endl;
		for (size_t i = 0; i < 3; i++)
			std::cout << str[i] << std::endl;
		std::cout << std::endl;
	}
	catch(const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	Array<int> integer(3);
	try
	{
		for (size_t i = 0; i < 3; i++)
			integer[i] = i * i;
		std::cout << "Test with an integer :" << std::endl;
		for (size_t i = 0; i < 3; i++)
			std::cout << integer[i] << std::endl;
		std::cout << std::endl;
	}
	catch(const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

    Array<std::string> stringg;
    try
    {
        std::cout << stringg[0] << std::endl;  
    }
	catch(const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
    return 0;
}
