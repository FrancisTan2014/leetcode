# LeetCode Practice

A C++ practice environment for solving LeetCode problems with CMake build system and Google Test framework.

## Features

- **CMake Build System**: Modern C++20 with automated problem discovery
- **Google Test Integration**: Write and run unit tests for each solution
- **Performance Measurement**: Built-in utilities to measure execution time and memory usage
- **Problem Template Script**: Quickly scaffold new problem directories
- **Organized Structure**: Each problem in its own directory with solution, tests, and notes

## Prerequisites

- CMake 3.16 or higher
- C++20 compatible compiler (GCC 10+, Clang 10+, or MSVC 2019+)
- Git

## Project Structure

```
leetcode/
├── CMakeLists.txt           # Root CMake configuration
├── cmake/
│   └── GoogleTest.cmake     # Google Test fetcher
├── new_problem.sh           # Script to create new problem directories
└── problems/
    └── 0001-two-sum/
        ├── CMakeLists.txt
        ├── problem.md       # Problem description
        ├── solution.cpp     # Solution implementation
        └── tests/
            └── test_two_sum.cpp
```

## Getting Started

### Quick Start with Makefile

```bash
# Build the project
make build

# Run all tests
make test

# Run tests with performance metrics
make test-verbose

# Run only performance tests
make test-perf

# Create a new problem
make new PROBLEM=0042-trapping-rain-water

# Clean build
make clean
```

### Manual Build with CMake

```bash
# Create build directory
mkdir -p build && cd build

# Configure with CMake
cmake ..

# Build all problems
make

# Run all tests
ctest
```

### Running Tests for a Specific Problem

```bash
# From the build directory
./problems/0001-two-sum/test_two_sum

# Or using ctest
ctest -R two_sum

# Run with verbose output to see performance metrics
ctest -R two_sum --verbose
```

### Running Tests with Performance Details

```bash
# Use the enhanced test runner (from project root)
./run_tests_detailed.sh

# Or run standard tests with CTest
cd build
ctest --output-on-failure

# View performance metrics in output
ctest --verbose | grep PERF
```

## Creating a New Problem

Use the provided script to create a new problem directory:

```bash
./new_problem.sh 0042-trapping-rain-water
```

This creates:
- `problems/0042-trapping-rain-water/solution.cpp` - Solution template
- `problems/0042-trapping-rain-water/tests/test_0042-trapping-rain-water.cpp` - Test template
- `problems/0042-trapping-rain-water/problem.md` - Problem description file
- `problems/0042-trapping-rain-water/CMakeLists.txt` - Build configuration

## Workflow

1. **Create a new problem**:
   ```bash
   ./new_problem.sh 0123-problem-name
   ```

2. **Add problem description** to `problem.md`

3. **Implement solution** in `solution.cpp`

4. **Write tests** in `tests/test_0123-problem-name.cpp`

5. **Build and test**:
   ```bash
   cd build
   cmake ..
   make
   ctest
   ```

## Performance Testing

The project includes a performance measurement utility (`utils/performance.h`) to track execution time and memory usage.

### Basic Usage

```cpp
#include <performance.h>
using namespace leetcode;

TEST(MyTest, Performance) {
    Solution s;
    
    // Create performance monitor
    PerformanceMonitor monitor;
    
    // Measure function execution
    auto metrics = monitor.measure([&]() {
        s.myFunction();
    });
    
    // Log results
    LOG_PERFORMANCE(metrics);
    
    // Assert performance limits
    EXPECT_TIME_LIMIT(metrics, 100.0);  // 100ms
    EXPECT_MEMORY_LIMIT(metrics, 1024); // 1MB (in KB)
}
```

### Setting Performance Limits

```cpp
// Monitor with time limit (100ms) and memory limit (10MB)
PerformanceMonitor monitor(100.0, 10 * 1024);

vector<int> result;
auto metrics = monitor.measureWithReturn([&]() {
    return s.compute(data);
}, result);

// Check if limits were exceeded
if (metrics.time_exceeded || metrics.memory_exceeded) {
    FAIL() << "Performance limits exceeded!";
}

// Or use convenience macros
EXPECT_PERFORMANCE(metrics, 100.0, 10 * 1024);
```

### Available Macros

- `LOG_PERFORMANCE(metrics)` - Print execution time and memory usage
- `LOG_PERFORMANCE_VERBOSE(metrics)` - Detailed performance report
- `RECORD_PERFORMANCE_PROPERTY(metrics, name)` - Record metrics in CTest XML
- `EXPECT_TIME_LIMIT(metrics, limit_ms)` - Soft assertion for time limit
- `ASSERT_TIME_LIMIT(metrics, limit_ms)` - Hard assertion for time limit
- `EXPECT_MEMORY_LIMIT(metrics, limit_kb)` - Soft assertion for memory limit
- `ASSERT_MEMORY_LIMIT(metrics, limit_kb)` - Hard assertion for memory limit
- `EXPECT_PERFORMANCE(metrics, time_ms, memory_kb)` - Combined soft assertion
- `ASSERT_PERFORMANCE(metrics, time_ms, memory_kb)` - Combined hard assertion

### Performance Metrics

```cpp
struct PerformanceMetrics {
    double time_ms;        // Execution time in milliseconds
    long memory_kb;        // Peak memory usage in kilobytes
    bool time_exceeded;    // Whether time limit was exceeded
    bool memory_exceeded;  // Whether memory limit was exceeded
};
```

## Example

See `problems/0001-two-sum/` for a complete example of a solved problem with tests and performance measurements.

## Notes

- All problems are automatically discovered by CMake
- Google Test is fetched automatically during the first build
- Each problem is built as a separate executable
- Test results are integrated with CTest

## License

This is a personal practice repository for educational purposes.
