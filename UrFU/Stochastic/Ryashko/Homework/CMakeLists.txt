cmake_minimum_required(VERSION 3.19)
project(Homework)

set(CMAKE_CXX_STANDARD 20)

add_executable(Homework main.cpp Support/Random_engine.h
        Support/Random_engine.cpp Distributions_test/Uniform.cpp Distributions_test/Uniform.h
        Support/Calc_Expectation_Variance_Covariance.h Support/Calc_Expectation_Variance_Covariance.cpp
        Support/Write_functions.h Distributions_test/Normal.cpp Distributions_test/Normal.h Model_equation/Calc_model_eq.cpp Model_equation/Calc_model_eq.h Model_equation/calc_trajectory_for_hist.cpp Model_equation/calc_trajectory_for_hist.h KW_equation/Calc_eq.cpp KW_equation/Calc_eq.h KW_equation/Calc_trj_for_hist.cpp KW_equation/Calc_trj_for_hist.h)