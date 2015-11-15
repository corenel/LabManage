cmake_minimum_required(VERSION 3.3)
project(LabManage)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp ValidInfo.cpp ValidInfo.h Member.cpp Member.h Project.cpp Project.h)

add_executable(LabManage ${SOURCE_FILES})