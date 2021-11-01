cmake_minimum_required(VERSION 3.20.1)

project(3DGE)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)
file(GLOB_RECURSE SOURCES "source/*.cpp")
add_executable(${PROJECT_NAME} ${SOURCES})

find_package(glfw3 3.3 REQUIRED)
target_link_libraries(3DGE glfw)