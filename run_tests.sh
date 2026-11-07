#!/bin/bash

# Ensure the examples directory exists
mkdir -p examples

# Check if there are any .c files in the examples directory
count=$(ls -1 examples/*.c 2>/dev/null | wc -l)

if [ "$count" == "0" ]; then
    echo "No .c files found in the examples/ directory."
    echo "Add some broken C files to examples/ to test them!"
    exit 1
fi

echo "========================================"
echo " Running SyntaxRecover Test Suite"
echo "========================================"

for file in examples/*.c; do
    echo "▶ Testing: $file"
    ./build/syntaxrecover "$file"
    echo "----------------------------------------"
done

echo "All tests complete!"
