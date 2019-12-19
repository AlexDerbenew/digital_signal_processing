cmake_minimum_required(VERSION 3.14)
project(dsp)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS -Wall)

set(INCLUDE_DIRECTORIES
        include/AmpDetector/
        include/Generator/
        include/)

set(INCLUDES
        include/AmpDetector/AmpDetector.hpp
        include/Generator/FunctionParameters.hpp
        include/Generator/Generator.hpp
        include/cxxopts.hpp
        include/graph.hpp
        include/point.hpp include/FloatingAverage/FloatingAverage.h include/KFilter/KFilter.h)

set(SOURCES
        main.cpp
        src/AmpDetector/AmpDetector.cpp
        src/Generator/Generator.cpp src/FloatingAverage/FloatingAverage.cpp src/KFilter/KFilter.cpp)

add_executable(dsp ${INCLUDES} ${SOURCES})