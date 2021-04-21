//
// Created by Антон on 21.04.2021.
//

#include <vector>
#include <iostream>
#include "Normal.h"
#include "../Support/Random_engine.h"
#include "../Support/Calc_Expectation_Variance_Covariance.h"
#include "../Support/Write_functions.h"

using namespace std;

void test_normal()
    {
        vector<double> sample, variance, expectation;
        vector<int> array_N;

        int N_max = 10e6;
        int i_max = 4;

        string drill = "Distributions_test", source = "data_N", sam = "sample", e = "_expectation", v = "_variance",
                path = "../" + drill + "/" + source + "/"+ sam;

        write_number_in_file(N_max, path + "_N_max.txt");
        write_number_in_file(i_max - 1, path + "_i_max.txt");
        for (int i = 0; i < i_max; ++i)
        {
            sample.clear();
            variance.clear();
            expectation.clear();
            array_N.clear();

            for (int N = 10e1; N < N_max; N *= 10)
            {
                array_N.push_back(N);
                sample.clear();
                sample.reserve(N);

                for (int n = 0; n < N; ++n)
                {
                    sample.push_back(randomEngine.get_normal());
                }

                expectation.push_back(calc_Expectation(sample));
                variance.push_back(calc_Variance(sample));

                write_vector_in_file(sample, path + "_i" + to_string(i) + "_N" + to_string(N) + ".txt");
            }
            write_vector_in_file(expectation, path + "_i" + to_string(i) + e + ".txt");
            write_vector_in_file(variance, path + "_i" + to_string(i) + v  + ".txt");


        }

        write_vector_in_file(array_N, path + "N_max="+ to_string(N_max) + ".txt", false);

        std::cout << "test_normal complete!" << std::endl;
    }