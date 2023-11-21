cmake_minimum_required(VERSION 3.10)
project(luaCIO C)

set(CMAKE_C_STANDARD 11)

add_library(luacio SHARED io.c)
set_target_properties(luacio PROPERTIES PREFIX "")
set_target_properties(luacio PROPERTIES POSITION_INDEPENDENT_CODE ON)
