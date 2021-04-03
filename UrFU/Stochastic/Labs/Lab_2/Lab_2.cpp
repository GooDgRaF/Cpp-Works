//
// Created by Антон on 21.03.2021.
//

#include <vector>
#include <iostream>
#include "Lab_2.h"
#include "cmath"
#include "../Support/Randomize.h"
#include "../Support/Write_functions.h"
#include "../Support/Calc_Expectation_Variance_Covariance.h"

double g(const double y);

double g_MK(const double x);

void do_lab_2(std::mt19937 &random_generator)
    {
//Смоделировать N значений случайной величины с плотностью f(x) = 1.5*sqrt(x)
        {
//            int N = 10e7;
//            std::vector<double> uniform_sample = {0}, g_sample = {0};
//            get_rand_Mersenne_Twister(N, uniform_sample, random_generator);
//
//            g_sample.resize(N);
//            for (int i = 0; i < uniform_sample.size(); ++i)
//            {
//                g_sample[i] = g(uniform_sample[i]);
//            }
//            std::string path = "../Lab_2/data/g_sample.txt";
//            write_vector_in_file(g_sample, path);
//            //Найти точные значения Матожидания и Дисперсии
//            //     М = 3/5, Д = 12/175
//
//            //Вычислить оценки М и Д сравнить с точными
//            double E = calc_Expectation(g_sample);
//            double V = calc_Variance(g_sample);
//
//            std::cout << "Expectation = " << E << std::endl;
//            std::cout << "Variance = " << V << std::endl;
        }

//
//Вычисление площади методом Монте-Карло
//
        {
            double g_max = 2.0, segment = 2.0, exact = 8.0/3;
            std::vector<int> N_vector = {};
            std::vector<double> integral_mean = {}, inaccuracy = {};
            std::uniform_real_distribution<double> urd(0, 1);
            for (int N = 10; N < 10e7; N *= 10)
            {
                int count = 0;
                for (int n = 1; n < N; ++n)
                {
                    std::pair<double, double> point = {segment * urd(random_generator),
                                                       g_max * urd(random_generator)};
                    double g_xn = g_MK(point.first);
                    if (point.second < g_xn)
                        count++;
                }
                double integral_g_MK = ((double) count) / N * g_max * segment;
                double error_rate = std::abs(exact - integral_g_MK);
                N_vector.push_back(N);
                integral_mean.push_back(integral_g_MK);
                inaccuracy.push_back(error_rate);
            }
            std::string path = "../Lab_2/data/g_integral.txt";
            write_two_vectors(path, integral_mean, N_vector);
            path = "../Lab_2/data/g_integral_inaccuracy.txt";
            write_two_vectors(path, inaccuracy, N_vector);
        }
    }


double g(const double y)
    {
        return std::pow(y, 2.0 / 3);
    }

double g_MK(const double x)
    {
        return x * x - 2 * x + 2;
    }