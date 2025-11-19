# Performance Utility Documentation

## Overview
The `performance.h` utility provides robust, cross-platform performance measurement capabilities for LeetCode solutions.

## Improvements Made

### 1. **Cross-Platform Support**
- ✅ Linux (tested)
- ✅ macOS/Darwin support
- ✅ Windows support
- Proper memory unit conversion for each platform

### 2. **Robustness Features**

#### Input Validation
- Negative time/memory limits throw `std::invalid_argument`
- Proper error messages for invalid parameters

#### Exception Safety
- Try-catch blocks around measurement code
- Exceptions from measured functions are properly propagated
- Diagnostic messages on measurement failures

#### Type Safety
- Uses C++17 `std::invoke_result` for better type inference
- Static casts in macros to prevent comparison warnings
- Proper const correctness for internal methods

#### Memory Safety
- Prevents negative memory readings with `std::max(0L, ...)`
- Platform-specific memory handling
- Graceful fallback for unsupported platforms

### 3. **Precision Improvements**

#### Time Measurement
- Uses `std::chrono::duration_cast` for accurate nanosecond precision
- Both `time_ns` and `time_ms` fields maintained
- Consistent conversion: `time_ms = time_ns / 1000000.0`

#### Memory Measurement
- Platform-specific implementations
- Linux: `ru_maxrss` in KB (native)
- macOS: `ru_maxrss` in bytes → converted to KB
- Windows: `WorkingSetSize` in bytes → converted to KB

### 4. **Enhanced Macros**

#### Improved Error Messages
```cpp
EXPECT_TIME_LIMIT(metrics, 100.0);
// Output: "Execution time 150ms exceeded limit 100ms (elapsed: 150000000ns)"
```

#### New Verbose Logging
```cpp
LOG_PERFORMANCE_VERBOSE(metrics);
// Performance Metrics:
//   Time: 2300ns (0.0023ms)
//   Memory: 384KB
//   Time Limit Exceeded: No
//   Memory Limit Exceeded: No
```

### 5. **Comprehensive Test Suite**

14 test cases covering:
- Basic functionality
- Return value handling
- Complex return types
- Time limit detection
- Memory measurement
- Exception handling
- Invalid parameters
- Nanosecond precision
- Macro functionality
- Default constructors

## API Reference

### PerformanceMonitor Constructor
```cpp
PerformanceMonitor(double time_limit_ms = 0, long memory_limit_kb = 0);
```
- Throws `std::invalid_argument` if limits are negative
- 0 means no limit

### Methods

#### measure()
```cpp
template<typename Func>
PerformanceMetrics measure(Func&& func);
```
Measures void-returning functions.

#### measureWithReturn()
```cpp
template<typename Func, typename ResultType>
PerformanceMetrics measureWithReturn(Func&& func, ResultType& result);
```
Measures functions with return values.

### PerformanceMetrics Structure
```cpp
struct PerformanceMetrics {
    double time_ns;        // Nanosecond precision
    double time_ms;        // Millisecond convenience
    long memory_kb;        // Memory in KB
    bool time_exceeded;    // Time limit flag
    bool memory_exceeded;  // Memory limit flag
};
```

### Macros

#### Assertions
- `EXPECT_TIME_LIMIT(metrics, limit_ms)` - Soft time assertion
- `ASSERT_TIME_LIMIT(metrics, limit_ms)` - Hard time assertion
- `EXPECT_MEMORY_LIMIT(metrics, limit_kb)` - Soft memory assertion
- `ASSERT_MEMORY_LIMIT(metrics, limit_kb)` - Hard memory assertion
- `EXPECT_PERFORMANCE(metrics, time_ms, mem_kb)` - Combined soft
- `ASSERT_PERFORMANCE(metrics, time_ms, mem_kb)` - Combined hard

#### Logging
- `LOG_PERFORMANCE(metrics)` - One-line summary
- `LOG_PERFORMANCE_VERBOSE(metrics)` - Detailed output

## Best Practices

1. **Always check for exceptions** in measured code:
   ```cpp
   try {
       auto metrics = monitor.measure([&]() { /* code */ });
   } catch (const std::exception& e) {
       // Handle or log error
   }
   ```

2. **Use appropriate limits** based on problem constraints:
   ```cpp
   // For O(n) algorithms with n=10^4
   PerformanceMonitor monitor(100.0, 10 * 1024); // 100ms, 10MB
   ```

3. **Prefer measureWithReturn()** when you need the result:
   ```cpp
   vector<int> result;
   auto metrics = monitor.measureWithReturn([&]() {
       return solution.compute();
   }, result);
   ```

4. **Log performance** during development:
   ```cpp
   LOG_PERFORMANCE(metrics);
   // Then add assertions for CI/CD
   EXPECT_TIME_LIMIT(metrics, 100.0);
   ```

## Platform Notes

### Linux
- Native support with `getrusage()`
- Memory reported in KB directly
- Most accurate measurements

### macOS
- Uses `getrusage()` with byte→KB conversion
- Memory measurement may be less granular

### Windows
- Uses `GetProcessMemoryInfo()`
- Requires linking with `psapi.lib` if used in Windows builds
- WorkingSetSize provides current memory usage

### Unsupported Platforms
- Memory measurement returns 0
- Warning printed once to stderr
- Time measurement still works accurately
