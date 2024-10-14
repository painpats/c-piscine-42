#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void Harl::debug(void)
{
    std::cout << "[DEBUG]" << std::endl;
    std::cout << "Ogres are like onions." << std::endl << std::endl;
}

void Harl::info(void)
{
    std::cout << "[INFO]" << std::endl;
    std::cout << "They stink ? They make you cry ? You leave them in the sun, they get all brown, start sproutin' little white hairs." << std::endl << std::endl;
}

void Harl::warning(void)
{
    std::cout << "[WARNING]" << std::endl;
    std::cout << "No! Layers! Onions have layers. Ogres have layers! Onions have layers. You get it? We both have layers. Ogres are like onions! End of story. Bye-bye. See ya later." << std::endl << std::endl;
}

void Harl::error(void)
{
    std::cout << "[ERROR]" << std::endl;
    std::cout << "You know, not everybody likes onions. Cake! Everybody loves cakes! Cakes have layers." << std::endl;
}

void Harl::complain(std::string level)
{
    std::string statement[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    size_t      i = 0;
    
    while (statement[i] != level && i < 4)
        i++;
    switch (i)
    {
        case 0:
            debug();
            std::cout << std::endl;
        case 1:
            info();
            std::cout << std::endl;
        case 2:
            warning();
            std::cout << std::endl;
        case 3:
            error();
            break ;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
}