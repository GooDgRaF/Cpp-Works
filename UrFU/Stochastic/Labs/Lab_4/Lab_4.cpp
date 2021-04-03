//
// Created by Антон on 01.04.2021.
//

#include "Lab_4.h"
#include <cmath>
#include <sstream>
#include <map>
#include "../Support/Random_engine.h"
#include "../Support/Write_functions.h"
#include "../Support/Calc_Expectation_Variance_Covariance.h"

double colorNoise(const double x, const double h, const double a);

void write_data(const std::vector<int> &N_set, const std::map<double, std::vector<double>> &a_to_, const std::string c);

double skipT(const int T, const double h, double x = 0);

void do_lab_4()
    {
        double h = 0.01;
        {
//Построить реализцаии цветного шума
//        {
//            std::vector<double> sample = {};
//            std::vector<int> N_set = {};
//            std::map<double, std::vector<double>> a_to_E = {}, a_to_V = {};
//            for (int T = 1; T <= 100000; T *= 10)
//            {
//                double N = T / h;
//                N_set.push_back(N);
//                sample.reserve(N);
//
//                for (int a = 2; a <= 16; a *= 2)
//                {
//                    sample.clear();
//                    double x = 0;
//                    for (int n = 0; n < N; ++n)
//                    {
//                        x = colorNoise(x, h, a);
//                        sample.push_back(x);
//                    }
//
////Матожидание и Дисперсия
//                    a_to_E[a].push_back(calc_Expectation(sample));
//                    a_to_V[a].push_back(calc_Variance(sample));
//
//                    std::ostringstream a_str, T_str;
//                    a_str << a;
//                    T_str << T;
//
//                    std::string path = "../Lab_4/data/Source/sampleNoise_a" + a_str.str() + "_T" + T_str.str() + ".txt";
//                    write_vector_in_file(sample, path);
//                }
//            }
//
//            write_data(N_set, a_to_E, "E");
//            write_data(N_set, a_to_V, "V");
//        }
        }
//Исследование корреляции между моментом T = 100 и T = 110 шагом N = 100
        {
            std::vector<double> sample = {};
            sample.reserve(10);

            for (int N = 10e1; N < 10e6; N*=10)
            {
                std::ostringstream N_str;
                N_str << N;
                std::string path = "../Lab_4/data/Source/sample10_N" + N_str.str() + ".txt";
                write_vector_in_file(std::vector<double>{}, path, true); //Почистили файл перед записью
                for (int n = 0; n < N; ++n)
                {
                    sample.clear();
                    double x = 0;

                    x = skipT(10, h, x);
                    //x = skipT(100, h, x);
                    sample.push_back(x);
                    for (int i = 0; i < 9; ++i)
                    {
                        x = skipT(1, h, x);
                        sample.push_back(x);
                    }
                    write_vector_in_file(sample, path, false);
                }
            }
        }

    }

double skipT(const int T, const double h, double x)
    {
        double N = T / h;
        for (int n = 0; n < N; ++n)
        {
            x = colorNoise(x, h, 1);
        }
        return x;
    }


//Функции:
void write_data(const std::vector<int> &N_set, const std::map<double, std::vector<double>> &a_to_, const std::string c)
    {
        for (const auto &pair: a_to_)
        {
            std::ostringstream a;
            a << pair.first;
            std::string path = "../Lab_4/data/" + c + "_noise_a" + a.str() + ".txt";
            write_two_vectors(path, pair.second, N_set);
        }
    }

double colorNoise(const double x, const double h, const double a)
    {
        double u1 = randomEngine.get_real_uniform(0, 1);
        double u2 = randomEngine.get_real_uniform(0, 1);

        return (1 - h * a) * x + a * sqrt(h) * sqrt(-2 * log(u1)) * cos(2 * M_PI * u2);
    }
