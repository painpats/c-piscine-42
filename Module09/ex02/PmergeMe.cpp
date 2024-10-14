#include "PmergeMe.hpp"

size_t  binarySearchVector(std::vector<unsigned int> sorted, unsigned int target, unsigned int right);
int findMinInPartnerVector(std::vector<partner_t> &toFind, unsigned int target);
int findMaxInAlmostVector(std::vector<unsigned int> &toFind, unsigned int target);

size_t  binarySearchDeque(std::deque<unsigned int> sorted, unsigned int target, unsigned int right);
int findMinInPartnerDeque(std::deque<partner_t> &toFind, unsigned int target);
int findMaxInAlmostDeque(std::deque<unsigned int> &toFind, unsigned int target);

unsigned int    jacobsthal(unsigned int iter);

/////////////////////////////////////////////////////////////////////
//-------------------------- VECTOR -------------------------------//
/////////////////////////////////////////////////////////////////////
std::vector<unsigned int> fordJohnsonVector(std::vector<unsigned int> input) {
    partner_t   tmp;
    std::vector<partner_t>  pairs;
    std::vector<unsigned int> inputMax;
    std::vector<unsigned int> almostSorted;
    std::vector<unsigned int> sorted;

    //exit condition
    if (input.size() == 1)
        return input;

    //find min and max in pairs
    for (size_t i=0 ; i<input.size()-1 ; i+=2) {
        if (input[i] < input[i+1]) {
            tmp.min = input[i];
            tmp.max = input[i+1];
        }
        else {
            tmp.min = input[i+1];
            tmp.max = input[i];
        }
        pairs.push_back(tmp);
        inputMax.push_back(tmp.max);
    }

    almostSorted = fordJohnsonVector(inputMax);
    sorted = almostSorted;

    //first insertion : find the min of the max
    unsigned int   toInsert;
    for (size_t i=0 ; i<input.size() ; i++) {

        if (almostSorted[0] == pairs[i].max) {

            toInsert = pairs[i].min;
            pairs.erase(pairs.begin() + i);
            break;
        }
    }
    sorted.insert(sorted.begin(), toInsert);

    unsigned int    posMin;
    unsigned int    posMax;
    int count = 1;
    int previousInsertion = 0;
    int sizeToInsert;
    int backup;
    int element;
    int posToInsert;
    while (pairs.size() > 0) {

        sizeToInsert = jacobsthal(count);
        //if jacobsthal ask more that what offers the input (refining the right terminal)
        if ((int)almostSorted.size() < sizeToInsert + previousInsertion + 1)
            sizeToInsert = almostSorted.size() - previousInsertion - 1;

        backup = sizeToInsert;

        while (sizeToInsert) {
            element = previousInsertion + sizeToInsert;
            posMin = findMinInPartnerVector(pairs, almostSorted[element]);
            posMax = findMaxInAlmostVector(sorted, almostSorted[element]);

            posToInsert = binarySearchVector(sorted, pairs[posMin].min, posMax);

            sorted.insert(sorted.begin() + posToInsert, pairs[posMin].min);
            pairs.erase(pairs.begin() + posMin);

            sizeToInsert--;
        }

        previousInsertion += backup;
        count++;
    }

    //odd insertion remaining
    if (input.size()%2 != 0) {
        unsigned int    lastOne;
        lastOne = binarySearchVector(sorted, input[input.size() - 1], sorted.size()- 1);
        sorted.insert(sorted.begin() + lastOne, input[input.size() - 1]);
    }

    return sorted;
}

int findMinInPartnerVector(std::vector<partner_t> &toFind, unsigned int target) {
    for (size_t i=0 ; i<toFind.size() ; i++) {
        if (target == toFind[i].max)
            return i;
    }
    throw std::runtime_error("Unreachable");
}
int findMaxInAlmostVector(std::vector<unsigned int> &toFind, unsigned int target) {
    for (size_t i=0 ; i<toFind.size() ; i++) {
        if (target == toFind[i])
            return i;
    }
    throw std::runtime_error("Unreachable");
}
size_t  binarySearchVector(std::vector<unsigned int> sorted, unsigned int target, unsigned int right) {
    size_t  middle;
    unsigned int    left = 0;

    while (left <= right) {
        middle = (left + right) / 2;
        if (sorted[middle] < target)
            left = middle + 1;
        else if (sorted[middle] > target && middle > 0)
            right = middle - 1;
        else
            return middle;
    }
    return left;
}


