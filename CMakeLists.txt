cmake_minimum_required(VERSION 3.20.1)

project(3DGE)

add_definitions(
	-c
	-Wall
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SOURCES "source/*.cpp")
add_executable(${PROJECT_NAME} ${SOURCES})

SET(3DGameEngine_CMAKE_DIR "${3DGameEngine_CMAKE_DIR}/cmake")

add_subdirectory("dependencies/stb_image")
add_subdirectory("dependencies/tiny_obj_loader")

find_package(glfw3 3.3 REQUIRED)
find_package(GLEW REQUIRED)
find_package(OpenGL REQUIRED)
find_package(glm REQUIRED)

include_directories(
  "include"
  "dependencies"
  ${OPENGL_INCLUDE_DIRS} 
  ${GLEW_INCLUDE_DIRS}
  ${GLM_INCLUDE_DIRS}
)

target_link_libraries(3DGE 
  glfw 
  stb_image
  tiny_obj_loader
  ${OPENGL_LIBRARIES}
  ${GLEW_LIBRARIES}
  ${GLM_LIBRARIES}
)