#!/usr/bin/env bash
# Enhanced test runner with performance metrics extraction

set -e

BUILD_DIR="$(dirname "$0")/build"
cd "$BUILD_DIR"

# Colors for output
GREEN='\033[0;32m'
BLUE='\033[0;34m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

echo -e "${BLUE}================================${NC}"
echo -e "${BLUE}LeetCode Performance Test Runner${NC}"
echo -e "${BLUE}================================${NC}"
echo ""

# Run tests with verbose output
echo -e "${YELLOW}Running all tests...${NC}"
ctest --output-on-failure --verbose 2>&1 | tee test_output.log

echo ""
echo -e "${BLUE}================================${NC}"
echo -e "${BLUE}Performance Summary${NC}"
echo -e "${BLUE}================================${NC}"

# Extract and display performance metrics
grep "\[PERF\]" test_output.log | while IFS= read -r line; do
    echo -e "${GREEN}${line}${NC}"
done

echo ""

# Generate XML report for detailed analysis
echo -e "${YELLOW}Generating XML report...${NC}"
ctest -T Test --no-compress-output > /dev/null 2>&1 || true

# Find the most recent test XML
XML_FILE=$(find Testing -name "Test.xml" -type f -printf '%T@ %p\n' 2>/dev/null | sort -rn | head -1 | cut -d' ' -f2)

if [ -n "$XML_FILE" ] && [ -f "$XML_FILE" ]; then
    echo -e "${GREEN}✓ XML report generated: $XML_FILE${NC}"
    echo ""
    echo -e "${BLUE}Performance Properties:${NC}"
    
    # Extract performance properties from XML
    grep -A 1 "<NamedMeasurement" "$XML_FILE" 2>/dev/null | \
        grep -E "name=|<Value>" | \
        paste - - | \
        sed 's/<NamedMeasurement.*name="\([^"]*\)".*/<Property: \1>/; s/<Value>\(.*\)<\/Value>/= \1/' | \
        head -20 || echo "  No performance properties found in XML"
fi

echo ""
echo -e "${BLUE}================================${NC}"
echo -e "${GREEN}Test run complete!${NC}"
echo -e "${BLUE}================================${NC}"

# Clean up
rm -f test_output.log
