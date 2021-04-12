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

#define PARAMETER_a 1.1

using namespace std;

void odeRC4(vector<vector<double>> &X, vector<double> &grid,
            const vector<function<double(double, vector<double>)>> &F,
            const double t_init, const vector<double> &X_init,
            const double T, const double h = 0.01);

void
calc_K(const vector<double> &grid, const vector<function<double(double, vector<double>)>> &F,
       const double h, const int t, vector<double> &k1, vector<double> &k2, vector<double> &k3, vector<double> &k4,
       const vector<double> &X_prev);

void clear_K(vector<double> &k1, vector<double> &k2, vector<double> &k3, vector<double> &k4);

void
calc_k(const vector<function<double(double, vector<double>)>> &F, vector<double> &k, double t, const vector<double> &X);

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
            { return n * el; });
        return res;
    }


double g1(const double t, const vector<double> &X)
    {
        return (X[0] - X[1] - X[0] * X[0] * X[0] / 3) * 10;
    }

double g2(const double t, const vector<double> &X)
    {
        return X[0] + PARAMETER_a;
    }

void do_lab_5()
    {
        vector<vector<double>> X;
        vector<double> grid;
        double t_init = 0, T = 100;
        vector<double> X_init = {-PARAMETER_a, -1};//TODO Писать в файл с разными начальными условиями

        odeRC4(X, grid, {g1, g2}, t_init, X_init, T);

        ostringstream a_str;
        a_str << PARAMETER_a;
        string path = "../Lab_5/data/FitzHugh_a_" + a_str.str() + "_.txt";

        write_vector_in_file(vector<double>{}, path, true); //Почистили файл перед записью
        for (const auto &item : X)
        {
            write_vector_in_file(item, path, false);
        }

//        path = "../Lab_5/data/FitzHugh_grid.txt";
//        write_vector_in_file(grid, path);

    }


/**Возвращает вектор значений (N-мерные точки) и сетку с шагом h на T */
void odeRC4(vector<vector<double>> &X, vector<double> &grid,
            const vector<function<double(double, vector<double>)>> &F,
            const double t_init, const vector<double> &X_init,
            const double T, const double h)
    {
        double N = T / h;

        X.clear();
        grid.clear();

        X.reserve(N + 1);
        grid.reserve(N + 1);

        vector<double> k1 = {}, k2 = {}, k3 = {}, k4 = {};
        reserve_K(X_init, k1, k2, k3, k4);

        grid.push_back(t_init);
        X.push_back(X_init);

        for (int t = 1; t <= N; ++t)
        {
            grid.push_back(t_init + t * h);
            vector<double> &X_prev = X[t - 1];

            clear_K(k1, k2, k3, k4);
            calc_K(grid, F, h, t, k1, k2, k3, k4, X_prev);
            X.push_back(X_prev + h / 6 * (k1 + 2 * k2 + 2 * k3 + k4));
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
calc_K(const vector<double> &grid, const vector<function<double(double, vector<double>)>> &F,
       const double h, const int t, vector<double> &k1, vector<double> &k2, vector<double> &k3, vector<double> &k4,
       const vector<double> &X_prev)
    {
        calc_k(F, k1, grid[t - 1], X_prev);
        calc_k(F, k2, grid[t - 1] + h / 2, X_prev + h / 2 * k1);
        calc_k(F, k3, grid[t - 1] + h / 2, X_prev + h / 2 * k2);
        calc_k(F, k4, grid[t - 1] + h, X_prev + h * k3);
    }

void
calc_k(const vector<function<double(double, vector<double>)>> &F, vector<double> &k, double t, const vector<double> &X)
    {
        for (const auto &f : F)
        {
            k.push_back(f(t, X));
        }
    }


