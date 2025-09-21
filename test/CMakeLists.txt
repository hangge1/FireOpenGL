

file(GLOB_RECURSE TEST_SOURCES "*.cpp")
add_executable(test_main ${TEST_SOURCES})
target_link_libraries(test_main PRIVATE gtest glfw glad)
add_test(NAME test_main COMMAND test_main)