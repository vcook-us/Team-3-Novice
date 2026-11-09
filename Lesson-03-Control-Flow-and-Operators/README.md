# Lesson 3: Control Flow and Operators

One program per concept from the lesson.

| File | Concept |
|------|---------|
| `01_operators.cpp` | `+ - * / % ++ -- ! = == && \|\|` |
| `02_common_operator_issues.cpp` | Integer division, precedence, `=` vs `==`, prefix vs postfix, comparison chains, uninitialized variables |
| `03_if_else.cpp` | `if`, `else if` ladder, `else` |
| `04_combining_conditions.cpp` | Shortening if statements with `&&` and `\|\|` |
| `05_switch.cpp` | `switch`, `case`, `break`, `default`, fall-through |
| `06_while_loop.cpp` | `while` loops, `break`, `continue` |
| `07_for_loop.cpp` | `for` loops, for vs. while |
| `08_control_flow_challenge.cpp` | Practice: predict the output |

## Run a program

```bash
g++ -std=c++17 01_operators.cpp -o operators
./operators
```

Note: the slides write `void main()`. Standard C++ requires `int main()`, so these programs use `int main()` and `return 0;`.
