cmake_minimum_required(VERSION 3.7)

add_definitions(-std=c++17)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

project(HelloWorld)

add_executable(HelloWorld src/main.cpp src/Cell.cc src/Cell.h src/Board.cc src/Board.h src/Position.h src/Game.cc src/Game.h src/Move.h src/Player.h src/Player.cpp src/UI/UI.cpp src/UI/UI.h src/UI/Console/ConsoleUI.cpp src/UI/Console/ConsoleUI.h)
