// tests/test_0146-lru-cache.cpp
#include <gtest/gtest.h>
#include <performance.h>
#include "../solution.cpp"

using namespace std;
using namespace leetcode;

TEST(LRUCache, Example1) {
    LRUCache cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    EXPECT_EQ(cache.get(1), 1);
    cache.put(3, 3);
    EXPECT_EQ(cache.get(2), -1);
    cache.put(4, 4);
    EXPECT_EQ(cache.get(1), -1);
    EXPECT_EQ(cache.get(3), 3);
    EXPECT_EQ(cache.get(4), 4);
}

TEST(LRUCache, CapacityOne) {
    LRUCache cache(1);
    cache.put(1, 1);
    EXPECT_EQ(cache.get(1), 1);
    cache.put(2, 2);
    EXPECT_EQ(cache.get(1), -1);
    EXPECT_EQ(cache.get(2), 2);
}

TEST(LRUCache, CapacityOneMultipleOps) {
    LRUCache cache(1);
    cache.put(1, 10);
    EXPECT_EQ(cache.get(1), 10);
    cache.put(2, 20);
    EXPECT_EQ(cache.get(2), 20);
    cache.put(3, 30);
    EXPECT_EQ(cache.get(3), 30);
    EXPECT_EQ(cache.get(1), -1);
    EXPECT_EQ(cache.get(2), -1);
}

TEST(LRUCache, UpdateExisting) {
    LRUCache cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    cache.put(1, 10);
    EXPECT_EQ(cache.get(1), 10);
    EXPECT_EQ(cache.get(2), 2);
}

TEST(LRUCache, UpdateMakesRecent) {
    LRUCache cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    cache.put(1, 10);
    cache.put(3, 3);
    EXPECT_EQ(cache.get(2), -1);
    EXPECT_EQ(cache.get(1), 10);
    EXPECT_EQ(cache.get(3), 3);
}

TEST(LRUCache, GetMakesRecent) {
    LRUCache cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    EXPECT_EQ(cache.get(1), 1);
    cache.put(3, 3);
    EXPECT_EQ(cache.get(2), -1);
    EXPECT_EQ(cache.get(1), 1);
    EXPECT_EQ(cache.get(3), 3);
}

TEST(LRUCache, GetNonExistent) {
    LRUCache cache(2);
    EXPECT_EQ(cache.get(1), -1);
    cache.put(1, 1);
    EXPECT_EQ(cache.get(2), -1);
    EXPECT_EQ(cache.get(1), 1);
}

TEST(LRUCache, CapacityThree) {
    LRUCache cache(3);
    cache.put(1, 1);
    cache.put(2, 2);
    cache.put(3, 3);
    EXPECT_EQ(cache.get(1), 1);
    EXPECT_EQ(cache.get(2), 2);
    EXPECT_EQ(cache.get(3), 3);
    cache.put(4, 4);
    EXPECT_EQ(cache.get(1), -1);
    EXPECT_EQ(cache.get(2), 2);
    EXPECT_EQ(cache.get(3), 3);
    EXPECT_EQ(cache.get(4), 4);
}

TEST(LRUCache, EvictionOrder) {
    LRUCache cache(3);
    cache.put(1, 1);
    cache.put(2, 2);
    cache.put(3, 3);
    cache.put(4, 4);
    EXPECT_EQ(cache.get(1), -1);
    cache.put(5, 5);
    EXPECT_EQ(cache.get(2), -1);
    cache.put(6, 6);
    EXPECT_EQ(cache.get(3), -1);
}

TEST(LRUCache, ZeroKeyValue) {
    LRUCache cache(2);
    cache.put(0, 0);
    EXPECT_EQ(cache.get(0), 0);
    cache.put(1, 1);
    EXPECT_EQ(cache.get(0), 0);
    EXPECT_EQ(cache.get(1), 1);
}

TEST(LRUCache, MaxKeyValue) {
    LRUCache cache(2);
    cache.put(10000, 100000);
    EXPECT_EQ(cache.get(10000), 100000);
    cache.put(9999, 99999);
    EXPECT_EQ(cache.get(10000), 100000);
    EXPECT_EQ(cache.get(9999), 99999);
}

TEST(LRUCache, SameKeyMultipleUpdates) {
    LRUCache cache(2);
    cache.put(1, 1);
    cache.put(1, 2);
    cache.put(1, 3);
    EXPECT_EQ(cache.get(1), 3);
}

TEST(LRUCache, AlternatingAccess) {
    LRUCache cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    EXPECT_EQ(cache.get(1), 1);
    EXPECT_EQ(cache.get(2), 2);
    EXPECT_EQ(cache.get(1), 1);
    EXPECT_EQ(cache.get(2), 2);
}

TEST(LRUCache, AlternatingAccessWithEviction) {
    LRUCache cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    EXPECT_EQ(cache.get(1), 1);
    cache.put(3, 3);
    EXPECT_EQ(cache.get(2), -1);
    EXPECT_EQ(cache.get(1), 1);
    cache.put(4, 4);
    EXPECT_EQ(cache.get(3), -1);
}

