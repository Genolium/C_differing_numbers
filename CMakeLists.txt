cmake_minimum_required(VERSION 3.26)
project(task53 C)

set(CMAKE_C_STANDARD 11)

add_executable(task53 main.c)

add_library(matrix_operations STATIC IMPORTED)
set_target_properties(matrix_operations PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/lib/matrixlib.a)
add_library(static_operations STATIC IMPORTED)
set_target_properties(static_operations PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/lib/staticlib.a)

target_link_libraries(task53 matrix_operations)
target_link_libraries(task53 static_operations)