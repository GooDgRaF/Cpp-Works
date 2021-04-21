//
// Created by Антон on 02.03.2021.
//

#ifndef HOMEWORK_CALC_EXPECTATION_VARIANCE_COVARIANCE_H
#define HOMEWORK_CALC_EXPECTATION_VARIANCE_COVARIANCE_H


#include <vector>

double calc_Expectation(const std::vector<double> &sample);

double calc_Variance(const std::vector<double> &sample);

double calc_Covariance(const std::vector<double> &sample_1, const std::vector<double> &sample_2);
double calc_Correlation(const std::vector<double> &sample_1, const std::vector<double> &sample_2);

#endif //HOMEWORK_CALC_EXPECTATION_VARIANCE_COVARIANCE_H
