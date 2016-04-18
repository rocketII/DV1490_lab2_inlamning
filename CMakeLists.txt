cmake_minimum_required(VERSION 3.3)
project(inlamning1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES  IQueue.h   Queue.h testQueue_oneStepAtaTime.cpp) #TestFunctionalityOfQueue.cpp TestDeepCopyingOfQueue.cpp
add_executable(inlamning1 ${SOURCE_FILES})
# set: ICircularDoubleDirectedList.h JosephusProblem.cpp TestDeepCopyingOfList.cpp TestFunctionalityOfList.cpp CircularDoubleDirectedList.cpp CircularDoubleDirectedList.h