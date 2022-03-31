cmake_minimum_required(VERSION 3.21)
project(Chart_World)
set(CMAKE_CXX_STANDARD 23)
add_executable(Chart_World Cpp/main.cpp Cpp/TApplication.cpp Headers/TApplication.h Headers/main.h)

set (SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR D:/Dev/SFML/SFML_2.5.1/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(D:/Dev/SFML/SFML_2.5.1/include)
target_link_libraries(Chart_World sfml-window sfml-system sfml-graphics sfml-audio)