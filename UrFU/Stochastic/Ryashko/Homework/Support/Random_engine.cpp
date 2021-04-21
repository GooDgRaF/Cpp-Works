//
// Created by Антон on 01.04.2021.
//

#include "Random_engine.h"
Random_engine &Random_engine::get_instance()
    {
        // The only instance of the class is created at the first call get_instance ()
        // and will be destroyed only when the program exits
        static Random_engine instance;
        return instance;
    }

Random_engine::Random_engine(): m_engine((std::chrono::high_resolution_clock::now()).time_since_epoch().count())
    {

    }

double Random_engine::get_real_uniform(const double min, const double max)
    {
        std::uniform_real_distribution<double> urd(min,max);
        return urd(m_engine);
    }

double Random_engine::get_normal(const double E, const double V)
    {
        double a = randomEngine.get_real_uniform(), b = randomEngine.get_real_uniform();
        double ksi = sqrt(-2 * log(a)) * cos(2 * M_PI * b);
        return E + V*ksi;
    }

Random_engine randomEngine = Random_engine::get_instance();