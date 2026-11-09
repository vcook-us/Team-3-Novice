// Lesson 3 - Control Flow Challenge
// Figure out what is printed BEFORE you run it!
//
// Answer:
//   1 is odd
//   2 is even -> Two
//   3 is odd
//   4 is even -> Four

#include <iostream>

int main() {
    // A loop that runs 4 times, with 'i' starting at 1
    for (int i = 1; i <= 4; i++) {

        // Step 1: Check if 'i' is an even number
        if (i % 2 == 0) {
            std::cout << i << " is even -> ";

            // Step 2: Run a switch based on the value of 'i'
            switch (i) {
                case 2:
                    std::cout << "Two\n";
                    break;
                case 4:
                    std::cout << "Four\n";
                    break;
                default:
                    std::cout << "Unknown\n";
                    break;
            }
        }
        // Step 3: Run this block if 'i' is an odd number
        else {
            std::cout << i << " is odd\n";
        }
    }
    return 0;
}
