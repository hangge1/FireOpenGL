
set(SOURCES 
vendor/stb/stb_image.h
vendor/stb/stb_image.cpp
)

add_library(Core STATIC)

target_sources(Core PRIVATE ${SOURCES})

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${SOURCES})

target_link_libraries(Core glfw)
target_link_libraries(Core glad)
target_link_libraries(Core spdlog)
#target_link_libraries(Core glm)

target_include_directories(Core PUBLIC "Source" "vendor/stb")