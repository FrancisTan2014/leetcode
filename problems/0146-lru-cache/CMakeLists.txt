add_library(0146-lru-cache_lib OBJECT solution.cpp)

add_executable(test_0146-lru-cache tests/test_0146-lru-cache.cpp $<TARGET_OBJECTS:0146-lru-cache_lib>)
target_link_libraries(test_0146-lru-cache GTest::gtest_main)
gtest_discover_tests(test_0146-lru-cache)
