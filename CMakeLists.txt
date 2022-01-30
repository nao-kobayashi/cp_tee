cmake_minimum_required(VERSION 3.21)
project(cp_tee)

set(CMAKE_CXX_STANDARD 17)

add_executable(cp_tee main.cpp WriterBase.h StdOutWriter.cpp StdOutWriter.h FileWriter.cpp FileWriter.h)
