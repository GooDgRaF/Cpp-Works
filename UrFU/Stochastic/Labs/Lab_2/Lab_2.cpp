//
// Created by Антон on 21.03.2021.
//

#include <vector>
#include <iostream>
#include "Lab_2.h"
#include "cmath"
#include "../Randomize.h"
#include "../Write_functions.h"
#include "../Calc Expectation, Variance and Covariance.h"
double g(const double y);

void do_lab_2(std::mt19937 &random_generator)
    {
//Смоделировать N значений случайной величины с плотностью f(x) = 1.5*sqrt(x)
        int N = 10e7;
        std::vector<double> uniform_sample = {0}, g_sample = {0};
        get_rand_Mersenne_Twister(N, uniform_sample, random_generator);

        g_sample.resize(N);
        for (int i = 0; i < uniform_sample.size(); ++i)
        {
            g_sample[i] = g(uniform_sample[i]);
        }
        std::string path = "../Lab_2/data/g_sample.txt";
        write_vector_in_file(g_sample, path);
 //Найти точные значения Матожидания и Дисперсии
 //     М = 3/5, Д = 12/175

 //Вычислить оценки М и Д сравнить с точными
        double E = calc_Expectation(g_sample);
        double V = calc_Variance(g_sample);

        std::cout << "Expectation = "<< E << std::endl;
        std::cout << "Variance = "<< V << std::endl;

    }
    

double g(const double y)
    {
        return std::pow(y,2.0/3);
    }
