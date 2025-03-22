#!/bin/bash

GREEN="\033[0;32m"
RED="\033[0;31m"
NC="\033[0m"

pass() {
    echo -e "${GREEN}✅ PASSED${NC} - $1"
}

fail() {
    echo -e "${RED}❌ FAILED${NC} - $1"
    echo "Expected:"
    echo "$2"
    echo "Got:"
    cat "$3"
    echo ""
}

run_test() {
    test_name=$1
    input=$2
    s1=$3
    s2=$4
    expected_output=$5

    echo -e "$input" > test_input.txt
    ./sed test_input.txt "$s1" "$s2" > /dev/null
    output=$(cat test_input.txt.replace)

    if [ "$output" == "$expected_output" ]; then
        pass "$test_name"
    else
        fail "$test_name" "$expected_output" test_input.txt.replace
    fi

    rm -f test_input.txt test_input.txt.replace
}

# ----------------- TEST CASES -----------------

run_test "1. Basic single replacement" \
"hello world" \
"hello" "hi" \
"hi world"

run_test "2. Multiple replacements" \
"hello hello hello" \
"hello" "yo" \
"yo yo yo"

run_test "3. s1 not found" \
"nothing changes" \
"pizza" "burger" \
"nothing changes"

run_test "4. s1 inside s2 (expanding text)" \
"ababa" \
"a" "aa" \
"aabaabaa"

run_test "5. s1 longer than s2 (shrinking)" \
"abcabcabc" \
"abc" "x" \
"xxx"

run_test "6. s1 = s2 (no change)" \
"repeat repeat repeat" \
"repeat" "repeat" \
"repeat repeat repeat"

run_test "7. s1 = single space" \
"hello world again" \
" " "-" \
"hello-world-again"

run_test "8. Replace space with nothing" \
"hello world again" \
" " "" \
"helloworldagain"

run_test "9. Replace full line" \
"matchme" \
"matchme" "replaced" \
"replaced"

run_test "10. s1 at end of line" \
"the endend" \
"end" "exit" \
"the exitexit"

run_test "11. s1 at start of line" \
"start here" \
"start" "go" \
"go here"

run_test "12. Special symbols" \
"a+b=c and a+b=c" \
"a+b" "x" \
"x=c and x=c"

run_test "13. Unicode symbols" \
"cafè déjà vu" \
"è" "e" \
"cafe déjà vu"

run_test "14. One-letter swap" \
"abababab" \
"a" "b" \
"bbbbbbbb"

run_test "15. Empty input file" \
"" \
"x" "y" \
""

run_test "16. Input = s1" \
"wow" \
"wow" "OMG" \
"OMG"

run_test "17. Newline character (\\n as text)" \
"print\\nnewline" \
"\\n" "\n" \
"print
newline"

run_test "18. Very long line" \
"$(head -c 10000 < /dev/zero | tr '\0' 'a')" \
"a" "b" \
"$(head -c 10000 < /dev/zero | tr '\0' 'b')"

run_test "19. Replace numbers" \
"123 456 123" \
"123" "789" \
"789 456 789"

run_test "20. s1 is substring of s2" \
"abcabcabc" \
"abc" "abcabc" \
"abcabcabcabcabcabc"

# Edge: Empty s1
echo "anything" > test_input.txt
./sed test_input.txt "" "x" > test_err.txt 2>&1
if grep -q "must not be empty" test_err.txt; then
    pass "21. Rejects empty s1"
else
    fail "21. Empty s1 should trigger error" "Error message" test_err.txt
fi
rm -f test_input.txt test_input.txt.replace test_err.txt

# ------------------------------------------------

echo ""
echo "🎉 All tests complete."

