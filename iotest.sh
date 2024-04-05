#!/bin/bash  
  
# This is a test script for C++ IO problems.
# single source file, single test case, single expected output file.
# example: ./test_script.sh /path/to/B.cpp /path/to/test_case_b.txt /path/to/expected_ouput_b.txt  
  
# check the number of arguments
if [ $# -ne 3 ]; then  
    echo "Usage: $0 <cpp_file> <test_file> <expected_output_file>"  
    exit 1  
fi  
  
# get the arguments
cpp_file="$1"  
test_file="$2"  
expected_output_file="$3"  
  
# ­ensure that the files exist
if [ ! -f "$cpp_file" ]; then  
    echo "Error: Cpp file '$cpp_file' does not exist."  
    exit 1  
fi  
  
if [ ! -f "$test_file" ]; then  
    echo "Error: Test file '$test_file' does not exist."  
    exit 1  
fi  
  
if [ ! -f "$expected_output_file" ]; then  
    echo "Error: Expected output file '$expected_output_file' does not exist."  
    exit 1  
fi  
  
# obtain the filename without the extension
filename=$(basename "$cpp_file" .cpp)  
  
# compile the cpp file
g++ -o "$filename" "$cpp_file"  
  
# Run the cpp file, and redirect the input from the test file  
output=$(./"$filename" < "$test_file")  
  
# Compare the output with the expected output  
if [ "$output" == "$(cat "$expected_output_file")" ]; then  
    echo "Test passed"  
else  
    echo "Test failed"  
    echo "-------------------"  
    echo "Input:"  
    cat "$test_file"  
    echo -e "\n-------------------"  
    echo "Actual output:"  
    echo "$output"  
    echo -e "\n-------------------"  
    echo "Expected output:"  
    cat "$expected_output_file"  
fi
