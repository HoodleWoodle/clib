cmake_minimum_required(VERSION 3.10)
set(CMAKE_C_STANDARD 99)

project(clib)

include_directories("./src/")

add_executable("${PROJECT_NAME}-ll-test" "./test/linked_list_test.c" "./src/linked_list.c")
add_executable("${PROJECT_NAME}-al-test" "./test/array_list_test.c" "./src/array_list.c")