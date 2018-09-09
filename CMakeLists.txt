cmake_minimum_required(VERSION 3.12)
project(TestRunner)

set(CMAKE_CXX_STANDARD 14)

add_executable(TestRunner src/main.cpp src/LabelDataLine.cpp include/LabelDataLine.h src/LabelDataFile.cpp include/LabelDataFile.h src/Parser.cpp include/Parser.h)