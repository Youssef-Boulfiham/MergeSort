#ifndef MERGESORT_MERGESORT_H
#define MERGESORT_MERGESORT_H

#include <iostream>
#include <sstream>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <vector>


using std::string, std::cout, std::endl, std::vector;

class MergeSort {
public:
    MergeSort(string taskName);
    std::vector<int> run(vector<int> xs);

};


#endif //MERGESORT_MERGESORT_H
