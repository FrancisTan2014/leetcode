add_library(0340-longest-substring-with-at-most-k-distinct-characters_lib OBJECT solution.cpp)

add_executable(test_0340-longest-substring-with-at-most-k-distinct-characters tests/test_0340-longest-substring-with-at-most-k-distinct-characters.cpp $<TARGET_OBJECTS:0340-longest-substring-with-at-most-k-distinct-characters_lib>)
target_link_libraries(test_0340-longest-substring-with-at-most-k-distinct-characters GTest::gtest_main)
gtest_discover_tests(test_0340-longest-substring-with-at-most-k-distinct-characters)
