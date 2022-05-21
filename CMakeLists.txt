cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

project(system_prog C)

set(CMAKE_BUILD_TYPE Debug)
set(EXECUTABLE_OUTPUT_PATH "../bin")

set(INCLUDE_DIRS src/lib)
set(EXERCISES_DIRS src/exercises)

# test libs
set(TEST_LIBS ${INCLUDE_DIRS}/test.c)
add_library(test SHARED ${TEST_LIBS})

add_executable(mmap src/mmap.c)

add_executable(main src/main.c)
target_include_directories(main PUBLIC ${INCLUDE_DIRS})
target_link_libraries(main PUBLIC test)

set(IO_LIBS ${INCLUDE_DIRS}/error_functions.c ${INCLUDE_DIRS}/get_num.c)
add_library(io SHARED ${IO_LIBS})

add_executable(large_file ${EXERCISES_DIRS}/large_file.c)
target_include_directories(large_file PUBLIC ${INCLUDE_DIRS})
target_link_libraries(large_file PUBLIC io)

add_executable(ex5_2 ${EXERCISES_DIRS}/ex5_2.c)

