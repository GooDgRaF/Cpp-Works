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

#define a 1.1
#define x_ 1.1
#define x0 1.1
#define eps 0.1

using namespace std;

double f(const double x);
double sigma(const double x);
double Euler_Maruyama(const double h, const double x_prev,
                      const function<double(const double)> &f,
                      const function<double(const double)> &sigma);


void calc_model_equation()
    {
        double T = 10;
        double h = 0.01;
        double N = T/0.01;
        
        int i_max = 5;
        
        
        vector<double> sample;
        sample.reserve(ceil(N));
        
        string drill = "Model_equation", source = "data", sam = "sample",
                a_str = "_a=" + to_str(a), x0_str = "_x0=" + to_str(x0),
                x_str = "_x_=" + to_str(x_), T_str = "_T=" + to_str(T),
                eps_str = "_eps=" + to_str(eps),
                path = "../" + drill + "/" + source + "/" + sam;
        string path_param = path + x0_str + a_str + x_str + T_str + eps_str + ".txt";
        
        write_vector_in_file(vector<double>{}, path_param, true);//Почистили файл
        
        write_element_in_file(i_max, path + "_i_max.txt");
        write_element_in_file(T, path + "_T.txt");
        write_element_in_file(h, path + "_h.txt");
        write_element_in_file(eps, path + "_eps.txt");
        
        
        
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