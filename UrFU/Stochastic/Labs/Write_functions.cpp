//
// Created by Антон on 21.03.2021.
//

#include "Calc Expectation, Variance and Covariance.h"
#include "algorithm"
#include <fstream>
#include <iostream>
#include "Write_functions.h"


void write_two_vectors(const std::string &path, const std::vector<double> &data_set, const std::vector<double> &N_set)
    {
        write_vector_in_file(N_set, path, true);
        write_vector_in_file(data_set, path, false);
    }

void write_vector_in_file(const std::vector<double> &v, const std::string &path, const bool clear_up)
    {
        if (clear_up)
        {
            std::ofstream out(path);
            out.close();
        }
        std::ofstream out(path, std::ios::app);
        if (out.fail())
        {
            std::cerr << "Can't reach or open file from this path: " << path << std::endl;
            exit(-1);
        }
        for (auto item : v)
        {
            out << item << " ";
        }
        out << '\n';
        out.close();
    }