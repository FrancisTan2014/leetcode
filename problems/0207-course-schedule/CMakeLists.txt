add_library(course_schedule_lib OBJECT solution.cpp)

add_executable(test_0207-course-schedule tests/test_0207-course-schedule.cpp $<TARGET_OBJECTS:course_schedule_lib>)
target_link_libraries(test_0207-course-schedule GTest::gtest_main)
gtest_discover_tests(test_0207-course-schedule)
