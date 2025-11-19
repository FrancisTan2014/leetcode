#!/usr/bin/env bash
# Script to run tests with detailed performance reporting

cd "$(dirname "$0")/build"

echo "================================"
echo "Running Tests with Performance Metrics"
echo "================================"
echo ""

# Run tests with verbose output to show performance logs
ctest --output-on-failure --verbose 2>&1 | grep -E "Test #|PERF|Passed|Failed|Total Test"

echo ""
echo "================================"
echo "Generating XML Report"
echo "================================"

# Run tests with XML output for detailed metrics
ctest -T Test --no-compress-output

# Check if XML was generated
if [ -f Testing/*/Test.xml ]; then
    echo ""
    echo "Performance data saved to: Testing/$(ls -t Testing | head -1)/Test.xml"
    echo ""
    echo "Extract performance metrics with:"
    echo "  grep -A 5 'measurement' Testing/*/Test.xml"
fi
