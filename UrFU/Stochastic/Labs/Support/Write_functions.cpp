//
// Created by Антон on 21.03.2021.
//

#include "Calc_Expectation_Variance_Covariance.h"
#include "algorithm"
#include <fstream>
#include <iostream>
#include <iomanip>
#include "Write_functions.h"


void write_two_vectors(const std::string &path, const std::vector<double> &data_set, const std::vector<int> &N_set)
    {
        write_vector_in_file(N_set, path, true);
        write_vector_in_file(data_set, path, false);
    }
