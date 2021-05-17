//
// Created by Антон on 17.05.2021.
//

#ifndef STRING_QSORT_MASS_TASK_H
#define STRING_QSORT_MASS_TASK_H

#include <string>

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
};

Experiment read_from_XML(const std::string &xml_path);

void do_mass_task();


#endif //STRING_QSORT_MASS_TASK_H
