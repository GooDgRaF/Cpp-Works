//
// Created by Антон on 21.05.2021.
//

#ifndef RECURSIVE_DETERMINANT_READ_DATA_H
#define RECURSIVE_DETERMINANT_READ_DATA_H

#include <vector>
#include <string>


using matrix_double = std::vector<std::vector<double>>;

const std::vector<double> value_det_Redheffer {1, 0, -1, -1, -2, -1, -2, -2, -2, -1, -2, -2, -3, -2, -1};

struct SLEquation
{
    matrix_double coefficientMatrix{{0}};
    std::vector<double> right_column{0};
};


void read_XML(matrix_double &mat, matrix_double &matRedheffer, SLEquation &sleq);


matrix_double create_mRedheffer(size_t size);

matrix_double create_matrix_from_string(size_t row_size, size_t column_size, const std::string &str);

#endif //RECURSIVE_DETERMINANT_READ_DATA_H
