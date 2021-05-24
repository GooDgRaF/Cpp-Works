//
// Created by Антон on 24.05.2021.
//

#include <iostream>
#include "Solver.h"
#include "Recursive_determinant.h"

const matrix_double &replace_column(matrix_double &mat, const std::vector<double> &right_column, int column);

using namespace std;

std::vector<double> solve_sle(const SLEquation &sle)
    {
        double main_det = det_by_first_row(sle.coefficientMatrix);
        
        if (abs(main_det) < 0.000001)
        {
            return {};
        }
        
        vector<double> solution;
        solution.resize(sle.right_column.size());
        
        
        for (int i = 0; i < sle.coefficientMatrix.size(); ++i)
        {
            matrix_double mat = sle.coefficientMatrix;
            double det = det_by_first_row(replace_column(mat, sle.right_column, i));
            solution[i] = det/main_det;
        }
        
        return solution;
    }

const matrix_double &replace_column(matrix_double &mat, const vector<double> &right_column, int column)
    {
        for (int i = 0; i < mat.size(); ++i)
        {
            for (int j = 0; j < mat.size(); ++j)
            {
                if (j == column)
                {
                    mat[i][j] = right_column[i];
                }
            }
        }
        return mat;
    }
