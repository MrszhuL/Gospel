cmake_minimum_required(VERSION 3.22)

file(GLOB_RECURSE TARGET_SOURCE *.cpp)
file(GLOB_RECURSE TARGET_HEADER *.hpp)

set(TARGET_NAME "Gospel.Compiler")

set(CMAKE_CXX_STANDARD 17)

add_executable(${TARGET_NAME} ${TARGET_HEADER} ${TARGET_SOURCE})

target_include_directories(${TARGET_NAME} PRIVATE ../)
target_link_libraries(${TARGET_NAME} PRIVATE Gospel.Language)

find_package(TBB)
target_link_libraries(${TARGET_NAME} PRIVATE TBB::tbb)
