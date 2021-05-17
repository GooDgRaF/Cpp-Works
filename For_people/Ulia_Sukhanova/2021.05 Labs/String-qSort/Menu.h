//
// Created by Антон on 17.05.2021.
//

#ifndef STRING_QSORT_MENU_H
#define STRING_QSORT_MENU_H


struct Menu
{
    char user_choice{-1};
    
    enum menu_interface
    {
        USER_STRINGS = 1,
        XML_TEST = 2,
        EXIT = 0
    };
    
    void ask_next_action();
    
    void while_incorrect();
    
    static void print_enter_strings();
    static void print_enter_number_of_rows();
    
    static void print_goodbye();
    
    static void print_incorrect_input();
};

#endif //STRING_QSORT_MENU_H
