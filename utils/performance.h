// utils/performance.h
#ifndef LEETCODE_PERFORMANCE_H
#define LEETCODE_PERFORMANCE_H

#include <chrono>
#include <functional>
#include <iostream>
#include <stdexcept>
#include <type_traits>

// Platform-specific includes
#if defined(__linux__)
    #include <sys/resource.h>
    #include <unistd.h>
#elif defined(__APPLE__) || defined(__MACH__)
    #include <sys/resource.h>
    #include <unistd.h>
    #include <mach/mach.h>
#elif defined(_WIN32) || defined(_WIN64)
    #include <windows.h>
    #include <psapi.h>
#endif

namespace leetcode {

struct PerformanceMetrics {
    double time_ns;        // Execution time in nanoseconds
    double time_ms;        // Execution time in milliseconds (for convenience)
    long memory_kb;        // Peak memory usage in kilobytes
    bool time_exceeded;    // Whether time limit was exceeded
    bool memory_exceeded;  // Whether memory limit was exceeded
    
    // Default constructor
    PerformanceMetrics() 
        : time_ns(0.0), time_ms(0.0), memory_kb(0), 
          time_exceeded(false), memory_exceeded(false) {}
};

class PerformanceMonitor {
public:
    // Constructor with optional limits (0 means no limit)
    PerformanceMonitor(double time_limit_ms = 0, long memory_limit_kb = 0)
        : time_limit_ms_(time_limit_ms), memory_limit_kb_(memory_limit_kb) {
        // Validate input parameters
        if (time_limit_ms_ < 0) {
            throw std::invalid_argument("Time limit cannot be negative");
        }
        if (memory_limit_kb_ < 0) {
            throw std::invalid_argument("Memory limit cannot be negative");
        }
    }

    // Measure performance of a function (void return type)
    template<typename Func>
    PerformanceMetrics measure(Func&& func) {
        PerformanceMetrics metrics;
        
        try {
            // Get baseline memory usage
            long baseline_memory = getCurrentMemoryUsage();
            
            // Measure execution time with high precision
            auto start = std::chrono::high_resolution_clock::now();
            
            // Execute function
            std::forward<Func>(func)();
            
            auto end = std::chrono::high_resolution_clock::now();
            
            // Calculate time in nanoseconds and milliseconds
            auto duration_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
            metrics.time_ns = static_cast<double>(duration_ns.count());
            metrics.time_ms = metrics.time_ns / 1000000.0;
            
            // Get peak memory usage (relative to baseline)
            long peak_memory = getPeakMemoryUsage();
            metrics.memory_kb = std::max(0L, peak_memory - baseline_memory);
            
            // Check limits
            metrics.time_exceeded = (time_limit_ms_ > 0 && metrics.time_ms > time_limit_ms_);
            metrics.memory_exceeded = (memory_limit_kb_ > 0 && metrics.memory_kb > memory_limit_kb_);
            
        } catch (const std::exception& e) {
            std::cerr << "Performance measurement failed: " << e.what() << std::endl;
            throw;
        }
        
        return metrics;
    }

    // Measure with return value (C++17 compatible)
    template<typename Func, typename ResultType = typename std::invoke_result<Func>::type>
    PerformanceMetrics measureWithReturn(Func&& func, ResultType& result) {
        PerformanceMetrics metrics;
        
        try {
            long baseline_memory = getCurrentMemoryUsage();
            
            auto start = std::chrono::high_resolution_clock::now();
            
            // Execute function and capture result
            result = std::forward<Func>(func)();
            
            auto end = std::chrono::high_resolution_clock::now();
            
            auto duration_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
            metrics.time_ns = static_cast<double>(duration_ns.count());
            metrics.time_ms = metrics.time_ns / 1000000.0;
            
            long peak_memory = getPeakMemoryUsage();
            metrics.memory_kb = std::max(0L, peak_memory - baseline_memory);
            
            metrics.time_exceeded = (time_limit_ms_ > 0 && metrics.time_ms > time_limit_ms_);
            metrics.memory_exceeded = (memory_limit_kb_ > 0 && metrics.memory_kb > memory_limit_kb_);
            
        } catch (const std::exception& e) {
            std::cerr << "Performance measurement failed: " << e.what() << std::endl;
            throw;
        }
        
        return metrics;
    }

private:
    double time_limit_ms_;
    long memory_limit_kb_;

