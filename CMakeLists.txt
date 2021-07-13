cmake_minimum_required(VERSION 3.15)
project(trabalhoEstruturaDeDados2)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-g")
SET(CMAKE_CXX_COMPILER clang++)

add_executable(trabalhoEstruturaDeDados2 main.cpp Artist.cpp Track.cpp)

