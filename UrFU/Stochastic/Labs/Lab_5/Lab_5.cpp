//
// Created by Антон on 10.04.2021.
//

#include <vector>
#include <functional>
#include <iostream>
#include <cassert>
#include <cmath>
#include <sstream>
#include "Lab_5.h"
#include "../Support/Write_functions.h"

#define PARAMETER_a 0.001

void odeRC4(std::vector<std::vector<double>> &X, std::vector<double> &grid,
            const std::vector<std::function<double(double, std::vector<double>)>> &F,
            const double t_init, const std::vector<double> &X_init,
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


double g1(const double t, const std::vector<double> &v)
    {
        return (v[0] - v[1] - v[0] * v[0] * v[0] / 3) / 10;
    }

double g2(const double t, const std::vector<double> &v)
    {
        return v[0] + PARAMETER_a;
    }

void do_lab_5()
    {
        std::vector<std::vector<double>> X;
        std::vector<double> grid;
        double t_init = 0, T = 500;
        std::vector<double> X_init = {0,0};

        odeRC4(X, grid, {g1, g2}, t_init, X_init, T);

        std::ostringstream a_str;
        a_str << PARAMETER_a;
        std::string path = "../Lab_5/data/FitzHugh_a_"+ a_str.str() +"_.txt";

        write_vector_in_file(std::vector<double>{}, path, true); //Почистили файл перед записью
        for (const auto &item : X)
        {
            write_vector_in_file(item, path, false);
        }

//        path = "../Lab_5/data/FitzHugh_grid.txt";
//        write_vector_in_file(grid, path);

    }


/**Возвращает вектор значений (N-мерные точки) и сетку с шагом h на T */
void odeRC4(std::vector<std::vector<double>> &X, std::vector<double> &grid,
            const std::vector<std::function<double(double, std::vector<double>)>> &F,
            const double t_init, const std::vector<double> &X_init,
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

        grid.push_back(t_init);
        std::vector<double> X_prev = X_init;

        X.push_back(X_init);

        for (int t = 1; t <= N; ++t)
        {
            k1.clear();
            k2.clear();
            k3.clear();
            k4.clear();

            grid.push_back(t_init + t * h);

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


