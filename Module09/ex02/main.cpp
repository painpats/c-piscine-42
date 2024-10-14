#include "PmergeMe.hpp"

bool    checkArg(char **av);
void    printNbrVector(std::vector<unsigned int> list, std::string message);

////////////////////////////////////////////////////////////////////////
//---------------------------- MAIN ----------------------------------//
////////////////////////////////////////////////////////////////////////
int main(int ac, char **av) {

    try
    {
        if (ac<2)
            throw std::invalid_argument("Error: ./PmergeMe [list of random numbers]");
        if (checkArg(av) == false)
            throw std::invalid_argument("Error: Invalid argument.s");

        //------------ Ford Johnson with vector container ------------//
        clock_t startVector;
        startVector = clock();

        std::vector<unsigned int>       inputVector;
        for (size_t i=1 ; av[i] ; i++) {
            int value;
            value = strtol(av[i], NULL, 10);
            inputVector.push_back(value);
        }
        printNbrVector(inputVector, "Before: ");

        std::vector<unsigned int>   listVectorSorted;
        listVectorSorted = fordJohnsonVector(inputVector);

        clock_t endVector;
        endVector = clock();

        double timeVector;
        timeVector = static_cast<double>(endVector - startVector) / CLOCKS_PER_SEC * 1000;

        printNbrVector(listVectorSorted, "After:  ");

        //------------ Ford Johnson with deque container -------------//
        clock_t startDeque;
        startDeque = clock();

        std::deque<unsigned int>       inputDeque;
        for (size_t i=1 ; av[i] ; i++) {
            int value;
            value = strtol(av[i], NULL, 10);
            inputDeque.push_back(value);
        }
        std::deque<unsigned int>   listDequeSorted;
        listDequeSorted = fordJohnsonDeque(inputDeque);

        clock_t endDeque;
        endDeque = clock();

        double timeDeque;
        timeDeque = static_cast<double>(endDeque - startDeque) / CLOCKS_PER_SEC * 1000;

        //-- Time dif between algo with vector and deque containers --//
        std::cout << std::fixed << std::setprecision(5);
        std::cout << "Time to process a range of " << ac-1 << " elements with std::vector : " << timeVector << " ms" << std::endl;
        std::cout << "Time to process a range of " << ac-1 << " elements with std::deque  : " << timeDeque << " ms" << std::endl;

    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    
    return 0;
}

////////////////////////////////////////////////////////////////////////
//---------------------------- TOOLS ---------------------------------//
////////////////////////////////////////////////////////////////////////

//function that check that the input number is a positive integer
bool    checkArg(char **av) {
    long int    value;
    char        *restValue;

    for (size_t i=1 ; av[i] ; i++) {
        if (!strlen(av[i]) || strlen(av[i]) > 11)
            return false;
        value = strtol(av[i], &restValue, 10);
        if (restValue[0] != '\0' || value < 0 || value > 2147483647)
            return false;
    }
    return true;
}

//function that print the 5 first number of the list
void    printNbrVector(std::vector<unsigned int> list, std::string message) {
    std::cout << message;
    int i = 0;
    while (list.size() && i<5) {
        std::cout << list[0] << " ";
        list.erase(list.begin());
        i++;
        if (i == 5 && list.size())
            std::cout << "[...]";
    }

    std::cout << std::endl;
}
