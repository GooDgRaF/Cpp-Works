//
// Created by Антон on 17.05.2021.
//

#ifndef STRING_QSORT_STRINGSHOLDER_H
#define STRING_QSORT_STRINGSHOLDER_H

#include <vector>
#include <string>

struct Strings_holder
{
    std::vector<std::string> strings_to_sort{};
    int k{};
    
    void get_size();
    
    void get_strings();
    
    void show_sorted();
    
    void qSort(std::vector<std::string> &v,
               std::vector<std::string>::iterator begin,
               std::vector<std::string>::iterator end);
    
};


#endif //STRING_QSORT_STRINGSHOLDER_H
