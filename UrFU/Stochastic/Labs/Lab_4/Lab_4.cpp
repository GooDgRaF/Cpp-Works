//
// Created by Антон on 01.04.2021.
//

#include "Lab_4.h"
#include <cmath>
#include <sstream>
#include <map>
#include "../Support/Random_engine.h"
#include "../Support/Write_functions.h"
#include "../Support/Calc Expectation, Variance and Covariance.h"

double colorNoise(const double x, const double h, const double a);

void write_data(const std::vector<int> &N_set, const std::map<double, std::vector<double>> &a_to_, const std::string c);

void do_lab_4()
    {
//Построить реализцаии цветного шума
        double h = 0.01;
        std::vector<double> sample = {};
        std::vector<int> N_set = {};
        std::map<double, std::vector<double>> a_to_E = {}, a_to_V = {};
        for (int T = 1; T <= 100; T *= 10)
        {
            double N = T / h;
            N_set.push_back(N);
            sample.reserve(N);

            for (int a = 1; a <= 100; a *= 10)
            {
                sample.clear();
                double x = 0;
                for (int n = 0; n < N; ++n)
                {
                    sample.push_back(colorNoise(x, h, a));
                }

//Матожидание и Дисперсия
                auto E = calc_Expectation(sample);
                auto V = calc_Variance(sample);
                a_to_E[a].push_back(E);
                a_to_V[a].push_back(V);

                std::ostringstream a_str, T_str;
                a_str << a;
                T_str << T;

                std::string path = "../Lab_4/data/Source/sampleNoise_a" + a_str.str() + "_T" + T_str.str() + ".txt";
                write_vector_in_file(sample, path);
            }
        }

        write_data(N_set, a_to_E, "E");
        write_data(N_set, a_to_V, "V");
    }

void write_data(const std::vector<int> &N_set, const std::map<double, std::vector<double>> &a_to_, const std::string c)
    {
        for (const auto &pair: a_to_)
        {
            std::ostringstream a;
            a << pair.first;
            std::string path = "../Lab_4/data/" + c +"_noise_a" + a.str() + ".txt";
            write_two_vectors(path, pair.second, N_set);
        }
    }

double colorNoise(const double x, const double h, const double a)
    {
        double u1 = randomEngine.get_real_uniform(0, 1);
        double u2 = randomEngine.get_real_uniform(0, 1);

        return x - h * a * x + a * sqrt(h) * sqrt(-2 * log(u1)) * cos(2 * M_PI * u2);
    }
