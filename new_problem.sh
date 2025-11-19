#!/usr/bin/env bash
# Usage: ./new_problem.sh 0002-two-sum-variant

if [ $# -ne 1 ]; then
  echo "Usage: $0 <problem-name>"
  exit 1
fi

PROBLEM_NAME=$1
PROBLEM_DIR="problems/$PROBLEM_NAME"

# Create directories
mkdir -p "$PROBLEM_DIR/tests"

# Create solution.cpp if not exists
SOLUTION_FILE="$PROBLEM_DIR/solution.cpp"
if [ ! -f "$SOLUTION_FILE" ]; then
cat <<EOF > "$SOLUTION_FILE"
// solution.cpp
#include <vector>
using namespace std;

class Solution {
public:
    // TODO: implement solution
};
EOF
fi

# Create test file
TEST_FILE="$PROBLEM_DIR/tests/test_${PROBLEM_NAME}.cpp"
if [ ! -f "$TEST_FILE" ]; then
cat <<EOF > "$TEST_FILE"
// tests/test_${PROBLEM_NAME}.cpp
#include <gtest/gtest.h>
#include "../solution.cpp"

TEST(${PROBLEM_NAME}, SampleTest) {
    Solution s;
    // TODO: add test cases
}
EOF
fi

# Create problem.md for notes
PROBLEM_MD="$PROBLEM_DIR/problem.md"
if [ ! -f "$PROBLEM_MD" ]; then
  touch "$PROBLEM_MD"
fi

# Create CMakeLists.txt
CMAKE_FILE="$PROBLEM_DIR/CMakeLists.txt"
if [ ! -f "$CMAKE_FILE" ]; then
cat <<EOF > "$CMAKE_FILE"
add_library(${PROBLEM_NAME}_lib OBJECT solution.cpp)

add_executable(test_${PROBLEM_NAME} tests/test_${PROBLEM_NAME}.cpp \$<TARGET_OBJECTS:${PROBLEM_NAME}_lib>)
target_link_libraries(test_${PROBLEM_NAME} GTest::gtest_main)
gtest_discover_tests(test_${PROBLEM_NAME})
EOF
fi

echo "Problem $PROBLEM_NAME created successfully!"
