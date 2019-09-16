cmake_minimum_required(VERSION 3.14)
project(Tx)

set(CMAKE_CXX_STANDARD 14)

add_executable(Tx main.cpp CustomFrame.cpp CustomFrame.h FileSender.cpp FileSender.h)