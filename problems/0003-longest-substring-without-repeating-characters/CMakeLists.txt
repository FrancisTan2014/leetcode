add_library(0003-longest-substring-without-repeating-characters_lib OBJECT solution.cpp)

add_executable(test_0003-longest-substring-without-repeating-characters tests/test_0003-longest-substring-without-repeating-characters.cpp $<TARGET_OBJECTS:0003-longest-substring-without-repeating-characters_lib>)
target_link_libraries(test_0003-longest-substring-without-repeating-characters GTest::gtest_main)
gtest_discover_tests(test_0003-longest-substring-without-repeating-characters)