    // Get current memory usage in KB (platform-specific)
    long getCurrentMemoryUsage() const {
#if defined(__linux__)
        struct rusage usage;
        if (getrusage(RUSAGE_SELF, &usage) == 0) {
            // On Linux, ru_maxrss is in kilobytes
            return usage.ru_maxrss;
        }
        return 0;
        
#elif defined(__APPLE__) || defined(__MACH__)
        struct rusage usage;
        if (getrusage(RUSAGE_SELF, &usage) == 0) {
            // On macOS, ru_maxrss is in bytes, convert to KB
            return usage.ru_maxrss / 1024;
        }
        return 0;
        
#elif defined(_WIN32) || defined(_WIN64)
        PROCESS_MEMORY_COUNTERS_EX pmc;
        if (GetProcessMemoryInfo(GetCurrentProcess(), 
                                 (PROCESS_MEMORY_COUNTERS*)&pmc, 
                                 sizeof(pmc))) {
            // Windows reports in bytes, convert to KB
            return static_cast<long>(pmc.WorkingSetSize / 1024);
        }
        return 0;
        
#else
        // Unsupported platform
        static bool warning_shown = false;
        if (!warning_shown) {
            std::cerr << "Warning: Memory measurement not supported on this platform" << std::endl;
            warning_shown = true;
        }
        return 0;
#endif
    }

    // Get peak memory usage in KB
    long getPeakMemoryUsage() const {
        return getCurrentMemoryUsage();
    }
};

} // namespace leetcode

// Google Test macros for performance assertions
#define EXPECT_TIME_LIMIT(metrics, limit_ms) \
    EXPECT_LE((metrics).time_ms, static_cast<double>(limit_ms)) \
        << "Execution time " << (metrics).time_ms << "ms exceeded limit " \
        << static_cast<double>(limit_ms) << "ms (elapsed: " << (metrics).time_ns << "ns)"

#define ASSERT_TIME_LIMIT(metrics, limit_ms) \
    ASSERT_LE((metrics).time_ms, static_cast<double>(limit_ms)) \
        << "Execution time " << (metrics).time_ms << "ms exceeded limit " \
        << static_cast<double>(limit_ms) << "ms (elapsed: " << (metrics).time_ns << "ns)"

#define EXPECT_MEMORY_LIMIT(metrics, limit_kb) \
    EXPECT_LE((metrics).memory_kb, static_cast<long>(limit_kb)) \
        << "Memory usage " << (metrics).memory_kb << "KB exceeded limit " \
        << static_cast<long>(limit_kb) << "KB"

#define ASSERT_MEMORY_LIMIT(metrics, limit_kb) \
    ASSERT_LE((metrics).memory_kb, static_cast<long>(limit_kb)) \
        << "Memory usage " << (metrics).memory_kb << "KB exceeded limit " \
        << static_cast<long>(limit_kb) << "KB"

#define EXPECT_PERFORMANCE(metrics, time_limit_ms, memory_limit_kb) \
    do { \
        EXPECT_TIME_LIMIT(metrics, time_limit_ms); \
        EXPECT_MEMORY_LIMIT(metrics, memory_limit_kb); \
    } while(0)

#define ASSERT_PERFORMANCE(metrics, time_limit_ms, memory_limit_kb) \
    do { \
        ASSERT_TIME_LIMIT(metrics, time_limit_ms); \
        ASSERT_MEMORY_LIMIT(metrics, memory_limit_kb); \
    } while(0)

// Convenience macros for logging performance
#define LOG_PERFORMANCE(metrics) \
    std::cout << "Performance: " << (metrics).time_ns << "ns (" \
              << (metrics).time_ms << "ms), " \
              << (metrics).memory_kb << "KB" << std::endl

#define LOG_PERFORMANCE_VERBOSE(metrics) \
    std::cout << "Performance Metrics:\n" \
              << "  Time: " << (metrics).time_ns << "ns (" << (metrics).time_ms << "ms)\n" \
              << "  Memory: " << (metrics).memory_kb << "KB" \
              << ((metrics).memory_kb >= 1024 ? " (" + std::to_string((metrics).memory_kb / 1024) + "MB)" : "") << "\n" \
              << "  Time Limit Exceeded: " << ((metrics).time_exceeded ? "Yes" : "No") << "\n" \
              << "  Memory Limit Exceeded: " << ((metrics).memory_exceeded ? "Yes" : "No") \
              << std::endl

#endif // LEETCODE_PERFORMANCE_H
