cmake_minimum_required(VERSION 3.17)
project(Laba1)

set(CMAKE_CXX_STANDARD 14)

add_executable(Laba1 main.cpp "Support/Calc_Expectation_Variance_Covariance.cpp"
        "Support/Calc_Expectation_Variance_Covariance.h"
        Support/Randomize.cpp Support/Randomize.h Lab_1/Lab_1.cpp Lab_1/Lab_1.h Lab_2/Lab_2.cpp Lab_2/Lab_2.h
        Support/Write_functions.h Support/Write_functions.cpp Lab_3/Lab_3.cpp Lab_3/Lab_3.h Support/Random_engine.cpp Support/Random_engine.h Lab_4/Lab_4.cpp Lab_4/Lab_4.h)