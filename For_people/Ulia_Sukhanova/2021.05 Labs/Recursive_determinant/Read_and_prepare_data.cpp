//
// Created by Антон on 21.05.2021.
//

#include <sstream>
#include <iostream>
#include "TinyXML/tinyxml.h"
#include "Read_and_prepare_data.h"

using namespace std;

void read_XML()
    {
        TiXmlDocument doc("Det.xml");
        if (!doc.LoadFile())
            exit(-1);
        
        TiXmlElement *ptr_data_lab_4 = doc.FirstChildElement("data");

//        //////////////////////// MATRIX
        {
            TiXmlElement *ptr_matrix = ptr_data_lab_4->FirstChildElement("matrix");
            
            size_t matrix_size = stoi({ptr_matrix->Attribute("size")});
            string line_matrix = ptr_matrix->GetText();
            auto KUDATO = create_matrix_from_string(matrix_size, matrix_size, line_matrix);
        }


//        //////////////////////// Redheffer
        
        {
            TiXmlElement *ptr_Redheffer = ptr_data_lab_4->FirstChildElement("Redheffer");
            
            size_t Redheffer_size = stoi({ptr_Redheffer->Attribute("size")});
            auto KUDATOTO = create_mRedheffer(Redheffer_size);
        }

//        //////////////////////// Cramer
        
        {
            TiXmlElement *ptr_Cramer = ptr_data_lab_4->FirstChildElement("Cramer");
            size_t matrix_size = stoi({ptr_Cramer->Attribute("size")});
            
            TiXmlElement *ptr_coefficient_matrix = ptr_Cramer->FirstChildElement("coefficients");
            TiXmlElement *ptr_right_column = ptr_Cramer->FirstChildElement("right_column");
            
            string line_coefficient_matrix = ptr_coefficient_matrix->GetText();
            string line_right_column_transpose = ptr_right_column->GetText();
            
            auto AKLAKKLAKLA = create_matrix_from_string(matrix_size, matrix_size, line_coefficient_matrix);
            auto KHASGN = create_matrix_from_string(matrix_size, 1, line_right_column_transpose);
        }
    }

matrix_double create_matrix_from_string(size_t row_size, size_t column_size, const string &str)
    {
        matrix_double matrix;
        matrix.resize(row_size);
        for (auto &row : matrix)
        {
            row.resize(column_size);
        }
        
        stringstream ss(str);
        for (int row = 0; row < row_size; ++row)
        {
            for (int col = 0; col < column_size; ++col)
            {
                
                ss >> matrix[row][col];
            }
        }
        return matrix;
    }

matrix_double create_mRedheffer(size_t size)
    {
        matrix_double mRedheffer;
        
        mRedheffer.resize(size);
        for (auto &row : mRedheffer)
        {
            row.resize(size);
        }
        
        for (int row = 0; row < size; ++row)
        {
            for (int col = 0; col < size; ++col)
            {
                if (col == 0)
                {
                    mRedheffer[row][0] = 1;
                }
                else
                {
                    if ((col + 1)%(row + 1) == 0)
                    {
                        mRedheffer[row][col] = 1;
                    }
                }
            }
        }
        show_matrix(mRedheffer);
        return mRedheffer;
    }

void show_matrix(matrix_double &m)
    {
        for (const auto &row: m)
        {
            for (auto el: row)
            {
                cout << el << " ";
            }
            cout << endl;
        }
    }
