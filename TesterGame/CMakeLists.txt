cmake_minimum_required(VERSION 3.20.1)

project(GenericGame)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SOURCES "source/*.cpp")
add_executable(${PROJECT_NAME} ${SOURCES})

add_subdirectory("../3DGE" "build")

include_directories(
  "include"
  "../3DGE/include"
  "../3DGE/dependencies"
)

target_link_libraries(GenericGame
  3DGE
)