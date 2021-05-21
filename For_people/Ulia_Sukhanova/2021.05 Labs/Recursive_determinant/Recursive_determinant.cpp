//
// Created by Антон on 21.05.2021.
//

#include "Recursive_determinant.h"
#include "cmath"

using namespace std;

double det_by_first_row(const matrix_double &m)
    {
        if (m.size() == 1)
        { return m[0][0]; }
        
        matrix_double minor;
        minor.resize(m.size() - 1);
        for (auto &row: minor)
        {
            row.resize(m.size() - 1);
        }
        
        double det_m = 0;
        for (int i = 0; i < m.size(); ++i) //O(n) * O((n-1)^2)
        {
            for (int row = 0; row < minor.size(); ++row) //O((n-1)^2)
            {
                for (int col = 0; col < minor.size(); ++col)
                {
                    if (i > col)
                    { minor[row][col] = m[row + 1][col]; }
                    else
                    { minor[row][col] = m[row + 1][col + 1]; }
                }
            }
            det_m += pow(-1, i)*m[0][i]*det_by_first_row(minor);// T(n) = n*((n-1)^2 * T(n - 1)) ~~ (n^2)!
        }
        return det_m;
    }