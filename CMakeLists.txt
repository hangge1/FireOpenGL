
cmake_minimum_required(VERSION 3.26)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(submodule/glfw)
add_subdirectory(submodule/glad/cmake)

set(GLAD_NAME glad_lib)
glad_add_library(${GLAD_NAME} STATIC API gl:core=3.3)

project(FireOpenGL)
add_executable(FireOpenGL)


#get gl.c
set(GL_SOURCE_FILE ${CMAKE_BINARY_DIR}/gladsources/${GLAD_NAME}/src/gl.c)

target_sources(FireOpenGL PRIVATE main.cpp ${GL_SOURCE_FILE})

target_link_libraries(FireOpenGL PRIVATE glfw)
target_link_libraries(FireOpenGL PRIVATE ${GLAD_NAME})

#target_include_directories(FireOpenGL PRIVATE ${CMAKE_BINARY_DIR}/gladsources/${GLAD_NAME}/include)

