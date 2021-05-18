//
// Created by Антон on 18.05.2021.
//

#ifndef STRING_QSORT_QSORT_H
#define STRING_QSORT_QSORT_H

#include <vector>
#include <string>

using v_str = std::vector<std::string>;

void qSort_main(v_str &v,
                v_str::iterator begin, v_str::iterator end,
                size_t &number_of_operations);
    
size_t qSort(v_str &v);
    
    
    void show_v_str(v_str &v);
#endif //STRING_QSORT_QSORT_H
