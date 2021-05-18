cmake_minimum_required(VERSION 3.19)
project(String_qSort)

set(CMAKE_CXX_STANDARD 20)

add_executable(String_qSort main.cpp Menu.cpp Menu.h Test.cpp Test.h
         TinyXML/tinystr.h TinyXML/tinystr.cpp TinyXML/tinyxml.h TinyXML/tinyxml.cpp TinyXML/tinyxmlerror.cpp TinyXML/tinyxmlparser.cpp Mass_task.cpp Mass_task.h QSort.cpp QSort.h)