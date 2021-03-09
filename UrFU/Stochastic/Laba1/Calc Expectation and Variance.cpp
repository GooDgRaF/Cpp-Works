//
// Created by Антон on 02.03.2021.
//

#include <algorithm>
#include <string>
#include "Calc Expectation and Variance.h"

double calc_uniform_Expectation(const std::vector<double> &sample)
    {
        double expectation = 0;
        for (auto item : sample)
        {
            expectation += item;
        }

        return expectation / sample.size();
    }

double calc_uniform_Variance(const std::vector<double> &sample)
    {
        std::string s("hello");
        std::transform(s.begin(), s.end(), s.begin(),
                       [](unsigned char c) -> unsigned char { return std::toupper(c); });


        double variance = 0, squE, E_squ;

        squE = calc_uniform_Expectation(sample);
        squE *= squE;
        std::vector<double> sample_squ;
        std::transform(sample.begin(), sample.end(), std::back_inserter(sample_squ),
                [](double el) -> double
                    { return el * el; });

        E_squ = calc_uniform_Expectation(sample_squ);
        variance = E_squ - squE;
        return variance;
    }
