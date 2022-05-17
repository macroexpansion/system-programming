cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

project(system_prog C)

set(EXECUTABLE_OUTPUT_PATH "../bin")

set(INCLUDE_DIRS src/lib)
set(LIBS ${INCLUDE_DIRS}/test.c)

add_library(sysprog SHARED ${LIBS})

add_executable(main src/main.c)
target_include_directories(main PUBLIC ${INCLUDE_DIRS})
target_link_libraries(main PUBLIC sysprog)

# add_executable(large_file src/large_file.c)
