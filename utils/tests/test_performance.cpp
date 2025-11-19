// utils/tests/test_performance.cpp
#include <gtest/gtest.h>
#include <performance.h>
#include <vector>
#include <thread>
#include <chrono>

using namespace leetcode;

// Test basic functionality
TEST(PerformanceMonitor, BasicMeasurement) {
    PerformanceMonitor monitor;
    
    auto metrics = monitor.measure([]() {
        // Simple computation
        volatile int sum = 0;
        for (int i = 0; i < 1000; ++i) {
            sum += i;
        }
    });
    
    EXPECT_GT(metrics.time_ns, 0);
    EXPECT_GE(metrics.time_ms, 0);
    EXPECT_GE(metrics.memory_kb, 0);
    EXPECT_FALSE(metrics.time_exceeded);
    EXPECT_FALSE(metrics.memory_exceeded);
}

// Test measurement with return value
TEST(PerformanceMonitor, MeasureWithReturn) {
    PerformanceMonitor monitor;
    
    int result;
    auto metrics = monitor.measureWithReturn([]() {
        return 42;
    }, result);
    
    EXPECT_EQ(result, 42);
    EXPECT_GT(metrics.time_ns, 0);
    EXPECT_GE(metrics.memory_kb, 0);
}

// Test with complex return type
TEST(PerformanceMonitor, ComplexReturnType) {
    PerformanceMonitor monitor;
    
    std::vector<int> result;
    auto metrics = monitor.measureWithReturn([]() {
        std::vector<int> v;
        for (int i = 0; i < 100; ++i) {
            v.push_back(i);
        }
        return v;
    }, result);
    
    EXPECT_EQ(result.size(), 100);
    EXPECT_GT(metrics.time_ns, 0);
}

// Test time limits
TEST(PerformanceMonitor, TimeLimitDetection) {
    PerformanceMonitor monitor(1.0); // 1ms limit
    
    auto metrics = monitor.measure([]() {
        std::this_thread::sleep_for(std::chrono::milliseconds(5));
    });
    
    EXPECT_TRUE(metrics.time_exceeded);
    EXPECT_GT(metrics.time_ms, 1.0);
}

// Test time within limit
TEST(PerformanceMonitor, TimeWithinLimit) {
    PerformanceMonitor monitor(1000.0); // 1s limit
    
    auto metrics = monitor.measure([]() {
        volatile int sum = 0;
        for (int i = 0; i < 1000; ++i) {
            sum += i;
        }
    });
    
    EXPECT_FALSE(metrics.time_exceeded);
}

// Test memory measurement
TEST(PerformanceMonitor, MemoryMeasurement) {
    PerformanceMonitor monitor;
    
    std::vector<int> data;
    auto metrics = monitor.measureWithReturn([&]() {
        std::vector<int> temp;
        temp.reserve(10000);
        for (int i = 0; i < 10000; ++i) {
            temp.push_back(i);
        }
        return temp;
    }, data);
    
    EXPECT_EQ(data.size(), 10000);
    // Memory might be 0 or positive depending on allocator behavior
    EXPECT_GE(metrics.memory_kb, 0);
}

// Test exception handling
TEST(PerformanceMonitor, ExceptionHandling) {
    PerformanceMonitor monitor;
    
    EXPECT_THROW({
        monitor.measure([]() {
            throw std::runtime_error("Test exception");
        });
    }, std::runtime_error);
}

// Test invalid parameters
TEST(PerformanceMonitor, InvalidParameters) {
    EXPECT_THROW({
        PerformanceMonitor monitor(-1.0, 0);
    }, std::invalid_argument);
    
    EXPECT_THROW({
        PerformanceMonitor monitor(0, -1);
    }, std::invalid_argument);
}

// Test nanosecond precision
TEST(PerformanceMonitor, NanosecondPrecision) {
    PerformanceMonitor monitor;
    
    auto metrics = monitor.measure([]() {
        // Very fast operation
        volatile int x = 1;
        volatile int y = 1;
        volatile int z = x + y;
        (void)z; // Suppress unused warning
    });
    
    // Should be measurable in nanoseconds
    EXPECT_GT(metrics.time_ns, 0);
    // Conversion should be consistent
    EXPECT_DOUBLE_EQ(metrics.time_ms, metrics.time_ns / 1000000.0);
}

// Test default constructor
TEST(PerformanceMetrics, DefaultConstructor) {
    PerformanceMetrics metrics;
    
    EXPECT_EQ(metrics.time_ns, 0.0);
    EXPECT_EQ(metrics.time_ms, 0.0);
    EXPECT_EQ(metrics.memory_kb, 0);
    EXPECT_FALSE(metrics.time_exceeded);
    EXPECT_FALSE(metrics.memory_exceeded);
}

// Test macros
TEST(PerformanceMacros, TimeLimit) {
    PerformanceMetrics metrics;
    metrics.time_ms = 50.0;
    metrics.time_ns = 50000000.0;
    
    EXPECT_TIME_LIMIT(metrics, 100.0);
}

TEST(PerformanceMacros, MemoryLimit) {
    PerformanceMetrics metrics;
    metrics.memory_kb = 500;
    
    EXPECT_MEMORY_LIMIT(metrics, 1000);
}

TEST(PerformanceMacros, CombinedLimits) {
    PerformanceMetrics metrics;
    metrics.time_ms = 50.0;
    metrics.memory_kb = 500;
    
    EXPECT_PERFORMANCE(metrics, 100.0, 1000);
}

// Test logging (no assertion, just ensure it doesn't crash)
TEST(PerformanceMacros, Logging) {
    PerformanceMetrics metrics;
    metrics.time_ns = 123456.0;
    metrics.time_ms = 0.123456;
    metrics.memory_kb = 1024;
    
    // These should not crash
    testing::internal::CaptureStdout();
    LOG_PERFORMANCE(metrics);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
}
