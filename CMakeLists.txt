cmake_minimum_required(VERSION 4.0)
project(pandasregexcpp)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
FetchContent_Declare(
        pybind11
        GIT_REPOSITORY https://github.com/pybind/pybind11
        GIT_TAG v3.0.1
)
FetchContent_MakeAvailable(pybind11)
pybind11_add_module(pandasregexcpp library.cpp)