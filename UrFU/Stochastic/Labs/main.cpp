#include <iostream>
#include <chrono>
#include <random>
#include "Lab_1/Lab_1.h"
#include "Lab_2/Lab_2.h"


int main()
    {
        auto now = std::chrono::high_resolution_clock::now();
        std::mt19937 random_generator(now.time_since_epoch().count());


        //do_lab_1(random_generator);
        do_lab_2(random_generator);
        return 0;

    }

