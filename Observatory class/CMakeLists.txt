cmake_minimum_required(VERSION 3.17)
project(Observatory_class)

set(CMAKE_CXX_STANDARD 14)

add_executable(Observatory_class main.cpp AEvent.cpp AEvent.h ADistance.cpp ADistance.h AEventCart.cpp AEventCart.h AEventSph.cpp AEventSph.h AAggr.cpp AAggr.h)