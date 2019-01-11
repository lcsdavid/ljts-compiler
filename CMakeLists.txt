cmake_minimum_required(VERSION 3.11)
project(ljts_compiler)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)
include_directories(utils)
include_directories(utils/libljts)

add_executable(ljts_compiler
        utils/libljts/tree.cpp
        utils/libljts/tree.hpp
        utils/libljts/tree.tcc
        utils/abstract_syntax_tree.hpp
        utils/abstract_syntax_tree.tcc
        ljts-compiler.cpp
        ljts-compiler.hpp utils/class_struct.cpp utils/class_struct.h)
