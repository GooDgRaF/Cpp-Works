//
// Created by Антон on 21.03.2021.
//

#ifndef LABA1_WRITE_FUNCTIONS_H
#define LABA1_WRITE_FUNCTIONS_H

#include <fstream>
#include <iomanip>
#include "iostream"

void write_two_vectors(const std::string &path, const std::vector<double> &data_set, const std::vector<int> &N_set);

template<typename T>
void write_vector_in_file(const std::vector<T> &v, const std::string &path, const bool clear_up = true)
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
                out << std::setprecision(5) << item << " ";
            }
            out << '\n';
        }
        out.close();
    }

template<typename T>
void write_number_in_file(const T n, const std::string &path)
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

template<typename T>
std::string to_str(T const &value)
    {
        std::stringstream sstr;
        sstr << value;
        return sstr.str();
    }

#endif //LABA1_WRITE_FUNCTIONS_H
