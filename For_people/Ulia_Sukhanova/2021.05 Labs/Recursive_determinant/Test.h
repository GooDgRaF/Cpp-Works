//
// Created by Антон on 21.05.2021.
//

#ifndef RECURSIVE_DETERMINANT_TEST_H
#define RECURSIVE_DETERMINANT_TEST_H

#include <vector>
#include "cmath"


void test_det_by_first_row();

void test_solver();

namespace test
{
    bool operator==(const std::vector<double> &v1,
                 const std::vector<double> &v2);
}


#endif //RECURSIVE_DETERMINANT_TEST_H
