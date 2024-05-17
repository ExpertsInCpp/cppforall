cmake_minimum_required(VERSION 3.1...3.29)

project(CppForAll VERSION 1.0 LANGUAGES CXX)

file(GLOB SOURCES sources/*.cpp)
add_executable(CppForAll ${SOURCES})
target_include_directories(CppForAll PRIVATE include)
target_compile_features(CppForAll PRIVATE cxx_std_17)
