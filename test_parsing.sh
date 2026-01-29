#!/bin/bash

# Colors
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

PUSH_SWAP="./push_swap"
PASS=0
FAIL=0

# Test function
test_case() {
    local description="$1"
    local args="$2"
    local expected="$3"  # "OK" or "Error"

    # Run command and capture output + exit code
    output=$(eval "$PUSH_SWAP $args 2>&1")
    exit_code=$?

    if [ "$expected" = "Error" ]; then
        # Should print "Error" on stderr and return non-zero
        if echo "$output" | grep -q "Error" && [ $exit_code -ne 0 ]; then
            echo -e "${GREEN}✓${NC} $description"
            ((PASS++))
        else
            echo -e "${RED}✗${NC} $description"
            echo "  Expected: Error output + non-zero exit"
            echo "  Got: '$output' (exit=$exit_code)"
            ((FAIL++))
        fi
    else
        # Should NOT print "Error" and return 0
        if ! echo "$output" | grep -q "Error" && [ $exit_code -eq 0 ]; then
            echo -e "${GREEN}✓${NC} $description"
            ((PASS++))
        else
            echo -e "${RED}✗${NC} $description"
            echo "  Expected: Valid parsing (no error)"
            echo "  Got: '$output' (exit=$exit_code)"
            ((FAIL++))
        fi
    fi
}

echo "========================================="
echo "  PUSH_SWAP PARSING TESTS"
echo "========================================="

echo ""
echo -e "${YELLOW}=== VALID INPUTS ===${NC}"

# Basic valid cases
test_case "Simple positive numbers" "1 2 3" "OK"
test_case "Simple negative numbers" "-1 -2 -3" "OK"
test_case "Mixed positive and negative" "5 -3 2 -1 0" "OK"
test_case "Single number" "42" "OK"
test_case "Zero" "0" "OK"
test_case "Negative zero" "-0" "OK"

# Numbers with signs
test_case "Positive sign +" "+42" "OK"
test_case "Mix of +/- signs" "+1 -2 +3 -4" "OK"

# Large valid numbers (within INT range)
test_case "INT_MAX (2147483647)" "2147483647" "OK"
test_case "INT_MIN (-2147483648)" "-2147483648" "OK"
test_case "Near INT_MAX" "2147483646 2147483645" "OK"
test_case "Near INT_MIN" "-2147483647 -2147483646" "OK"

# Multiple arguments as single string (if supported)
test_case "Single string argument" '"1 2 3 4 5"' "OK"

echo ""
echo -e "${YELLOW}=== INVALID: NON-INTEGERS ===${NC}"

# Non-integer inputs
test_case "Letter in input" "1 2 a 3" "Error"
test_case "Word in input" "1 hello 3" "Error"
test_case "Special characters" "1 @ 3" "Error"
test_case "Decimal number" "1.5 2" "Error"
test_case "Float notation" "1.0" "Error"
test_case "Hexadecimal notation" "0x42" "Error"
test_case "Mixed digits and letters" "42abc" "Error"
test_case "Letters only" "abc" "Error"

echo ""
echo -e "${YELLOW}=== INVALID: OVERFLOW/UNDERFLOW ===${NC}"

# Integer overflow/underflow
test_case "Overflow INT_MAX+1" "2147483648" "Error"
test_case "Overflow large number" "9999999999" "Error"
test_case "Underflow INT_MIN-1" "-2147483649" "Error"
test_case "Underflow large negative" "-9999999999" "Error"
test_case "Very large number" "999999999999999999" "Error"

echo ""
echo -e "${YELLOW}=== INVALID: DUPLICATES ===${NC}"

# Exact duplicates
test_case "Duplicate positive" "1 2 3 2" "Error"
test_case "Duplicate negative" "-1 -2 -1" "Error"
test_case "Duplicate zero" "0 1 0" "Error"
test_case "Multiple duplicates" "1 2 3 2 3" "Error"

# Duplicates with different representations
test_case "Duplicate: 42 and +42" "42 +42" "Error"
test_case "Duplicate: 0 and -0" "0 -0" "Error"
test_case "Duplicate: 5 and 05" "5 05" "Error"
test_case "Duplicate: +5 and 5" "+5 5" "Error"

echo ""
echo -e "${YELLOW}=== INVALID: EMPTY/WHITESPACE ===${NC}"

# Empty inputs
test_case "No arguments" "" "OK"  # Subject says: display nothing
test_case "Empty string argument" '""' "Error"
test_case "Only spaces" '"   "' "Error"
test_case "Tab character" '"\t"' "Error"

echo ""
echo -e "${YELLOW}=== INVALID: SIGN ERRORS ===${NC}"

# Invalid signs
test_case "Double negative" "--1" "Error"
test_case "Double positive" "++1" "Error"
test_case "Mixed double sign" "+-1" "Error"
test_case "Sign only" "-" "Error"
test_case "Plus sign only" "+" "Error"
test_case "Sign with space" "- 1" "Error"
test_case "Number with trailing sign" "42-" "Error"

echo ""
echo -e "${YELLOW}=== EDGE CASES ===${NC}"

# Edge cases
test_case "Leading zeros" "001 002 003" "OK"
test_case "Negative with leading zeros" "-001 -002" "OK"
test_case "Single zero with sign" "+0" "OK"
test_case "All same duplicates" "5 5 5 5" "Error"
test_case "Two numbers same" "42 42" "Error"

echo ""
echo "========================================="
echo -e "Results: ${GREEN}${PASS} passed${NC}, ${RED}${FAIL} failed${NC}"
echo "========================================="

if [ $FAIL -eq 0 ]; then
    echo -e "${GREEN}All tests passed! 🎉${NC}"
    exit 0
else
    echo -e "${RED}Some tests failed${NC}"
    exit 1
fi
