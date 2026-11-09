// Lesson 3 - Section 1: Common Operator Issues
// Each example shows a mistake and the fix.

#include <iostream>

int main() {
    std::cout << std::boolalpha;

    // 1. Dividing two integers: C++ truncates (rounds down) the result.
    //    Make at least one side floating point.
    int wrong = 7 / 2;            // 3   (the .5 is thrown away)
    double right = 7.0 / 2;       // 3.5
    std::cout << "7 / 2   = " << wrong << "\n";
    std::cout << "7.0 / 2 = " << right << "\n";

    // 2. Operator precedence: * and / happen before + and - (like PEMDAS).
    //    Use parentheses if unsure!
    int noParens = 2 + 3 * 4;     // 2 + 12 = 14
    int withParens = (2 + 3) * 4; // 5 * 4  = 20
    std::cout << "\n2 + 3 * 4   = " << noParens << "\n";
    std::cout << "(2 + 3) * 4 = " << withParens << "\n";

    // 3. Using = instead of == to check equality.
    //    = assigns a value, == compares. The compiler may only warn you.
    int score = 50;
    if (score == 100) {           // correct: compares score to 100
        std::cout << "\nPerfect score!\n";
    } else {
        std::cout << "\nscore == 100 is false, score is still " << score << "\n";
    }
    // if (score = 100)  <- BUG: sets score to 100, and the check is always true

    // 4. Prefix vs. Postfix (++x vs x++)
    //    Prefix  (++x): increment BEFORE the value is used
    //    Postfix (x++): increment AFTER the value is used
    int x = 5;
    int prefixResult = ++x;       // x becomes 6, then 6 is used
    std::cout << "\n++x gives " << prefixResult << " (x is now " << x << ")\n";

    int y = 5;
    int postfixResult = y++;      // 5 is used, then y becomes 6
    std::cout << "y++ gives " << postfixResult << " (y is now " << y << ")\n";

    // 5. Greater/Less than chains (like 10 < z < 20)
    //    C++ evaluates left to right: (10 < z) becomes false (0),
    //    then 0 < 20 is true, so the chain gives the WRONG answer.
    //    Newer compilers refuse to build "10 < z < 20" at all, so the
    //    parentheses below spell out what C++ would do with it.
    int z = 5;
    bool chained = (10 < z) < 20;            // true  (wrong!)
    bool fixed = (10 < z) && (z < 20);       // false (correct)
    std::cout << "\nz = " << z << "\n";
    std::cout << "10 < z < 20          is " << chained << "  <- wrong\n";
    std::cout << "(10 < z) && (z < 20) is " << fixed << " <- correct\n";

    // 6. Uninitialized variables: always give a variable a starting value.
    int total = 0;                // NOT: int total;  (it would hold garbage)
    total = total + 10;
    std::cout << "\ntotal = " << total << "\n";

    return 0;
}
