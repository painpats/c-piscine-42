#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
    try
    {
    	if (ac != 2)
        	throw BadArgumentsException();
        openFile(av[1]);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    
    return 0;
}
