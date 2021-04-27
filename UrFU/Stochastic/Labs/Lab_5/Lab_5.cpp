//
// Created by Антон on 10.04.2021.
//

#include <vector>
#include <functional>
#include <iostream>
#include <cassert>
#include <cmath>
#include <sstream>
#include <algorithm>
#include "Lab_5.h"
#include "../Support/Write_functions.h"

using namespace std;

void
odeRC4(vector<vector<double>> &X, vector<double> &array_N, const vector<function<double(double, vector<double>, vector<double>)>> &F, const vector<double> &Param, const vector<double> &X_init, const double T, const double h = 0.01);

void
calc_K(const vector<double> &array_N, const vector<function<double(double, vector<double>, vector<double>)>> &F, const vector<double> &Param, const double h, const int i, vector<double> &k1, vector<double> &k2, vector<double> &k3, vector<double> &k4, const vector<double> &X_prev);

void clear_K(vector<double> &k1, vector<double> &k2, vector<double> &k3, vector<double> &k4);

void
calc_k(const vector<function<double(double, vector<double>, vector<double>)>> &F, const vector<double> &Param, vector<double> &k, double t, const vector<double> &X);

void
reserve_K(const vector<double> &X_init, vector<double> &k1, vector<double> &k2, vector<double> &k3, vector<double> &k4);

vector<double> operator+(const vector<double> &a, const vector<double> &b)
    {
        assert(a.size() == b.size());
        
        vector<double> res;
        res.reserve(a.size());
        
        transform(a.begin(), a.end(), b.begin(), back_inserter(res),
                  [](double a, double b) -> double
                      { return a + b; });
        return res;
    }

template<typename T>
vector<double> operator*(const T n, const vector<double> &a)
    {
        vector<double> res;
        res.reserve(a.size());
        
        transform(a.begin(), a.end(), back_inserter(res), [n](double el) -> double
            { return n*el; });
        return res;
    }

// X[0] - x, X[1] - y, P[0] = a.
double g1(const double t, const vector<double> &X, const vector<double> &P = {})
    {
        return (X[0] - X[1] - X[0]*X[0]*X[0]/3)*10;
    }

double g2(const double t, const vector<double> &X, const vector<double> &P)
    {
        return X[0] + P[0];
    }

void do_lab_5()
    {
        double T = 50;
        double x0 = -2;
        
        vector<double> Y0 = {-2, -1, -0.9, -0.8, -0.7, -0.6, -0.5, -0.1, 0.3, 0.7, 2};
        
        vector<double> A;
        const double h = 0.1;
        A.reserve(ceil(2/h));
        for (int i = 1; i < 2/h; ++i)
        {
            A.push_back(i*h);
        }
        for (int i = 1; i < 2/h; ++i)
        {
            A.push_back(0.9 + i*0.01);
        }
        
        sort(A.begin(), A.end());
        A.erase(unique(A.begin(), A.end()), A.end());
        
        vector<vector<double>> X;
        vector<double> array_N;
        
        string path = "../Lab_5/data/FitzHugh",
                Y0_str = "_Y0", A_str = "_A",
                array_N_str = "_arrayN", T_str = "_T", txt = "__.txt";
        
        for (const auto &a : A)
        {
            string a_str = "_a=" + to_str(a);
            
            for (const auto &y0 : Y0)
            {
                string y0_str = "_y0=" + to_str(y0), path_trajectory = path + a_str + y0_str + txt;
                vector<double> X_init = {x0, y0};
                
                odeRC4(X, array_N, {g1, g2}, {a}, X_init, T);
                write_vector_in_file(vector<double>{}, path_trajectory, true); //Почистили файл перед записью
                for (const auto &trajectory : X)
                {
                    write_vector_in_file(trajectory, path_trajectory, false);
                }
            }
        }
        
        write_vector_in_file(array_N, path + array_N_str + txt);
        write_vector_in_file(Y0, path + Y0_str + txt);
        write_vector_in_file(A, path + A_str + txt);
        write_number_in_file(T, path + T_str + txt);
    }


/**Возвращает вектор значений (N-мерные точки) и массив с шагом h на T */
void
odeRC4(vector<vector<double>> &X, vector<double> &array_N, const vector<function<double(double, vector<double>, vector<double>)>> &F, const vector<double> &Param, const vector<double> &X_init, const double T, const double h)
    {
        assert(h > 0);
        double N = T/h;
        
        X.clear();
        array_N.clear();
        
        X.reserve(N + 1);
        array_N.reserve(N + 1);
        
        vector<double> k1 = {}, k2 = {}, k3 = {}, k4 = {};
        reserve_K(X_init, k1, k2, k3, k4);
        
        array_N.push_back(0);
        X.push_back(X_init);
        
        for (int t = 1; t <= N; ++t)
        {
            array_N.push_back(t*h);
            vector<double> &X_prev = X[t - 1];
            
            clear_K(k1, k2, k3, k4);
            calc_K(array_N, F, Param, h, t, k1, k2, k3, k4, X_prev);
            X.push_back(X_prev + h/6*(k1 + 2*k2 + 2*k3 + k4));
        }
    }

void
reserve_K(const vector<double> &X_init, vector<double> &k1, vector<double> &k2, vector<double> &k3, vector<double> &k4)
    {
        k1.reserve(X_init.size() + 1);
        k2.reserve(X_init.size() + 1);
        k3.reserve(X_init.size() + 1);
        k4.reserve(X_init.size() + 1);
    }

void clear_K(vector<double> &k1, vector<double> &k2, vector<double> &k3, vector<double> &k4)
    {
        k1.clear();
        k2.clear();
        k3.clear();
        k4.clear();
    }

void
calc_K(const vector<double> &array_N, const vector<function<double(double, vector<double>, vector<double>)>> &F,
       const vector<double> &Param, const double h, const int i,
       vector<double> &k1, vector<double> &k2, vector<double> &k3, vector<double> &k4, const vector<double> &X_prev)
    {
        calc_k(F, Param, k1, array_N[i - 1], X_prev);
        calc_k(F, Param, k2, array_N[i - 1] + h/2, X_prev + h/2*k1);
        calc_k(F, Param, k3, array_N[i - 1] + h/2, X_prev + h/2*k2);
        calc_k(F, Param, k4, array_N[i - 1] + h, X_prev + h*k3);
    }

void
calc_k(const vector<function<double(double, vector<double>, vector<double>)>> &F,
       const vector<double> &Param, vector<double> &k, double t, const vector<double> &X)
    {
        for (const auto &f : F)
        {
            k.push_back(f(t, X, Param));
        }
    }


