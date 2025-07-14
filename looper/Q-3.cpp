#include <iostream>
using namespace std;

int main() {
    int number, firstDigit, lastDigit;

    cout << "Enter a number: ";
    cin >> number;

    // Handle negative numbers
    if (number < 0) {
        number = -number;
    }

    lastDigit = number % 10; // Get the last digit

    // Find the first digit
    while (number >= 10) {
        number /= 10;
    }
    firstDigit = number;

    int sum = firstDigit + lastDigit;

    cout << "Sum of the first and last digits: " << sum << endl;

    return 0;
}
