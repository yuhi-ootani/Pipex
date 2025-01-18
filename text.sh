#!/bin/bash

# Test 1: Basic Command
echo "Hello World\nPipex Test\nAnother Line" > infile
< infile ls -l | wc -l > expected_output
./pipex infile "ls -l" "wc -l" outfile
if diff outfile expected_output > /dev/null; then
    echo "Test 1 passed"
else
    echo "Test 1 failed"
fi

# Test 2: Command with Parameters
echo -e "a1 a2 a3\na1 b2 c3\nx1 y2 z3" > infile
< infile grep a1 | wc -w > expected_output
./pipex infile "grep a1" "wc -w" outfile
if diff outfile expected_output > /dev/null; then
    echo "Test 2 passed"
else
    echo "Test 2 failed"
fi

# Test 3: Missing Input File
if ./pipex missing_file "ls -l" "wc -l" outfile 2>&1 | grep -q "No such file or directory"; then
    echo "Test 3 passed"
else
    echo "Test 3 failed"
fi

# Test 4: Invalid Command
if ./pipex infile "invalid_command" "wc -l" outfile 2>&1 | grep -q "command not found"; then
    echo "Test 4 passed"
else
    echo "Test 4 failed"
fi

# Test 5: Empty Input File
touch empty_file
./pipex empty_file "cat" "wc -l" outfile
if [ "$(cat outfile)" = "0" ]; then
    echo "Test 5 passed"
else
    echo "Test 5 failed"
fi

# Clean up
rm -f infile empty_file outfile expected_output
