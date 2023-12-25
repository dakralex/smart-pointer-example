cmake_minimum_required(VERSION 3.10)
project(pr2_smart_pointer LANGUAGES CXX)

include(CTest)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -Wextra -pedantic-errors -fsanitize=address -fsanitize=undefined -fno-sanitize-recover=all -Wno-unused-variable")

include_directories(include)

add_executable(pr2_smart_pointer src/main.cpp
        src/illness.cpp
        src/patient.cpp
        src/hcp.cpp
        src/hospital.cpp)
