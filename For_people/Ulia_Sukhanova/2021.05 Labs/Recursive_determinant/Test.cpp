//
// Created by Антон on 21.05.2021.
//

#include <cassert>
#include "Test.h"
#include "Recursive_determinant.h"
#include <iostream>
#include "Solver.h"

using namespace test;

void test_det_by_first_row()
    {
        matrix_double
                E_1 = {{1}},
                
                E_2 = {{1, 0},
                       {0, 1}},
                
                triangle_up_2 = {{-2, 3},
                                 {0,  1}},
                
                triangle_down_3 = {{3, 0,    0},
                                   {1, -5.5, 0},
                                   {2, 3,    9.99}},
                
                qadr = {{5.135,  3.226,  10.071, 5.273},
                        {13.466, 11.332, 11.229, 8.917},
                        {4.367,  1.520,  7.893,  5.197},
                        {7.847,  14.606, 2.217,  3.982}};
        
        const double eps = 10e-5;
        
        assert(det_by_first_row(E_1) == 1);
        assert(det_by_first_row(E_2) == 1);
        assert(det_by_first_row(triangle_up_2) == -2);
        assert(abs(det_by_first_row(triangle_down_3) - 3*(-5.5)*9.99) < eps);
        assert(abs(det_by_first_row(qadr) + 540.314940) < eps);
        
        std::cout << " --Test of recursive determinant successful complete!" << std::endl;
        
    }

void test_solver()
    {
        matrix_double
                E_1 = {{1}},
                
                E_2 = {{1, 0},
                       {0, 1}},
                
                triangle_up_2 = {{-2, 3},
                                 {0,  1}},
                
                triangle_down_3 = {{3, 0,    0},
                                   {1, -5.5, 0},
                                   {2, 3,    9.99}},
                
                qadr = {{5.135,  3.226,  10.071, 5.273},
                        {13.466, 11.332, 11.229, 8.917},
                        {4.367,  1.520,  7.893,  5.197},
                        {7.847,  14.606, 2.217,  3.982}},
                
                infSol = {{1, 1},
                          {2, 2}},
                          
                nonSol = {{2, 6},
                          {1, 3}};
        
        const double eps = 10e-2;
        
        std::vector<double> //right column
        r1 = {5},
                r2 = {-7.25, 897.3333},
                r_t2 = {2, 4},
                r_t3 = {-1.06, -9.76, 5.83},
                r_qadr = {0.327, 12.505, 13.944, 3.690},
                r_infSol = {1, 2},
                r_nonSol = {3, 8};
        
        SLEquation
                sle_1 = {E_1, r1},
                sle_2 = {E_2, r2},
                sle_t2 = {triangle_up_2, r_t2},
                sle_t3 = {triangle_down_3, r_t3},
                sle_qadr = {qadr, r_qadr},
                sle_infSol = {infSol, r_infSol},
                sle_nonSol = {nonSol, r_nonSol};
        
        
        std::vector<double> //Solution
        sol_1 = {5},
                sol_2 = {-7.25, 897.3333},
                sol_t2 = {5, 4},
                sol_t3 = {-0.353, 1.710, 0.1407},
                sol_qadr = {-1.973, -1.280, -4.983, 12.283},
                non{};
        
        assert(solve_sle(sle_1) == sol_1);
        assert(solve_sle(sle_2) == sol_2);
        assert(solve_sle(sle_t2) == sol_t2);
        assert(solve_sle(sle_t3) == sol_t3);
        assert(solve_sle(sle_qadr) == sol_qadr);
        assert(solve_sle(sle_infSol) == non);
        assert(solve_sle(sle_nonSol) == non);
        
        std::cout << " --Test of solver linear system successful complete!" << std::endl;
    }

bool test::operator==(const std::vector<double> &v1,
                      const std::vector<double> &v2)
    {
        if (v1.size() != v2.size())
        { return false; }
        else
        {
            bool is_eq = true;
            for (int i = 0; i < v1.size(); ++i)
            {
                if (is_eq)
                {
                    if (std::abs(v1[i] - v2[i]) > 0.001)
                    {
                        is_eq = false;
                    }
                }
                else
                    return false;
            }
            return true;
        }
    }