cmake_minimum_required(VERSION 3.23)
project(cpp_square_lab3)

set(CMAKE_CXX_STANDARD 14)

add_executable(cpp_square_lab3 main.cpp src/App.cpp src/App.h src/Service/ConsoleDisplayService.cpp src/Service/ConsoleDisplayService.h src/Service/DisplayServiceInterface.h src/Service/FileService.cpp src/Service/FileService.h src/Geometry/Square.cpp src/Geometry/Square.h src/Service/ExceptionService.h)
