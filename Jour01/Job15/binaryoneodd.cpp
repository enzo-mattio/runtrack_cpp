#include <iostream>

int main() {
    unsigned int number;
    std::cout << "Enter a number: ";
    std::cin >> number;
    // check if the sum of bits == 1 is even

    // 1 = 0001 == odd
    // 2 = 0010 == odd
    // 3 = 0011 == even
    // 4 = 0100 == odd
    // 5 = 0101 == even
    // 6 = 0110 == even
    // 7 = 0111 == odd
    // 8 = 1000 == odd
    // 9 = 1001 == even



    if (__builtin_popcount(number) % 2 == 0) {
        std::cout << "The number has an even number of 1s in its binary representation." << std::endl;
    } else {
        std::cout << "The number has an odd number of 1s in its binary representation." << std::endl;
    }
    return 0;
    
    
    
}
