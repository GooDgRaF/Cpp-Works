//
// Created by Антон on 17.05.2021.
//

#ifndef STRING_QSORT_MENU_H
#define STRING_QSORT_MENU_H

#include <vector>
#include <string>
using v_str = std::vector<std::string>;

struct Menu
{
    char user_choice{-1};
    
    enum menu_interface
    {
        USER_STRINGS = 1,
        XML_TEST = 2,
        TEST = 3,
        EXIT = 0
    };
    
    void ask_next_action();
    
    static size_t ask_row_size();
    
    static void ask_strings(v_str &v, size_t row_size);
    
    void while_incorrect();
    
    static void print_enter_strings();
    
    static void print_enter_number_of_rows();
    
    static void print_goodbye();
    
    static void print_incorrect_input();
    
    static void print_test_start();
};

#endif //STRING_QSORT_MENU_H
