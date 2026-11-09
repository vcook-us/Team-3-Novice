// Lesson 3 - Section 2: If else Statements
// - if runs a block of code when its condition is true
// - else runs another block when the if is false
// - an else if ladder checks the next condition only if the ones above were false
// - only the FIRST block that is true runs

#include <iostream>

int main() {
    int temperature = 24;

    if (temperature > 30) {
        // runs if temperature is greater than 30
        std::cout << "It's hot outside!\n";
    }
    else if (temperature >= 20) {
        // runs if the first condition was false,
        // but temperature is between 20 and 30 (inclusive)
        std::cout << "The weather is nice and warm.\n";
    }
    else if (temperature >= 10) {
        // runs if both conditions above were false,
        // but temperature is between 10 and 19
        std::cout << "It's a bit chilly.\n";
    }
    else {
        // acts as a catch-all.
        // runs only if ALL of the conditions above were false.
        std::cout << "It's freezing cold!\n";
    }

    return 0;
}
