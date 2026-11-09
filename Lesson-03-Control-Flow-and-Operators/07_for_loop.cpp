// Lesson 3 - Section 2: For Loops
// - like a while loop with different syntax:
//       for (start; condition; update) { ... }
// - break and continue work the same way
// - use FOR when the number of iterations is known
// - use WHILE when it depends on a condition being met

#include <iostream>

int main() {
    for (int runLoop = 1; runLoop < 5; runLoop++) { // loop runs each time runLoop < 5
        if (runLoop == 5) { // check if runLoop equals 5
            break; // exit the for loop if runLoop equals 5
        }

        if (runLoop == 0) { // check if runLoop equals 0
            runLoop = 1; // set runLoop equal to 1
            continue; // immediately return to top of for loop and check condition
        }

        std::cout << runLoop << "\n"; // print runLoop
    }

    // The same loop written as a while loop, to compare the syntax
    int counter = 1;              // start
    while (counter < 5) {         // condition
        std::cout << "while: " << counter << "\n";
        counter++;                // update
    }

    // Counting down with --
    std::cout << "Countdown:";
    for (int i = 3; i > 0; i--) {
        std::cout << " " << i;
    }
    std::cout << " Go!\n";

    return 0;
}
