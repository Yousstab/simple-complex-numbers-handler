cmake_minimum_required(VERSION 3.30)
project(complexnumbershandler C)

set(CMAKE_C_STANDARD 11)
add_executable(complexnumbershandler main.c complexFunctionsLib.c mathUtil.c)
