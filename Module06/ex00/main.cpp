#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
    if (ac != 2) {
        std::cout << "./convert <char or int or float or double>" << std::endl;
        return -1;
    }
    ScalarConverter::convert(av[1]);
    return 0;
}
