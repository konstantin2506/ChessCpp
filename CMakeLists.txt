cmake_minimum_required(VERSION 3.15)
project(ChessCpp)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
file(GLOB_RECURSE SOURCES "src/*.cpp")
file(GLOB_RECURSE HEADERS "include/*.hpp")

add_executable(ChessCpp ${SOURCES} ${HEADERS})
target_include_directories(ChessCpp PRIVATE include)
target_compile_features(ChessCpp PRIVATE cxx_std_17)
