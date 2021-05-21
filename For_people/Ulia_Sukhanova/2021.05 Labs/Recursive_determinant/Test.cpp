//
// Created by Антон on 21.05.2021.
//

#include <cassert>
#include "Test.h"
#include "Recursive_determinant.h"
#include <iostream>

void test_det_by_first_row()
    {
        matrix_double
                E_1 = {{1}},
                
                E_2 = {{1, 0},
                       {0, 1}},
                
                Triangle_up_2 = {{-2, 3},
                                 {0,  1}},
                
                Triangle_down_3 = {{3, 0,    0},
                                   {1, -5.5, 0},
                                   {2, 3,    9.99}},
                
                Qadr = {{5.135,  3.226,  10.071, 5.273},
                        {13.466, 11.332, 11.229, 8.917},
                        {4.367,  1.520,  7.893,  5.197},
                        {7.847,  14.606, 2.217,  3.982}};
        
        assert(det_by_first_row(E_1) == 1);
        assert(det_by_first_row(E_2) == 1);
        assert(det_by_first_row(Triangle_up_2) == -2);
        assert(abs(det_by_first_row(Triangle_down_3) - 3*(-5.5)*9.99) < 0.001);
        assert(abs(det_by_first_row(Qadr) + 540.314940) < 0.001);
        
        std::cout << "Tests successfully completed!" << std::endl;
        
        
    }
