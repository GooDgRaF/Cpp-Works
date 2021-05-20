//
// Created by Антон on 17.05.2021.
//

#ifndef STRING_QSORT_MENU_H
#define STRING_QSORT_MENU_H

#include <vector>
#include <string>

using v_str = std::vector<std::string>;

namespace Menu
{
    enum menu_interface
    {
        USER_STRINGS = 1,
        XML_TEST = 2,
        TEST = 3,
        EXIT = 0
    };
    
    size_t ask_next_action();
    
    size_t ask_row_size();
    
    void ask_strings(v_str &v, size_t row_size);
    
    void print_enter_strings();
    
    void print_enter_number_of_rows();
    
    void print_goodbye();
    
    void print_incorrect_input();
    
    void print_test_start();
    
    void print_XML_start();
    
    void print_sort_str();
    
    void show_v_str(v_str &v);
    
}
#endif //STRING_QSORT_MENU_H
