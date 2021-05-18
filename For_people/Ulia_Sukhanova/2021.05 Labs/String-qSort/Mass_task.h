//
// Created by Антон on 17.05.2021.
//

#ifndef STRING_QSORT_MASS_TASK_H
#define STRING_QSORT_MASS_TASK_H

#include <string>
#include <vector>
#include "QSort.h"

struct Progression
{
    std::string title;
    int minElem{0};
    int maxElem{0};
    int startLen{0};
    int maxLen{0};
    int repeat{0};
};

struct Arithmetic_progression : Progression
{
    int diff{0};
};

struct Geometric_progression : Progression
{
    double znam{0};
};

struct Experiment
{
    std::string name;
    Arithmetic_progression arith;
    Geometric_progression geom;

    std::vector<v_str> a_mt;//mass task
    std::vector<v_str> g_mt;
private:
    void fill_mt();

    void fill_a_mt();
};

Experiment read_from_XML(const std::string &xml_path);

void do_mass_task();





#endif //STRING_QSORT_MASS_TASK_H
