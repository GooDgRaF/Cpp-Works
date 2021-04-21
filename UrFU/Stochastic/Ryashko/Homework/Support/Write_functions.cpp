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

template<typename T>
void write_vector_in_file(const std::vector<T> &v, const std::string &path, const bool clear_up)
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
        if (!(v.empty()))
        {
            for (auto item : v)
            {
                out << std::setprecision(9) << item << " ";
            }
            out << '\n';
        }
        out.close();
    }


void write_number_in_file(const double n, const std::string &path)
    {
        std::ofstream out(path);
        if (out.fail())
        {
            std::cerr << "Can't reach or open file from this path: " << path << std::endl;
            exit(-1);
        }
        out << n;
        out.close();
    }
