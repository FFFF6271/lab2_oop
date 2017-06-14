cmake_minimum_required(VERSION 3.6)
project(l2_oop)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp lib/vectorina.h lib/vectorina_base.cpp lib/vectorina_base.h lib/vectorina_exception.cpp lib/vectorina_exception.h lib/lib_mem.cpp lib/lib_mem.h lib/vectorina_iterbase.cpp lib/vectorina_iterbase.h lib/vectorina_iter.cpp lib/vectorina_iter.h)
add_executable(l2_oop ${SOURCE_FILES})