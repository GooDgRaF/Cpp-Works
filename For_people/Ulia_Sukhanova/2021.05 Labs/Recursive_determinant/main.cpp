#include <iostream>
#include "Read_data.h"
#include "Test.h"
#include "Menu.h"
#include "Recursive_determinant.h"
#include "Solver.h"

using namespace Menu;

int main()
    {
        matrix_double matrix, mRedheffer;
        SLEquation sleq;
        
        read_XML(matrix, mRedheffer, sleq);
        while (true)
        {
            switch (ask_next_action())
            {
                case REREAD_XML:
                    
                    read_XML(matrix, mRedheffer, sleq);
                    break;
                
                case CALC_DET:
                    
                    print_det_value(det_by_first_row(matrix));
                    break;
                case CALC_REDHEFFER:
                    
                    print_Redheffer_det_value(det_by_first_row(mRedheffer), mRedheffer.size());
                    
                    break;
                case CALC_SLE:
                    
                    print_sle_solution(solve_sle(sleq));
                    
                    break;
                case TEST:
                    
                    print_test_start();
                    test_det_by_first_row();
                    test_solver();
                    break;
                
                case EXIT:print_goodbye();
                    return 0;
                default:print_incorrect_input();
                    break;
            }
        }
        
    }


