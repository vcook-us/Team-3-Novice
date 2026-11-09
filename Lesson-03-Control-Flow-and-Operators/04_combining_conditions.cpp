// Lesson 3 - Section 2: Combining conditions with && and ||
// Answers to "How can this code be made shorter and easier to read?"

#include <iostream>

int main() {
    // Example 1 - BEFORE: nested ifs, "Access denied." written twice
    //
    //   if (age >= 18) {
    //       if (hasTicket) {
    //           std::cout << "Allowed entry.\n";
    //       } else {
    //           std::cout << "Access denied.\n";
    //       }
    //   } else {
    //       std::cout << "Access denied.\n";
    //   }
    //
    // AFTER: use && (and) because BOTH must be true
    int age = 20;
    bool hasTicket = true;

    if (age >= 18 && hasTicket) {
        std::cout << "Allowed entry.\n";
    } else {
        std::cout << "Access denied.\n";
    }

    // Example 2 - BEFORE: two branches print the same discount message
    //
    //   if (age < 12) {
    //       std::cout << "You qualify for a discount!\n";
    //   }
    //   else if (isStudent) {
    //       std::cout << "You qualify for a discount!\n";
    //   }
    //   else {
    //       std::cout << "Regular pricing applies.\n";
    //   }
    //
    // AFTER: use || (or) because EITHER one earns the discount
    int customerAge = 25;
    bool isStudent = true;

    if (customerAge < 12 || isStudent) {
        std::cout << "You qualify for a discount!\n";
    } else {
        std::cout << "Regular pricing applies.\n";
    }

    return 0;
}
