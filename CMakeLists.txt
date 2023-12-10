cmake_minimum_required(VERSION 3.27)
project(advent_of_code)

set(CMAKE_CXX_STANDARD 17)

#add_library(advent_of_code_lib SHARED src/common.cpp include/advent_of_code/common.h )


add_executable(advent_of_code
        src/main.cpp
        src/day1.cpp
        src/day2.cpp
        src/common.cpp
)
target_include_directories(advent_of_code PUBLIC include)

#target_link_libraries(advent_of_code PUBLIC advent_of_code_lib)