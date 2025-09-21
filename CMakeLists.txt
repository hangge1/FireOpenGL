
cmake_minimum_required(VERSION 3.26)

project(FireOpenGL)

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

include(Dependencies.cmake)

#add_subdirectory(Core)
add_subdirectory(App)


if(BUILD_TESTS)
    add_subdirectory(test)
endif()