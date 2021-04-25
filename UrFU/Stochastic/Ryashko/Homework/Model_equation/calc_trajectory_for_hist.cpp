//
// Created by Антон on 24.04.2021.
//

#include <vector>
#include <iostream>
#include <functional>
#include "Calc_model_eq.h"
#include "../Support/Random_engine.h"
#include "../Support/Calc_Expectation_Variance_Covariance.h"
#include "../Support/Write_functions.h"

#define a 3
#define x_ 2
#define x0 0
#define eps 1

using namespace std;

double f(const double x);

double sigma(const double x);

double Euler_Maruyama(const double h, const double x_prev,
                      const function<double(const double)> &f,
                      const function<double(const double)> &sigma);


void calc_for_hist()
    {
        const double h = 0.01;
        const int i_max = 10e4;
        const int T = 10;
        
        vector<int> N_for_hist;
        for (int i = 1; i < 20; ++i)
        {
            N_for_hist.push_back(i);
        }
        for (int i = 20; i < 100 ; i += 10)
        {
            N_for_hist.push_back(i);
        }
        for (int i = 100; i <= 1000; i += 100)
        {
            N_for_hist.push_back(i);
        }
        
        string drill = "Model_equation", source = "data", sam = "HIST_sample",
                a_str = "_a=" + to_str(a), x0_str = "_x0=" + to_str(x0),
                x_str = "_x_=" + to_str(x_),
                eps_str = "_eps=" + to_str(eps),
                path = "../" + drill + "/" + source + "/" + sam;
        
        write_element_in_file(i_max, path + "_i_max.txt");
        write_element_in_file(h, path + "_h.txt");
        write_element_in_file(T, path + "_T.txt");
        write_vector_in_file(N_for_hist, path + "_bins.txt");
        
        const double N = T/0.01;
        
        vector<double> sample;
        sample.reserve(ceil(N));
        
        string T_str = "_T=" + to_str(T),
                path_param = path + x0_str + a_str + x_str + T_str + eps_str + ".txt";
        
        write_vector_in_file(vector<double>{}, path_param, true);//Почистили файл
        
        for (int i = 0; i < i_max; ++i)
        {
            sample.clear();
            sample.push_back(x0);
            
            auto x = sample[0];
            
            for (int n = 1; n < N; ++n)
            {
                x = Euler_Maruyama(h, x, f, sigma);
                if (find(N_for_hist.begin(), N_for_hist.end(), n) != N_for_hist.end())
                {
                    sample.push_back(x);
                }
                
            }
            write_vector_in_file(sample, path_param, false);
        }
        
        
        std::cout << "calc_model_equation complete!" << std::endl;
    }