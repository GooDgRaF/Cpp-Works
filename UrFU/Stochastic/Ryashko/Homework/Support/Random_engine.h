//
// Created by Антон on 01.04.2021.
//

#ifndef HOMEWORK_RANDOM_ENGINE_H
#define HOMEWORK_RANDOM_ENGINE_H

#include <chrono>
#include <random>

class Random_engine
{
public:
    static Random_engine &get_instance();

    double get_real_uniform(const double min = 0, const double max = 1);

    double get_normal(const double E = 0, const double V = 1);

private:
    Random_engine();

    std::mt19937 m_engine;
};

extern Random_engine randomEngine;

#endif //HOMEWORK_RANDOM_ENGINE_H
