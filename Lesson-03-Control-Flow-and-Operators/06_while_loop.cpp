// Lesson 3 - Section 2: While Loops
// - repeat the body until the condition becomes false (it can be a counter)
// - if the condition is false at the start, the body is skipped
// - break: immediately exit the loop
// - continue: immediately jump back to the top and re-check the condition
// - Common Error: getting stuck in a while loop (forgetting to change the counter)

#include <iostream>

int main() {
    int runLoop = 1; // create a variable named runLoop equal to 1

    while (runLoop < 5) { // the loop runs while runLoop < 5 is true
        if (runLoop == 5) { // check if runLoop equals 5
            break; // exit the while loop if runLoop equals 5
        }

        if (runLoop == 0) { // check if runLoop equals 0
            runLoop = 1; // set runLoop equal to 1
            continue; // immediately return to top of while loop and check condition
        }

        std::cout << runLoop << "\n"; // print runLoop
        runLoop++; // increment runLoop by 1 (without this, the loop never ends!)
    }

    // break example: stop as soon as we find the first number divisible by 7
    int number = 20;
    while (true) { // runs forever unless something breaks out
        if (number % 7 == 0) {
            std::cout << "First number >= 20 divisible by 7: " << number << "\n";
            break;
        }
        number++;
    }

    // continue example: print only odd numbers from 1 to 9
    int n = 0;
    std::cout << "Odd numbers:";
    while (n < 9) {
        n++;
        if (n % 2 == 0) {
            continue; // skip even numbers
        }
        std::cout << " " << n;
    }
    std::cout << "\n";

    return 0;
}
