cmake_minimum_required(VERSION 3.19)
project(Recursive_determinant)

set(CMAKE_CXX_STANDARD 20)

add_executable(Recursive_determinant main.cpp
        TinyXML/tinystr.h TinyXML/tinystr.cpp TinyXML/tinyxml.h TinyXML/tinyxml.cpp TinyXML/tinyxmlerror.cpp TinyXML/tinyxmlparser.cpp
        Read_and_prepare_data.cpp Read_and_prepare_data.h Recursive_determinant.cpp Recursive_determinant.h Test.cpp Test.h)