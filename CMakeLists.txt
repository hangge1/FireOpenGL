
cmake_minimum_required(VERSION 3.26)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#check multi config
get_property(is_multi_config GLOBAL PROPERTY GENERATOR_IS_MULTI_CONFIG)

if(NOT is_multi_config AND NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build." FORCE)
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS ${possible_build_types})
endif()

message("====CMAKE_BUILD_TYPE: ${CMAKE_BUILD_TYPE}====")
message("====is_multi_config: ${is_multi_config}====")


add_subdirectory(submodule/spdlog)
add_subdirectory(submodule/glfw)
add_subdirectory(submodule/glad/cmake)

set(GLAD_NAME glad_lib)
glad_add_library(${GLAD_NAME} STATIC API gl:core=3.3)

project(FireOpenGL)
add_executable(FireOpenGL)


#build gl.h + gl.c -> glad
set(GL_HEADER_FILE ${CMAKE_BINARY_DIR}/gladsources/${GLAD_NAME}/include/glad/gl.h)
set(GL_SOURCE_FILE ${CMAKE_BINARY_DIR}/gladsources/${GLAD_NAME}/src/gl.c)
add_library(glad STATIC ${GL_SOURCE_FILE} ${GL_HEADER_FILE})
target_include_directories(glad PUBLIC ${CMAKE_BINARY_DIR}/gladsources/${GLAD_NAME}/include)

target_sources(FireOpenGL PRIVATE main.cpp)
target_link_libraries(FireOpenGL PRIVATE glfw)
target_link_libraries(FireOpenGL PRIVATE glad)
target_link_libraries(FireOpenGL PRIVATE spdlog)


option(BUILD_TESTS "Build the tests" ON)
if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(submodule/googletest)
    add_subdirectory(test)
endif()