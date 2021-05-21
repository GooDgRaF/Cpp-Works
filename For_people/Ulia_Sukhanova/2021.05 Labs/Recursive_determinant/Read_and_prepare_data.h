//
// Created by Антон on 21.05.2021.
//

#ifndef RECURSIVE_DETERMINANT_READ_AND_PREPARE_DATA_H
#define RECURSIVE_DETERMINANT_READ_AND_PREPARE_DATA_H

#include <vector>
#include <string>


using matrix_double = std::vector<std::vector<double>>;


void read_XML();


matrix_double create_mRedheffer(size_t size);

matrix_double create_matrix_from_string(size_t row_size, size_t column_size, const std::string &str);

void show_matrix(matrix_double &m);

#endif //RECURSIVE_DETERMINANT_READ_AND_PREPARE_DATA_H
