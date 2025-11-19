#!/usr/bin/env bash
# Extract problem folder from file path
# Usage: get_problem_folder.sh <file_path>

FILE="$1"

if [[ "$FILE" =~ problems/([^/]+) ]]; then
    echo "${BASH_REMATCH[1]}"
else
    echo ""
    exit 1
fi
