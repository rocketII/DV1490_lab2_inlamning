cmake_minimum_required(VERSION 3.3)
project(inlamning1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES ICircularDoubleDirectedList.h IQueue.h JosephusProblem.cpp TestDeepCopyingOfList.cpp TestDeepCopyingOfQueue.cpp TestFunctionalityOfList.cpp TestFunctionalityOfQueue.cpp Queue.cpp Queue.h CircularDoubleDirectedList.cpp CircularDoubleDirectedList.h)
add_executable(inlamning1 ${SOURCE_FILES})