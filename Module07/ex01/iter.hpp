#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>
# include <cctype>

template <typename Array>
void    iter(Array *addressAray, int lengthArray, void (*f)(const Array&)) {
    if (addressAray == NULL || f == NULL) {
        std::cout << "Invalid input";
        return ;
    }
    if (lengthArray <= 0) {
        std::cout << "Invalid length array";
        return ;
    }
    for (int i=0 ; i<lengthArray ; i++) 
        f(addressAray[i]);
}

template <typename Array>
void    print(const Array& input) {
    std::cout << input;
}

template <typename Array>
void    flower(const Array& input) {
    std:: cout << input << " flower.s, ";
}

#endif