/////////////////////////////////////////////////////////////////////
//--------------------------- DEQUE -------------------------------//
/////////////////////////////////////////////////////////////////////
std::deque<unsigned int> fordJohnsonDeque(std::deque<unsigned int> input) {
    partner_t   tmp;
    std::deque<partner_t>  pairs;
    std::deque<unsigned int> inputMax;
    std::deque<unsigned int> almostSorted;
    std::deque<unsigned int> sorted;

    //exit condition
    if (input.size() == 1)
        return input;

    //find min and max in pairs
    for (size_t i=0 ; i<input.size()-1 ; i+=2) {
        if (input[i] < input[i+1]) {
            tmp.min = input[i];
            tmp.max = input[i+1];
        }
        else {
            tmp.min = input[i+1];
            tmp.max = input[i];
        }
        pairs.push_back(tmp);
        inputMax.push_back(tmp.max);
    }

    almostSorted = fordJohnsonDeque(inputMax);
    sorted = almostSorted;

    //first insertion : find the min of the max
    unsigned int   toInsert;
    for (size_t i=0 ; i<input.size() ; i++) {

        if (almostSorted[0] == pairs[i].max) {

            toInsert = pairs[i].min;
            pairs.erase(pairs.begin() + i);
            break;
        }
    }
    sorted.insert(sorted.begin(), toInsert);

    unsigned int    posMin;
    unsigned int    posMax;
    int count = 1;
    int previousInsertion = 0;
    int sizeToInsert;
    int backup;
    int element;
    int posToInsert;
    while (pairs.size() > 0) {

        sizeToInsert = jacobsthal(count);
        //if jacobsthal ask more that what offers the input (refining the right terminal)
        if ((int)almostSorted.size() < sizeToInsert + previousInsertion + 1)
            sizeToInsert = almostSorted.size() - previousInsertion - 1;

        backup = sizeToInsert;

        while (sizeToInsert) {
            element = previousInsertion + sizeToInsert;
            posMin = findMinInPartnerDeque(pairs, almostSorted[element]);
            posMax = findMaxInAlmostDeque(sorted, almostSorted[element]);

            posToInsert = binarySearchDeque(sorted, pairs[posMin].min, posMax);

            sorted.insert(sorted.begin() + posToInsert, pairs[posMin].min);
            pairs.erase(pairs.begin() + posMin);

            sizeToInsert--;
        }

        previousInsertion += backup;
        count++;
    }

    //odd insertion remaining
    if (input.size()%2 != 0) {
        unsigned int    lastOne;
        lastOne = binarySearchDeque(sorted, input[input.size() - 1], sorted.size()- 1);
        sorted.insert(sorted.begin() + lastOne, input[input.size() - 1]);
    }

    return sorted;
}

int findMinInPartnerDeque(std::deque<partner_t> &toFind, unsigned int target) {
    for (size_t i=0 ; i<toFind.size() ; i++) {
        if (target == toFind[i].max)
            return i;
    }
    throw std::runtime_error("Unreachable");
}
int findMaxInAlmostDeque(std::deque<unsigned int> &toFind, unsigned int target) {
    for (size_t i=0 ; i<toFind.size() ; i++) {
        if (target == toFind[i])
            return i;
    }
    throw std::runtime_error("Unreachable");
}
size_t  binarySearchDeque(std::deque<unsigned int> sorted, unsigned int target, unsigned int right) {
    size_t  middle;
    unsigned int    left = 0;

    while (left <= right) {
        middle = (left + right) / 2;
        if (sorted[middle] < target)
            left = middle + 1;
        else if (sorted[middle] > target && middle > 0)
            right = middle - 1;
        else
            return middle;
    }
    return left;
}


/////////////////////////////////////////////////////////////////////
//--------------------------- TOOLS -------------------------------//
/////////////////////////////////////////////////////////////////////
unsigned int    jacobsthal(unsigned int iter) {
    if (iter == 0)
        return 0;
    if (iter == 1)
        return 2;
    return jacobsthal(iter-1) + 2 * jacobsthal(iter-2);
}
