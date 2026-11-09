// Lesson 3 - Section 2: Switches
// - test one variable against constant values (called cases)
// - cleaner than a long else if ladder
// - the variable must be an integral type (int, char...; not float, double, or string)
// - case values must be constants, and only exact values work (no ranges)
// - break exits the switch; without it the code falls through into the next case
// - default is the catch-all when no case matches

#include <iostream>

int main() {
    int day = 3;

    switch (day) {
        case 1:
            std::cout << "Monday\n";
            break;
        case 2:
            std::cout << "Tuesday\n";
            break;
        case 3:
            std::cout << "Wednesday\n";
            // Matches! This block will run.
            break;
            // Exits the switch statement here.
        case 4:
            std::cout << "Thursday\n";
            break;
        case 5:
            std::cout << "Friday\n";
            break;
        default:
            std::cout << "Weekend!\n";
            break;
    }

    // Fall-through demo: case 2 has no break, so case 3 runs too.
    int level = 2;
    std::cout << "\nFall-through with level = " << level << ":\n";
    switch (level) {
        case 1:
            std::cout << "Level 1\n";
            break;
        case 2:
            std::cout << "Level 2\n";
            // no break here!
        case 3:
            std::cout << "Level 3 (ran because case 2 had no break)\n";
            break;
        default:
            std::cout << "Unknown level\n";
            break;
    }

    return 0;
}