TEST(LRUCache, FillToCapacity) {
    LRUCache cache(5);
    for (int i = 1; i <= 5; i++) {
        cache.put(i, i * 10);
    }
    for (int i = 1; i <= 5; i++) {
        EXPECT_EQ(cache.get(i), i * 10);
    }
}

TEST(LRUCache, FillBeyondCapacity) {
    LRUCache cache(5);
    for (int i = 1; i <= 10; i++) {
        cache.put(i, i * 10);
    }
    for (int i = 1; i <= 5; i++) {
        EXPECT_EQ(cache.get(i), -1);
    }
    for (int i = 6; i <= 10; i++) {
        EXPECT_EQ(cache.get(i), i * 10);
    }
}

TEST(LRUCache, AccessPattern) {
    LRUCache cache(3);
    cache.put(1, 1);
    cache.put(2, 2);
    cache.put(3, 3);
    EXPECT_EQ(cache.get(1), 1);
    cache.put(4, 4);
    EXPECT_EQ(cache.get(2), -1);
    EXPECT_EQ(cache.get(3), 3);
    cache.put(5, 5);
    EXPECT_EQ(cache.get(1), -1);
    EXPECT_EQ(cache.get(4), 4);
}

TEST(LRUCache, UpdateAfterEviction) {
    LRUCache cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    cache.put(3, 3);
    EXPECT_EQ(cache.get(1), -1);
    cache.put(1, 10);
    EXPECT_EQ(cache.get(1), 10);
    EXPECT_EQ(cache.get(2), -1);
}

TEST(LRUCache, LargeCapacity) {
    LRUCache cache(100);
    for (int i = 0; i < 100; i++) {
        cache.put(i, i * 2);
    }
    for (int i = 0; i < 100; i++) {
        EXPECT_EQ(cache.get(i), i * 2);
    }
    cache.put(100, 200);
    EXPECT_EQ(cache.get(0), -1);
    EXPECT_EQ(cache.get(100), 200);
}

TEST(LRUCache, GetRefreshesOrder) {
    LRUCache cache(3);
    cache.put(1, 1);
    cache.put(2, 2);
    cache.put(3, 3);
    EXPECT_EQ(cache.get(1), 1);
    EXPECT_EQ(cache.get(2), 2);
    cache.put(4, 4);
    EXPECT_EQ(cache.get(3), -1);
    EXPECT_EQ(cache.get(1), 1);
    EXPECT_EQ(cache.get(2), 2);
    EXPECT_EQ(cache.get(4), 4);
}

TEST(LRUCache, MixedOperations) {
    LRUCache cache(2);
    cache.put(2, 1);
    cache.put(1, 1);
    cache.put(2, 3);
    cache.put(4, 1);
    EXPECT_EQ(cache.get(1), -1);
    EXPECT_EQ(cache.get(2), 3);
}

TEST(LRUCache, SequentialPutGet) {
    LRUCache cache(10);
    for (int i = 0; i < 20; i++) {
        cache.put(i, i);
        if (i >= 10) {
            EXPECT_EQ(cache.get(i - 10), -1);
        }
        EXPECT_EQ(cache.get(i), i);
    }
}

TEST(LRUCache, Performance1000Operations) {
    LRUCache cache(500);
    
    PerformanceMonitor monitor(100.0, 10 * 1024);
    auto metrics = monitor.measure([&]() {
        for (int i = 0; i < 1000; i++) {
            cache.put(i, i * 2);
            if (i >= 500) {
                cache.get(i - 500);
            }
        }
    });
    
    RECORD_PERFORMANCE_PROPERTY(metrics, "Performance1000Operations");
    EXPECT_PERFORMANCE(metrics, 100.0, 10 * 1024);
}

TEST(LRUCache, Performance10000Operations) {
    LRUCache cache(1000);
    
    PerformanceMonitor monitor(1000.0, 50 * 1024);
    auto metrics = monitor.measure([&]() {
        for (int i = 0; i < 10000; i++) {
            cache.put(i % 5000, i);
            cache.get(i % 5000);
        }
    });
    
    RECORD_PERFORMANCE_PROPERTY(metrics, "Performance10000Operations");
    EXPECT_PERFORMANCE(metrics, 1000.0, 50 * 1024);
}

TEST(LRUCache, PerformanceMaxCapacity) {
    LRUCache cache(3000);
    
    PerformanceMonitor monitor(1000.0, 100 * 1024);
    auto metrics = monitor.measure([&]() {
        for (int i = 0; i < 3000; i++) {
            cache.put(i, i);
        }
        for (int i = 0; i < 3000; i++) {
            cache.get(i);
        }
    });
    
    RECORD_PERFORMANCE_PROPERTY(metrics, "PerformanceMaxCapacity");
    EXPECT_PERFORMANCE(metrics, 1000.0, 100 * 1024);
}
