cmake_minimum_required(VERSION 3.14)
project(Rx)

set(CMAKE_CXX_STANDARD 14)

add_executable(Rx main.cpp FileReceiver.cpp FileReceiver.h CustomFrame.cpp CustomFrame.h BasicFrame.cpp BasicFrame.h)