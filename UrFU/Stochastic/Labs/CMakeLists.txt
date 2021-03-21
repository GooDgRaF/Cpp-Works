cmake_minimum_required(VERSION 3.17)
project(Laba1)

set(CMAKE_CXX_STANDARD 14)

add_executable(Laba1 main.cpp "Calc Expectation, Variance and Covariance.cpp"
        "Calc Expectation, Variance and Covariance.h"
        Randomize.cpp Randomize.h Lab_1/Lab_1.cpp Lab_1/Lab_1.h Lab_2/Lab_2.cpp Lab_2/Lab_2.h
        Write_functions.h Write_functions.cpp)