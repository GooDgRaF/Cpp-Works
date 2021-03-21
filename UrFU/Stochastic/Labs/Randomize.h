//
// Created by Антон on 02.03.2021.
//

#ifndef LABA1_RANDOMIZE_H
#define LABA1_RANDOMIZE_H
#include <vector>
#include <random>

void get_rand(const int N, std::vector<double> &sample);

void get_rand_Mersenne_Twister(const int N, std::vector<double> &sample, std::mt19937 &random_generator);

#endif //LABA1_RANDOMIZE_H
