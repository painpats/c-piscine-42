#include "iter.hpp"

int main()
{
    int         firstArray[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    char        secondArray[6] = {'a', 'e', 'i', 'o', 'u', 'y'};
    std::string thirdArray[2] = {"Hello ", "word"};

    std::cout << ".-------.\n| TESTS |\n.-------." << std::endl;
    ::iter(firstArray, 5, &flower);
    std::cout << std::endl;
    ::iter(secondArray, 5, &print);
    std::cout << std::endl;
    ::iter(thirdArray, 2, &print);
    std::cout << std::endl;

    std::cout << ".-------.\n| ERROR |\n.-------." << std::endl;
    std::cout << "negative lenght array: ";
    ::iter(firstArray, -1, &print);
    std::cout << std::endl;
    std::cout << "lenght array null: ";
    ::iter(firstArray, 0, &flower);
    std::cout << std::endl;

    return 0;
}
