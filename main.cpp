#include <iostream>
#include <string>
#include <cstring>
#include <typeinfo>
#include <string.h>

using namespace std;

int hasDupes (unsigned int n) {
    // Flag to indicate digit has been used, all zero to start.
    int used[10] = {0};

    // More than 10 digits must have duplicates, return true quickly.
    if (n > 9999999999) return 1;

    // Process each digit in number.
    while (n != 0) {
        // If duplicate, return true as soon as found.
        if (used[n%10]) return 1;

        // Otherwise, mark used, go to next digit.
        used[n%10] = 1;
        n /= 10;
    }

    // No duplicates after checking all digits, return false.
    return 0;
}

int main() {
    cout << hasDupes(12355);


    return 0;
}
