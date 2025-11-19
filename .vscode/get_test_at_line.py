#!/usr/bin/env python3
"""
Extract test name from file at current line number
Usage: get_test_at_line.py <file_path> <line_number>
"""
import sys
import re

if len(sys.argv) < 3:
    print("*")  # Default to all tests
    sys.exit(0)

file_path = sys.argv[1]
try:
    line_number = int(sys.argv[2])
except ValueError:
    print("*")
    sys.exit(0)

try:
    with open(file_path, 'r') as f:
        lines = f.readlines()
    
    # Find the TEST macro at or before current line
    current_test = None
    test_pattern = re.compile(r'TEST\s*\(\s*([^,]+)\s*,\s*([^)]+)\s*\)')
    
    for i in range(min(line_number, len(lines)) - 1, -1, -1):
        match = test_pattern.search(lines[i])
        if match:
            suite = match.group(1).strip()
            name = match.group(2).strip()
            current_test = f"{suite}.{name}"
            break
    
    if current_test:
        print(current_test)
    else:
        print("*")
        
except Exception:
    print("*")
