//
// Created by Антон on 10.04.2021.
//

#include <vector>
#include <functional>
#include <iostream>
#include <cassert>
#include <cmath>
#include "Lab_5.h"

void odeRC4(std::vector<std::vector<double>> &X, std::vector<double> &grid,
            const std::vector<std::function<double(double, std::vector<double>)>> &F,
            const double x_init, const std::vector<double> &X_init,
            const double T, const double h = 0.01);

std::vector<double> operator+(const std::vector<double> &a, const std::vector<double> &b)
    {
        assert(a.size() == b.size());

        std::vector<double> res;
        res.reserve(a.size());


        for (int i = 0; i < a.size(); ++i)
        {
            res.push_back(a[i] + b[i]);
        }
        return res;
    }

template<typename T>
std::vector<double> operator*(const T n, const std::vector<double> &a)
    {
        std::vector<double> res;
        res.reserve(a.size());

        for (double el : a)
        {
            res.push_back(n * el);
        }
        return res;
    }

double f(double x, std::vector<double> y)
    {
        return 3 * x * x * y[0] + x * x * pow(M_E, x * x * x);
    }

double g1(double x, std::vector<double> y)
    {
        return y[1];
    }
double g2(double x, std::vector<double> y)
    {
        return y[2];
    }
double g3(double x, std::vector<double> y)
    {
        return -3*y[2] - 3*y[1] - y[0];
    }
void do_lab_5()
    {
        std::vector<std::vector<double>> X;
        std::vector<double> grid;
        odeRC4(X, grid, {f}, 0, {0}, 1, 0.1);
        std::cout << X[0][0];


        X.clear();
        grid.clear();

        odeRC4(X,grid,{g1, g2, g3},0, {-1,2,3},1);
        std::cout << X[0][0];

    }


/**Возвращает вектор значений (N-мерные точки) и сетку с шагом h на T**/
void odeRC4(std::vector<std::vector<double>> &X, std::vector<double> &grid,
            const std::vector<std::function<double(double, std::vector<double>)>> &F,
            const double x_init, const std::vector<double> &X_init,
            const double T, const double h)
    {
        double N = T / h;
        X.reserve(N + 1);
        grid.reserve(N + 1);
        std::vector<double> k1 = {}, k2 = {}, k3 = {}, k4 = {};
        k1.reserve(X_init.size() + 1);
        k2.reserve(X_init.size() + 1);
        k3.reserve(X_init.size() + 1);
        k4.reserve(X_init.size() + 1);

        grid.push_back(x_init);
        std::vector<double> X_prev = X_init;

        for (int t = 1; t <= N; ++t)
        {
            k1.clear();
            k2.clear();
            k3.clear();
            k4.clear();

            grid.push_back(x_init + t * h);

            for (const auto &f : F)
            {
                k1.push_back(f(grid[t - 1], X_prev));
            }
            for (const auto &f : F)
            {
                k2.push_back(f(grid[t - 1] + h / 2, X_prev + h / 2 * k1));
            }
            for (const auto &f : F)
            {
                k3.push_back(f(grid[t - 1] + h / 2, X_prev + h / 2 * k2));
            }
            for (const auto &f : F)
            {
                k4.push_back(f(grid[t - 1] + h, X_prev + h * k3));
            }


            X.push_back(X_prev + h / 6 * (k1 + 2 * k2 + 2 * k3 + k4));
            X_prev = X.back();
        }
    }


