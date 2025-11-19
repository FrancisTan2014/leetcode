# LeetCode Practice

A C++ practice environment for solving LeetCode problems with CMake build system and Google Test framework.

## Features

- **CMake Build System**: Modern C++20 with automated problem discovery
- **Google Test Integration**: Write and run unit tests for each solution
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

### Building the Project

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

## Example

See `problems/0001-two-sum/` for a complete example of a solved problem with tests.

## Notes

- All problems are automatically discovered by CMake
- Google Test is fetched automatically during the first build
- Each problem is built as a separate executable
- Test results are integrated with CTest

## License

This is a personal practice repository for educational purposes.
