
file(GLOB_RECURSE SOURCES "*.cpp" "*.h")

add_library(Core STATIC)

target_sources(Core PRIVATE ${SOURCES})

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${SOURCES})

add_compile_definitions(
    GLFW_INCLUDE_NONE
)

set(Link_Libs glfw glad spdlog glm)

target_link_libraries(Core ${Link_Libs})

target_include_directories(Core PUBLIC "Source" "vendor/stb" .)