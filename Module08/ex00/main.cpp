#include "easyfind.hpp"

int main()
{

    std::cout << "TEST WITH LIST INT" << std::endl;
    std::list<int>  listInt;
    try {
    ::easyfind(listInt, -2147483648);
    }
    catch(const std::exception& e) {
       std::cout << e.what() << '\n';
    }
    listInt.push_back(-2147483648);
    listInt.push_back(-3);
    listInt.push_back(2147);
    listInt.push_back(42);
    try
    {
        ::easyfind(listInt, -2147483648);
        ::easyfind(listInt, 3);
    }
    catch(const std::exception& e) {
        std::cout << e.what() << '\n';
    }
    
    std::cout << "\nTEST WITH VECTOR INT" << std::endl;
    std::vector<int>   listVect;
    listVect.push_back(500);
    listVect.push_back(21);
    listVect.push_back(0);
    listVect.push_back(2147483647);
    try
    {
        ::easyfind(listVect, 21);
        ::easyfind(listVect, 42424);
    }
    catch(const std::exception& e) {
        std::cout << e.what() << '\n';
    }

    return 0;
}
