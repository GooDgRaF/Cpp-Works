//
// Created by Антон on 21.03.2021.
//

#include <vector>
#include "Lab_2.h"
#include "cmath"
#include "../Randomize.h"
double g(const double y);

void do_lab_2()
    {
//Смоделировать N значений случайной величины с плотностью f(x) = 1.5*sqrt(x)
        int N = 10e6;
        std::vector<double> sample_f;
       // get_rand_Mersenne_Twister(N, sample_f, <#initializer#>);

    }

double g(const double y)
    {
        return std::pow(y/4, 1/3);
    }
