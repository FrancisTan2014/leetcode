add_library(insert_interval_lib OBJECT solution.cpp)

add_executable(test_0057-insert-interval tests/test_0057-insert-interval.cpp $<TARGET_OBJECTS:insert_interval_lib>)
target_link_libraries(test_0057-insert-interval GTest::gtest_main)
gtest_discover_tests(test_0057-insert-interval)
