//
// Created by Антон on 02.03.2021.
//

#ifndef LABA1_CALC_EXPECTATION_VARIANCE_AND_COVARIANCE_H
#define LABA1_CALC_EXPECTATION_VARIANCE_AND_COVARIANCE_H


#include <vector>

double calc_Expectation(const std::vector<double> &sample);

double calc_Variance(const std::vector<double> &sample);

double calc_Covariance(const std::vector<double> &sample_1, const std::vector<double> &sample_2);
double calc_Correlation(const std::vector<double> &sample_1, const std::vector<double> &sample_2);

#endif //LABA1_CALC_EXPECTATION_VARIANCE_AND_COVARIANCE_H
