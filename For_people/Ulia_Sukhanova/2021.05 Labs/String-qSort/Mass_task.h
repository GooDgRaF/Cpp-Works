//
// Created by Антон on 17.05.2021.
//

#ifndef STRING_QSORT_MASS_TASK_H
#define STRING_QSORT_MASS_TASK_H

#include <string>
#include <vector>
#include "QSort.h"

struct Arithmetic_progression
{
    std::string title;
    int minElem{0};
    int maxElem{0};
    int startLen{0};
    int maxLen{0};
    int repeat{0};
    int diff{0};
};

struct Experiment
{
    std::string name;
    Arithmetic_progression arith;
    
    std::vector<v_str> a_mt;//mass task
    std::vector<std::pair<size_t, size_t>> v__strLen_numOp;
    
    void fill_mt();
    
    void sort_mt();
    
    void write();
};

Experiment read_from_XML();

void do_mass_task();

v_str generate_v_str(size_t row_size, size_t minLen, size_t maxLen);

std::string generate_str(size_t minLen, size_t maxLen);

size_t rand_len(size_t minLen, size_t maxLen);


#endif //STRING_QSORT_MASS_TASK_H
