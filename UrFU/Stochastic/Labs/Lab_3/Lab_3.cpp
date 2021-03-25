//
// Created by Антон on 25.03.2021.
//

#include <sstream>
#include "Lab_3.h"
#include "../Randomize.h"
#include "../Write_functions.h"

double method12(std::mt19937 &engine);

double box_mueller(std::mt19937 &engine);

double normal(std::mt19937 &engine);


void do_lab_3(std::mt19937 &engine)
    {
//Выборки:
        {
            std::vector<int> N_set;
            for (int N = 10e3; N < 10e6; N *= 10)
            {
                N_set.push_back(N);
                {
                    std::vector<double> sample12 = {}, sample_box_mueller = {}, sample_normal = {};
                    sample12.reserve(N);
                    sample_box_mueller.reserve(N);
                    sample_normal.reserve(N);
                    for (int i = 0; i < N; ++i)
                    {
                        sample12.push_back(method12(engine));
                        sample_box_mueller.push_back(box_mueller(engine));
                        sample_normal.push_back(normal(engine));
                    }

                    std::ostringstream N_str;
                    N_str << N; // Превратили число в поток, из которого вытащим строку потом

                    std::string path_out("../Lab_3/data/Source/sample12_" + N_str.str() + ".txt");
                    write_vector_in_file(sample12, path_out);

                    path_out = "../Lab_3/data/Source/sampleBM_" + N_str.str() + ".txt";
                    write_vector_in_file(sample_box_mueller, path_out);

                    path_out = "../Lab_3/data/Source/sampleNormal_" + N_str.str() + ".txt";
                    write_vector_in_file(sample_normal, path_out);
                }
            }
        }

    }

double method12(std::mt19937 &engine)
    {
        double x = 0;
        std::uniform_real_distribution<double> urd(0, 1);
        for (int i = 0; i < 12; ++i)
        {
            x += (urd(engine) - 0.5);
        }
        return x;
    }

double box_mueller(std::mt19937 &engine)
    {
        std::uniform_real_distribution<double> urd(0, 1);
        double a = urd(engine), b = urd(engine);
        double x = sqrt(-2 * log(a)) * cos(2 * M_PI * b);
        return x;
    }

double normal(std::mt19937 &engine)
    {
        std::normal_distribution<double> normalDistribution(0, 1);
        return normalDistribution(engine);
    }
