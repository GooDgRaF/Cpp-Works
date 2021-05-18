//
// Created by Антон on 18.05.2021.
//

#include <iostream>
#include "QSort.h"

using namespace std;

void
qSort_main(v_str &v, v_str::iterator begin, v_str::iterator end, size_t &number_of_operations)
    {
        if (v.empty())
        {
            return;
        }
        
        auto first = begin;
        auto last = end;
        size_t sup_element = (begin->size() + end->size())/2;
        
        while (first <= last)
        {
            if (first->size() < sup_element)
            {
                while (first->size() < sup_element)
                {
                    number_of_operations++;
                    first++;
                }
            }
            else
            {
                number_of_operations++;
            }
            
            if (last->size() > sup_element)
            {
                while (last->size() > sup_element)
                {
                    number_of_operations++;
                    last--;
                }
            }
            else
            {
                number_of_operations++;
            }
            
            
            if (first <= last)
            {
                std::string tmp = *first;
                *first = *last;
                *last = tmp;
                first++;
                last--;
            }
        }
        if (begin < last) qSort_main(v, begin, last, number_of_operations);
        if (end > first) qSort_main(v, first, end, number_of_operations);
    }

void show_v_str(v_str &v)
    {
        cout << "Sorted strings: " << endl;
        for (const auto &el : v)
        {
            cout << el << endl;
        }
        cout << endl << endl;
    }

size_t qSort(v_str &v)
    {
        
        size_t num_of_op{0};
        qSort_main(v, v.begin(), v.end(), num_of_op);
        return num_of_op;
        
    }
