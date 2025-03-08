cmake_minimum_required(VERSION 3.5.0)
project(TinyWasmJIT VERSION 0.1.0 LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 17)

# set(CMAKE_POSITION_INDEPENDENT_CODE ON)
message( STATUS "Current system is :  ${CMAKE_SYSTEM_NAME}.")

set(CMAKE_CXX_CLANG_TIDY clang-tidy --config-file ${CMAKE_CURRENT_LIST_DIR}/.clang-tidy "--header-filter=${CMAKE_CURRENT_LIST_DIR}/(src|tests)/.*")

enable_testing()
add_subdirectory(./src)
add_subdirectory(./test)
