//
// Created by Антон on 02.03.2021.
//

#include <algorithm>
#include <string>
#include <cmath>
#include "Calc Expectation, Variance and Covariance.h"

double calc_Expectation(const std::vector<double> &sample)
    {
        double expectation = 0;
        for (auto item : sample)
        {
            expectation += item;
        }

        return expectation / sample.size();
    }

double calc_Variance(const std::vector<double> &sample)
    {
        double variance = 0, squE, E_squ;

        squE = calc_Expectation(sample);
        squE *= squE;
        std::vector<double> sample_squ;
        std::transform(sample.begin(), sample.end(), std::back_inserter(sample_squ),
                       [](double el) -> double
                           { return el * el; });

        E_squ = calc_Expectation(sample_squ);
        variance = E_squ - squE;
        return variance;
    }

double calc_Covariance(const std::vector<double> &sample_1, const std::vector<double> &sample_2)
    {
        double cov = 0;
        double E_1 = calc_Expectation(sample_1);
        double E_2 = calc_Expectation(sample_2);

        std::vector<double> multi_sample;
        multi_sample.resize(sample_1.size());

        for (int i = 0; i < multi_sample.size(); ++i)
        {
            multi_sample[i] = sample_1[i] * sample_2[i];
        }

        double E_multi = calc_Expectation(multi_sample);
        cov = E_multi - E_1 * E_2;
        return cov;
    }

double calc_Correlation(const std::vector<double> &sample_1, const std::vector<double> &sample_2)
    {
        double cor = 0;
        double cov = calc_Covariance(sample_1,sample_2);
        double sqrtD_1 = std::sqrt(calc_Variance(sample_1));
        double sqrtD_2 = std::sqrt(calc_Variance(sample_2));

        cor = cov/(sqrtD_1 * sqrtD_2);
        return cor;
    }
