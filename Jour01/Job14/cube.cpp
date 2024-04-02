#include <iostream>

int main() {

    int number;
    std::cout << "Enter a number: ";
    std::cin >> number;
    // calculate the sum of the cubes since 1^3 + 2^3 + 3^3 + ... + n^3
    int sum = 0;
    for (int i = 1; i <= number; i++) {
        sum += i * i * i;
    }
    std::cout << "The sum of the cubes is " << sum << std::endl;
    return 0;
    
}
