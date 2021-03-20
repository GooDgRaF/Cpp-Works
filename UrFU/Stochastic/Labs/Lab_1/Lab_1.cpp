//
// Created by Антон on 20.03.2021.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include "../Randomize.h"
#include "../Lab_1/Calc Expectation, Variance and Covariance.h"


void
write_data_sets(const std::vector<double> &E_set, const std::vector<double> &E_Mer_set, const std::vector<double> &V_set,
                const std::vector<double> &V_Mer_set, const std::vector<double> &N_set,
                const std::vector<double> &Cor_set, const std::vector<double> &Cor_Mer_set,
                const std::vector<double> &Cor2N_set, const std::vector<double> &Cor2N_Mer_set);

void write_vector_in_file(const std::vector<double> &v, const std::string &path)
    {
        std::ofstream out(path, std::ios::app);
        if (out.fail())
        {
            std::cerr << "Can't reach or open file from this path: " << path << std::endl;
            exit(-1);
        }
        for (auto item : v)
        {
            out << item << " ";
        }
        out << '\n';
        out.close();
    }

void write_two_vectors(const std::string &path, const std::vector<double> &data_set, const std::vector<double> &N_set)
    {
        std::ofstream out(path);
        out.close();

        write_vector_in_file(N_set, path);
        write_vector_in_file(data_set, path);
    }

void do_lab_1()
    {
        std::vector<double> E_set, E_Mer_set, V_set, V_Mer_set, N_set,
                Cor_set, Cor_Mer_set, Cor2N_set, Cor2N_Mer_set,
                histogram_set, inaccuracy_set;
        for (int N = 10; N < 10e5; N *= 10)
        {
            N_set.push_back(N);
            {
                std::vector<double> sample, sample_Mer;
// 1) Выборка:
                get_rand(N, sample);
                get_rand_Mersenne_Twister(N, sample_Mer);

                std::ostringstream N_str;
                N_str << N; // Превратили число в поток, из которого вытащим строку потом


                std::string path_out("../Lab_1/data/Source_data/" + N_str.str() + ".txt");
                std::string path_out_Mer("../Lab_1/data/Source_data/Mer" + N_str.str() + ".txt");

                write_vector_in_file(sample, path_out);
                write_vector_in_file(sample_Mer, path_out_Mer);

// 2) Матожидание и Дисперсия:
                E_set.push_back(calc_Expectation(sample));
                E_Mer_set.push_back(calc_Expectation(sample_Mer));
                V_set.push_back(calc_Variance(sample));
                V_Mer_set.push_back(calc_Variance(sample_Mer));
            }


// 3) Гистограммы
            {
                //TODO отсортировать вектор sample и sample_Mer для каждого N и наклепать данные для гистограмм


            }
// Две выборки и их корреляция
// 4а) Две отдельных выборки
            {
                std::vector<double> sample_1, sample_2, sample_Mer_1, sample_Mer_2;

                get_rand(N, sample_1);
                get_rand(N, sample_2);
                get_rand_Mersenne_Twister(N, sample_Mer_1);
                get_rand_Mersenne_Twister(N, sample_Mer_2);

                Cor_set.push_back(calc_Correlation(sample_1, sample_2));
                Cor_Mer_set.push_back(calc_Correlation(sample_Mer_1, sample_Mer_2));
            }
// 4б) Чётная и Нечётная части одной выборки
            {
                std::vector<double> sample2N, sample2N_Mer, sampleOdd, sampleEven, sampleOdd_Mer, sampleEven_Mer;
                get_rand(2 * N, sample2N);
                get_rand_Mersenne_Twister(2 * N, sample2N_Mer);
                sampleEven.reserve(sample2N.size() / 2);
                sampleOdd_Mer.reserve(sample2N.size() / 2);
                sampleOdd.reserve(sample2N.size() / 2);
                sampleEven_Mer.reserve(sample2N.size() / 2);

                for (int i = 0; i < sample2N.size(); ++i)
                {
                    if (i % 2 == 0)
                    {
                        sampleEven.push_back(sample2N[i]);
                        sampleEven_Mer.push_back(sample2N_Mer[i]);
                    }
                    else
                    {
                        sampleOdd.push_back(sample2N[i]);
                        sampleOdd_Mer.push_back(sample2N_Mer[i]);
                    }
                }

                Cor2N_set.push_back(calc_Correlation(sampleOdd, sampleEven));
                Cor2N_Mer_set.push_back(calc_Correlation(sampleOdd_Mer, sampleEven_Mer));

            }
        }
        write_data_sets(E_set, E_Mer_set, V_set, V_Mer_set, N_set, Cor_set, Cor_Mer_set, Cor2N_set, Cor2N_Mer_set);


    }

void
write_data_sets(const std::vector<double> &E_set, const std::vector<double> &E_Mer_set, const std::vector<double> &V_set,
                const std::vector<double> &V_Mer_set, const std::vector<double> &N_set,
                const std::vector<double> &Cor_set, const std::vector<double> &Cor_Mer_set,
                const std::vector<double> &Cor2N_set, const std::vector<double> &Cor2N_Mer_set)
    {
        std::string path = "../Lab_1/data/E.txt";
        write_two_vectors(path, E_set, N_set);

        path = "../Lab_1/data/E_Mer.txt";
        write_two_vectors(path, E_Mer_set, N_set);

        path = "../Lab_1/data/V.txt";
        write_two_vectors(path, V_set, N_set);

        path = "../Lab_1/data/V_Mer.txt";
        write_two_vectors(path, V_Mer_set, N_set);

        path = "../Lab_1/data/Cor.txt";
        write_two_vectors(path, Cor_set, N_set);

        path = "../Lab_1/data/Cor_Mer.txt";
        write_two_vectors(path, Cor_Mer_set, N_set);

        path = "../Lab_1/data/Cor2N.txt";
        write_two_vectors(path, Cor2N_set, N_set);

        path = "../Lab_1/data/Cor2N_Mer.txt";
        write_two_vectors(path, Cor2N_Mer_set, N_set);
    }
