cmake_minimum_required(VERSION 3.12)

project(pidc C)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

add_subdirectory(src)
if (${PIDC_WITH_TESTS})
    add_subdirectory(test)
    add_subdirectory(unity)
endif()
