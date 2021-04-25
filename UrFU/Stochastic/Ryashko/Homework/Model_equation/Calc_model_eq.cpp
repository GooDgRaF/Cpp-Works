//
// Created by Антон on 22.04.2021.
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


void calc_model_equation()
    {
        const double h = 0.01;
        const int i_max = 5;
        const int T_max = 1000;
        
        string drill = "Model_equation", source = "data", sam = "sample",
                a_str = "_a=" + to_str(a), x0_str = "_x0=" + to_str(x0),
                x_str = "_x_=" + to_str(x_),
                eps_str = "_eps=" + to_str(eps),
                path = "../" + drill + "/" + source + "/" + sam;
        
        write_element_in_file(i_max, path + "_i_max.txt");
        write_element_in_file(h, path + "_h.txt");
        write_element_in_file(T_max, path + "_T_max.txt");
        
        for (int T = 1; T <= T_max; T*=10)
        {
            const double N = T/0.01;
            
            vector<double> sample;
            sample.reserve(ceil(N));
            
            string  T_str = "_T=" + to_str(T),
            path_param = path + x0_str + a_str + x_str + T_str + eps_str + ".txt";
            
            write_vector_in_file(vector<double>{}, path_param, true);//Почистили файл
            
            for (int i = 0; i < i_max; ++i)
            {
                sample.clear();
                sample.push_back(x0);
                
                for (int n = 0; n < N; ++n)
                {
                    auto x = sample.back();
                    sample.push_back(Euler_Maruyama(h, x, f, sigma));
                }
                write_vector_in_file(sample, path_param, false);
            }
        }
        
        std::cout << "calc_model_equation complete!" << std::endl;
    }

double f(const double x)
    {
        return -a*(x - x_);
    }

double sigma(const double x)
    {
        return eps;
    }

/**
* @Name Cкалярный метод Эйлера-Маруямы для стационарного случая
 * @param h - шаг метода
 * @param x_prev - значение уравнения в предыдущей точке по времени
 * @param f - функция при dt
 * @param sigma - функция при dw

* @return Возвращет значение уравнения в текущей точке по времени
*/
double Euler_Maruyama(const double h, const double x_prev,
                      const function<double(const double)> &f,
                      const function<double(const double)> &sigma)
    {
        double ksi = randomEngine.get_normal();
        return x_prev + f(x_prev)*h + sigma(x_prev)*sqrt(h)*ksi;
    }