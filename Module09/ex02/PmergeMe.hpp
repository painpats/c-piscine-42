#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <deque>
#include <vector>
#include <iostream>
#include <iomanip>
#include <exception>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <cstring>

typedef struct partner_s {
    unsigned int max;
    unsigned int min;
} partner_t ;

std::vector<unsigned int> fordJohnsonVector(std::vector<unsigned int> input);
std::deque<unsigned int> fordJohnsonDeque(std::deque<unsigned int> input);

#endif