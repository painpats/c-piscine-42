#include "RPN.hpp"

int main(int ac, char **av) {

    try
    {
        if (ac != 2 || av[1][0] == '\0')
            throw ExecErrorException();
        rpn(av);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    
    return 0;
}
