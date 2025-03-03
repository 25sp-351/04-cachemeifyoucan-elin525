#!/bin/bash

# ========================
#  compile
# ========================
echo "Compiling project"
make || { echo "Compilation failed! Exiting."; exit 1; }

# ========================
#  test data
# ========================
TEST_FILES=("pieces1.txt" "pieces2.txt" "pieces3.txt" "pieces4.txt" "pieces5.txt" "pieces6.txt")
TEST_CONTENTS=(
    "10, 15\n15, 25\n20, 40"
    "10, 10\n15, 20"
    "10, 10\n15, 25"
    "15, 20\n30, 50"
    "10, 10\n20, 25\n40, 35"
    "10, 10\n20, 25\n50, 70"
)
ROD_LENGTHS=("50" "5" "25" "12" "40" "100")
EXPECTED_OUTPUTS=("95" "0" "35" "0" "50" "140")

# ========================
#  create test files
# ========================
echo "Creating test input files..."
for i in "${!TEST_FILES[@]}"; do
    echo -e "${TEST_CONTENTS[$i]}" > "${TEST_FILES[$i]}"
done

# ========================
#  run tests
# ========================
for policy in "fifo" "lru"; do
    echo -e "\n==================================="
    echo " Running Tests: rod_cut_${policy} "
    echo "======================================"

    for i in "${!ROD_LENGTHS[@]}"; do
        input_file="${TEST_FILES[$i]}"
        rod_length="${ROD_LENGTHS[$i]}"
        expected_value="${EXPECTED_OUTPUTS[$i]}"

        # run the program and get the output value
        output_value=$(echo "$rod_length" | ./rod_cut_${policy} "$input_file" | grep "Value" | awk '{print $2}')

        # compare the output value with the expected value
        if [[ "$output_value" == "$expected_value" ]]; then
            echo "[PASS] $input_file -> Expected: $expected_value, Got: $output_value"
        else
            echo "[FAIL] $input_file -> Expected: $expected_value, Got: $output_value"
        fi
    done
done

# ========================================
#  cleanup test files and compiled files
# ========================================
echo "Cleaning up test files..."
for file in "${TEST_FILES[@]}"; do
    rm -f "$file"
done

echo "Cleaning up compiled files"
make clean

echo "All tests completed!"
