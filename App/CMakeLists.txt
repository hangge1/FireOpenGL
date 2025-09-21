

set(SOURCES main.cpp)

add_executable(FireOpenGL)
target_sources(FireOpenGL PRIVATE ${SOURCES})

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${SOURCES})

target_link_libraries(FireOpenGL PRIVATE glfw)
target_link_libraries(FireOpenGL PRIVATE glad)
target_link_libraries(FireOpenGL PRIVATE spdlog)

set_target_properties(FireOpenGL PROPERTIES
    VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/App"
)