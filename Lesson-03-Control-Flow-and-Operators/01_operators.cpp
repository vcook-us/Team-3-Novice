// Lesson 3 - Section 1: Operators
// Operators modify variables and check whether they equal certain values.
// NOTE: These are not all the operators in C++.

#include <iostream>

int main() {
    // =  assign a value to a variable
    int variable = 5;                       // variable is now 5
    std::cout << "variable = " << variable << "\n";

    // Math operators: +  -  *  /  %
    variable = (variable * 3);              // 5 * 3 = 15
    std::cout << "variable * 3 = " << variable << "\n";

    variable = (variable % 4);              // remainder of 15 / 4 = 3
    std::cout << "variable % 4 = " << variable << "\n";

    int a = 17;
    int b = 5;
    std::cout << "\n" << a << " + " << b << " = " << (a + b) << "\n";   // addition
    std::cout << a << " - " << b << " = " << (a - b) << "\n";           // subtraction
    std::cout << a << " * " << b << " = " << (a * b) << "\n";           // multiplication
    std::cout << a << " / " << b << " = " << (a / b) << "\n";           // division (int: 3)
    std::cout << a << " % " << b << " = " << (a % b) << "\n";           // modulo (remainder: 2)

    // ++ increment (add 1)   -- decrement (subtract 1)
    int count = 10;
    count++;                                // 11
    std::cout << "\ncount after ++ = " << count << "\n";
    count--;                                // back to 10
    std::cout << "count after -- = " << count << "\n";

    // == check if equal (gives true or false)
    std::cout << std::boolalpha;            // print true/false instead of 1/0
    std::cout << "\ncount == 10 is " << (count == 10) << "\n";
    std::cout << "count == 99 is " << (count == 99) << "\n";

    // ! not (the opposite)
    bool isRobotOn = true;
    std::cout << "\nisRobotOn  is " << isRobotOn << "\n";
    std::cout << "!isRobotOn is " << !isRobotOn << "\n";

    // && and (both must be true)   || or (at least one must be true)
    bool hasBattery = true;
    bool hasController = false;
    std::cout << "\nhasBattery && hasController is " << (hasBattery && hasController) << "\n";
    std::cout << "hasBattery || hasController is " << (hasBattery || hasController) << "\n";

    return 0;
}
