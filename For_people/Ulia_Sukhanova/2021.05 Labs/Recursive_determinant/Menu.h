//
// Created by Антон on 24.05.2021.
//

#ifndef RECURSIVE_DETERMINANT_MENU_H
#define RECURSIVE_DETERMINANT_MENU_H
#include <cstddef>
#include "Read_data.h"

namespace Menu
{
    enum menu_interface
    {
        CALC_DET = 1,
        CALC_REDHEFFER = 2,
        CALC_SLE = 3,
        TEST = 4,
        REREAD_XML = 7,
        EXIT = 0
    };
    
    size_t ask_next_action();
    
    void print_incorrect_input();
    
    void print_det_value(const double d);
    
    void print_sle_solution(const std::vector<double> &solution);
    
    void print_Redheffer_det_value(const double d, const size_t det_size);
    
    void print_test_start();
    
    void print_matrix(const matrix_double &mat);
    
    void print_goodbye();
    
}
#endif //RECURSIVE_DETERMINANT_MENU_H
