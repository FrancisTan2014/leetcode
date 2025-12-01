add_library(0424-longest-repeating-character-replacement_lib OBJECT solution.cpp)

add_executable(test_0424-longest-repeating-character-replacement tests/test_0424-longest-repeating-character-replacement.cpp $<TARGET_OBJECTS:0424-longest-repeating-character-replacement_lib>)
target_link_libraries(test_0424-longest-repeating-character-replacement GTest::gtest_main)
gtest_discover_tests(test_0424-longest-repeating-character-replacement)
