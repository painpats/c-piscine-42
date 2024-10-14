#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <string>
# include <algorithm>
# include <exception>
# include <vector>
# include <list>
# include <map>

class OccurenceNotFoundException : public std::exception {
    public:
        char const *what() const throw() {
            return "No occurence was found in the container of int.";
        }
};

template <typename T>
void    easyfind(T& containerOfInt, int occurrence) {
    typename T::iterator    i;

    i = std::find(containerOfInt.begin(), containerOfInt.end(), occurrence);
    if ( i == containerOfInt.end())
        throw OccurenceNotFoundException();
    std::cout << "An occurence was found" << std::endl;
}

#endif