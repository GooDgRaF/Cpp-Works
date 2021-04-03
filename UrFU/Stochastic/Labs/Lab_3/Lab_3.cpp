//
// Created by Антон on 25.03.2021.
//

#include <sstream>
#include "Lab_3.h"
#include "../Support/Randomize.h"
#include "../Support/Write_functions.h"
#include "../Support/Calc_Expectation_Variance_Covariance.h"

double method12(std::mt19937 &engine);

double box_mueller(std::mt19937 &engine);

double normal(std::mt19937 &engine);

void
write_data(const std::vector<int> &N_set, const std::vector<double> &E_12_set, const std::vector<double> &E_BM_set,
           const std::vector<double> &E_normal_set, const std::vector<double> &V_12_set, const std::vector<double> &V_BM_set,
           const std::vector<double> &V_normal_set);


void do_lab_3(std::mt19937 &engine)
    {
//Выборки:
        std::vector<int> N_set = {};
        std::vector<double> E_12 = {}, E_BM = {}, E_normal = {}, V_12 = {}, V_BM = {}, V_normal = {};
        for (int N = 10e1; N < 10e7; N *= 10)
        {
            N_set.push_back(N);

            std::vector<double> sample12 = {}, sample_box_mueller = {}, sample_normal = {};
            sample12.reserve(N);
            sample_box_mueller.reserve(N);
            sample_normal.reserve(N);
            for (int i = 0; i < N; ++i)
            {
                sample12.push_back(method12(engine));
                sample_box_mueller.push_back(box_mueller(engine));
                sample_normal.push_back(normal(engine));
            }

            std::ostringstream N_str;
            N_str << N; // Превратили число в поток, из которого вытащим строку потом

            std::string path_out("../Lab_3/data/Source/sample12_" + N_str.str() + ".txt");
            write_vector_in_file(sample12, path_out);

            path_out = "../Lab_3/data/Source/sampleBM_" + N_str.str() + ".txt";
            write_vector_in_file(sample_box_mueller, path_out);

            path_out = "../Lab_3/data/Source/sampleNormal_" + N_str.str() + ".txt";
            write_vector_in_file(sample_normal, path_out);

//Матожидание и Дисперсия
            E_12.reserve(N);
            E_BM.reserve(N);
            E_normal.reserve(N);
            V_12.reserve(N);
            V_BM.reserve(N);
            V_normal.reserve(N);

            E_12.push_back(calc_Expectation(sample12));
            E_BM.push_back(calc_Expectation(sample_box_mueller));
            E_normal.push_back(calc_Expectation(sample_normal));

            V_12.push_back(calc_Variance(sample12));
            V_BM.push_back(calc_Variance(sample_box_mueller));
            V_normal.push_back(calc_Variance(sample_normal));
        }

        write_data(N_set, E_12, E_BM, E_normal, V_12, V_BM, V_normal);
    }

double method12(std::mt19937 &engine)
    {
        double x = 0;
        std::uniform_real_distribution<double> urd(0, 1);
        for (int i = 0; i < 12; ++i)
        {
            x += (urd(engine) - 0.5);
        }
        return x;
    }

double box_mueller(std::mt19937 &engine)
    {
        std::uniform_real_distribution<double> urd(0, 1);
        double a = urd(engine), b = urd(engine);
        double x = sqrt(-2 * log(a)) * cos(2 * M_PI * b);
        return x;
    }

double normal(std::mt19937 &engine)
    {
        std::normal_distribution<double> normalDistribution(0, 1);
        return normalDistribution(engine);
    }

void
write_data(const std::vector<int> &N_set, const std::vector<double> &E_12_set, const std::vector<double> &E_BM_set,
           const std::vector<double> &E_normal_set, const std::vector<double> &V_12_set,
           const std::vector<double> &V_BM_set, const std::vector<double> &V_normal_set)
    {
        std::string path_out = "../Lab_3/data/Source/N_set.txt";
        write_vector_in_file(N_set, path_out);

        path_out = "../Lab_3/data/E_12.txt";
        write_vector_in_file(E_12_set, path_out);

        path_out = "../Lab_3/data/E_BM.txt";
        write_vector_in_file(E_BM_set, path_out);

        path_out = "../Lab_3/data/E_normal.txt";
        write_vector_in_file(E_normal_set, path_out);

        path_out = "../Lab_3/data/V_12.txt";
        write_vector_in_file(V_12_set, path_out);

        path_out = "../Lab_3/data/V_BM.txt";
        write_vector_in_file(V_BM_set, path_out);

        path_out = "../Lab_3/data/V_normal.txt";
        write_vector_in_file(V_normal_set, path_out);
    }
