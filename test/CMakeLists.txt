

file(GLOB_RECURSE TEST_SOURCES "*.cpp")
add_executable(test_main ${TEST_SOURCES})
target_link_libraries(test_main Core gtest)


include(GoogleTest)
gtest_discover_tests(test_main)