add_library(1011-capacity-to-ship-packages-within-d-days_lib OBJECT solution.cpp)

add_executable(test_1011-capacity-to-ship-packages-within-d-days tests/test_1011-capacity-to-ship-packages-within-d-days.cpp $<TARGET_OBJECTS:1011-capacity-to-ship-packages-within-d-days_lib>)
target_link_libraries(test_1011-capacity-to-ship-packages-within-d-days GTest::gtest_main)
gtest_discover_tests(test_1011-capacity-to-ship-packages-within-d-days)
