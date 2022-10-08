cmake_minimum_required(VERSION 3.22)

file(GLOB_RECURSE TARGET_SOURCE *.cpp)
file(GLOB_RECURSE TARGET_HEADER *.hpp)

set(TARGET_NAME "Gospel.Builder")

set(CMAKE_CXX_STANDARD 20)

add_executable(${TARGET_NAME} ${TARGET_HEADER} ${TARGET_SOURCE})

target_include_directories(${TARGET_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/../")
target_link_libraries(${TARGET_NAME} PRIVATE Gospel.Language)

find_package(TBB)
target_link_libraries(${TARGET_NAME} PRIVATE TBB::tbb)
