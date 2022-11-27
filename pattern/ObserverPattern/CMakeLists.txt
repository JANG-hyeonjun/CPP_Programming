cmake_minimum_required(VERSION 3.23)
project(ObserverPattern)

set(CMAKE_CXX_STANDARD 14)

add_executable(ObserverPattern main.cpp Person.h Observer.h Observable.h)
