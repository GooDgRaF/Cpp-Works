//
// Created by Антон on 02.03.2021.
//

#include "Randomize.h"
#include <cstdlib> // для функций rand() и srand()
#include <ctime> // для функции time()
#include <random> // для std::random_device и std::mt19937
#include <chrono>


void get_rand(const int N, std::vector<double> &sample)
    {
        sample.resize(N);
        static bool flag_gen = false;
        if (!flag_gen)
        {
            srand(static_cast<unsigned int>(time(0))); // устанавливаем значение системных часов в качестве стартового числа
            flag_gen = true;
        }

        rand();rand();
        for (auto &el : sample)
        {
            el = (double) (rand()) / RAND_MAX;
        }
    }

void get_rand_Mersenne_Twister(const int N, std::vector<double> &sample, std::mt19937 &random_generator)
    {
        sample.resize(N);
        std::uniform_real_distribution<double> urd(0, 1);
        for (auto &el : sample)
        {
            el = urd(random_generator);
        }
    }
