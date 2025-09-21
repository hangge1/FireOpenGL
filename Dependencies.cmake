

option(BUILD_TESTS "Build the tests" ON)
if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(submodule/googletest)
endif()

add_subdirectory(submodule/spdlog)
add_subdirectory(submodule/glfw)
add_subdirectory(submodule/glm)
add_subdirectory(submodule/glad/cmake)

set(GLAD_NAME glad_lib)
glad_add_library(${GLAD_NAME} STATIC API gl:core=3.3)

#build gl.h + gl.c -> glad
set(GL_HEADER_FILE ${CMAKE_BINARY_DIR}/gladsources/${GLAD_NAME}/include/glad/gl.h)
set(GL_SOURCE_FILE ${CMAKE_BINARY_DIR}/gladsources/${GLAD_NAME}/src/gl.c)
add_library(glad STATIC ${GL_SOURCE_FILE} ${GL_HEADER_FILE})
target_include_directories(glad PUBLIC ${CMAKE_BINARY_DIR}/gladsources/${GLAD_NAME}/include)
