#include "Harl.hpp"

int main(int ac, char **av)
{
    Harl    shrek;

    if (ac == 2)
        shrek.complain(av[1]);
    else
        shrek.complain("void");
    return 0;
}
