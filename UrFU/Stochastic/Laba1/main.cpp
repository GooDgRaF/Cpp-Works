#include <iostream>
#include "Randomize.h"
#include "Calc Expectation and Variance.h"


int main()
    {
        int N = 10000;
        std::vector<double> sample, sample_Mer;
// 1) Выборка:
        get_rand(N, sample);
        get_rand_Mersenne_Twister(N, sample_Mer);
// 2) Матожидание и Дисперсия:
        double E, E_Mer, V, V_Mer;
        E = calc_uniform_Expectation(sample);
        E_Mer = calc_uniform_Expectation(sample_Mer);

        V = calc_uniform_Variance(sample);
        V_Mer = calc_uniform_Variance(sample_Mer);
        //TODO Автоматизировать по N и сохранить в файл
// 3) Гистограммы
// 4а) Две выборки
// 4б) Чётная и Нечётная части выборки

        return 0;

    }